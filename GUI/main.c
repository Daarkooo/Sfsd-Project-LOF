#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "methods.h"
#include "methods.c"


// Controls Functions Declaration
//--------------------- MAIN MENU BUTTONS -------------------------
static void EditButton();                // Button: editButton logic

//------------- CREATE WINDOW BUTTONS ------------
static void FinishCreateButton();                // Button: FinishCreateButton logic


// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 1200;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "LOF GUI");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    // Const text
    const char *createButtonText = "CREATE A NEW FILE";    // BUTTON: createButton
    const char *editButtonText = "EDIT AN OLD FILE";    // BUTTON: editButton
    const char *exitButtonText = "EXIT THE PROGRAM";    // BUTTON: exitButton
    
    // Define controls variables

    // Define controls rectangles
    Rectangle layoutRecs[4] = {
        (Rectangle){ 100, 150, 330, 80 },    // Button: createButton
        (Rectangle){ 100, 300, 330, 80 },    // Button: editButton
        (Rectangle){ 150, 450, 230, 60 },    // Button: exitButton
    };
    //----------------------------------------------------------------------------------

    //------------ CREATE WINDOW -----------------
    // Const text
    const char *CreateWindowBoxText = "CREATE WINDOW";    // WINDOWBOX: CreateWindowBox
    const char *FileNameLabelText = "FILE NAME";    // LABEL: FileNameLabel
    const char *NbStudentLabelText = "NUMBER OF STUDENTS";    // LABEL: NbStudentLabel
    const char *FinishCreateButtonText = "FINISH";    // BUTTON: FinishCreateButton
    
    // Define controls variables
    bool CreateWindowBoxActive = false;            // WindowBox: CreateWindowBox
    bool FileNameTextBoxEditMode = false;
    char FileNameTextBoxText[128] = "";            // TextBox: FileNameTextBox
    bool NbStudentsSpinnerEditMode = false;
    int NbStudentsSpinnerValue = 0;            // Spinner: NbStudentsSpinner

    // Define controls rectangles
    Rectangle layoutRecs2[6] = {
        (Rectangle){ 500, 104, 616, 376 },    // WindowBox: CreateWindowBox
        (Rectangle){ 740, 176, 224, 48 },    // TextBox: FileNameTextBox
        (Rectangle){ 740, 280, 224, 40 },    // Spinner: NbStudentsSpinner
        (Rectangle){ 612, 192, 120, 24 },    // Label: FileNameLabel
        (Rectangle){ 580, 288, 120, 24 },    // Label: NbStudentLabel
        (Rectangle){ 756, 400, 104, 48 },    // Button: FinishCreateButton
    };
    //-------------- END CREATE WINDOW ------------




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

            ClearBackground(DARKGRAY);

            DrawText("--- MAIN MENU ---", 150, 50, 25, WHITE); 

            // raygui: controls drawing
            //----------------------- MAIN MENU --------------------------
            // Draw controls
            if (GuiButton(layoutRecs[0], createButtonText)) CreateWindowBoxActive = true; 
            if (GuiButton(layoutRecs[1], editButtonText)) EditButton(); 
            if (GuiButton(layoutRecs[2], exitButtonText)) break;
            //------------------------ END MAIN MENU -------------------------

            //--------------------- CREATE WINDOW ---------------------
            // Draw controls
            if (CreateWindowBoxActive)
            {
                CreateWindowBoxActive = !GuiWindowBox(layoutRecs2[0], CreateWindowBoxText);
                if (GuiTextBox(layoutRecs2[1], FileNameTextBoxText, 128, FileNameTextBoxEditMode)) FileNameTextBoxEditMode = !FileNameTextBoxEditMode;
                if (GuiSpinner(layoutRecs2[2], "", &NbStudentsSpinnerValue, 0, 100, NbStudentsSpinnerEditMode)) NbStudentsSpinnerEditMode = !NbStudentsSpinnerEditMode;
                GuiLabel(layoutRecs2[3], FileNameLabelText);
                GuiLabel(layoutRecs2[4], NbStudentLabelText);
                if (GuiButton(layoutRecs2[5], FinishCreateButtonText)) FinishCreateButton();
            }
            //---------------------- END CREATE WINDOW ----------------------

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
// Button: editButton logic
static void EditButton()
{
    // TODO: Implement control logic
}
// Button: FinishCreateButton logic
static void FinishCreateButton()
{
    // TODO: Implement control logic
}

