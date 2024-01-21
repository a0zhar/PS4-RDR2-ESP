#pragma once
#include "../include/types.h"
void givePedWeapon(Ped ped, Hash weapon);
void playSound(char* sound, char* sound_dict);
void print(const char* text, int nothing = NULL);
bool Match(const unsigned char* pData, const unsigned char* bMask, const char* szMask);