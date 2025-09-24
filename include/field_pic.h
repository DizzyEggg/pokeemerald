#ifndef GUARD_FIELD_PIC_H
#define GUARD_FIELD_PIC_H

#include "constants/field_pic.h"

u32 LoadFieldPicVars(u32 id, s16 x, s16 y);
void LoadFieldPic(void);
void DestroyFieldPicVars(u32 id, u32 spriteId);
void SpriteCb_DestroyOnButonPress(struct Sprite *sprite);
void FieldPicSpriteDestroy(struct Sprite *sprite);
void RemoveAllCreatedPics(void);

#endif
