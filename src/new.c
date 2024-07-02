#include "global.h"
#include "event_data.h"
#include "palette.h"
#include "constants/rgb.h"

// New functions
void BlendTalkingObj(void)
{
    u32 spriteId = gObjectEvents[gSpecialVar_LastTalked].spriteId;
    u32 palNum = gSprites[spriteId].oam.paletteNum;
    u32 clr = gSpecialVar_0x8004;
    u32 coeff = gSpecialVar_0x8005;

    BlendPalettes(1 << (palNum + 16), coeff, clr);
}
