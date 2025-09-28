#include "global.h"
#include "item.h"
#include "item_ball.h"
#include "event_data.h"
#include "constants/event_objects.h"
#include "constants/items.h"

static u32 GetItemBallAmountFromTemplate(u32);
static u32 GetItemBallIdFromTemplate(u32);

static u32 GetItemBallAmountFromTemplate(u32 itemBallId)
{
    u32 amount = gMapHeader.events->objectEvents[itemBallId].movementRangeX;

    if (amount > MAX_BAG_ITEM_CAPACITY)
        return MAX_BAG_ITEM_CAPACITY;

    return (amount == 0) ? 1 : amount;
}

static u32 GetItemBallIdFromTemplate(u32 itemBallId)
{
    u32 itemId = gMapHeader.events->objectEvents[itemBallId].trainerRange_berryTreeId;

    return (itemId >= ITEMS_COUNT) ? (ITEM_NONE + 1) : itemId;
}

void GetItemBallIdAndAmountFromTemplate(void)
{
    u32 itemBallId = (gSpecialVar_LastTalked - 1);
    gSpecialVar_Result = GetItemBallIdFromTemplate(itemBallId);
    gSpecialVar_0x8009 = GetItemBallAmountFromTemplate(itemBallId);
}

bool32 IsUniqueItem(u32 itemId)
{
    switch (itemId) {
        case UNIQUE_ITEM_GREEN_DISC:
        case UNIQUE_ITEM_RED_DISC:
        case UNIQUE_ITEM_BLACK_DISC:
        case UNIQUE_ITEM_GRAY_DISC:
        case UNIQUE_ITEM_PURPLE_DISC:
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1:
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2:
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3:
        case UNIQUE_ITEM_PHOTO_1:
        case UNIQUE_ITEM_PHOTO_2:
        case UNIQUE_ITEM_PHOTO_3:
        case UNIQUE_ITEM_PHOTO_4:
        case UNIQUE_ITEM_PHOTO_5:
            return TRUE;
        default:
            return FALSE;
    }
}

bool32 IsVialItem(u32 itemId)
{
    switch (itemId) {
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_1:
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_2:
        case UNIQUE_ITEM_INKWELL_FULL_BOTTLE_3:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3:
        case ITEM_LATIASITE:
        case ITEM_LATIOSITE:
        case ITEM_SALAMENCITE:
        case ITEM_LOPUNNITE:
        case ITEM_METAGROSSITE:
        case ITEM_GARCHOMPITE:
            return TRUE;
        default:
            return FALSE;
    }
}

bool32 IsVialEmptyItem(u32 itemId)
{
    switch (itemId) {
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_1:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_2:
        case UNIQUE_ITEM_INKWELL_EMPTY_BOTTLE_3:
        case ITEM_LATIASITE:
        case ITEM_SALAMENCITE:
        case ITEM_METAGROSSITE:
            return TRUE;
        default:
            return FALSE;
    }
}

static u32 GetItemBallIdFromSet(u32 itemBallId)
{
    s32 i;
    u8 *counter = &gSaveBlock1Ptr->availableItems.other.counter;
    u32 itemId = gSaveBlock1Ptr->availableItems.other.arr[(*counter)++];

    // Mark unique item as taken
    if (IsUniqueItem(itemId)) {
        for (i = 0; i < UNIQUE_ITEMS_COUNT; i++) {
            if (gSaveBlock1Ptr->availableItems.unique.obtainedArr[i] == ITEM_NONE) {
                gSaveBlock1Ptr->availableItems.unique.obtainedArr[i] = itemId;
                break;
            }
        }
    }

    return (itemId >= ITEMS_COUNT) ? (ITEM_NONE + 1) : itemId;
}

void GetItemBallIdAndAmountFromSet(void)
{
    u32 itemBallId = (gSpecialVar_LastTalked - 1);
    gSpecialVar_Result = GetItemBallIdFromSet(itemBallId);
    gSpecialVar_0x8009 = GetItemBallAmountFromTemplate(itemBallId);
}
