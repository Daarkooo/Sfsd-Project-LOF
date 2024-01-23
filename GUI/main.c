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

//------------------ EDIT WINDOW BUTTONS ----------------------
static void InsertStudentButton();                // Button: InsertStudentButton logic
static void SearchStudentButton();                // Button: SearchStudentButton logic
static void DeleteStudentButton();                // Button: DeleteStudentButton logic
static void ModifyStudentButton();                // Button: ModifyStudentButton logic



// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 1200;
    int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "LOF GUI");


    //------------------------ MAIN MENU ------------------------
    // Const text
    const char *createButtonText = "CREATE A NEW FILE";    // BUTTON: createButton
    const char *editButtonText = "EDIT AN OLD FILE";    // BUTTON: editButton
    const char *exitButtonText = "EXIT THE PROGRAM";    // BUTTON: exitButton
    
    // Define controls variables

    // Define controls rectangles
    Rectangle layoutRecs[4] = {
        (Rectangle){ 50, 150, 330, 80 },    // Button: createButton
        (Rectangle){ 50, 300, 330, 80 },    // Button: editButton
        (Rectangle){ 100, 450, 230, 60 },    // Button: exitButton
    };
    //----------------------------- END MAIN MENU -----------------------------

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
        (Rectangle){ 500, 100, 620, 400 },    // WindowBox: CreateWindowBox
        (Rectangle){ 740, 210, 225, 40 },    // TextBox: FileNameTextBox
        (Rectangle){ 740, 310, 225, 40 },    // Spinner: NbStudentsSpinner
        (Rectangle){ 612, 220, 120, 24 },    // Label: FileNameLabel
        (Rectangle){ 580, 320, 120, 24 },    // Label: NbStudentLabel
        (Rectangle){ 756, 400, 104, 48 },    // Button: FinishCreateButton
    };
    //-------------- END CREATE WINDOW ------------

    //-------------------- EDIT WINDOW --------------------
    // Const text
    const char *EditWindowText = "EDIT WINDOW";    // WINDOWBOX: EditWindow
    const char *EditFileNameLabelText = "FILE NAME";    // LABEL: EditFileNameLabel
    const char *InsertStudentButtonText = "INSERT STUDENT";    // BUTTON: InsertStudentButton
    const char *SearchStudentButtonText = "SEARCH STUDENT";    // BUTTON: SearchStudentButton
    const char *DeleteStudentButtonText = "DELETE STUDENT";    // BUTTON: DeleteStudentButton
    const char *ModifyStudentButtonText = "MODIFY STUDENT";    // BUTTON: ModifyStudentButton
    
    // Define controls variables
    bool EditWindowActive = false;            // WindowBox: EditWindow
    bool EditFileNameTextBoxEditMode = false;
    char EditFileNameTextBoxText[128] = "";            // TextBox: EditFileNameTextBox

    // Define controls rectangles
    Rectangle layoutRecs3[7] = {
        (Rectangle){ 450, 40, 704, 528 },    // WindowBox: EditWindow
        (Rectangle){ 700, 190, 216, 48 },    // TextBox: EditFileNameTextBox
        (Rectangle){ 620, 200, 112, 32 },    // Label: EditFileNameLabel
        (Rectangle){ 500, 340, 264, 64 },    // Button: InsertStudentButton
        (Rectangle){ 500, 450, 264, 64 },    // Button: SearchStudentButton
        (Rectangle){ 840, 340, 264, 64 },    // Button: DeleteStudentButton
        (Rectangle){ 840, 450, 264, 64 },    // Button: ModifyStudentButton
    };
    //------------------ END EDIT WINDOW -------------------

    //Loading Style File
    GuiLoadStyle("./style/style.rgs");

    //Loading Font Files
    Font EmizenFont = LoadFontEx("./fonts/Emizen.ttf", 48, 0, 0);
    Font CourierFont = LoadFontEx("./fonts/Courier New Bold Italic font.ttf", 40, 0, 0);
    GuiSetFont(CourierFont);

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

            ClearBackground(BLACK);

            DrawTextEx(EmizenFont, "MAIN MENU", (Vector2){100, 50}, EmizenFont.baseSize, 3, WHITE);
            DrawLine(100, 100, 300, 100, WHITE);
            DrawTextEx(EmizenFont, "VISUALISATION", (Vector2){10, 580}, EmizenFont.baseSize, 3, WHITE);
            DrawLine(320, 600, 1200, 600, WHITE);
            

            // raygui: controls drawing
            //----------------------- MAIN MENU --------------------------
            // Draw controls
            if (GuiButton(layoutRecs[0], createButtonText)) { 
                CreateWindowBoxActive = true;
                EditWindowActive = false;
            }
            if (GuiButton(layoutRecs[1], editButtonText)) {
                EditWindowActive = true;
                CreateWindowBoxActive = false;
            } 
            if (GuiButton(layoutRecs[2], exitButtonText)) break;
            
            //------------------------ END MAIN MENU -------------------------

            //--------------------- CREATE WINDOW ---------------------
            // Draw controls
            if (CreateWindowBoxActive)
            {
                CreateWindowBoxActive = !GuiWindowBox(layoutRecs2[0], CreateWindowBoxText);
                DrawText("--- CREATE MENU ---", 675, 150, 20, WHITE);
                if (GuiTextBox(layoutRecs2[1], FileNameTextBoxText, 128, FileNameTextBoxEditMode)) FileNameTextBoxEditMode = !FileNameTextBoxEditMode;
                if (GuiSpinner(layoutRecs2[2], "", &NbStudentsSpinnerValue, 0, 100, NbStudentsSpinnerEditMode)) NbStudentsSpinnerEditMode = !NbStudentsSpinnerEditMode;
                GuiLabel(layoutRecs2[3], FileNameLabelText);
                GuiLabel(layoutRecs2[4], NbStudentLabelText);
                if (GuiButton(layoutRecs2[5], FinishCreateButtonText)) FinishCreateButton();
            }
            //---------------------- END CREATE WINDOW ----------------------

            //----------------------- EDIT WINDOW --------------------------
            // Draw controls
            if (EditWindowActive)
            {
                EditWindowActive = !GuiWindowBox(layoutRecs3[0], EditWindowText);
                DrawText("--- EDIT MENU ---", 710, 100, 20, WHITE);
                if (GuiTextBox(layoutRecs3[1], EditFileNameTextBoxText, 128, EditFileNameTextBoxEditMode)) EditFileNameTextBoxEditMode = !EditFileNameTextBoxEditMode;
                GuiLabel(layoutRecs3[2], EditFileNameLabelText);
                if (GuiButton(layoutRecs3[3], InsertStudentButtonText)) InsertStudentButton(); 
                if (GuiButton(layoutRecs3[4], SearchStudentButtonText)) SearchStudentButton(); 
                if (GuiButton(layoutRecs3[5], DeleteStudentButtonText)) DeleteStudentButton(); 
                if (GuiButton(layoutRecs3[6], ModifyStudentButtonText)) ModifyStudentButton(); 
            }
            //----------------------- END EDIT WINDOW --------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Unload the font when done
    UnloadFont(EmizenFont);
    UnloadFont(CourierFont);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


//------------------------- CREATE WINDOW BUTTON --------------------------
// Button: FinishCreateButton logic
static void FinishCreateButton()
{
    // TODO: Implement control logic
}

//----------------------- EDIT WINDOW BUTTONS ----------------------
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

