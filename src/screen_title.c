/**********************************************************************************************
 *
 *   raylib - Advance Game template
 *
 *   Title Screen Functions Definitions (Init, Update, Draw, Unload)
 *
 *   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
 *
 *   This software is provided "as-is", without any express or implied warranty. In no event
 *   will the authors be held liable for any damages arising from the use of this software.
 *
 *   Permission is granted to anyone to use this software for any purpose, including commercial
 *   applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 *     1. The origin of this software must not be misrepresented; you must not claim that you
 *     wrote the original software. If you use this software in a product, an acknowledgment
 *     in the product documentation would be appreciated but is not required.
 *
 *     2. Altered source versions must be plainly marked as such, and must not be misrepresented
 *     as being the original software.
 *
 *     3. This notice may not be removed or altered from any source distribution.
 *
 **********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include "fontstyle.h"
#include "my-library.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
	// TODO: Initialize TITLE screen variables here!
	framesCounter = 0;
	finishScreen = 0;

	FontStyle *titleStyle = (FontStyle *)(MemAlloc(sizeof(FontStyle)));
	titleStyle->font = GetFontDefault();
	titleStyle->color = DARKGREEN;
	titleStyle->size = titleStyle->font.baseSize * 3;
	titleStyle->spacing = 4;

	LoadFontStyle("title", titleStyle);
	SetCurrentFontStyle("title");

	FontStyle *small = (FontStyle *)(MemAlloc(sizeof(FontStyle)));
	small->font = GetFontDefault();
	small->color = DARKGREEN;
	small->size = 20;
	small->spacing = 4;
	LoadFontStyle("titlesmall", small);

	Say("welcome to the title screen");
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
	// TODO: Update TITLE screen variables here!

	// Press enter or tap to change to GAMEPLAY screen
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		// finishScreen = 1;   // OPTIONS
		finishScreen = 2; // GAMEPLAY
		PlaySound(fxCoin);
	}
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
	// TODO: Draw TITLE screen here!
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
	SetCurrentFontStyle("title");
	DrawStyleTextCentered("Title", 10);
	SetCurrentFontStyle("titlesmall");
	DrawStyleTextAnchored("[ENTER]", (FontAnchors){-1, 10, 10, -1});
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
	// TODO: Unload TITLE screen variables here!
	UnloadFontStyle("title");
	UnloadFontStyle("titlesmall");
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
	return finishScreen;
}