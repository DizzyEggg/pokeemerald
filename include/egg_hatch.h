#ifndef GUARD_EGG_HATCH_H
#define GUARD_EGG_HATCH_H

void ScriptHatchMon(void);
bool8 CheckDaycareMonReceivedMail(void);
void EggHatch(void);
u8 GetEggCyclesToSubtract(void);
u16 CountPartyAliveNonEggMons(void);
void EggHatchAnim(u32 species, bool8 isShiny);

#endif // GUARD_EGG_HATCH_H
