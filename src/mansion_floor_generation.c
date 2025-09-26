#include "global.h"
#include "mansion_floor_generation.h"
#include "random.h"
#include "text.h"
#include "window.h"
#include "menu.h"
#include "overworld.h"
#include "script.h"
#include "main.h"
#include "debug.h"

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

// Left/Right and Down/Up directions have to be reversed, my head hurts thinking about it, but yeah has to be this way lol
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

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_DOWN) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1TREASURE_DOWN))
            return ROOM_TREASURE_UP;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_UP) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1TREASURE_UP))
            return ROOM_TREASURE_DOWN;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_LEFT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1TREASURE_LEFT))
            return ROOM_TREASURE_RIGHT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_RIGHT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1TREASURE_RIGHT))
            return ROOM_TREASURE_LEFT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1HALLWAY1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1HALLWAY1))
            return ROOM_HALLWAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1HALLWAY2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1HALLWAY2))
            return ROOM_HALLWAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR1ROOM_BOSS) && mapNum == MAP_NUM(MAP_MANSION_FLOOR1ROOM_BOSS))
            return ROOM_BOSS;
    }
    else if (floorNum == 2) {
        if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ENTRANCE) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ENTRANCE))
            return ROOM_ENTRANCE;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ROOM1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ROOM1))
            return ROOM_4WAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ROOM2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ROOM2))
            return ROOM_4WAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ROOM3) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ROOM3))
            return ROOM_4WAY_3;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ROOM4) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ROOM4))
            return ROOM_4WAY_4;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_DOWN) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2TREASURE_DOWN))
            return ROOM_TREASURE_UP;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_UP) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2TREASURE_UP))
            return ROOM_TREASURE_DOWN;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_LEFT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2TREASURE_LEFT))
            return ROOM_TREASURE_RIGHT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_RIGHT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2TREASURE_RIGHT))
            return ROOM_TREASURE_LEFT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2HALLWAY1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2HALLWAY1))
            return ROOM_HALLWAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2HALLWAY2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2HALLWAY2))
            return ROOM_HALLWAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR2ROOM_BOSS) && mapNum == MAP_NUM(MAP_MANSION_FLOOR2ROOM_BOSS))
            return ROOM_BOSS;
    }
    else if (floorNum == 3) {
        if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ENTRANCE) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ENTRANCE))
            return ROOM_ENTRANCE;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ROOM1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ROOM1))
            return ROOM_4WAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ROOM2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ROOM2))
            return ROOM_4WAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ROOM3) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ROOM3))
            return ROOM_4WAY_3;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ROOM4) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ROOM4))
            return ROOM_4WAY_4;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_DOWN) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3TREASURE_DOWN))
            return ROOM_TREASURE_UP;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_UP) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3TREASURE_UP))
            return ROOM_TREASURE_DOWN;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_LEFT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3TREASURE_LEFT))
            return ROOM_TREASURE_RIGHT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_RIGHT) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3TREASURE_RIGHT))
            return ROOM_TREASURE_LEFT;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3HALLWAY1) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3HALLWAY1))
            return ROOM_HALLWAY_1;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3HALLWAY2) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3HALLWAY2))
            return ROOM_HALLWAY_2;

        else if (mapGroup == MAP_GROUP(MAP_MANSION_FLOOR3ROOM_BOSS) && mapNum == MAP_NUM(MAP_MANSION_FLOOR3ROOM_BOSS))
            return ROOM_BOSS;
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
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ENTRANCE);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ENTRANCE);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ENTRANCE);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ENTRANCE);
            }
            break;
        case ROOM_4WAY_1:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM1);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ROOM1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ROOM1);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ROOM1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ROOM1);
            }
            break;
        case ROOM_4WAY_2:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM2);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ROOM2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ROOM2);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ROOM2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ROOM2);
            }
            break;
        case ROOM_4WAY_3:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM3);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM3);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ROOM3);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ROOM3);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ROOM3);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ROOM3);
            }
            break;
        case ROOM_4WAY_4:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM4);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM4);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ROOM4);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ROOM4);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ROOM4);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ROOM4);
            }
            break;
        case ROOM_HALLWAY_1:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1HALLWAY1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1HALLWAY1);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2HALLWAY1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2HALLWAY1);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3HALLWAY1);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3HALLWAY1);
            }
            break;
        case ROOM_HALLWAY_2:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1HALLWAY2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1HALLWAY2);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2HALLWAY2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2HALLWAY2);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3HALLWAY2);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3HALLWAY2);
            }
            break;
        case ROOM_TREASURE_DOWN:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_UP);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1TREASURE_UP);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_UP);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2TREASURE_UP);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_UP);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3TREASURE_UP);
            }
            break;
        case ROOM_TREASURE_UP:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_DOWN);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1TREASURE_DOWN);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_DOWN);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2TREASURE_DOWN);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_DOWN);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3TREASURE_DOWN);
            }
            break;
        case ROOM_TREASURE_LEFT:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_RIGHT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1TREASURE_RIGHT);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_RIGHT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2TREASURE_RIGHT);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_RIGHT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3TREASURE_RIGHT);
            }
            break;
        case ROOM_TREASURE_RIGHT:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1TREASURE_LEFT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1TREASURE_LEFT);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2TREASURE_LEFT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2TREASURE_LEFT);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3TREASURE_LEFT);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3TREASURE_LEFT);
            }
            break;
        case ROOM_BOSS:
            if (floorNum == 1) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR1ROOM_BOSS);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR1ROOM_BOSS);
            }
            else if (floorNum == 2) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR2ROOM_BOSS);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR2ROOM_BOSS);
            }
            else if (floorNum == 3) {
                *mapGroup = MAP_GROUP(MAP_MANSION_FLOOR3ROOM_BOSS);
                *mapNum = MAP_NUM(MAP_MANSION_FLOOR3ROOM_BOSS);
            }
            break;
        case ROOM_NOTHING:
            break;
    }
}

