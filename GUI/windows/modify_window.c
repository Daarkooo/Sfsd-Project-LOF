/*******************************************************************************************
*
*   LayoutName v1.0.0 - Tool Description
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
static void ModifyButton();                // Button: ModifyButton logic

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_name");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *ModifyWindowBoxText = "MODIFY WINDOW";    // WINDOWBOX: ModifyWindowBox
    const char *ModifyButtonText = "MODIFY";    // BUTTON: ModifyButton
    const char *ModifyNameLabelText = "NEW NAME";    // LABEL: ModifyNameLabel
    const char *ModifySurnameLabelText = "NEW SURNAME";    // LABEL: ModifySurnameLabel
    const char *ModifyKeyLabelText = "STUDENT KEY";    // LABEL: ModifyKeyLabel
    
    // Define controls variables
    bool ModifyWindowBoxActive = true;            // WindowBox: ModifyWindowBox
    bool ModifySurnameTextBoxEditMode = false;
    char ModifySurnameTextBoxText[128] = "";            // TextBox: ModifySurnameTextBox
    bool ModifyNameTextBoxEditMode = false;
    char ModifyNameTextBoxText[128] = "";            // TextBox: ModifyNameTextBox
    bool ModifyValueBoxEditMode = false;
    int ModifyValueBoxValue = 0;            // ValueBOx: ModifyValueBox

    // Define controls rectangles
    Rectangle layoutRecs8[8] = {
        (Rectangle){ 744, 72, 744, 480 },    // WindowBox: ModifyWindowBox
        (Rectangle){ 1176, 360, 240, 48 },    // TextBox: ModifySurnameTextBox
        (Rectangle){ 816, 360, 240, 48 },    // TextBox: ModifyNameTextBox
        (Rectangle){ 1056, 472, 120, 56 },    // Button: ModifyButton
        (Rectangle){ 984, 240, 432, 48 },    // ValueBOx: ModifyValueBox
        (Rectangle){ 888, 328, 120, 24 },    // Label: ModifyNameLabel
        (Rectangle){ 1248, 328, 120, 24 },    // Label: ModifySurnameLabel
        (Rectangle){ 864, 256, 120, 24 },    // Label: ModifyKeyLabel
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
            if (ModifyWindowBoxActive)
            {
                ModifyWindowBoxActive = !GuiWindowBox(layoutRecs8[0], ModifyWindowBoxText);
                if (GuiTextBox(layoutRecs8[1], ModifySurnameTextBoxText, 128, ModifySurnameTextBoxEditMode)) ModifySurnameTextBoxEditMode = !ModifySurnameTextBoxEditMode;
                if (GuiTextBox(layoutRecs8[2], ModifyNameTextBoxText, 128, ModifyNameTextBoxEditMode)) ModifyNameTextBoxEditMode = !ModifyNameTextBoxEditMode;
                if (GuiButton(layoutRecs8[3], ModifyButtonText)) ModifyButton(); 
                if (GuiValueBox(layoutRecs8[4], "", &ModifyValueBoxValue, 0, 100, ModifyValueBoxEditMode)) ModifyValueBoxEditMode = !ModifyValueBoxEditMode;
                GuiLabel(layoutRecs8[5], ModifyNameLabelText);
                GuiLabel(layoutRecs8[6], ModifySurnameLabelText);
                GuiLabel(layoutRecs8[7], ModifyKeyLabelText);
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
// Button: ModifyButton logic
static void ModifyButton()
{
    // TODO: Implement control logic
}

