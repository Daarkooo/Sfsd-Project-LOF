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
static void Button007();                // Button: Button007 logic

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
    const char *AddWindowBoxText = "ADD WINDOW";    // WINDOWBOX: AddWindowBox
    const char *AddNameLabelText = "NAME :";    // LABEL: AddNameLabel
    const char *AddKeyLabelText = "Student Key :";    // LABEL: AddKeyLabel
    const char *AddSurnameLabelText = "Surname :";    // LABEL: AddSurnameLabel
    const char *Button007Text = "SAMPLE TEXT";    // BUTTON: Button007
    
    // Define controls variables
    bool AddWindowBoxActive = true;            // WindowBox: AddWindowBox
    bool AddNameTextBoxEditMode = false;
    char AddNameTextBoxText[128] = "";            // TextBox: AddNameTextBox
    bool AddKeyTextBoxEditMode = false;
    char AddKeyTextBoxText[128] = "";            // TextBox: AddKeyTextBox
    bool AddSurnameTextBoxEditMode = false;
    char AddSurnameTextBoxText[128] = "";            // TextBox: AddSurnameTextBox

    // Define controls rectangles
    Rectangle layoutRecs[8] = {
        (Rectangle){ 480, 72, 408, 456 },    // WindowBox: AddWindowBox
        (Rectangle){ 648, 168, 192, 40 },    // TextBox: AddNameTextBox
        (Rectangle){ 648, 360, 192, 40 },    // TextBox: AddKeyTextBox
        (Rectangle){ 648, 264, 192, 40 },    // TextBox: AddSurnameTextBox
        (Rectangle){ 552, 176, 120, 24 },    // Label: AddNameLabel
        (Rectangle){ 552, 368, 120, 24 },    // Label: AddKeyLabel
        (Rectangle){ 552, 272, 120, 24 },    // Label: AddSurnameLabel
        (Rectangle){ 624, 432, 120, 72 },    // Button: Button007
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
            if (AddWindowBoxActive)
            {
                AddWindowBoxActive = !GuiWindowBox(layoutRecs[0], AddWindowBoxText);
                if (GuiTextBox(layoutRecs[1], AddNameTextBoxText, 128, AddNameTextBoxEditMode)) AddNameTextBoxEditMode = !AddNameTextBoxEditMode;
                if (GuiTextBox(layoutRecs[2], AddKeyTextBoxText, 128, AddKeyTextBoxEditMode)) AddKeyTextBoxEditMode = !AddKeyTextBoxEditMode;
                if (GuiTextBox(layoutRecs[3], AddSurnameTextBoxText, 128, AddSurnameTextBoxEditMode)) AddSurnameTextBoxEditMode = !AddSurnameTextBoxEditMode;
                GuiLabel(layoutRecs[4], AddNameLabelText);
                GuiLabel(layoutRecs[5], AddKeyLabelText);
                GuiLabel(layoutRecs[6], AddSurnameLabelText);
                if (GuiButton(layoutRecs[7], Button007Text)) Button007(); 
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
// Button: Button007 logic
static void Button007()
{
    // TODO: Implement control logic
}

