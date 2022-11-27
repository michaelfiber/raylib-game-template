#include "stdlib.h"
#include "raylib.h"
#include "fontstyle.h"
#include "string.h"

typedef struct {
	FontStyle* style;
	char* name;
	StyleNode* next;
} StyleNode;

StyleNode root = {
	.name = "default",
	.next = NULL,
	.style = NULL 
};

void LoadFontStyle() {
	FontStyle* defaultStyle = (FontStyle *)malloc(sizeof(FontStyle));
	defaultStyle->font = GetFontDefault();
	defaultStyle->fontColor = WHITE;
	defaultStyle->fontSize = defaultStyle->font.baseSize * 3;
	defaultStyle->fontSpacing = 4;
	root.style = defaultStyle;
}

void UnloadFontStyle() {
	StyleNode *current = &root;
	while (current != NULL) {
		StyleNode *next = current->next;
		free(current);
		current = next;
	}
}

void UpsertFontStyleNode(StyleNode *current, char *name, FontStyle *style) {
	if (strcmp(current->name, name) == 0) {
		current->style = style;
	} else if (current->next != NULL) {
		UpsertFontStyleNode(current->next, name, style);
	} else {
		current->next = (StyleNode *)malloc(sizeof(StyleNode));
		current = current->next;
		current->name = name;
		current->style = style;
		current->next = NULL;
	}
}

void SetFontStyle(char *name, FontStyle *style) {
	StyleNode *current = &root;
	UpsertFontStyleNode(current, name, style);
}

void RemoveFontStyle(char *name) {
	StyleNode *current = &root;
	while (current != NULL) {
		if (current->next != NULL) {
			StyleNode *examine = current->next;
			if(strcmp(examine->name, name)==0) {
				current->next = examine->next;
				free(examine);
				break;
			}
			current = current->next;
		} 
	}
}

void SetFontEx(Font *font, float fontSize, float fontSpacing) {
	fontState.font = font;
	fontState.fontSize = fontSize;
	fontState.fontSpacing = fontSpacing;
}

void SetFontColor(Color color) {
	fontState.fontColor = color;
}

void DrawTextCenteredEx(char *text, float y) {
	if (fontState.font == NULL) {
		TraceLog(LOG_DEBUG, "DrawTextCeneteredEx called without calling SetFontEx first.");
		return;
	}

	DrawTextEx(*fontState.font, text, (Vector2){ (int)(GetScreenWidth() / 2 - MeasureTextEx(*fontState.font, text,fontState.fontSize, fontState.fontSpacing).x / 2), y }, fontState.fontSize, fontState.fontSpacing, fontState.fontColor);
}