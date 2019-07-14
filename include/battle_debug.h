#ifndef GUARD_BATTLE_DEBUG_H
#define GUARD_BATTLE_DEBUG_H


#if DEBUG == 1
#define USE_BATTLE_DEBUG TRUE
#else
#define USE_BATTLE_DEBUG FALSE
#endif

void CB2_BattleDebugMenu(void);

#endif // GUARD_BATTLE_DEBUG_H
