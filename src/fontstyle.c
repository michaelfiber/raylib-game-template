#include "stdlib.h"
#include "raylib.h"
#include "fontstyle.h"
#include "string.h"

typedef struct StyleNode
{
	FontStyle *style;
	char *name;
	struct StyleNode *next;
} StyleNode;

StyleNode root = {
	.name = "default",
	.next = NULL,
	.style = NULL};

FontStyle *currentStyle = NULL;

void InitFontStyle()
{
	FontStyle *defaultStyle = (FontStyle *)malloc(sizeof(FontStyle));
	defaultStyle->font = GetFontDefault();
	defaultStyle->color = WHITE;
	defaultStyle->size = defaultStyle->font.baseSize * 3;
	defaultStyle->spacing = 4;
	root.style = defaultStyle;
}

void UnloadFontStyles()
{
	StyleNode *current = &root;
	while (current != NULL)
	{
		StyleNode *next = current->next;
		free(current);
		current = next;
	}
}

void UpsertFontStyleNode(StyleNode *current, char *name, FontStyle *style)
{
	if (strcmp(current->name, name) == 0)
	{
		current->style = style;
	}
	else if (current->next != NULL)
	{
		UpsertFontStyleNode(current->next, name, style);
	}
	else
	{
		current->next = (StyleNode *)malloc(sizeof(StyleNode));
		current = current->next;
		current->name = name;
		current->style = style;
		current->next = NULL;
	}
}

void LoadFontStyle(char *name, FontStyle *style)
{
	StyleNode *current = &root;
	UpsertFontStyleNode(current, name, style);
}

void UnloadFontStyle(char *name)
{
	StyleNode *current = &root;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			StyleNode *examine = current->next;
			if (strcmp(examine->name, name) == 0)
			{
				current->next = examine->next;
				free(examine);
				break;
			}
			current = current->next;
		}
	}
}

StyleNode *FindStyleNode(char *name)
{
	StyleNode *current = &root;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			return current;
		}
		current = current->next;
	}
	TraceLog(LOG_DEBUG, TextFormat("Could not find style: %s", name));
	return NULL;
}

void SetCurrentFontStyle(char *styleName)
{
	StyleNode *node = FindStyleNode(styleName);
	if (node != NULL)
		currentStyle = node->style;
}

void DrawStyleTextCentered(char *text, float y)
{
	if (currentStyle == NULL)
		return;
	DrawTextEx(currentStyle->font,
			   text,
			   (Vector2){
				   (int)(GetScreenWidth() / 2 - MeasureTextEx(currentStyle->font, text, currentStyle->size, currentStyle->spacing).x / 2),
				   y},
			   currentStyle->size,
			   currentStyle->spacing,
			   currentStyle->color);
}

void DrawStyleTextAnchored(char *text, FontAnchors anchors)
{
	Vector2 textSize = MeasureTextEx(currentStyle->font, text, currentStyle->size, currentStyle->spacing);

	int x = GetScreenWidth() / 2 - textSize.x / 2;
	int y = GetScreenHeight() / 2 - textSize.y / 2;

	if (anchors.top > -1)
	{
		y = anchors.top;
	}

	if (anchors.bottom > -1)
	{
		y = GetScreenHeight() - anchors.bottom - textSize.y;
	}

	if (anchors.left > -1)
	{
		x = anchors.left;
	}

	if (anchors.right > -1)
	{
		x = GetScreenWidth() - anchors.right - textSize.x;
	}

	DrawTextEx(currentStyle->font, text, (Vector2){x, y}, currentStyle->size, currentStyle->spacing, currentStyle->color);
}
