#ifndef GUARD_MANSION_FLOOR_GENERATION_H
#define GUARD_MANSION_FLOOR_GENERATION_H

#include "constants/mansion_floor_generation.h"

enum ROOM_ENUM MapToRoomEnum(s32 mapGroup, s32 mapNum, s32 floorNum);
void RoomEnumToMap(enum ROOM_ENUM roomEnum, s32 *mapGroup, s32 *mapNum, s32 floorNum);
void GenerateMansionFloorLayout(u8 roomsGrid[GRID_X_LEN][GRID_Y_LEN]);
void SetMansionWarpDestination(const struct WarpEvent *warpEvent);

#endif
