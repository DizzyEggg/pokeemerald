#ifndef GUARD_CONSTANTS_MAPS_H
#define GUARD_CONSTANTS_MAPS_H

#include "map_groups.h"

// Warps using this map will instead use the warp data stored in gSaveBlock1Ptr->dynamicWarp.
// Used for warps that need to change destinations, e.g. when stepping off an elevator.
#define MAP_DYNAMIC (0x7F | (0x7F << 8))

#define MAP_RND_MANSION_UP (0xFB | (0xFB << 8))
#define MAP_RND_MANSION_DOWN (0xFC | (0xFC << 8))
#define MAP_RND_MANSION_LEFT (0xFD | (0xFD << 8))
#define MAP_RND_MANSION_RIGHT (0xFE | (0xFE << 8))
// Special sets for floor3, where the room has 2 sets of possible entries.
#define MAP_RND_MANSION_UP_SIDE_RIGHT (0xFA | (0xFA << 8))
#define MAP_RND_MANSION_DOWN_SIDE_RIGHT (0xF9 | (0xF9 << 8))
#define MAP_RND_MANSION_LEFT_SIDE_RIGHT (0xF8 | (0xF8 << 8))
#define MAP_RND_MANSION_RIGHT_SIDE_RIGHT (0xF7 | (0xF7 << 8))

#define MAP_RND_MANSION_UP_SIDE_LEFT (0xF6 | (0xF6 << 8))
#define MAP_RND_MANSION_DOWN_SIDE_LEFT (0xF5 | (0xF5 << 8))
#define MAP_RND_MANSION_LEFT_SIDE_LEFT (0xF4 | (0xF4 << 8))
#define MAP_RND_MANSION_RIGHT_SIDE_LEFT (0xF3 | (0xF3 << 8))

#define MAP_UNDEFINED (0xFF | (0xFF << 8))

#define MAP_GROUP(map) (map >> 8)
#define MAP_NUM(map) (map & 0xFF)

// IDs for dynamic warps. Both are used in the dest_warp_id field for warp events, but they
// are never read in practice. A dest_map of MAP_DYNAMIC is used to indicate that a
// dynamic warp should be used, at which point the warp id is ignored. They can be passed
// as the argument to SetWarpDestinationToDynamicWarp, but this argument is unused.
// As only one dynamic warp is saved at a time there's no need to distinguish between them.
#define WARP_ID_SECRET_BASE 0x7E
#define WARP_ID_DYNAMIC     0x7F

// Used to indicate an invalid warp id, for dummy warps or when a warp should
// use the given coordinates rather than the coordinates of a target warp.
#define WARP_ID_NONE (-1)

#endif  // GUARD_CONSTANTS_MAPS_H
