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
static void InsertStudentButton();                // Button: InsertStudentButton logic
static void SearchStudentButton();                // Button: SearchStudentButton logic
static void DeleteStudentButton();                // Button: DeleteStudentButton logic
static void ModifyStudentButton();                // Button: ModifyStudentButton logic

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
    const char *EditWindowText = "EDIT WINDOW";    // WINDOWBOX: EditWindow
    const char *EditFileNameLabelText = "FILE NAME";    // LABEL: EditFileNameLabel
    const char *InsertStudentButtonText = "INSERT STUDENT";    // BUTTON: InsertStudentButton
    const char *SearchStudentButtonText = "SEARCH STUDENT";    // BUTTON: SearchStudentButton
    const char *DeleteStudentButtonText = "DELETE STUDENT";    // BUTTON: DeleteStudentButton
    const char *ModifyStudentButtonText = "MODIFY STUDENT";    // BUTTON: ModifyStudentButton
    
    // Define controls variables
    bool EditWindowActive = true;            // WindowBox: EditWindow
    bool EditFileNameTextBoxEditMode = false;
    char EditFileNameTextBoxText[128] = "";            // TextBox: EditFileNameTextBox

    // Define controls rectangles
    Rectangle layoutRecs3[7] = {
        (Rectangle){ 280, 112, 704, 528 },    // WindowBox: EditWindow
        (Rectangle){ 592, 264, 216, 48 },    // TextBox: EditFileNameTextBox
        (Rectangle){ 456, 272, 112, 32 },    // Label: EditFileNameLabel
        (Rectangle){ 336, 392, 264, 64 },    // Button: InsertStudentButton
        (Rectangle){ 336, 512, 264, 64 },    // Button: SearchStudentButton
        (Rectangle){ 672, 392, 264, 64 },    // Button: DeleteStudentButton
        (Rectangle){ 672, 512, 264, 64 },    // Button: ModifyStudentButton
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
            if (EditWindowActive)
            {
                EditWindowActive = !GuiWindowBox(layoutRecs3[0], EditWindowText);
                if (GuiTextBox(layoutRecs3[1], EditFileNameTextBoxText, 128, EditFileNameTextBoxEditMode)) EditFileNameTextBoxEditMode = !EditFileNameTextBoxEditMode;
                GuiLabel(layoutRecs3[2], EditFileNameLabelText);
                if (GuiButton(layoutRecs3[3], InsertStudentButtonText)) InsertStudentButton(); 
                if (GuiButton(layoutRecs3[4], SearchStudentButtonText)) SearchStudentButton(); 
                if (GuiButton(layoutRecs3[5], DeleteStudentButtonText)) DeleteStudentButton(); 
                if (GuiButton(layoutRecs3[6], ModifyStudentButtonText)) ModifyStudentButton(); 
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
// Button: InsertStudentButton logic
static void InsertStudentButton()
{
    // TODO: Implement control logic
}
// Button: SearchStudentButton logic
static void SearchStudentButton()
{
    // TODO: Implement control logic
}
// Button: DeleteStudentButton logic
static void DeleteStudentButton()
{
    // TODO: Implement control logic
}
// Button: ModifyStudentButton logic
static void ModifyStudentButton()
{
    // TODO: Implement control logic
}

