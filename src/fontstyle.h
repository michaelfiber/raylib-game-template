#pragma once
#include "raylib.h"

typedef struct {
	Font font;
	float fontSize;
	float fontSpacing;
	Color fontColor;
} FontStyle;

void SetFontEx(Font *font, float fontSize, float fontSpacing);

void SetFontColor(Color color);

void DrawTextCenteredEx(char *text, float y);