void GenerateMansionFloorLayout(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN], s32 floorNum)
{
    enum ROOM_ENUM last4WayId;
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
    if (!(bits4Way & (1u << ROOM_4WAY_1))) {
        last4WayId = ROOM_4WAY_1;
    }
    else if (!(bits4Way & (1u << ROOM_4WAY_2))) {
        last4WayId = ROOM_4WAY_2;
    }
    else if (!(bits4Way & (1u << ROOM_4WAY_3))) {
        last4WayId = ROOM_4WAY_3;
    }
    else if (!(bits4Way & (1u << ROOM_4WAY_4))) {
        last4WayId = ROOM_4WAY_4;
    }
    else {
        // Should never be reached
        last4WayId = ROOM_4WAY_1;
    }

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
            roomsGrid[ENTRANCE_X][ENTRANCE_Y-3] = last4WayId;
            roomsGrid[ENTRANCE_X+1][ENTRANCE_Y-3] = ROOM_TREASURE_DOWN;
            break;
        case 1: // 4-E-H-L4
            roomsGrid[ENTRANCE_X][ENTRANCE_Y+3] = last4WayId;
            roomsGrid[ENTRANCE_X+1][ENTRANCE_Y+3] = ROOM_TREASURE_DOWN;
            break;
        case 2: // L4-H-4
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y-2] = last4WayId;
            roomsGrid[ENTRANCE_X][ENTRANCE_Y-2] = ROOM_TREASURE_DOWN;
            break;
        case 3: // 4-H-L4
            roomsGrid[ENTRANCE_X-1][ENTRANCE_Y+2] = last4WayId;
            roomsGrid[ENTRANCE_X][ENTRANCE_Y+2] = ROOM_TREASURE_DOWN;
            break;
    }

    // Step 5: Assign the Treasure Up to either entrance Entrance Up 4 way up or last 4 way up
    // Also assign the boss room
    if (Random() % 2 == 0 && floorNum != 2) { // Floor 2 can only be accessed left/right for now
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

#define tWindowId data[0]

static void Task_WaitForInput(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (JOY_NEW(A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON)) {
        ClearRemoveWindow(task->tWindowId);
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

static void PrintMansionFloorLayout(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN])
{
    u8 taskId;
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
    taskId = CreateTask(Task_WaitForInput, 5);
    gTasks[taskId].tWindowId = windowId;
}

#undef tWindowId

void PrintMansionFloor1Layout(void)
{
    PrintMansionFloorLayout(gSaveBlock1Ptr->mansionFloor1Grid);
}

void PrintMansionFloor2Layout(void)
{
    PrintMansionFloorLayout(gSaveBlock1Ptr->mansionFloor2Grid);
}

void PrintMansionFloor3Layout(void)
{
    PrintMansionFloorLayout(gSaveBlock1Ptr->mansionFloor3Grid);
}

static s32 FindRndWarpInMap(s32 mapGroup, s32 mapNum, s32 wantedDst)
{
    s32 i;
    const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);
    s32 warpCount = header->events->warpCount;
    const struct WarpEvent *warps = header->events->warps;

    for (i = 0; i < warpCount; i++) {
        if (warps[i].mapGroup == MAP_GROUP(wantedDst) && warps[i].mapNum == MAP_NUM(wantedDst)) {
            return i;
        }
    }

    // This should never happen!
    return -1;
}

static enum ROOM_ENUM GetNextGridLocation(s32 floorNum, enum ROOM_ENUM currLoc, s32 dir)
{
    enum ROOM_ENUM next;
    s32 i, j;
    u8 (*roomsGrid)[GRID_X_LEN][GRID_Y_LEN];

    if (floorNum == 1) {
        roomsGrid = &gSaveBlock1Ptr->mansionFloor1Grid;
    }
    else if (floorNum == 2) {
        roomsGrid = &gSaveBlock1Ptr->mansionFloor2Grid;
    }
    else if (floorNum == 3) {
        roomsGrid = &gSaveBlock1Ptr->mansionFloor3Grid;
    }
    else {
        // Should never happen
        return ROOM_NOTHING;
    }

    for (i = 1; i < GRID_X_LEN; i++) {
        for (j = 0; j < GRID_Y_LEN; j++) {
            if ((*roomsGrid)[i][j] == currLoc) {
                if (dir == DIR_NORTH) {
                    next = (*roomsGrid)[i-1][j];
                }
                else if (dir == DIR_SOUTH) {
                    next = (*roomsGrid)[i+1][j];
                }
                else if (dir == DIR_EAST) {
                    next = (*roomsGrid)[i][j+1];
                }
                else if (dir == DIR_WEST) {
                    next = (*roomsGrid)[i][j-1];
                }

                // Treasure rooms can only be accessed from 1 direction only!
                switch (next) {
                    case ROOM_TREASURE_DOWN:
                        if (dir != DIR_SOUTH)
                            continue;
                        break;
                    case ROOM_TREASURE_UP:
                        if (dir != DIR_NORTH)
                            continue;
                        break;
                    case ROOM_TREASURE_LEFT:
                        if (dir != DIR_WEST)
                            continue;
                        break;
                    case ROOM_TREASURE_RIGHT:
                        if (dir != DIR_EAST)
                            continue;
                        break;
                    default:
                        break;
                }

                return next;
            }
        }
    }

    // Should never happen
    return ROOM_NOTHING;
}

extern const u8 EventScript_MansionDoorLocked[];

static s32 MapToFloorNum(s32 mapGroup, s32 mapNum)
{
    s32 mapId = (mapGroup << 8) | mapNum;

    switch (mapId) {
        case MAP_MANSION_FLOOR1ENTRANCE:
        case MAP_MANSION_FLOOR1ROOM1:
        case MAP_MANSION_FLOOR1ROOM2:
        case MAP_MANSION_FLOOR1ROOM3:
        case MAP_MANSION_FLOOR1ROOM4:
        case MAP_MANSION_FLOOR1TREASURE_DOWN:
        case MAP_MANSION_FLOOR1TREASURE_UP:
        case MAP_MANSION_FLOOR1TREASURE_LEFT:
        case MAP_MANSION_FLOOR1TREASURE_RIGHT:
        case MAP_MANSION_FLOOR1HALLWAY1:
        case MAP_MANSION_FLOOR1HALLWAY2:
        case MAP_MANSION_FLOOR1ROOM_BOSS:
            return 1;
        case MAP_MANSION_FLOOR2ENTRANCE:
        case MAP_MANSION_FLOOR2ROOM1:
        case MAP_MANSION_FLOOR2ROOM2:
        case MAP_MANSION_FLOOR2ROOM3:
        case MAP_MANSION_FLOOR2ROOM4:
        case MAP_MANSION_FLOOR2TREASURE_DOWN:
        case MAP_MANSION_FLOOR2TREASURE_UP:
        case MAP_MANSION_FLOOR2TREASURE_LEFT:
        case MAP_MANSION_FLOOR2TREASURE_RIGHT:
        case MAP_MANSION_FLOOR2HALLWAY1:
        case MAP_MANSION_FLOOR2HALLWAY2:
        case MAP_MANSION_FLOOR2ROOM_BOSS:
            return 2;
        case MAP_MANSION_FLOOR3ENTRANCE:
        case MAP_MANSION_FLOOR3ROOM1:
        case MAP_MANSION_FLOOR3ROOM2:
        case MAP_MANSION_FLOOR3ROOM3:
        case MAP_MANSION_FLOOR3ROOM4:
        case MAP_MANSION_FLOOR3TREASURE_DOWN:
        case MAP_MANSION_FLOOR3TREASURE_UP:
        case MAP_MANSION_FLOOR3TREASURE_LEFT:
        case MAP_MANSION_FLOOR3TREASURE_RIGHT:
        case MAP_MANSION_FLOOR3HALLWAY1:
        case MAP_MANSION_FLOOR3HALLWAY2:
        case MAP_MANSION_FLOOR3ROOM_BOSS:
            return 3;
        // Should never be reached
        default:
            return 1;
    }
}

bool32 SetMansionWarpDestination(const struct WarpEvent *warpEvent)
{
    s32 warpId;
    s32 retWarpDir;
    s32 floorNum = MapToFloorNum(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    s32 dstMapGroup = 0, dstMapNum = 0;
    enum ROOM_ENUM dstGridLocation;
    // Get current location in grid
    enum ROOM_ENUM currGridLocation = MapToRoomEnum(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, floorNum);

    // Get next location in desired direction in grid
    if (warpEvent->mapNum == MAP_NUM(MAP_RND_MANSION_UP)) {
        dstGridLocation = GetNextGridLocation(floorNum, currGridLocation, DIR_NORTH);
        retWarpDir = MAP_RND_MANSION_DOWN;
    }
    else if (warpEvent->mapNum == MAP_NUM(MAP_RND_MANSION_DOWN)) {
        dstGridLocation = GetNextGridLocation(floorNum, currGridLocation, DIR_SOUTH);
        retWarpDir = MAP_RND_MANSION_UP;
    }
    else if (warpEvent->mapNum == MAP_NUM(MAP_RND_MANSION_LEFT)) {
        dstGridLocation = GetNextGridLocation(floorNum, currGridLocation, DIR_WEST);
        retWarpDir = MAP_RND_MANSION_RIGHT;
    }
    else if (warpEvent->mapNum == MAP_NUM(MAP_RND_MANSION_RIGHT)) {
        dstGridLocation = GetNextGridLocation(floorNum, currGridLocation, DIR_EAST);
        retWarpDir = MAP_RND_MANSION_LEFT;
    }
    else { // Should not happen
        return FALSE;
    }

    // Get the map id from the randomized grid
    RoomEnumToMap(dstGridLocation, &dstMapGroup, &dstMapNum, floorNum);

    // Find the warp with an opposite direction
    warpId = FindRndWarpInMap(dstMapGroup, dstMapNum, retWarpDir);
    if (warpId == -1) {
        // Print Door is jammed msg
        ScriptContext_SetupScript(EventScript_MansionDoorLocked);
        return FALSE;
    }

    SetWarpDestinationToMapWarp(dstMapGroup, dstMapNum, warpId);
    return TRUE;
}

void GenerateAllMansionFloorLayouts(void)
{
    GenerateMansionFloorLayout(gSaveBlock1Ptr->mansionFloor1Grid, 1);
    GenerateMansionFloorLayout(gSaveBlock1Ptr->mansionFloor2Grid, 2);
    GenerateMansionFloorLayout(gSaveBlock1Ptr->mansionFloor3Grid, 3);
}
