#include "global.h"
#include "mansion_floor_generation.h"
#include "random.h"
#include "text.h"
#include "window.h"
#include "menu.h"

#define ENTRANCE_X 4
#define ENTRANCE_Y 4

static void GenerateStep2Entry(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN], u32 rndCase, enum ROOM_ENUM entry)
{
    switch (rndCase) {
        case 0: // H-4-E
            roomsGrid[ENTRANCE_X][ENTRANCE_Y-2] = entry;
            break;
        case 1: // 4-E-H
            roomsGrid[ENTRANCE_X][ENTRANCE_Y+2] = entry;
            break;
        case 2: // H-4
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-1] = entry;
            break;
        case 3: // 4-H
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+1] = entry;
            break;
    }
}

static enum ROOM_ENUM GetRandom4Way(u32 *doneBits)
{
    enum ROOM_ENUM rnd4Way = ROOM_4WAY_1;
    do {
        rnd4Way = ROOM_4WAY_1 + (Random() % 4);
    } while (*doneBits & (1u << rnd4Way));

    *doneBits |= (1u << rnd4Way);

    return rnd4Way;
}

// Note: floorNum is not an id, so floor 1 is 1, floor 2 is 2, etc.
enum ROOM_ENUM MapToRoomEnum(s32 mapGroup, s32 mapNum, s32 floorNum)
{
    if (floorNum == 1) {
        if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ENTRANCE) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ENTRANCE))
            return ROOM_ENTRANCE;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ROOM1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ROOM1))
            return ROOM_4WAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ROOM2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ROOM2))
            return ROOM_4WAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ROOM3) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ROOM3))
            return ROOM_4WAY_3;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ROOM4) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ROOM4))
            return ROOM_4WAY_4;

        // TODO: Handle last 4way
    }


    return ROOM_NOTHING;
}

void RoomEnumToMap(enum ROOM_ENUM roomEnum, s32 *mapGroup, s32 *mapNum, s32 floorNum)
{
    switch (roomEnum) {
        case ROOM_ENTRANCE:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ENTRANCE);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ENTRANCE);
            }
            break;
        case ROOM_4WAY_1:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM1);
            }
            break;
        case ROOM_4WAY_2:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM2);
            }
            break;
        case ROOM_4WAY_3:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM3);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM3);
            }
            break;
        case ROOM_4WAY_4:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM4);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM4);
            }
            break;
        case ROOM_4WAY_LAST:
            break;
        case ROOM_HALLWAY_1:
            break;
        case ROOM_HALLWAY_2:
            break;
        case ROOM_TREASURE_DOWN:
            break;
        case ROOM_TREASURE_UP:
            break;
        case ROOM_TREASURE_LEFT:
            break;
        case ROOM_TREASURE_RIGHT:
            break;
        case ROOM_BOSS:
            break;
        case ROOM_NOTHING:
            break;
    }
}

