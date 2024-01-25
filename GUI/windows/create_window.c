
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void FinishCreateButton();                // Button: FinishCreateButton logic

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
    const char *CreateWindowBoxText = "CREATE WINDOW";    // WINDOWBOX: CreateWindowBox
    const char *FileNameLabelText = "FILE NAME";    // LABEL: FileNameLabel
    const char *NbStudentLabelText = "NUMBER OF STUDENTS";    // LABEL: NbStudentLabel
    const char *FinishCreateButtonText = "FINISH";    // BUTTON: FinishCreateButton
    
    // Define controls variables
    bool CreateWindowBoxActive = true;            // WindowBox: CreateWindowBox
    bool FileNameTextBoxEditMode = false;
    char FileNameTextBoxText[128] = "";            // TextBox: FileNameTextBox
    bool NbStudentsSpinnerEditMode = false;
    int NbStudentsSpinnerValue = 0;            // Spinner: NbStudentsSpinner

    // Define controls rectangles
    Rectangle layoutRecs[6] = {
        (Rectangle){ 400, 104, 616, 376 },    // WindowBox: CreateWindowBox
        (Rectangle){ 640, 176, 224, 48 },    // TextBox: FileNameTextBox
        (Rectangle){ 640, 280, 224, 40 },    // Spinner: NbStudentsSpinner
        (Rectangle){ 512, 192, 120, 24 },    // Label: FileNameLabel
        (Rectangle){ 480, 288, 120, 24 },    // Label: NbStudentLabel
        (Rectangle){ 656, 400, 104, 48 },    // Button: FinishCreateButton
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
            if (CreateWindowBoxActive)
            {
                CreateWindowBoxActive = !GuiWindowBox(layoutRecs[0], CreateWindowBoxText);
                if (GuiTextBox(layoutRecs[1], FileNameTextBoxText, 128, FileNameTextBoxEditMode)) FileNameTextBoxEditMode = !FileNameTextBoxEditMode;
                if (GuiSpinner(layoutRecs[2], "", &NbStudentsSpinnerValue, 0, 100, NbStudentsSpinnerEditMode)) NbStudentsSpinnerEditMode = !NbStudentsSpinnerEditMode;
                GuiLabel(layoutRecs[3], FileNameLabelText);
                GuiLabel(layoutRecs[4], NbStudentLabelText);
                if (GuiButton(layoutRecs[5], FinishCreateButtonText)) FinishCreateButton(); 
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
// Button: FinishCreateButton logic
static void FinishCreateButton()
{
    // TODO: Implement control logic
}

