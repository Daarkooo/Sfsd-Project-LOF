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
static void InsertWindowButton();                // Button: insertWindowButton logic

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
    const char *insertWindowText = "INSERT WINDOW";    // WINDOWBOX: insertWindow
    const char *nameLabelText = "NAME";    // LABEL: nameLabel
    const char *matriculeLabelText = "STUDENT KEY";    // LABEL: matriculeLabel
    const char *surnameLabelText = "SURNAME";    // LABEL: surnameLabel
    const char *insertWindowButtonText = "INSERT";    // BUTTON: insertWindowButton
    
    // Define controls variables
    bool insertWindowActive = true;            // WindowBox: insertWindow
    bool NameTextBoxEditMode = false;
    char NameTextBoxText[128] = "";            // TextBox: NameTextBox
    bool MatriculeTextBoxEditMode = false;
    char MatriculeTextBoxText[128] = "";            // TextBox: MatriculeTextBox
    bool SurnameTextBoxEditMode = false;
    char SurnameTextBoxText[128] = "";            // TextBox: SurnameTextBox

    // Define controls rectangles
    Rectangle layoutRecs4[8] = {
        (Rectangle){ 216, 104, 408, 568 },    // WindowBox: insertWindow
        (Rectangle){ 288, 216, 264, 48 },    // TextBox: NameTextBox
        (Rectangle){ 400, 192, 120, 24 },    // Label: nameLabel
        (Rectangle){ 288, 456, 264, 48 },    // TextBox: MatriculeTextBox
        (Rectangle){ 288, 336, 264, 48 },    // TextBox: SurnameTextBox
        (Rectangle){ 384, 432, 120, 24 },    // Label: matriculeLabel
        (Rectangle){ 392, 312, 120, 24 },    // Label: surnameLabel
        (Rectangle){ 336, 584, 168, 64 },    // Button: insertWindowButton
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
            if (insertWindowActive)
            {
                insertWindowActive = !GuiWindowBox(layoutRecs4[0], insertWindowText);
                if (GuiTextBox(layoutRecs4[1], NameTextBoxText, 128, NameTextBoxEditMode)) NameTextBoxEditMode = !NameTextBoxEditMode;
                GuiLabel(layoutRecs4[2], nameLabelText);
                if (GuiTextBox(layoutRecs4[3], MatriculeTextBoxText, 128, MatriculeTextBoxEditMode)) MatriculeTextBoxEditMode = !MatriculeTextBoxEditMode;
                if (GuiTextBox(layoutRecs4[4], SurnameTextBoxText, 128, SurnameTextBoxEditMode)) SurnameTextBoxEditMode = !SurnameTextBoxEditMode;
                GuiLabel(layoutRecs4[5], matriculeLabelText);
                GuiLabel(layoutRecs4[6], surnameLabelText);
                if (GuiButton(layoutRecs4[7], insertWindowButtonText)) InsertWindowButton(); 
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
// Button: insertWindowButton logic
static void InsertWindowButton()
{
    // TODO: Implement control logic
}

