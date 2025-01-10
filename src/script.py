import os
import re
import threading

# For debugging. Normally always set to True
delete_processed_file = True

# Only one file which will be processed - useful for debugging. Needs to be set to "" by default
forced_file = ""

# Files that should not be processed at all
skip_files = ["agb_flash.c", "agb_flash_1m.c", "agb_flash_mx.c", "agb_flash_le.c", "siirtc.c", "librfu_intr.c", "berry_crush.c", "graphics.c", "pokedex_plus_hgss.c"]

# Lock for thread-safe writing to output.c
write_lock = threading.Lock()

# Precompiled regex patterns
static_variable_pattern = re.compile(
    r"^\s*(static\s+(?:const\s+)?(?:\w+\s+)+)(\w+)(\s*(?:\[.*\]|=.*|;))(.*.*$)",
    re.IGNORECASE,
)
complex_static_var_pattern = re.compile(
    r"^\s*(static\s+(?:const\s+)?(?:\w+\s+)+\*+\s+)(\w+)(\s*(?:\[.*\]|=.*|;))",
    re.IGNORECASE,
)
ewram_data_pattern = re.compile(
    r"^\s*(static\s+EWRAM_DATA|EWRAM_DATA\s+static)\s+((?:\w+\s+|\*)+)(\w+)(\s*(?:\[.*\]|=.*|;).*)$",
    re.IGNORECASE
)
ewram_data_struct_pattern = re.compile(
    r"^\s*(static\s+EWRAM_DATA|EWRAM_DATA\s+static)\s+((?:struct\s+\w+\s*|\w+\s+|\*)+)(\*?\s*\w+)(\s*(?:\[.*\]|=.*|;).*)$",
    re.IGNORECASE
)
ewram_complex_pattern = re.compile(
    r"^\s*(static\s+EWRAM_DATA\s+(?:\w+\s+)+\*+\s+)(\w+)(\s*(?:\[.*\]|=.*|;))",
    re.IGNORECASE,
)
inline_macro_pattern = re.compile(
    r"^\s*(static\s+(?:const\s+)?(?:\w+\s+)+)(\w+)(\s*=\s*\w+\(.*\);)",
    re.IGNORECASE,
)
# Add regex for variables with pointers and `*const` keywords
pointer_with_const_pattern = re.compile(
    r"^\s*(static\s+(?:const\s+)?(?:\w+\s+)+\*+const\s+)(\w+)(\s*\[\s*\]\s*=.*)",
    re.IGNORECASE,
)
function_pattern = re.compile(
    r"^\s*(static\s+)?((?:\w+\s+)+)(\w+)\s*\([^;{}]*\)\s*(\{)?\s*$",  # Match only valid function declarations/definitions
    re.IGNORECASE,
)
function_struct_pattern = re.compile(
    r"^\s*(static\s+)?(struct\s+\w+\s*\*?|[\w\*]+\s+)(\w+)\s*\([^;{}]*\)\s*(\{)?\s*$",
    re.IGNORECASE,
)
macro_pattern = re.compile(
    r"^\s*#define\s+(\w+)(\s*.*)$",
    re.IGNORECASE,
)
# Some macros are used only for a tiny specific thing or use ##, so they'll be hardcoded to get ignored.
macro_exceptions = ["move", "x", "power", "X", "MENU_TOP_WIN0", "MENU_TOP_WIN1", "MENU_TOP_WIN2", "MENU_TOP_WIN3", "MENU_TOP_WIN4", "MENU_TOP_WIN5", "MENU_TOP_WIN6", "MENU_HEIGHT_WIN0", "MENU_HEIGHT_WIN1", "MENU_HEIGHT_WIN2", "MENU_HEIGHT_WIN3", "MENU_HEIGHT_WIN4", "MENU_HEIGHT_WIN5", "MENU_HEIGHT_WIN6"]

aligned_variable_pattern = re.compile(
    r'^\s*(static\s+(?:const\s+)?(?:\w+\s+)+)ALIGNED\(\d+\)\s+(\w+)\s*(\[\s*\]\s*=\s*.+;)',
    re.IGNORECASE
)
# Regex for enum fields
enum_field_pattern = re.compile(r"^\s*(\w+)(\s*=\s*[^,]*|)(\s*,?)$")

