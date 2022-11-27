#pragma once
#include "raylib.h"

typedef struct {
	Font font;
	float size;
	float spacing;
	Color color;
} FontStyle;

typedef struct {
	int top;
	int right;
	int bottom;
	int left;
} FontAnchors;

void InitFontStyle();

void UnloadFontStyles();

void LoadFontStyle(char *name, FontStyle *style);

void UnloadFontStyle(char *name);

void SetCurrentFontStyle(char *styleName);

void DrawStyleTextCentered(char *text, float y);

void DrawStyleTextAnchored(char *text, FontAnchors anchors);