void GenerateMansionFloorLayout(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN])
{
    s32 i;
    u32 randH1, randH2, last4Way, bits4Way;

    // Clear grid
    memset(roomsGrid, 0, GRID_LEN);

    // Define entrance point
    roomsGrid[ENTRANCE_X][ENTRANCE_Y] = ROOM_ENTRANCE;

    // Step 1: Generate 4 rooms
    bits4Way = 0;
    roomsGrid[ENTRANCE_X][ENTRANCE_Y+1] = GetRandom4Way(&bits4Way);
    roomsGrid[ENTRANCE_X][ENTRANCE_Y-1] = GetRandom4Way(&bits4Way);
    roomsGrid[ENTRANCE_X-1][ENTRANCE_Y] = GetRandom4Way(&bits4Way);

    // Step 2a: Generate 2 hallways. There are 4 possible options
    randH1 = Random() % 4;
    do {
        randH2 = Random() % 4;
        // Hallways have to be on the opposite sides, so case 0 cannot go with case 2 and case 1 cannot go with case 3
    } while (randH1 == randH2 || ((randH1 & 1) == (randH2 & 1)));

    GenerateStep2Entry(roomsGrid, randH1, ROOM_HALLWAY_1);
    GenerateStep2Entry(roomsGrid, randH2, ROOM_HALLWAY_2);

    // Step 2b: Generate 2 Treasure Rooms, or rather assign them to the remaining Left and Right 4ways
    for (i = 0; i < 4; i++) {
        if (randH1 == i || randH2 == i)
            continue;
        if (i % 2 == 0) {
            GenerateStep2Entry(roomsGrid, i, ROOM_TREASURE_LEFT);
        }
        else {
            GenerateStep2Entry(roomsGrid, i, ROOM_TREASURE_RIGHT);
        }
    }

    // Step 3 and 4: Assign the last 4way room to one of the hallways and treasure up to it.
    last4Way = ((Random() & 1) != 0) ? randH1 : randH2;
    switch (last4Way) {
        case 0: // L4-H-4-E
            roomsGrid[ENTRANCE_X][ENTRANCE_Y-3] = ROOM_4WAY_LAST;
            roomsGrid[ENTRANCE_X+1][ENTRANCE_Y-3] = ROOM_TREASURE_DOWN;
            break;
        case 1: // 4-E-H-L4
            roomsGrid[ENTRANCE_X][ENTRANCE_Y+3] = ROOM_4WAY_LAST;
            roomsGrid[ENTRANCE_X+1][ENTRANCE_Y+3] = ROOM_TREASURE_DOWN;
            break;
        case 2: // L4-H-4
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-2] = ROOM_4WAY_LAST;
            roomsGrid[ENTRANCE_X][ENTRANCE_Y-2] = ROOM_TREASURE_DOWN;
            break;
        case 3: // 4-H-L4
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+2] = ROOM_4WAY_LAST;
            roomsGrid[ENTRANCE_X][ENTRANCE_Y+2] = ROOM_TREASURE_DOWN;
            break;
    }

    // Step 5: Assign the Treasure Up to either entrance Entrance Up 4 way up or last 4 way up
    // Also assign the boss room
    if (Random() % 2 == 0) {
        u32 rndB = Random() & 1;
        // Tu is in the entrance up 4way, so boss1 can in be in the last4Way left/right or up
        roomsGrid[ENTRANCE_X-2][ENTRANCE_Y] = ROOM_TREASURE_UP;
        switch (last4Way) {
            case 0:
                if (rndB == 0) {
                    roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-3] = ROOM_BOSS;
                }
                else {
                    roomsGrid[ENTRANCE_X][ENTRANCE_Y-4] = ROOM_BOSS;
                }
                break;
            case 1:
                if (rndB == 0) {
                    roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+3] = ROOM_BOSS;
                }
                else {
                    roomsGrid[ENTRANCE_X][ENTRANCE_Y+4] = ROOM_BOSS;
                }
                break;
            case 2:
                if (rndB == 0) {
                    roomsGrid[ENTRANCE_X-2][ENTRANCE_Y-2] = ROOM_BOSS;
                }
                else {
                    roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-3] = ROOM_BOSS;
                }
                break;
            case 3:
                if (rndB == 0) {
                    roomsGrid[ENTRANCE_X-2][ENTRANCE_Y+2] = ROOM_BOSS;
                }
                else {
                    roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+3] = ROOM_BOSS;
                }
                break;
        }
    }
    else {
        // Tu is in the last 4way, so boss1 has to be left/right
        switch (last4Way) {
            case 0:
                roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-3] = ROOM_TREASURE_UP;
                roomsGrid[ENTRANCE_X][ENTRANCE_Y-4] = ROOM_BOSS;
                break;
            case 1:
                roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+3] = ROOM_TREASURE_UP;
                roomsGrid[ENTRANCE_X][ENTRANCE_Y+4] = ROOM_BOSS;
                break;
            case 2:
                roomsGrid[ENTRANCE_X-2][ENTRANCE_Y-2] = ROOM_TREASURE_UP;
                roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-3] = ROOM_BOSS;
                break;
            case 3:
                roomsGrid[ENTRANCE_X-2][ENTRANCE_Y+2] = ROOM_TREASURE_UP;
                roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+3] = ROOM_BOSS;
                break;
        }
    }

    //PrintGrid(roomsGrid);
}

void RoomEnumToChar(enum ROOM_ENUM roomEnum, u8 *c1, u8 *c2)
{
    switch (roomEnum) {
        case ROOM_NOTHING:
            *c1 = CHAR_X, *c2 = CHAR_X;
            break;
        case ROOM_ENTRANCE:
            *c1 = CHAR_E, *c2 = CHAR_E;
            break;
        case ROOM_4WAY_1:
            *c1 = CHAR_4, *c2 = CHAR_a;
            break;
        case ROOM_4WAY_2:
            *c1 = CHAR_4, *c2 = CHAR_b;
            break;
        case ROOM_4WAY_3:
            *c1 = CHAR_4, *c2 = CHAR_c;
            break;
        case ROOM_4WAY_4:
            *c1 = CHAR_4, *c2 = CHAR_d;
            break;
        case ROOM_4WAY_LAST:
            *c1 = CHAR_4, *c2 = CHAR_l;
            break;
        case ROOM_HALLWAY_1:
            *c1 = CHAR_H, *c2 = CHAR_a;
            break;
        case ROOM_HALLWAY_2:
            *c1 = CHAR_H, *c2 = CHAR_b;
            break;
        case ROOM_TREASURE_UP:
            *c1 = CHAR_T, *c2 = CHAR_u;
            break;
        case ROOM_TREASURE_DOWN:
            *c1 = CHAR_T, *c2 = CHAR_d;
            break;
        case ROOM_TREASURE_LEFT:
            *c1 = CHAR_T, *c2 = CHAR_l;
            break;
        case ROOM_TREASURE_RIGHT:
            *c1 = CHAR_T, *c2 = CHAR_r;
            break;
        case ROOM_BOSS:
            *c1 = CHAR_B, *c2 = CHAR_b;
            break;
    }
}

static const struct WindowTemplate sGridWinTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 20,
    .height = 11,
    .paletteNum = 15,
    .baseBlock = 1,
};

static void PrintMansionFloorLayout(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN])
{
    u8 text[100];
    s32 i, j;
    s32 windowId;

    LoadMessageBoxAndBorderGfx();
    windowId = AddWindow(&sGridWinTemplate);
    DrawStdWindowFrame(windowId, FALSE);
    for (i = 0; i < GRID_X_LEN; i++) {
        for (j = 0; j < GRID_Y_LEN; j++) {
            RoomEnumToChar(roomsGrid[i][j], &text[j * 2 + 0], &text[j * 2 + 1]);
        }
        text[j*2] = CHAR_NEWLINE;
        text[j*2+1] = EOS;

        AddTextPrinterParameterized(windowId, FONT_NORMAL, text, 0, 15 * i, 0, NULL);
    }
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

void PrintMansionFloor1Layout(void)
{
    PrintMansionFloorLayout(gSaveBlock1Ptr->mansionFloor1Grid);
}
