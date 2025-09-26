#include "global.h"
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

static u32 GetItemBallIdFromSet(u32 itemBallId)
{
    s32 i;
    u8 *counter = &gSaveBlock1Ptr->availableItems.other.counter;
    u32 itemId = gSaveBlock1Ptr->availableItems.other.arr[(*counter)++];

    // Mark unique item as taken
    for (i = 0; i < UNIQUE_ITEMS_COUNT; i++) {
        if (gSaveBlock1Ptr->availableItems.unique.obtainedArr[i] == ITEM_NONE) {
            gSaveBlock1Ptr->availableItems.unique.obtainedArr[i] = itemId;
            break;
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