# Function to process a single file
def process_file(filepath, output_file):   
    # Print to console after processing a file
    print(f"Processing: {os.path.basename(filepath)}")
   
    suffix = "_" + os.path.basename(filepath).replace(".c", "")
    with open(filepath, "r", encoding="utf-8") as input_file:
        lines = input_file.readlines()

    inside_struct = False
    inside_enum = False
    renames = {}
    processed_lines = []

    for i in range(len(lines)):
        line = lines[i]
        # Handle multi-line static struct definitions/declarations
        if inside_struct:
            struct_var_match = re.search(r"\}\s*(\w+)\[]?\s*=", line)
            if struct_var_match:
                struct_var_name = struct_var_match.group(1)
                if struct_var_name not in renames:
                    inside_struct = False
                    if not struct_var_name.endswith(suffix):  # Avoid duplicate suffixes
                        new_struct_var_name = struct_var_name + suffix
                        renames[struct_var_name] = new_struct_var_name
                        line = line.replace(struct_var_name, new_struct_var_name)
            # Append processed line
            processed_lines.append(line)
            continue 
        if inside_enum == False and "static const struct {" in line:
            inside_struct = True
            # Append processed line
            processed_lines.append(line)
            continue 
            
        stripped_line = line.strip()

        # Detect the start of an enum
        if inside_enum == False and stripped_line.startswith("enum"):
            if stripped_line.endswith("{"):
                inside_enum = True
            # Check Multi line enum start
            elif lines[i+1].strip().startswith("{") and not function_pattern.match(line):
                inside_enum = True
                #print("Line = " + line + "\nLine2 = " + lines[i+1] + "\n\n")
                # Append processed line
                processed_lines.append(line)
                continue 

        if inside_enum:
            # Detect the end of an enum
            if stripped_line.endswith("};"):
                inside_enum = False
            match = enum_field_pattern.match(line)
            if match:
                field_name = match.group(1)  # Enum field name
                value_part = match.group(2)  # Optional '= value' part
                comma = match.group(3)      # Trailing comma or whitespace

                # Add suffix to the enum field name
                if not field_name.endswith(suffix):
                    #print("Enum found: " + field_name)
                    new_field_name = field_name + suffix
                    renames[field_name] = new_field_name
                    line = line.replace(field_name, new_field_name, 1)
            # Append processed line
            processed_lines.append(line)
            continue 
        
        # Handle variables with ALIGNED(X) attribute
        aligned_match = aligned_variable_pattern.match(line)
        if aligned_match:
            declaration = aligned_match.group(1)  # Capture the declaration part
            var_name = aligned_match.group(2)     # Capture the variable name
            rest = aligned_match.group(3)         # Capture the rest (including array brackets and initialization)
            #print("Declaration : " + declaration + " var name:" + var_name + " rest : " + rest + "\n")
            if var_name not in renames:
                if not var_name.endswith(suffix):
                    new_var_name = var_name + suffix
                    renames[var_name] = new_var_name
                    line = declaration + "ALIGNED(" + re.search(r"ALIGNED\((\d+)\)", line).group(1) + ") " + new_var_name + rest + "\n"
            # Append processed line
            processed_lines.append(line)
            continue
            
        # Handle EWRAM DATA static struct variables
        ewram_struct_match = ewram_data_struct_pattern.match(line)
        if ewram_struct_match:
            prefix = ewram_struct_match.group(1)  # static EWRAM_DATA or EWRAM_DATA static
            type_declaration = ewram_struct_match.group(2)  # struct and type info
            var_name = ewram_struct_match.group(3)  # variable name
            rest = ewram_struct_match.group(4)  # remaining part (e.g., = NULL; or [size])
            
            var_name = var_name.lstrip()
            if var_name not in renames:
                if not var_name.endswith(suffix):
                    # Append suffix to the variable name
                    new_variable_name = re.sub(r"(\w+)$", rf"\1{suffix}", var_name)
                    renames[var_name] = new_variable_name
                    #print("Old " + var_name + " New: " + new_variable_name)
                    # Construct the updated line
                    line = f"{prefix} {type_declaration} {new_variable_name}{rest}\n"
            # Append processed line
            processed_lines.append(line)
            continue

        # Handle EWRAM DATA static variables
        ewram_match = ewram_data_pattern.match(line)
        if ewram_match:
            static_before = ewram_match.group(1) or ""  # `static` before EWRAM_DATA, if present
            static_after = ewram_match.group(2) or ""   # `static` after EWRAM_DATA, if present
            declaration = ewram_match.group(0)         # The full declaration line
            var_name = ewram_match.group(3)            # Variable name (e.g., `sUnusedOverheatData`)
            rest = ewram_match.group(4)                # Rest of the line (e.g., `[7] = {0};`)
            #print("Declaration : " + declaration + " var name:" + var_name + " rest : " + rest + "\n")
            if var_name not in renames and len(var_name) > 2:
                if not var_name.endswith(suffix):
                    new_var_name = var_name + suffix
                    renames[var_name] = new_var_name
                    line = declaration.replace(var_name, new_var_name)
                    line += "\n"
            # Append processed line
            processed_lines.append(line)
            continue
        
        # Handle static variables
        has_fourth_group = False
        
        match = static_variable_pattern.match(line)
        if match:
            has_fourth_group = True
        
        if not match:
            match = complex_static_var_pattern.match(line)
        if not match:
            match = ewram_complex_pattern.match(line)
        if not match:
            match = inline_macro_pattern.match(line)
        if not match:
            match = pointer_with_const_pattern.match(line)

        if match:
            declaration = match.group(1)
            var_name = match.group(2)
            rest = match.group(3)
            if has_fourth_group:
                rest += match.group(4)
            #print("Declaration : " + declaration + " var name:" + var_name + " rest : " + rest + "\n")
            if var_name not in renames and len(var_name) > 2:
                if not var_name.endswith(suffix):
                    new_var_name = var_name + suffix
                    renames[var_name] = new_var_name
                    line = declaration + new_var_name + rest + "\n"
            # Append processed line
            processed_lines.append(line)
            continue

        # Handle functions
        function_match = function_pattern.match(line)
        if not function_match:
            function_match = function_struct_pattern.match(line)
        if function_match:
            is_static = function_match.group(1) is not None
            return_type = function_match.group(2).strip()  # Capture return type and attributes
            function_name = function_match.group(3)  # Capture the function name
            
            # False positive
            if return_type == "else" and function_name == "if":
                #print("Found" + line)
                processed_lines.append(line)
                continue
            
            if is_static and function_name not in renames:
                #print("Function match: " + line + "name: " + function_name)
                if not function_name.endswith(suffix):
                    new_function_name = function_name + suffix
                    renames[function_name] = new_function_name
                    line = re.sub(
                        rf"(\b{return_type}\s+{function_name}\b)",
                        rf"{return_type} {new_function_name}",
                        line,
                    )
            # Append processed line
            processed_lines.append(line)
            continue

        # Handle macros
        macro_match = macro_pattern.match(line)
        if macro_match:
            macro_name = macro_match.group(1)
            if macro_name not in renames and macro_name not in macro_exceptions:
                if not macro_name.endswith(suffix):
                    new_macro_name = macro_name + suffix
                    renames[macro_name] = new_macro_name
                    #print("Macro change from: " + macro_name + " to: " + new_macro_name)
            # Append processed line
            processed_lines.append(line)
            continue

        # Append processed line
        processed_lines.append(line)

    # Update all occurrences of renamed variables, functions, and macros
    for original, renamed in renames.items():
        # Replace standalone occurrences of the original name
        processed_lines = [
            re.sub(rf"\b{original}\b", renamed, pline) for pline in processed_lines
        ]

    # Write processed lines to output
    with write_lock:
        with open(output_file, "a", encoding="utf-8") as output:
            output.write(f"// Contents of {os.path.basename(filepath)}\n")
            output.writelines(processed_lines)

    # Process includes
    process_includes(filepath, renames, False)

    # Delete the original file
    if delete_processed_file:
        os.remove(filepath)
        print(f"Deleted: {os.path.basename(filepath)}")

