#ifndef GUARD_INKWELL_H
#define GUARD_INKWELL_H

void SetPlayerMonSprite(u32 speciesId, bool32 isShiny);
void ChangePlayerMonSpriteVisuals(bool32 inOverworld);
void TryUpdatePlayerSprite(struct Pokemon *mon);

#endif // GUARD_INKWELL_H
