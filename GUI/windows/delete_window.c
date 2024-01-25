/*******************************************************************************************
*
*   DeleteWindow v1.0.0 - Tool Description
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
static void DeleteWindowButton();                // Button: DeleteWindowButton logic

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "delete_window");

    // delete_window: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *DeleteWindowBoxText = "DELETE WINDOW";    // WINDOWBOX: DeleteWiindowBox
    const char *DeleteWindowButtonText = "DELETE";    // BUTTON: DeleteWindowButton
    const char *DeleteWindowLabelText = "KEY TO DELETE";    // LABELBUTTON: DeleteWindowLabel
    
    // Define controls variables
    bool DeleteWindowBoxActive = false;            // WindowBox: DeleteWiindowBox
    bool DeleteWindowValueBoxEditMode = false;
    int DeleteWindowValueBoxValue = 0;            // ValueBOx: DeleteWindowValueBox

    // Define controls rectangles
    Rectangle layoutRecs7[4] = {
        (Rectangle){ 696, 72, 696, 384 },    // WindowBox: DeleteWiindowBox
        (Rectangle){ 816, 360, 456, 48 },    // Button: DeleteWindowButton
        (Rectangle){ 1008, 224, 120, 24 },    // LabelButton: DeleteWindowLabel
        (Rectangle){ 744, 264, 600, 48 },    // ValueBOx: DeleteWindowValueBox
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
            if (DeleteWindowBoxActive)
            {
                DeleteWindowBoxActive = !GuiWindowBox(layoutRecs7[0], DeleteWindowBoxText);
                if (GuiButton(layoutRecs7[1], DeleteWindowButtonText)) DeleteWindowButton(); 
                GuiLabel(layoutRecs7[2], DeleteWindowLabelText);
                if (GuiValueBox(layoutRecs7[3], "", &DeleteWindowValueBoxValue, 0, 100, DeleteWindowValueBoxEditMode)) DeleteWindowValueBoxEditMode = !DeleteWindowValueBoxEditMode;
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
// Button: DeleteWindowButton logic
static void DeleteWindowButton()
{
    // TODO: Implement control logic
}
// LabelButton: DeleteWindowLabel logic