# Function to process and update includes
def process_includes(filepath, renames, is_recursive):
    directory = os.path.dirname(filepath)
    with open(filepath, "r", encoding="utf-8") as file:
        for line in file:
            if is_recursive:
                include_match = re.match(r'^\s*#include\s+\"(.+?\.h)\"', line)
            else: # Has to be data
                include_match = re.match(r'^\s*#include\s+\"(data/.+?\.h)\"', line)
            if include_match:
                #print("Include found: +", include_match)
                include_file = include_match.group(1)
                include_path = os.path.join(directory, include_file)
                #print("include_path = ", include_path)
                if os.path.exists(include_path):
                    print("Checking for renames in: " + include_path)
                    with open(include_path, "r", encoding="utf-8") as inc_file:
                        contents = inc_file.read()
                    for original, renamed in renames.items():
                        contents = re.sub(rf"\b{original}\b", renamed, contents)
                    with open(include_path, "w", encoding="utf-8") as inc_file:
                        inc_file.write(contents)
                    # Check for recursive headers
                    process_includes(include_path, renames, True)

# Main function
def main():
    input_dir = os.path.dirname(os.path.abspath(__file__))  # Use script's directory
    output_file = os.path.join(input_dir, "output.c")
    
    do_threads = False

    # Clear the output file
    with open(output_file, "w", encoding="utf-8") as output:
        pass
        
    if forced_file == "":
        # Process files in the directory
        threads = []
        processed_files_count = 0
        for filename in os.listdir(input_dir):
            if processed_files_count >= 262:
                break
            if filename.endswith(".c") and filename != "output.c" and filename not in skip_files:
                filepath = os.path.join(input_dir, filename)
                if do_threads == True:
                    thread = threading.Thread(target=process_file, args=(filepath, output_file))
                    threads.append(thread)
                    thread.start()
                else:
                    process_file(filepath, output_file)
                processed_files_count += 1

        for thread in threads:
            thread.join()
    else:
        if os.path.exists(forced_file):
            process_file(forced_file, output_file)
        else:
            print("Forced file does not exist!")

if __name__ == "__main__":
    main()
