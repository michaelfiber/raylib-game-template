/**********************************************************************************************
 *
 *   raylib - Advance Game template
 *
 *   Ending Screen Functions Definitions (Init, Update, Draw, Unload)
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

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(void)
{
	// TODO: Initialize ENDING screen variables here!
	framesCounter = 0;
	finishScreen = 0;

	FontStyle *endingStyle = (FontStyle *)(MemAlloc(sizeof(FontStyle)));
	endingStyle->font = GetFontDefault();
	endingStyle->color = DARKBLUE;
	endingStyle->size = endingStyle->font.baseSize * 3;
	endingStyle->spacing = 4;
	LoadFontStyle("ending", endingStyle);

	FontStyle *small = (FontStyle *)(MemAlloc(sizeof(FontStyle)));
	small->font = GetFontDefault();
	small->color = DARKBLUE;
	small->size = small->font.baseSize * 2;
	small->spacing = 4;
	LoadFontStyle("endingsmall", small);
}

// Ending Screen Update logic
void UpdateEndingScreen(void)
{
	// TODO: Update ENDING screen variables here!

	// Press enter or tap to return to TITLE screen
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 1;
		PlaySound(fxCoin);
	}
}

// Ending Screen Draw logic
void DrawEndingScreen(void)
{
	// TODO: Draw ENDING screen here!
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);
	
	SetCurrentFontStyle("ending");
	DrawStyleTextCentered("Ending", 10);
	
	SetCurrentFontStyle("endingsmall");
	DrawStyleTextAnchored("[ENTER]", (FontAnchors){-1, 10, 10, -1});
}

// Ending Screen Unload logic
void UnloadEndingScreen(void)
{
	// TODO: Unload ENDING screen variables here!
	UnloadFontStyle("ending");
	UnloadFontStyle("endingsmall");
}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
	return finishScreen;
}