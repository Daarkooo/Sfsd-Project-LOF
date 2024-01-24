/*******************************************************************************************
*
*   SearchWindow v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void SearchWindowButton();                // Button: SearchWindowButton logic

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "search_window");

    // search_window: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *SearchWindowBoxText = "SEARCH WINDOW";    // WINDOWBOX: SearchWindowBox
    const char *SearchWindowButtonText = "SEARCH";    // BUTTON: SearchWindowButton
    const char *SearchWindowLabelText = "KEY TO SEARCH";    // LABELBUTTON: SearchWindowLabel
    
    // Define controls variables
    bool SearchWindowBoxActive = true;            // WindowBox: SearchWindowBox
    bool SearchWindowValueBoxEditMode = false;
    int SearchWindowValueBoxValue = 0;            // ValueBOx: SearchWindowValueBox

    // Define controls rectangles
    Rectangle layoutRecs6[4] = {
        (Rectangle){ 672, 72, 696, 384 },    // WindowBox: SearchWindowBox
        (Rectangle){ 792, 360, 456, 48 },    // Button: SearchWindowButton
        (Rectangle){ 984, 224, 120, 24 },    // LabelButton: SearchWindowLabel
        (Rectangle){ 720, 264, 600, 48 },    // ValueBOx: SearchWindowValueBox
    };
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            if (SearchWindowBoxActive)
            {
                SearchWindowBoxActive = !GuiWindowBox(layoutRecs6[0], SearchWindowBoxText);
                if (GuiButton(layoutRecs6[1], SearchWindowButtonText)) SearchWindowButton(); 
                GuiLabel(layoutRecs6[2], SearchWindowLabelText);
                if (GuiValueBox(layoutRecs6[3], "", &SearchWindowValueBoxValue, 0, 1000000, SearchWindowValueBoxEditMode)) SearchWindowValueBoxEditMode = !SearchWindowValueBoxEditMode;
            }
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
// Button: SearchWindowButton logic
static void SearchWindowButton()
{
    // TODO: Implement control logic
}


