#pragma once
#ifndef _UTILS_HH
#define _UTILS_HH

void ChangeMenu(int Menu);
int GET();
void resetVars();
void drawScroller();
void AddTitle(char* Text, int fontId = 1);
void AddOption(char* option, bool Normal, int color, char* Infox);
void addOption(char* option, int color, char* Infox);
void CheckBox(const char* text, bool toggle, int color, char* Infox = "");
void IntOption(char* option, int* var, int min, int max, bool fast, int color, char* Infox);
void FloatOption(char* option, float* var, float min, float max, float Default, int color, char* Infox);
void TextOption(char* option, char* Text, int* Num, int min, int max, bool SmallFont, bool withoutSPRITE, int color, char* Info);
bool check_button(int buttonID, bool checkSpeed);
bool delayed_key_press(int control);

#endif