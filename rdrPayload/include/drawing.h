#pragma once
#ifndef _DRAWING_HH
#define _DRAWING_HH

void SET_TEXT_JUSTIFICATON(int type);
void SET_TEXT_FONT(int fontId);
void SET_TEXT_WRAP(float start, float end);
void SET_TEXT_SCALE_s(float scale, float scale2);
void SET_TEXT_COLOR_s(int r, int g, int b, int a);
void DRAW_TEXT_OPTION(char* text, int Font, float x, float y, float scalex, float scaley, int a, bool center, bool UseEdge, int RD, int GD, int BD);
void DRAW_TEXT(const char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge, int RD, int GD, int BD);
void DRAW_TEXT2(char* text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center);
void drawFloat(float Val, bool center, float x, float y, float scalex, float scaley, int r, int b, int g, int a);
void drawNumber(int Val, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, int center);
void drawTextCounter(char* text, int Font, float x, float y, float scalex, float scaley, int r, int b, int g, int a);
void DrawSprite(const char* Streamedtexture, const char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);

#endif