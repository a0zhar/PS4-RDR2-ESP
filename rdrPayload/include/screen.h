#pragma once
#ifndef _SCREEN_HH
#define _SCREEN_HH

#include "types.h"
#include "sermath.h"

bool get_bone_screen_coord(Player player, const char *boneName, fSerVec2 *ScreenCoord);
bool WorldToScreenRel(Vector3 worldOrigin, float *screenX, float *screenY);

#endif