#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);
static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst);

static EWRAM_DATA u8 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
static const u8 sText_PkmnGainedEXP[] = _("{B_BUFF1} riceve{B_BUFF2} \n{B_BUFF3} punti ESP.!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" la bellezza di");
static const u8 sText_PkmnGrewToLv[] = _("{B_BUFF1} sale al L. {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_PkmnLearnedMove[] = _("{B_BUFF1} impara {B_BUFF2}!{WAIT_SE}\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} sta cercando di imparare\n{B_BUFF2}!\p");
static const u8 sText_TryToLearnMove2[] = _("Ma {B_BUFF1} non può conoscere\npiù di quattro mosse.\p");
static const u8 sText_TryToLearnMove3[] = _("Vuoi cancellare una mossa per\nfar posto a {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} scorda {B_BUFF2}!\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}Bloccare l’apprendimento\ndi {B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} non ha imparato\n{B_BUFF2}!\p");
static const u8 sText_UseNextPkmn[] = _("Usare un altro POKéMON?");
static const u8 sText_AttackMissed[] = _("{B_ATK_NAME_WITH_PREFIX} fallisce!");
static const u8 sText_PkmnProtectedItself[] = _("{B_DEF_NAME_WITH_PREFIX} si protegge!");
static const u8 sText_AvoidedDamage[] = _("{B_DEF_NAME_WITH_PREFIX} evita\nil colpo con {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("{B_DEF_NAME_WITH_PREFIX} neutralizza le\nmosse di TERRA con {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} evita l’attacco!");
static const u8 sText_ItDoesntAffect[] = _("Non ha effetto su\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("{B_ATK_NAME_WITH_PREFIX} è esausto!\p");
static const u8 sText_TargetFainted[] = _("{B_DEF_NAME_WITH_PREFIX} è esausto!\p");
static const u8 sText_PlayerGotMoney[] = _("{B_PLAYER_NAME} vince\n¥{B_BUFF1}!\p");
static const u8 sText_PlayerWhiteout[] = _("{B_PLAYER_NAME} non ha più\nPOKéMON utili!\p");
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} è fuori combattimento!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PreventsEscape[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} impedisce\nla fuga con {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("Non si scappa!\p");
static const u8 sText_AttackerCantEscape[] = _("{B_ATK_NAME_WITH_PREFIX}\nnon può scappare!");
static const u8 sText_HitXTimes[] = _("Colpi subiti: {B_BUFF1}!");
static const u8 sText_PkmnFellAsleep[] = _("{B_EFF_NAME_WITH_PREFIX}\ns’è addormentato!");
static const u8 sText_PkmnMadeSleep[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\naddormenta {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _("{B_DEF_NAME_WITH_PREFIX} sta già dormendo!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("{B_ATK_NAME_WITH_PREFIX} sta già dormendo!");
static const u8 sText_PkmnWasntAffected[] = _("{B_DEF_NAME_WITH_PREFIX} è incolume!");
static const u8 sText_PkmnWasPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX} è stato \navvelenato!");
static const u8 sText_PkmnPoisonedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\navvelena {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("Il veleno ha effetto\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} è già\navvelenato.");
static const u8 sText_PkmnBadlyPoisoned[] = _("{B_EFF_NAME_WITH_PREFIX}\nè iperavvelenato!");
static const u8 sText_PkmnEnergyDrained[] = _("Viene prelevata energia\nda {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWasBurned[] = _("{B_EFF_NAME_WITH_PREFIX} è stato \nscottato!");
static const u8 sText_PkmnBurnedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nscotta {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("{B_ATK_NAME_WITH_PREFIX} soffre\nper la scottatura!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} è già scottato.");
static const u8 sText_PkmnWasFrozen[] = _("{B_EFF_NAME_WITH_PREFIX} è stato\ncongelato!");
static const u8 sText_PkmnFrozenBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncongela {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("{B_ATK_NAME_WITH_PREFIX} è congelato!");
static const u8 sText_PkmnWasDefrosted[] = _("{B_DEF_NAME_WITH_PREFIX} è stato\nscongelato!");
static const u8 sText_PkmnWasDefrosted2[] = _("{B_ATK_NAME_WITH_PREFIX} è stato\nscongelato!");
static const u8 sText_PkmnWasDefrostedBy[] = _("{B_ATK_NAME_WITH_PREFIX} è stato\nscongelato da {B_CURRENT_MOVE}!");
static const u8 sText_PkmnWasParalyzed[] = _("{B_EFF_NAME_WITH_PREFIX} è stato\nparalizzato!\lForse non riuscirà ad attaccare!");
static const u8 sText_PkmnWasParalyzedBy[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nparalizza {B_EFF_NAME_WITH_PREFIX}!\lForse non riuscirà ad attaccare!");
static const u8 sText_PkmnIsParalyzed[] = _("{B_ATK_NAME_WITH_PREFIX} è paralizzato!\nNon può attaccare!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("{B_DEF_NAME_WITH_PREFIX}\nè già paralizzato!");
static const u8 sText_PkmnHealedParalysis[] = _("{B_DEF_NAME_WITH_PREFIX}\nè guarito dalla paralisi!");
static const u8 sText_PkmnDreamEaten[] = _("Mangia il sogno di\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_StatsWontIncrease[] = _("Non aumenta\n{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}.");
static const u8 sText_StatsWontDecrease[] = _("Non diminuisce \n{B_BUFF1} di {B_DEF_NAME_WITH_PREFIX}.");
static const u8 sText_TeamStoppedWorking[] = _("{B_BUFF1} della tua squadra\nnon funziona!");
static const u8 sText_FoeStoppedWorking[] = _("{B_BUFF1} dell’avversario\nnon funziona!");
static const u8 sText_PkmnIsConfused[] = _("{B_ATK_NAME_WITH_PREFIX} è confuso!");
static const u8 sText_PkmnHealedConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} \nnon è più confuso!");
static const u8 sText_PkmnWasConfused[] = _("{B_EFF_NAME_WITH_PREFIX} è stato confuso!");
static const u8 sText_PkmnAlreadyConfused[] = _("{B_DEF_NAME_WITH_PREFIX} è già confuso!");
static const u8 sText_PkmnFellInLove[] = _("{B_DEF_NAME_WITH_PREFIX} è innamorato!");
static const u8 sText_PkmnInLove[] = _("{B_ATK_NAME_WITH_PREFIX} è innamorato\ndi {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("L’innamoramento impedisce\na {B_ATK_NAME_WITH_PREFIX} di attaccare!");
static const u8 sText_PkmnBlownAway[] = _("{B_DEF_NAME_WITH_PREFIX} è spazzato via!");
static const u8 sText_PkmnChangedType[] = _("{B_ATK_NAME_WITH_PREFIX} si trasforma\nnel tipo {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("{B_ATK_NAME_WITH_PREFIX} tentenna!");
static const u8 sText_PkmnRegainedHealth[] = _("{B_DEF_NAME_WITH_PREFIX} s’è ripreso!");
static const u8 sText_PkmnHPFull[] = _("{B_DEF_NAME_WITH_PREFIX} ha tutti i PS!");
static const u8 sText_PkmnRaisedSpDef[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta la DIF. SP.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta un po’ la DIF. SP.!");
static const u8 sText_PkmnRaisedDef[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta la DIFESA!");
static const u8 sText_PkmnRaisedDefALittle[] = _("{B_CURRENT_MOVE} del POKéMON {B_ATK_PREFIX2}\naumenta un po’ la DIFESA!");
static const u8 sText_PkmnCoveredByVeil[] = _("Un velo ricopre la squadra\ndel POKéMON {B_ATK_PREFIX2}!");
static const u8 sText_PkmnUsedSafeguard[] = _("SALVAGUARDIA protegge\nla squadra di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSafeguardExpired[] = _("Cade SALVAGUARDIA della\nsquadra del POKéMON {B_ATK_PREFIX3}!");
static const u8 sText_PkmnWentToSleep[] = _("{B_ATK_NAME_WITH_PREFIX} va a dormire!");
static const u8 sText_PkmnSleptHealthy[] = _("{B_ATK_NAME_WITH_PREFIX}\ndorme e si riprende!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("{B_ATK_NAME_WITH_PREFIX}\ngenera un turbine!");
static const u8 sText_PkmnTookSunlight[] = _("{B_ATK_NAME_WITH_PREFIX} assorbe la luce!");
static const u8 sText_PkmnLoweredHead[] = _("{B_ATK_NAME_WITH_PREFIX} \nabbassa la testa!");
static const u8 sText_PkmnIsGlowing[] = _("{B_ATK_NAME_WITH_PREFIX} sta brillando!");
static const u8 sText_PkmnFlewHigh[] = _("{B_ATK_NAME_WITH_PREFIX} vola in alto!");
static const u8 sText_PkmnDugHole[] = _("{B_ATK_NAME_WITH_PREFIX} scava una fossa!");
static const u8 sText_PkmnHidUnderwater[] = _("{B_ATK_NAME_WITH_PREFIX} \nsparisce sott’acqua!");
static const u8 sText_PkmnSprangUp[] = _("{B_ATK_NAME_WITH_PREFIX} salta fuori!");
static const u8 sText_PkmnSqueezedByBind[] = _("{B_ATK_NAME_WITH_PREFIX} stritola\n{B_DEF_NAME_WITH_PREFIX} con LEGATUTTO!");
static const u8 sText_PkmnTrappedInVortex[] = _("{B_DEF_NAME_WITH_PREFIX} è intrappolato\nnel vortice!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("{B_DEF_NAME_WITH_PREFIX} è intrappolato\nda SABBIOTOMBA!");
static const u8 sText_PkmnWrappedBy[] = _("{B_ATK_NAME_WITH_PREFIX} usa AVVOLGI-\nBOTTA su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("{B_ATK_NAME_WITH_PREFIX} usa\nTENAGLIA su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("{B_ATK_NAME_WITH_PREFIX} è ferito\nda {B_BUFF1}!");
static const u8 sText_PkmnFreedFrom[] = _("{B_ATK_NAME_WITH_PREFIX} è liberato\nda {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("{B_ATK_NAME_WITH_PREFIX}\nsi sbilancia e si schianta!");
const u8 gText_PkmnShroudedInMist[] = _("Il POKéMON {B_ATK_PREFIX2}\nè avvolto dalla NEBBIA!");
static const u8 sText_PkmnProtectedByMist[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nè protetto dalla NEBBIA!");
const u8 gText_PkmnGettingPumped[] = _("{B_ATK_NAME_WITH_PREFIX} si gonfia!");
static const u8 sText_PkmnHitWithRecoil[] = _("{B_ATK_NAME_WITH_PREFIX}\nsubisce il contraccolpo!");
static const u8 sText_PkmnProtectedItself2[] = _("{B_ATK_NAME_WITH_PREFIX} è pronto a \nproteggersi!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\nda una tempesta di sabbia!");
static const u8 sText_PkmnPeltedByHail[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\nda GRANDINE!");
static const u8 sText_PkmnsXWoreOff[] = _("Finito l’effetto di\n{B_BUFF1} del POKéMON {B_ATK_PREFIX1}!");
static const u8 sText_PkmnSeeded[] = _("{B_DEF_NAME_WITH_PREFIX} è pieno di semi!");
static const u8 sText_PkmnEvadedAttack[] = _("{B_DEF_NAME_WITH_PREFIX} schiva l’attacco!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("PARASSISEME sottrae energia\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} dorme.");
static const u8 sText_PkmnWokeUp[] = _("{B_ATK_NAME_WITH_PREFIX} si è svegliato!");
static const u8 sText_PkmnUproarKeptAwake[] = _("Ma BARAONDA di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} lo tiene sveglio!");
static const u8 sText_PkmnWokeUpInUproar[] = _("{B_ATK_NAME_WITH_PREFIX} si sveglia\na causa di BARAONDA!");
static const u8 sText_PkmnCausedUproar[] = _("{B_ATK_NAME_WITH_PREFIX} scatena\nuna BARAONDA!");
static const u8 sText_PkmnMakingUproar[] = _("{B_ATK_NAME_WITH_PREFIX} sta facendo\nuna BARAONDA!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} si calma.");
static const u8 sText_PkmnCantSleepInUproar[] = _("Ma {B_DEF_NAME_WITH_PREFIX} non riesce\na dormire con BARAONDA!");
static const u8 sText_PkmnStockpiled[] = _("{B_ATK_NAME_WITH_PREFIX} usa ACCUMULO:\n{B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("{B_ATK_NAME_WITH_PREFIX} non può più\nusare ACCUMULO!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("Ma {B_DEF_NAME_WITH_PREFIX} non riesce\na dormire con BARAONDA!");
static const u8 sText_UproarKeptPkmnAwake[] = _("Ma BARAONDA di\n{B_DEF_NAME_WITH_PREFIX} lo tiene sveglio!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("{B_DEF_NAME_WITH_PREFIX} rimane sveglio\ngrazie a {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} \naccumula energia!");
static const u8 sText_PkmnUnleashedEnergy[] = _("{B_ATK_NAME_WITH_PREFIX} libera energia!");
static const u8 sText_PkmnFatigueConfusion[] = _("{B_ATK_NAME_WITH_PREFIX} è confuso\nper la fatica!");
static const u8 sText_PlayerPickedUpMoney[] = _("{B_PLAYER_NAME} raccoglie ¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _("{B_DEF_NAME_WITH_PREFIX} è incolume!");
static const u8 sText_PkmnTransformedInto[] = _("{B_ATK_NAME_WITH_PREFIX} si trasforma\nin {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} crea \nun SOSTITUTO!");
static const u8 sText_PkmnHasSubstitute[] = _("{B_ATK_NAME_WITH_PREFIX} ha già\nun SOSTITUTO!");
static const u8 sText_SubstituteDamaged[] = _("Il SOSTITUTO è colpito\nal posto di {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("Il SOSTITUTO di\n{B_DEF_NAME_WITH_PREFIX} svanisce!\p");
static const u8 sText_PkmnMustRecharge[] = _("{B_ATK_NAME_WITH_PREFIX} deve ricaricarsi!");
static const u8 sText_PkmnRageBuilding[] = _("Cresce l’IRA di\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMoveWasDisabled[] = _("INIBITORE ha messo {B_BUFF1}\ndi {B_DEF_NAME_WITH_PREFIX} fuori uso!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("Termina l’effetto di INIBITORE\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotEncore[] = _("{B_DEF_NAME_WITH_PREFIX} è colpito\nda RIPETI!");
static const u8 sText_PkmnEncoreEnded[] = _("Termina l’effetto di RIPETI\nsu {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTookAim[] = _("{B_ATK_NAME_WITH_PREFIX} prende\nla mira su {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("{B_ATK_NAME_WITH_PREFIX} disegna\nuno SCHIZZO di {B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("{B_ATK_NAME_WITH_PREFIX} tenta di\ntrascinare con sé l’avversario!");
static const u8 sText_PkmnTookFoe[] = _("{B_DEF_NAME_WITH_PREFIX} trascina\ncon sé {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnReducedPP[] = _("{B_BUFF1} di {B_DEF_NAME_WITH_PREFIX}\ncala di {B_BUFF2}!");
static const u8 sText_PkmnStoleItem[] = _("{B_ATK_NAME_WITH_PREFIX} ruba\n{B_LAST_ITEM} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("{B_DEF_NAME_WITH_PREFIX} \nnon può scappare!");
static const u8 sText_PkmnFellIntoNightmare[] = _("{B_DEF_NAME_WITH_PREFIX} ha un INCUBO!");
static const u8 sText_PkmnLockedInNightmare[] = _("{B_ATK_NAME_WITH_PREFIX} è\nintrappolato in un INCUBO!");
static const u8 sText_PkmnLaidCurse[] = _("{B_ATK_NAME_WITH_PREFIX} riduce i suoi PS\nper lanciare una MALEDIZIONE\lsu {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("{B_ATK_NAME_WITH_PREFIX} è colpito\ndalla MALEDIZIONE!");
static const u8 sText_SpikesScattered[] = _("Ci sono PUNTE ovunque!");
static const u8 sText_PkmnHurtBySpikes[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}\nsoffre per le PUNTE!");
static const u8 sText_PkmnIdentified[] = _("{B_ATK_NAME_WITH_PREFIX} identifica\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("ULTIMOCANTO di\n{B_ATK_NAME_WITH_PREFIX}: meno {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("{B_ATK_NAME_WITH_PREFIX} si rinvigorisce!");
static const u8 sText_PkmnEnduredHit[] = _("{B_DEF_NAME_WITH_PREFIX} RESISTE!");
static const u8 sText_MagnitudeStrength[] = _("MAGNITUDO {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("{B_ATK_NAME_WITH_PREFIX} riduce i suoi PS\nper massimizzare l’ATTACCO!");
static const u8 sText_PkmnCopiedStatChanges[] = _("{B_ATK_NAME_WITH_PREFIX} copia modifiche\nstatistiche di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("{B_ATK_NAME_WITH_PREFIX} si libera da\n{B_BUFF1} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("{B_ATK_NAME_WITH_PREFIX}\nsparge PARASSISEME!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("{B_ATK_NAME_WITH_PREFIX}\nspazza via le PUNTE!");
static const u8 sText_PkmnFledFromBattle[] = _("{B_ATK_NAME_WITH_PREFIX} se la dà a\ngambe!");
static const u8 sText_PkmnForesawAttack[] = _("{B_ATK_NAME_WITH_PREFIX} \nprevede l’attacco!");
static const u8 sText_PkmnTookAttack[] = _("{B_DEF_NAME_WITH_PREFIX} subisce\n{B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("{B_ATK_NAME_WITH_PREFIX} sceglie\n{B_CURRENT_MOVE} come suo destino!");
static const u8 sText_PkmnAttack[] = _("Attacco di {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("{B_ATK_NAME_WITH_PREFIX} è al\ncentro dell’attenzione!");
static const u8 sText_PkmnChargingPower[] = _("{B_ATK_NAME_WITH_PREFIX}\ninizia a caricarsi!");
static const u8 sText_NaturePowerTurnedInto[] = _("NATURFORZA si trasforma in\n{B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("Lo stato di {B_ATK_NAME_WITH_PREFIX}\ntorna normale!");
static const u8 sText_PkmnSubjectedToTorment[] = _("{B_DEF_NAME_WITH_PREFIX} subisce\nl’ATTACCALITE!");
static const u8 sText_PkmnTighteningFocus[] = _("{B_ATK_NAME_WITH_PREFIX} \nrestringe la mira!");
static const u8 sText_PkmnFellForTaunt[] = _("{B_DEF_NAME_WITH_PREFIX}\nè in balia di PROVOCAZIONE!");
static const u8 sText_PkmnReadyToHelp[] = _("{B_ATK_NAME_WITH_PREFIX} è pronto ad\naiutare {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("{B_ATK_NAME_WITH_PREFIX} scambia\nlo strumento!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} ottiene\n{B_BUFF1}!");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} ottiene\n{B_BUFF2}!");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} ottiene\n{B_BUFF1}!\p{B_DEF_NAME_WITH_PREFIX} ottiene\n{B_BUFF2}!");
static const u8 sText_PkmnCopiedFoe[] = _("{B_ATK_NAME_WITH_PREFIX} copia\n{B_DEF_ABILITY} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("{B_ATK_NAME_WITH_PREFIX}\nesprime un DESIDERIO!");
static const u8 sText_PkmnWishCameTrue[] = _("Il DESIDERIO di {B_BUFF1}\nsi avvera!");
static const u8 sText_PkmnPlantedRoots[] = _("{B_ATK_NAME_WITH_PREFIX} pianta le radici!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("{B_ATK_NAME_WITH_PREFIX} assorbe\nsostanze nutritive con le radici!");
static const u8 sText_PkmnAnchoredItself[] = _("{B_DEF_NAME_WITH_PREFIX} è ancorato\nal suolo grazie alle radici!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("{B_ATK_NAME_WITH_PREFIX} fa\nassopire {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnKnockedOff[] = _("{B_ATK_NAME_WITH_PREFIX} blocca\n{B_LAST_ITEM} di\l{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("{B_ATK_NAME_WITH_PREFIX} scambia abilità!");
static const u8 sText_PkmnSealedOpponentMove[] = _("{B_ATK_NAME_WITH_PREFIX} blocca una\no più mosse dell’avversario!");
static const u8 sText_PkmnWantsGrudge[] = _("{B_ATK_NAME_WITH_PREFIX} serba\nRANCORE all’avversario!");
static const u8 sText_PkmnLostPPGrudge[] = _("{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}\nperde tutti i PP\la causa di RANCORE!");
static const u8 sText_PkmnShroudedItself[] = _("{B_ATK_NAME_WITH_PREFIX} si avvolge\nin {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("{B_CURRENT_MOVE} di {B_ATK_NAME_WITH_PREFIX}\nrimbalza a causa di MAGIVELO!");
static const u8 sText_PkmnWaitsForTarget[] = _("{B_ATK_NAME_WITH_PREFIX} aspetta\nla mossa dell’avversario!");
static const u8 sText_PkmnSnatchedMove[] = _("{B_DEF_NAME_WITH_PREFIX} ruba la mossa di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} con SCIPPO!");
static const u8 sText_ElectricityWeakened[] = _("La potenza dell’elettricità\nè stata indebolita!");
static const u8 sText_FireWeakened[] = _("La potenza del fuoco\nè stata indebolita!");
static const u8 sText_XFoundOneY[] = _("{B_ATK_NAME_WITH_PREFIX}\ntrova {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("La zona è pervasa da\nun piacevole profumo!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Impossibile usare strumenti qui.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("Per {B_SCR_ACTIVE_NAME_WITH_PREFIX},\nla {B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} usa\n{B_LAST_ITEM}: aumentano\li brutti colpi!");
static const u8 sText_PkmnLostFocus[] = _("{B_ATK_NAME_WITH_PREFIX} perde la mira\ne rimane immobile!");
static const u8 sText_PkmnWasDraggedOut[] = _("{B_DEF_NAME_WITH_PREFIX} è tirato dentro!\p");
static const u8 sText_TheWallShattered[] = _("La barriera si frantuma!");
static const u8 sText_ButNoEffect[] = _("Ma è inefficace!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("{B_ACTIVE_NAME_WITH_PREFIX}\nnon ha più mosse!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("A causa di INIBITORE, {B_CURRENT_MOVE}\ndi {B_ACTIVE_NAME_WITH_PREFIX} è fuori uso!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare la\nstessa mossa 2 volte per\ll’ATTACCALITE!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare\n{B_CURRENT_MOVE} dopo PROVOCAZIONE!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("{B_ACTIVE_NAME_WITH_PREFIX} non può usare\nla mossa bloccata {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnMadeItRain[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nprovoca la pioggia!");
static const u8 sText_PkmnRaisedSpeed[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\naumenta la VELOCITÀ!");
static const u8 sText_PkmnProtectedBy[] = _("{B_DEF_NAME_WITH_PREFIX} è protetto\nda {B_DEF_ABILITY}!");
static const u8 sText_PkmnPreventsUsage[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nimpedisce a {B_ATK_NAME_WITH_PREFIX}\ldi usare {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("{B_DEF_NAME_WITH_PREFIX} ricarica PS\nusando {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nneutralizza {B_CURRENT_MOVE}!");
static const u8 sText_PkmnChangedTypeWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nlo ha reso di tipo {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("{B_DEF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene la paralisi!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\npreviene l’innamoramento!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("{B_DEF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene l’avvelenamento!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\npreviene la confusione!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\naumenta la potenza del tipo FUOCO!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("{B_DEF_NAME_WITH_PREFIX} è ancorato\nal suolo grazie a {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nriduce ATT. di {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita calo delle statistiche!");
static const u8 sText_PkmnHurtsWith[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\ncolpisce {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} TRACCIA\n{B_BUFF2} di\l{B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("{B_EFF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\npreviene le scottature!");
static const u8 sText_PkmnsXBlocksY[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nblocca {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nblocca {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("{B_ATK_ABILITY} di {B_ATK_NAME_WITH_PREFIX}\nristabilisce parte dei PS!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ngenera una tempesta di sabbia!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nintensifica i raggi solari!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita calo di {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nfa infatuare {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nrende inefficace {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXCuredYProblem[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("Succhia la MELMA!");
static const u8 sText_PkmnTransformed[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} si trasforma!");
static const u8 sText_PkmnsXTookAttack[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nriceve l’attacco!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_LAST_ABILITY} di {B_BUFF1}\nevita lo scambio!\p");
static const u8 sText_PreventedFromWorking[] = _("{B_DEF_ABILITY} di {B_DEF_NAME_WITH_PREFIX}\nblocca {B_BUFF1}\ldi {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha neutralizzato!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("{B_EFF_ABILITY} di {B_EFF_NAME_WITH_PREFIX}\nevita il tentennamento!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("{B_ATK_ABILITY} di {B_ATK_NAME_WITH_PREFIX}\nblocca {B_DEF_ABILITY}\ldi {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("{B_SCR_ACTIVE_ABILITY} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nnon agisce su {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_StatSharply[] = _("sale di molto!");
const u8 gText_StatRose[] = _("sale!");
static const u8 sText_StatHarshly[] = _("cala a picco!");
static const u8 sText_StatFell[] = _("cala!");
static const u8 sText_AttackersStatRose[] = _("Ehi, {B_BUFF1} di \n{B_ATK_NAME_WITH_PREFIX} {B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("Ehi, {B_BUFF1} di\n{B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Con {B_LAST_ITEM}, {B_BUFF1} di\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_BUFF1} di {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("Ehi, {B_BUFF1} di\n{B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("Statistiche di {B_ATK_NAME_WITH_PREFIX}\nnon aumenteranno!");
static const u8 sText_StatsWontDecrease2[] = _("Statistiche di {B_DEF_NAME_WITH_PREFIX}\nnon caleranno!");
static const u8 sText_CriticalHit[] = _("Brutto colpo!");
static const u8 sText_OneHitKO[] = _("KO in un attacco!");
static const u8 sText_123Poof[] = _("{PAUSE 32}1, {PAUSE 15}2 e{PAUSE 15}… {PAUSE 15}… {PAUSE 15}…{PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1} puf!\p");
static const u8 sText_AndEllipsis[] = _("Al suo posto…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Ora è impossibile\nscordare mosse MN.\p");
static const u8 sText_NotVeryEffective[] = _("Non è molto efficace…");
static const u8 sText_SuperEffective[] = _("È superefficace!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Scampato pericolo!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugge\nusando {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} fugge\nusando {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}{B_BUFF1} selvatico fugge!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("Hai avuto la meglio su\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{B_LINK_OPPONENT2_NAME} e {B_LINK_OPPONENT1_NAME} hanno\nperso la sfida!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{B_LINK_OPPONENT1_NAME}\nha vinto la sfida!");
static const u8 sText_PlayerLostToTwo[] = _("{B_LINK_OPPONENT2_NAME} e {B_LINK_OPPONENT1_NAME}\nhanno vinto la sfida!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("La sfida contro {B_LINK_OPPONENT1_NAME}\nsi è conclusa in parità!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("La sfida contro {B_LINK_OPPONENT2_NAME} e\n{B_LINK_OPPONENT1_NAME} si è conclusa in\lparità!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} se l’è data a gambe!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} e\n{B_LINK_OPPONENT2_NAME} se la sono data a gambe!");
static const u8 sText_NoRunningFromTrainers[] = _("Non puoi sottrarti alla\nlotta con un ALLENATORE!\p");
static const u8 sText_CantEscape[] = _("Non si scappa!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. BIRCH: Non lasciarmi qui così!\p");
static const u8 sText_ButNothingHappened[] = _("Ma non succede nulla!");
static const u8 sText_ButItFailed[] = _("Ma fallisce!");
static const u8 sText_ItHurtConfusion[] = _("È così confuso da\ncolpirsi da solo!");
static const u8 sText_MirrorMoveFailed[] = _("La SPECULMOSSA ha fallito!");
static const u8 sText_StartedToRain[] = _("Inizia a piovere!");
static const u8 sText_DownpourStarted[] = _("Inizia un acquazzone!");
static const u8 sText_RainContinues[] = _("Continua a piovere.");
static const u8 sText_DownpourContinues[] = _("L’acquazzone continua.");
static const u8 sText_RainStopped[] = _("Ha smesso di piovere.");
static const u8 sText_SandstormBrewed[] = _("Sta arrivando una tempesta di sabbia!");
static const u8 sText_SandstormRages[] = _("La tempesta di sabbia imperversa!");
static const u8 sText_SandstormSubsided[] = _("La tempesta di sabbia cessa.");
static const u8 sText_SunlightGotBright[] = _("La luce solare diventa intensa!");
static const u8 sText_SunlightStrong[] = _("La luce solare è fortissima!");
static const u8 sText_SunlightFaded[] = _("La luce solare torna normale!");
static const u8 sText_StartedHail[] = _("Inizia a grandinare!");
static const u8 sText_HailContinues[] = _("Continua a grandinare.");
static const u8 sText_HailStopped[] = _("Ha smesso di grandinare.");
static const u8 sText_FailedToSpitUp[] = _("Ma SFOGHENERGIA\nfallisce!");
static const u8 sText_FailedToSwallow[] = _("Ma INTROENERGIA\nfallisce!");
static const u8 sText_WindBecameHeatWave[] = _("Il vento si è trasformato in\nONDACALDA!");
static const u8 sText_StatChangesGone[] = _("Eliminate tutte le modifiche\ndelle statistiche!");
static const u8 sText_CoinsScattered[] = _("Ci sono monete sparse ovunque!");
static const u8 sText_TooWeakForSubstitute[] = _("Troppo debole! Non può creare\nun SOSTITUTO!");
static const u8 sText_SharedPain[] = _("I POKéMON condividono\ni PS!");
static const u8 sText_BellChimed[] = _("Suona la campana!");
static const u8 sText_FaintInThree[] = _("Tutti i POKéMON che la ascoltano\nsaranno esausti in tre turni!");
static const u8 sText_NoPPLeft[] = _("Non ha più PP per\nquesta mossa!\p");
static const u8 sText_ButNoPPLeft[] = _("Ma non ha più PP per\nquesta mossa!");
static const u8 sText_PkmnIgnoresAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} ignora gli\nordini, sta dormendo!");
static const u8 sText_PkmnIgnoredOrders[] = _("{B_ATK_NAME_WITH_PREFIX} ignora gli\nordini!");
static const u8 sText_PkmnBeganToNap[] = _("{B_ATK_NAME_WITH_PREFIX} fa un riposino!");
static const u8 sText_PkmnLoafing[] = _("{B_ATK_NAME_WITH_PREFIX} sta ciondolando!");
static const u8 sText_PkmnWontObey[] = _("{B_ATK_NAME_WITH_PREFIX} non obbedisce!");
static const u8 sText_PkmnTurnedAway[] = _("{B_ATK_NAME_WITH_PREFIX} disobbedisce!");
static const u8 sText_PkmnPretendNotNotice[] = _("{B_ATK_NAME_WITH_PREFIX} fa finta \ndi niente!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("La prossima scelta di {B_TRAINER1_NAME},\n{B_TRAINER1_CLASS}, sarà {B_BUFF2}.\p{B_PLAYER_NAME}, vuoi cambiare\nPOKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("{B_ATK_NAME_WITH_PREFIX} impara {B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Hai avuto la meglio su\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\p");
static const u8 sText_CreptCloser[] = _("{B_PLAYER_NAME} si avvicina a\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("{B_PLAYER_NAME} non può avvicinarsi ancora!");
static const u8 sText_PkmnWatchingCarefully[] = _("{B_OPPONENT_MON1_NAME} guarda\nattentamente!");
static const u8 sText_PkmnCuriousAboutX[] = _("{B_OPPONENT_MON1_NAME} guarda con\ncuriosità la {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("{B_OPPONENT_MON1_NAME} è ammaliato\ndalla {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("{B_OPPONENT_MON1_NAME} ignora completamente\nla {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("{B_PLAYER_NAME} lancia una {POKEMELLA}\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}ANNUNCIO: Hai finito tutte le\nSAFARI BALL! Fine del gioco!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} appeared!\p");
static const u8 sText_WildPkmnAppeared[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Appare {B_OPPONENT_MON1_NAME} selvatico!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Appaiono {B_OPPONENT_MON2_NAME} e\n{B_OPPONENT_MON1_NAME} selvatici!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("Parte la sfida di\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_Trainer1SentOutPkmn[] = _("È il turno di {B_OPPONENT_MON1_NAME}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("Ecco {B_OPPONENT_MON1_NAME} e {B_OPPONENT_MON2_NAME},\nmandati in campo da\l{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_Trainer1SentOutPkmn2[] = _("È il turno di {B_BUFF1}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda\nin campo {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda in campo\n{B_OPPONENT_MON1_NAME} e {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} manda in campo\n{B_LINK_OPPONENT_MON1_NAME}!\p{B_LINK_OPPONENT2_NAME} manda in campo\n{B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} manda\nin campo {B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} manda\nin campo {B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("Vai, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Avanti, {B_PLAYER_MON1_NAME} e\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Vai, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Dai, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Coraggio, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Nemico debole!\nForza, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} manda in campo\n{B_LINK_PLAYER_MON2_NAME}!\pVai, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, basta così!\nRientra!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, rientra!");
static const u8 sText_PkmnOkComeBack[] = _("{B_BUFF1}, OK!\nRientra!");
static const u8 sText_PkmnGoodComeBack[] = _("{B_BUFF1}, bene!\nRientra!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_BUFF1} è ritirato dalla lotta\nda {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} ritira\n{B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} ritira\n{B_BUFF1}!");
static const u8 sText_WildPkmnPrefix[] = _(" selvatico");
static const u8 sText_FoePkmnPrefix[] = _(" nemico");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("nemico");
static const u8 sText_AllyPkmnPrefix[] = _("amico");
static const u8 sText_FoePkmnPrefix3[] = _("nemico");
static const u8 sText_AllyPkmnPrefix2[] = _("amico");
static const u8 sText_FoePkmnPrefix4[] = _("nemico");
static const u8 sText_AllyPkmnPrefix3[] = _("amico");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} usa\n{B_BUFF2}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP2[] = _("PS");
static const u8 sText_Attack2[] = _("ATTACCO");
static const u8 sText_Defense2[] = _("DIFESA");
static const u8 sText_Speed[] = _("VELOC.");
static const u8 sText_SpAtk2[] = _("ATT. SP.");
static const u8 sText_SpDef2[] = _("DIF. SP.");
static const u8 sText_Accuracy[] = _("precisione");
static const u8 sText_Evasiveness[] = _("elusione");

const u8 * const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP2,
    [STAT_ATK]     = sText_Attack2,
    [STAT_DEF]     = sText_Defense2,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAtk2,
    [STAT_SPDEF]   = sText_SpDef2,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};

static const u8 sText_PokeblockWasTooSpicy[] = _("è troppo pepata!");
static const u8 sText_PokeblockWasTooDry[] = _("è troppo secca!");
static const u8 sText_PokeblockWasTooSweet[] = _("è troppo dolce!");
static const u8 sText_PokeblockWasTooBitter[] = _("è troppo amara!");
static const u8 sText_PokeblockWasTooSour[] = _("è troppo aspra!");

const u8 * const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("{B_PLAYER_NAME} usa {B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("LINO usa {B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("{B_LAST_ITEM} è lo strumento usato\nda {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_TrainerBlockedBall[] = _("La BALL è stata bloccata!");
static const u8 sText_DontBeAThief[] = _("Non si ruba!");
static const u8 sText_ItDodgedBall[] = _("Ha schivato la BALL! Questo\nPOKéMON non può essere catturato!");
static const u8 sText_YouMissedPkmn[] = _("Ti è sfuggito il POKéMON!");
static const u8 sText_PkmnBrokeFree[] = _("Oh, no!\nIl POKéMON si è liberato!");
static const u8 sText_ItAppearedCaught[] = _("Ah! Sembrava preso,\neh? E invece no!");
static const u8 sText_AarghAlmostHadIt[] = _("Grrr!\nPer un pelo!");
static const u8 sText_ShootSoClose[] = _("Nooo!\nEra così vicino!");
static const u8 sText_GotchaPkmnCaught[] = _("Preso!\n{B_OPPONENT_MON1_NAME} è catturato!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaught2[] = _("Preso!\n{B_OPPONENT_MON1_NAME} è catturato!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("Vuoi dare un soprannome\na {B_OPPONENT_MON1_NAME}?");
static const u8 sText_PkmnSentToPC[] = _("{B_OPPONENT_MON1_NAME} è stato inviato\nal PC di {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("???");
static const u8 sText_Lanettes[] = _("LANETTE");
static const u8 sText_PkmnDataAddedToDex[] = _("I dati di {B_OPPONENT_MON1_NAME} sono stati\ninseriti nel POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("Piove.");
static const u8 sText_SandstormIsRaging[] = _("Imperversa una tempesta di sabbia.");
static const u8 sText_BoxIsFull[] = _("I BOX sono pieni!\nNon ne puoi catturare altri!\p");
static const u8 sText_EnigmaBerry[] = _("BACCAENIGMA");
static const u8 sText_BerrySuffix[] = _("BACCA{B_COPY_VAR_3}");
static const u8 sText_PkmnsItemCuredParalysis[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce la paralisi!");
static const u8 sText_PkmnsItemCuredPoison[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce l’avvelenamento!");
static const u8 sText_PkmnsItemHealedBurn[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nguarisce la scottatura!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha scongelato!");
static const u8 sText_PkmnsItemWokeIt[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nl’ha svegliato!");
static const u8 sText_PkmnsItemSnappedOut[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nelimina la sua confusione!");
static const u8 sText_PkmnsItemCuredProblem[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura il problema di {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nnormalizza il suo stato!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce la salute!");
static const u8 sText_PkmnsItemRestoredPP[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce i PP di {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce le sue statistiche!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("{B_LAST_ITEM} di {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nristabilisce parte dei PS!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("{B_LAST_ITEM} consente di usare\nsoltanto {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} resiste\nusando {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Ora si lancia una BALL, vero?\nCercherò di fare del mio meglio!");

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

const u8 * const gBattleStringsTable[BATTLESTRINGS_COUNT - BATTLESTRINGS_TABLE_START] =
{
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = sText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHT - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaught,
    [STRINGID_GOTCHAPKMNCAUGHT2 - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaught2,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND] = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM] = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH] = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK] = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]        = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]        = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]       = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]     = STRINGID_PKMNSPRANGUP,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB // MOVE_SAND_TOMB
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_ITISRAINING,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gTrappingMoves[NUM_TRAPPING_MOVES + 1] =
{
    MOVE_BIND,
    MOVE_WRAP,
    MOVE_FIRE_SPIN,
    MOVE_CLAMP,
    MOVE_WHIRLPOOL,
    MOVE_SAND_TOMB,
    0xFFFF // Never read
};

const u8 gText_PkmnIsEvolving[] = _("Cosa?\n{B_COPY_VAR_1} si sta evolvendo!");
const u8 gText_CongratsPkmnEvolved[] = _("Complimenti! Il tuo {B_COPY_VAR_1}\nsi è evoluto in {B_COPY_VAR_2}!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Bloccata evoluzione\ndi {B_COPY_VAR_1}!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("Cosa deve fare\n{B_ACTIVE_NAME_WITH_PREFIX}?");
const u8 gText_WhatWillPkmnDo2[] = _("Cosa deve fare\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("Cosa deve fare\nLINO?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Un momento…");
const u8 gText_BattleMenu[] = _("LOTTA{CLEAR_TO 56}ZAINO\nPOKéMON{CLEAR_TO 56}FUGA");
const u8 gText_SafariZoneMenu[] = _("BALL{CLEAR_TO 56}{POKEMELLE}\nVICINO{CLEAR_TO 56}FUGA");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TIPO/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTYPE/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Which move should\nbe forgotten?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}SÌ\nNO");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Sposta\nquale?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

static const u8 sText_HP[] = _("PS");
static const u8 sText_Attack[] = _("ATTACCO");
static const u8 sText_Defense[] = _("DIFESA");
static const u8 sText_SpAtk[] = _("ATT. SP.");
static const u8 sText_SpDef[] = _("DIF. SP.");

// Unused
static const u8 * const sStatNamesTable2[] =
{
    sText_HP, sText_SpAtk, sText_Attack,
    sText_SpDef, sText_Defense, sText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}SAFARI BALL");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Ancora $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("sonno");
const u8 gText_Poison[] = _("avvelenamento");
const u8 gText_Burn[] = _("scottatura");
const u8 gText_Paralysis[] = _("paralisi");
const u8 gText_Ice[] = _("congelamento");
const u8 gText_Confusion[] = _("confusione");
const u8 gText_Love[] = _("amore");
const u8 gText_SpaceAndSpace[] = _(" e ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("sono");
const u8 gText_Are2[] = _("sono");
const u8 gText_BadEgg[] = _("UOVO peste");
const u8 gText_BattleWallyName[] = _("LINO");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Vinto");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Perso");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Pari");
static const u8 sText_SpaceIs[] = _(" è");
static const u8 sText_ApostropheS[] = _("di ");

// For displaying names of invalid moves
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][22] =
{
    [TYPE_NORMAL]   = _("una mossa NORMALE"),
    [TYPE_FIGHTING] = _("una mossa LOTTA"),
    [TYPE_FLYING]   = _("una mossa VOLANTE"),
    [TYPE_POISON]   = _("una mossa VELENO"),
    [TYPE_GROUND]   = _("una mossa TERRA"),
    [TYPE_ROCK]     = _("una mossa ROCCIA"),
    [TYPE_BUG]      = _("una mossa COLEOTTERO"),
    [TYPE_GHOST]    = _("una mossa SPETTRO"),
    [TYPE_STEEL]    = _("una mossa ACCIAIO"),
    [TYPE_MYSTERY]  = _("una mossa ???"),
    [TYPE_FIRE]     = _("una mossa FUOCO"),
    [TYPE_WATER]    = _("una mossa ACQUA"),
    [TYPE_GRASS]    = _("una mossa ERBA"),
    [TYPE_ELECTRIC] = _("una mossa ELETTRO"),
    [TYPE_PSYCHIC]  = _("una mossa PSICO"),
    [TYPE_ICE]      = _("una mossa GHIACCIO"),
    [TYPE_DRAGON]   = _("una mossa DRAGO"),
    [TYPE_DARK]     = _("una mossa BUIO")
};

const u8 gText_BattleTourney[] = _("TORNEO LOTTA");
static const u8 sText_Round1[] = _("1º round");
static const u8 sText_Round2[] = _("2º round");
static const u8 sText_Semifinal[] = _("Semifinale");
static const u8 sText_Final[] = _("Finale");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("The great new hope!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("Will the championship dream come true?!\p");
const u8 gText_AFormerChampion[] = _("A former CHAMPION!\p");
const u8 gText_ThePreviousChampion[] = _("The previous CHAMPION!\p");
const u8 gText_TheUnbeatenChampion[] = _("The unbeaten CHAMPION!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mente");
const u8 gText_Skill[] = _("Abilità");
const u8 gText_Body[] = _("Corpo");
const u8 gText_Judgement[] = _("{B_BUFF1}{CLEAR 13}Voto{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("È il turno di {B_OPPONENT_MON1_NAME}, mandato in\ncampo da {B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!\pÈ il turno di {B_OPPONENT_MON2_NAME}, mandato in\ncampo da {B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("È il turno di {B_BUFF1}, mandato in\ncampo da {B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("Parte la sfida di \n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}, e\l{B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("È il turno di {B_PLAYER_MON2_NAME}, mandato in\ncampo da {B_PARTNER_NAME}, {B_PARTNER_CLASS}!\pVai, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("Hai avuto la meglio su\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}, e\l{B_TRAINER2_NAME}, {B_TRAINER2_CLASS}!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("{B_ATK_NAME_WITH_PREFIX} non è al massimo\ndella potenza!");
static const u8 sText_GlintAppearsInEye[] = _("Negli occhi di {B_SCR_ACTIVE_NAME_WITH_PREFIX} è\napparsa una scintilla!");
static const u8 sText_PkmnGettingIntoPosition[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} si sta mettendo\nin posizione!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha iniziato a\nruggire profondamente!");
static const u8 sText_PkmnEagerForMore[] = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX} è impaziente!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("ARBITRO: Se dopo 3 turni non c’è\nnulla di fatto, si passa ai punti!");
static const u8 sText_RefThatsIt[] = _("ARBITRO: Passeremo ai punti per\ndecretare il vincitore!");
static const u8 sText_RefJudgeMind[] = _("ARBITRO: Criterio di giudizio 1: Mente!\nIl POKéMON più valoroso!\p");
static const u8 sText_RefJudgeSkill[] = _("ARBITRO: Criterio di giudizio 2: Abilità!\nIl POKéMON che usa meglio le mosse!\p");
static const u8 sText_RefJudgeBody[] = _("ARBITRO: Criterio di giudizio 3: Corpo!\nIl POKéMON più vitale!\p");
static const u8 sText_RefPlayerWon[] = _("ARBITRO: {B_BUFF1} a {B_BUFF2}!\nVince {B_PLAYER_MON1_NAME} di {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("ARBITRO: {B_BUFF1} a {B_BUFF2}!\nVince {B_OPPONENT_MON1_NAME} di {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("ARBITRO: 3 a 3!\nAbbiamo un pareggio!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("L’ARBITRO ha decretato la vittoria\ndi {B_PLAYER_MON1_NAME} contro {B_OPPONENT_MON1_NAME}!");
static const u8 sText_LostToOpponentByReferee[] = _("L’ARBITRO ha decretato la vittoria\ndi {B_OPPONENT_MON1_NAME} contro {B_PLAYER_MON1_NAME}!");
static const u8 sText_TiedOpponentByReferee[] = _("L’ARBITRO ha decretato il pareggio\ntra {B_PLAYER_MON1_NAME} e {B_OPPONENT_MON1_NAME}!");
static const u8 sText_RefCommenceBattle[] = _("ARBITRO: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\nChe la lotta abbia inizio!");

const u8 * const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _("Vuoi rinunciare all’incontro e\nuscire ora?");
static const u8 sText_ForfeitedMatch[] = _("{B_PLAYER_NAME} lascia l’incontro!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _("{PLAY_SE SE_FLEE}{B_TRAINER1_CLASS} {B_TRAINER1_NAME} fled!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("La sfida è vinta da\n{B_TRAINER1_NAME}, {B_TRAINER1_CLASS}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("La sfida contro {B_TRAINER1_NAME},\n{B_TRAINER1_CLASS}, si è conclusa\lin parità!");
const u8 gText_RecordBattleToPass[] = _("Vuoi che il filmato della tua lotta \nvenga registrato nel PASS PARCO?");
const u8 gText_BattleRecordedOnPass[] = _("Il filmato della lotta di {B_PLAYER_NAME} è\nstato registrato nel PASS PARCO.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME}!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("Parte la sfida di\n{B_LINK_OPPONENT1_NAME} e {B_LINK_OPPONENT2_NAME}!{PAUSE 49}");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VICE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sDummyWeirdStatusString[] = {EOS, EOS, EOS, EOS, EOS, EOS, EOS, EOS};

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_DARK_GRAY,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_GREEN,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_6,
        .shadowColor = TEXT_COLOR_GREEN,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_3,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_2,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_COLOR_TRANSPARENT,
        .shadowColor = TEXT_COLOR_DARK_GRAY,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_COLOR_WHITE,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_JUDGEMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
    [ARENA_WIN_JUDGEMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 1,
        .fgColor = TEXT_COLOR_DARK_GRAY,
        .bgColor = TEXT_COLOR_WHITE,
        .shadowColor = TEXT_COLOR_LIGHT_GRAY,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

// difference FR
void BufferStringBattle(u16 stringID)
{
    s32 i;
    const u8 *stringPtr = NULL;
    u32 size;
    u8 *txtBuff;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleBufferA[gActiveBattler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    *(&gBattleStruct->field_52) = gBattleMsgDataPtr->unk1605E;
    *(&gBattleStruct->hpScale) = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    *(&gBattleStruct->stringMoveType) = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) // interesting, looks like they had something planned for wild double battles
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        ChooseMoveUsedParticle(gBattleTextBuff1); // buff1 doesn't appear in the string, leftover from japanese move names

        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff2, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff2, gMoveNames[gBattleMsgDataPtr->currentMove]);

        ChooseTypeOfMoveUsedString(gBattleTextBuff2);
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    size = StringLength(stringPtr) + 1;
    txtBuff = Alloc(size);
    memcpy(txtBuff, stringPtr, size);
    BattleStringExpandPlaceholdersToDisplayedString(txtBuff);
    Free(txtBuff);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    BattleStringExpandPlaceholders(src, gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sDummyWeirdStatusString, 8);

    statusPtr = status;
    for (i = 0; i < 8; i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

// difference fr ; wild Pokemon -> Pokemon wild
#define HANDLE_NICKNAME_STRING_CASE(battlerId, monIndex)                \
    if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
                                                                        \
        GetMonData(&gEnemyParty[monIndex], MON_DATA_NICKNAME, text);    \
        StringGet_Nickname(text);                                       \
        StringAppend(text, toCpy);                                      \
    }                                                                   \
    else                                                                \
    {                                                                   \
        GetMonData(&gPlayerParty[monIndex], MON_DATA_NICKNAME, text);   \
        StringGet_Nickname(text);                                       \
    }                                                                   \
                                           \
    toCpy = text;


u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[30];
    u8 multiplayerId;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 1]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetMonData(&gPlayerParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 2]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetMonData(&gEnemyParty[gBattlerPartyIndexes[gLinkPlayers[multiplayerId].id ^ 3]],
                           MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // attacker name with prefix, only battlerId 0/1
                if (GetBattlerSide(gBattlerAttacker) != B_SIDE_PLAYER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;

                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker))]], MON_DATA_NICKNAME, text);
                    StringGet_Nickname(text);
                    StringAppend(text, toCpy);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker))]], MON_DATA_NICKNAME, text);
                    StringGet_Nickname(text);
                }
                toCpy = text;
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);
                else
                    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(GET_BATTLER_SIDE(gBattlerAttacker)) + 2]], MON_DATA_NICKNAME, text);

                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget, gBattlerPartyIndexes[gBattlerTarget])
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler, gBattlerPartyIndexes[gEffectBattler])
                break;
            case B_TXT_ACTIVE_NAME_WITH_PREFIX: // active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battlerId name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, gBattlerPartyIndexes[gBattleScripting.battler])
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // difference fr less enigma berry checks
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battlerId ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
            {
                s32 gender = -1, trClass;
                const u8 *trName = NULL;
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                    trClass = GetSecretBaseTrainerClass();
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    trClass = GetUnionRoomTrainerClass();
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                    trClass = GetFrontierBrainTrainerClass();
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    trClass = GetFrontierOpponentClass(gTrainerBattleOpponent_A), gender = IsFrontierTrainerFemale(gTrainerBattleOpponent_A);
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    trClass = GetTrainerHillOpponentClass(gTrainerBattleOpponent_A);
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                    trClass = GetEreaderTrainerClassId();
                else
                {
                    trClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;
                    gender = gTrainers[gTrainerBattleOpponent_A].encounterMusic_gender & 0x7F;
                    trName = gTrainers[gTrainerBattleOpponent_A].trainerName;
                }
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, trName);
                break;
            }
            case B_TXT_TRAINER1_NAME: // trainer1 name
                if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
                {
                    for (i = 0; i < (s32) ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
                        text[i] = gBattleResources->secretBase->trainerName[i];
                    text[i] = EOS;
                    ConvertInternationalString(text, gBattleResources->secretBase->language);
                    toCpy = text;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                {
                    toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
                }
                else if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
                {
                    CopyFrontierBrainTrainerName(text);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_A);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
                {
                    GetEreaderTrainerName(text);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_A].trainerName;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    toCpy = gLinkPlayers[0].name;
                else
                    toCpy = gSaveBlock2Ptr->playerName;
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler, *(&gBattleStruct->field_52))
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
            {
                s32 gender = -1, trClass;
                const u8 *trName = NULL;
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                    trClass = GetFrontierOpponentClass(gTrainerBattleOpponent_B), gender = IsFrontierTrainerFemale(gTrainerBattleOpponent_B);
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                    trClass = GetTrainerHillOpponentClass(gTrainerBattleOpponent_B);
                else
                {
                    trClass = gTrainers[gTrainerBattleOpponent_B].trainerClass;
                    gender = gTrainers[gTrainerBattleOpponent_B].encounterMusic_gender & 0x7F;
                    trName = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, trName);
                break;
            }
            case B_TXT_TRAINER2_NAME:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    GetFrontierTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    GetTrainerHillTrainerName(text, gTrainerBattleOpponent_B);
                    toCpy = text;
                }
                else
                {
                    toCpy = gTrainers[gTrainerBattleOpponent_B].trainerName;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
            {
                s32 trClass = GetFrontierOpponentClass(gPartnerTrainerId);
                s32 gender = IsFrontierTrainerFemale(gPartnerTrainerId);
                toCpy = GetTrainerClassNameGenderSpecific(trClass, gender, NULL);
                break;
            }
            case B_TXT_PARTNER_NAME:
                GetFrontierTrainerName(text, gPartnerTrainerId);
                toCpy = text;
                break;
            }

            // missing if (toCpy != NULL) check
            while (*toCpy != EOS)
            {
                dst[dstID] = *toCpy;
                dstID++;
                toCpy++;
            }
            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst) // difference FR
{
    u32 srcID = 1;
    u32 value = 0;
    u8 text[12];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            if (hword == STRINGID_STATSHARPLY || hword == STRINGID_STATHARSHLY)
                srcID += 3;
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                StringAppend(dst, text);
            }
            else
            {
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);
            }
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            GetSpeciesName(dst, T1_READ_16(&src[srcID + 1]));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            else
                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
            StringGet_Nickname(dst);
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY)
                {
                    CopyItemName(hword, dst);
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "は" or "の") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "を つかった！". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "した！". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "を した！" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " こうげき！" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGEMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGEMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(void)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleBufferA[gActiveBattler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[gActiveBattler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[gActiveBattler]]);

    gPlttBufferUnfaded[92] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[91] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[92], &gPlttBufferFaded[92], sizeof(u16));
    CpuCopy16(&gPlttBufferUnfaded[91], &gPlttBufferFaded[91], sizeof(u16));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
