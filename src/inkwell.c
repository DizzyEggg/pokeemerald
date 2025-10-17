#include "global.h"
#include "inkwell.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "sprite.h"
#include "pokemon.h"
#include "main.h"
#include "event_data.h"
#include "egg_hatch.h"
#include "script.h"
#include "new_game.h"
#include "string_util.h"
#include "constants/event_objects.h"

/*
Functions for controlling the player's sprite.
*/

void SetPlayerMonSprite(u32 speciesId, bool32 isShiny)
{
    gSaveBlock2Ptr->playerSpriteIsShiny = (isShiny != FALSE);
    gSaveBlock2Ptr->playerSpriteMonId = speciesId;
}

// This is hacky as fuck, but whatever, it works. There is a little 'turn' the sprite does, but meh, there's no time.
void ChangePlayerMonSpriteVisuals(bool32 inOverworld)
{
    if (inOverworld) {
        gSprites[gPlayerAvatar.spriteId].oam.paletteNum = LoadDynamicFollowerPalette(gSaveBlock2Ptr->playerSpriteMonId, gSaveBlock2Ptr->playerSpriteIsShiny, FALSE);
        SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT);
    }
    else if (!gMain.inBattle) {
        u8 spriteId = CreateInvisibleSprite(SpriteCallbackDummy);

        gPlayerAvatar.spriteId = spriteId;
        gSprites[gPlayerAvatar.spriteId].oam.paletteNum = LoadDynamicFollowerPalette(gSaveBlock2Ptr->playerSpriteMonId, gSaveBlock2Ptr->playerSpriteIsShiny, FALSE);
        gObjectEvents[gPlayerAvatar.objectEventId].spriteId = spriteId;
        ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
        ObjectEventTurn(&gObjectEvents[gPlayerAvatar.objectEventId], gObjectEvents[gPlayerAvatar.objectEventId].movementDirection);
        DestroySprite(&gSprites[spriteId]);
    }
}

void TryUpdatePlayerSprite(struct Pokemon *mon)
{
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    if (GetMonData(mon, MON_DATA_HP) != 0 && gSaveBlock2Ptr->playerSpriteMonId != species) {
        SetPlayerMonSprite(species, IsMonShiny(mon));
        ChangePlayerMonSpriteVisuals(FALSE);
    }
}

// Script commands
void ScriptCmd_SetPlayerMonSprite(struct ScriptContext *ctx)
{
    u32 speciesId = VarGet(ScriptReadHalfword(ctx));
    u32 isShiny = ScriptReadByte(ctx);

    if (speciesId == SPECIES_NONE) {
        speciesId = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES);
    }

    SetPlayerMonSprite(speciesId, isShiny);
}

void ScriptCmd_ChangePlayerSprite(struct ScriptContext *ctx)
{
    u8 trick;
    ScriptCmd_SetPlayerMonSprite(ctx);

    trick = ScriptReadByte(ctx);
    ChangePlayerMonSpriteVisuals(trick);
}

void ScriptCmd_GetPlayerSpecies(struct ScriptContext *ctx)
{
    gSpecialVar_Result = gSaveBlock2Ptr->playerSpriteMonId;
}

void ScriptCmd_GetPartnerSpecies(struct ScriptContext *ctx)
{
    struct Pokemon *mon = GetSecondLiveMon();
    gSpecialVar_Result = GetMonData(mon, MON_DATA_SPECIES);
}


/*
Functions for swapping party members
*/

static struct Pokemon *SpeciesToSavedMon(s32 species)
{
    switch (species) {
        default:
        case SPECIES_PHANPY:
        case SPECIES_DONPHAN:
            return &gSaveBlock1Ptr->savedPhanpy;
        case SPECIES_SWABLU:
        case SPECIES_ALTARIA:
            return &gSaveBlock1Ptr->savedSwablu;
        case SPECIES_TINKATINK:
            return &gSaveBlock1Ptr->savedTink;
        case SPECIES_SQUIRTLE:
        case SPECIES_WARTORTLE:
        case SPECIES_BLASTOISE:
            return &gSaveBlock1Ptr->savedSquirtle;
        case SPECIES_VENIPEDE:
            return &gSaveBlock1Ptr->savedVenipede;
        case SPECIES_ABRA:
        case SPECIES_KADABRA:
        case SPECIES_ALAKAZAM:
            return &gSaveBlock1Ptr->savedAbra;
    }
}

// Addition in later release: 2nd mon becomes the 1st mon, and new team member becomes the 2nd mon. This is so that players don't get stuck with Fluffball as their 2nd mon
void ScriptCmd_Swap1st2ndMons(struct ScriptContext *ctx)
{
    struct Pokemon copyPlayerMon;
    SWAP(gPlayerParty[0], gPlayerParty[1], copyPlayerMon);
}

// Prerequisities: player's sprite is NOT changed, species to be changed are in gSpecialVar_0x8007
void ScriptCmd_SwapTeamMembers(struct ScriptContext *ctx)
{
    struct Pokemon copyPlayerMon = gPlayerParty[0];
    struct Pokemon *newPlayerMon = SpeciesToSavedMon(gSpecialVar_0x8007);
    struct Pokemon *newTeamMemberMon = SpeciesToSavedMon(gSaveBlock2Ptr->playerSpriteMonId);

    gPlayerParty[0] = *newPlayerMon;
    *newTeamMemberMon = copyPlayerMon;

    ScriptCmd_Swap1st2ndMons(ctx);
}

/*
Script commands for egg hatches
*/

void PlayEggHatchAnimation(struct ScriptContext *ctx)
{
    u32 speciesId = ScriptReadHalfword(ctx);
    bool8 isShiny = ScriptReadByte(ctx);
    const u8 *name = (const u8 *) ScriptReadWord(ctx);
    EggHatchAnim(speciesId, isShiny, name, FALSE);
}

void PlayFastEggHatchAnimation(struct ScriptContext *ctx)
{
    EggHatchAnim(0, 0, NULL, TRUE);
}

/*
Other script commands
*/

void ScriptCmd_BufferNPCNameFromGfx(struct ScriptContext *ctx)
{
    u8 stringVarIndex = ScriptReadByte(ctx);
    u32 objEventId = GetObjectEventIdByLocalId(gSpecialVar_LastTalked);
    struct ObjectEvent *objectEvent = &gObjectEvents[objEventId];
    u32 species = objectEvent->graphicsId & OBJ_EVENT_MON_SPECIES_MASK;
    const u8 *name = SpeciesToNickname(species);

    gSpecialVar_0x8007 = species;

    StringCopy(gScriptStringVars[stringVarIndex], name);
}

void ScriptCmd_GetFalling3rdMonSpecies(struct ScriptContext *ctx)
{
    gSpecialVar_Result = VarGet(VAR_OBJ_GFX_ID_1) - OBJ_EVENT_MON - OBJ_EVENT_MON_SHINY;
}
