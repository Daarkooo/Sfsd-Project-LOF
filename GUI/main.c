#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "methods.h"
#include "methods.c"


// Controls Functions Declaration
//------------------ EDIT WINDOW BUTTONS ----------------------
static void InsertStudentButton();                // Button: InsertStudentButton logic
static void SearchStudentButton();                // Button: SearchStudentButton logic
static void DeleteStudentButton();                // Button: DeleteStudentButton logic
static void ModifyStudentButton();                // Button: ModifyStudentButton logic

//------------ INSERT WINDOW BUTTONS -------------------
static void InsertWindowButton(char* ch, char* name, char* surname, int matricule);                // Button: insertWindowButton logic

//--------------------- ADD WINDOW BUTTON ----------------------
static StudentP AddWindowButton(char* name, char*surname, int matricule);                // Button: Button007 logic

//---------------------- SEARCH WINDOW BUTTON ---------------------------
static void SearchWindowButton(char* ch, int matricule);                // Button: SearchWindowButton logic

//------------------------ DELETE WINDOW BUTTON ------------------------------
static void DeleteWindowButton(char* ch, int matricule);                // Button: DeleteWindowButton logic

//--------------------------- MODIFY WINDOW BUTTON --------------------------------
static void ModifyButton(char* ch, char* name, char* surname, int matricule);                // Button: ModifyButton logic

// Program main entry point
//------------------------------------------------------------------------------------
int main()
{


    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 1500;
    int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "LOF GUI");


    //------------------------ MAIN MENU ------------------------
    // Const text
    const char *createButtonText = "";    // BUTTON: createButton
    const char *editButtonText = "";    // BUTTON: editButton
    const char *exitButtonText = "";    // BUTTON: exitButton
    
    // Define controls variables

    // Define controls rectangles
    Rectangle layoutRecs[4] = {
        (Rectangle){ 50, 150, 350, 80 },    // Button: createButton
        (Rectangle){ 50, 300, 350, 80 },    // Button: editButton
        (Rectangle){ 100, 450, 250, 70 },    // Button: exitButton
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

    //--------------------- INSERT WINDOW --------------------------
    // Const text
    const char *insertWindowText = "INSERT WINDOW";    // WINDOWBOX: insertWindow
    const char *nameLabelText = "NAME";    // LABEL: nameLabel
    const char *matriculeLabelText = "STUDENT KEY";    // LABEL: matriculeLabel
    const char *surnameLabelText = "SURNAME";    // LABEL: surnameLabel
    const char *insertWindowButtonText = "INSERT";    // BUTTON: insertWindowButton
    
    // Define controls variables
    bool insertWindowActive = false;            // WindowBox: insertWindow
    bool NameTextBoxEditMode = false;
    char NameTextBoxText[128] = "";            // TextBox: NameTextBox
    bool MatriculeTextBoxEditMode = false;
    char MatriculeTextBoxText[128] = "";            // TextBox: MatriculeTextBox
    bool SurnameTextBoxEditMode = false;
    char SurnameTextBoxText[128] = "";            // TextBox: SurnameTextBox

    // Define controls rectangles
    Rectangle layoutRecs4[8] = {
        (Rectangle){ 600, 20, 600, 568 },    // WindowBox: insertWindow
        (Rectangle){ 680, 140, 460, 48 },    // TextBox: NameTextBox
        (Rectangle){ 890, 110, 120, 24 },    // Label: nameLabel
        (Rectangle){ 680, 380, 460, 48 },    // TextBox: MatriculeTextBox
        (Rectangle){ 680, 260, 460, 48 },    // TextBox: SurnameTextBox
        (Rectangle){ 870, 350, 120, 24 },    // Label: matriculeLabel
        (Rectangle){ 880, 230, 120, 24 },    // Label: surnameLabel
        (Rectangle){ 820, 500, 168, 64 },    // Button: insertWindowButton
    };
    //--------------------- END INSERT WINDOW ------------------

    //----------------------- ADD WINDOW ---------------------------
    // Const text
    const char *AddWindowBoxText = "ADD WINDOW";    // WINDOWBOX: AddWindowBox
    const char *AddNameLabelText = "NAME :";    // LABEL: AddNameLabel
    const char *AddKeyLabelText = "Student Key :";    // LABEL: AddKeyLabel
    const char *AddSurnameLabelText = "Surname :";    // LABEL: AddSurnameLabel
    const char *AddWindowButtonText = "ADD";    // BUTTON: AddWindowButton
    
    // Define controls variables
    bool AddWindowBoxActive = false;            // WindowBox: AddWindowBox
    bool AddNameTextBoxEditMode = false;
    char AddNameTextBoxText[128] = "";            // TextBox: AddNameTextBox
    bool AddKeyTextBoxEditMode = false;
    char AddKeyTextBoxText[128] = "";            // TextBox: AddKeyTextBox
    bool AddSurnameTextBoxEditMode = false;
    char AddSurnameTextBoxText[128] = "";            // TextBox: AddSurnameTextBox

    // Define controls rectangles
    Rectangle layoutRecs5[8] = {
        (Rectangle){ 550, 72, 408, 456 },    // WindowBox: AddWindowBox
        (Rectangle){ 710, 168, 192, 40 },    // TextBox: AddNameTextBox
        (Rectangle){ 710, 360, 192, 40 },    // TextBox: AddKeyTextBox
        (Rectangle){ 710, 264, 192, 40 },    // TextBox: AddSurnameTextBox
        (Rectangle){ 620, 176, 120, 24 },    // Label: AddNameLabel
        (Rectangle){ 620, 368, 120, 24 },    // Label: AddKeyLabel
        (Rectangle){ 620, 272, 120, 24 },    // Label: AddSurnameLabel
        (Rectangle){ 700, 432, 120, 72 },    // Button: Button007
    };
    //------------------------- END ADD WINDOW --------------------------

    //------------------------- SEARCH WINDOW -------------------------
    // Const text
    const char *SearchWindowBoxText = "SEARCH WINDOW";    // WINDOWBOX: SearchWindowBox
    const char *SearchWindowButtonText = "SEARCH";    // BUTTON: SearchWindowButton
    const char *SearchWindowLabelText = "KEY TO SEARCH";    // LABELBUTTON: SearchWindowLabel
    
    // Define controls variables
    bool SearchWindowBoxActive = false;            // WindowBox: SearchWindowBox
    bool SearchWindowValueBoxEditMode = false;
    int SearchWindowValueBoxValue = 0;            // ValueBOx: SearchWindowValueBox

    // Define controls rectangles
    Rectangle layoutRecs6[4] = {
        (Rectangle){ 572, 72, 696, 384 },    // WindowBox: SearchWindowBox
        (Rectangle){ 692, 360, 456, 48 },    // Button: SearchWindowButton
        (Rectangle){ 884, 224, 120, 24 },    // LabelButton: SearchWindowLabel
        (Rectangle){ 620, 264, 600, 48 },    // ValueBOx: SearchWindowValueBox
    };
    //--------------------------- END SEARCH WINDOW ------------------------

    //-------------------------------- DELETE WINDOW -----------------------------
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
        (Rectangle){ 596, 110, 696, 384 },    // WindowBox: DeleteWiindowBox
        (Rectangle){ 716, 400, 456, 48 },    // Button: DeleteWindowButton
        (Rectangle){ 908, 260, 120, 24 },    // LabelButton: DeleteWindowLabel
        (Rectangle){ 644, 300, 600, 48 },    // ValueBOx: DeleteWindowValueBox
    };
    //------------------------------- END DELETE WINDOW --------------------------------

    //----------------------------- MODIFY WINDOW ---------------------------------
    // Const text
    const char *ModifyWindowBoxText = "MODIFY WINDOW";    // WINDOWBOX: ModifyWindowBox
    const char *ModifyButtonText = "MODIFY";    // BUTTON: ModifyButton
    const char *ModifyNameLabelText = "NEW NAME";    // LABEL: ModifyNameLabel
    const char *ModifySurnameLabelText = "NEW SURNAME";    // LABEL: ModifySurnameLabel
    const char *ModifyKeyLabelText = "STUDENT KEY";    // LABEL: ModifyKeyLabel
    
    // Define controls variables
    bool ModifyWindowBoxActive = false;            // WindowBox: ModifyWindowBox
    bool ModifySurnameTextBoxEditMode = false;
    char ModifySurnameTextBoxText[128] = "";            // TextBox: ModifySurnameTextBox
    bool ModifyNameTextBoxEditMode = false;
    char ModifyNameTextBoxText[128] = "";            // TextBox: ModifyNameTextBox
    bool ModifyValueBoxEditMode = false;
    int ModifyValueBoxValue = 0;            // ValueBOx: ModifyValueBox

    // Define controls rectangles
    Rectangle layoutRecs8[8] = {
        (Rectangle){ 644, 72, 744, 480 },    // WindowBox: ModifyWindowBox
        (Rectangle){ 1076, 360, 240, 48 },    // TextBox: ModifySurnameTextBox
        (Rectangle){ 716, 360, 240, 48 },    // TextBox: ModifyNameTextBox
        (Rectangle){ 956, 472, 120, 56 },    // Button: ModifyButton
        (Rectangle){ 884, 240, 432, 48 },    // ValueBOx: ModifyValueBox
        (Rectangle){ 788, 328, 120, 24 },    // Label: ModifyNameLabel
        (Rectangle){ 1148, 328, 120, 24 },    // Label: ModifySurnameLabel
        (Rectangle){ 764, 256, 120, 24 },    // Label: ModifyKeyLabel
    };
    //----------------------------- MODIFY WINDOW END -------------------------------

    //Loading Style File
    GuiLoadStyle("./style/style.rgs");

    //Loading Font Files
    Font EmizenFontBig = LoadFontEx("./fonts/Emizen.ttf", 70, 0, 0);
    Font EmizenFontSmall = LoadFontEx("./fonts/Emizen.ttf", 48, 0, 0);
    Font ButtonFont = LoadFontEx("./fonts/Satoshi-Black.otf", 20, 0, 0);
    Font WindowTitleFont = LoadFontEx("./fonts/Hoover-Bold.otf", 35, 0, 0);
    Font WindowButtonFont = LoadFontEx("./fonts/Nippo-Medium.otf", 20, 0, 0);
    Font SuccesMessageFont = LoadFontEx("./fonts/Tanker-Regular.otf", 30, 0, 0);


    //File Variables decalaration
    LOF_fileP fichierLOF;
    StudentP studentTab = malloc(sizeof(Student)*NbStudentsSpinnerValue);
    int creationCounter = 0;


    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    Vector2 position = {0, 750};      // Position actuelle du rectangle
    Vector2 destination = {screenWidth - 100, 750};   // Destination du rectangle

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------
        // Logique de mise à jour
        float t = GetFrameTime(); // Temps écoulé depuis la dernière frame
        position.x += (destination.x - position.x) * t * 0.7f; // Ajustez la valeur 2.0f pour contrôler la vitesse de déplacement
        position.y += (destination.y - position.y) * t * 0.7f;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            
            ClearBackground((Color){0, 0,40, 0});

            //Testing moving elements :
            DrawRectangleV(position, (Vector2){100, 150}, DARKBROWN);
            DrawText(TextFormat("%d", 16), position.x + 40, position.y, 20, WHITE);
            DrawLine(position.x, position.y + 20, position.x + 100, position.y + 20, WHITE);
            DrawText("38", position.x + 40, position.y + 25, 20, WHITE);
            DrawLine(position.x, position.y + 50, position.x + 100, position.y + 50, WHITE);
            DrawText("66", position.x + 40, position.y + 50, 20, WHITE);
            DrawLine(position.x, position.y + 70, position.x + 100, position.y + 70, WHITE);
            DrawText("80", position.x + 40, position.y + 75, 20, WHITE);
            DrawLine(position.x, position.y + 100, position.x + 100, position.y + 100, WHITE);


            DrawTextEx(EmizenFontBig, "MAIN MENU", (Vector2){90, 30}, EmizenFontBig.baseSize, 3, WHITE);
            DrawLine(80, 100, 370, 100, WHITE);
            DrawTextEx(EmizenFontSmall, "VISUALISATION", (Vector2){10, 580}, EmizenFontSmall.baseSize, 3, WHITE);
            DrawLine(320, 600, screenWidth, 600, WHITE);
            

            // raygui: controls drawing
            //----------------------- MAIN MENU --------------------------
            // Draw controls
            if (GuiButton(layoutRecs[0], createButtonText)) { 
                CreateWindowBoxActive = true;
                EditWindowActive = false;
            }
            DrawTextEx(ButtonFont, "CREATE A NEW FILE", (Vector2){120, 180}, ButtonFont.baseSize, 3, WHITE);

            if (GuiButton(layoutRecs[1], editButtonText)) {
                EditWindowActive = true;
                CreateWindowBoxActive = false;
            }
            DrawTextEx(ButtonFont, "EDIT AN OLD FILE", (Vector2){135, 330}, ButtonFont.baseSize, 3, WHITE);

            if (GuiButton(layoutRecs[2], exitButtonText)) break;
            DrawTextEx(ButtonFont, "EXIT THE PROGRAM", (Vector2){125, 475}, ButtonFont.baseSize, 3, WHITE);
            
            //------------------------ END MAIN MENU -------------------------

            //--------------------- CREATE WINDOW ---------------------
            // Draw controls
            if (CreateWindowBoxActive)
            {
                CreateWindowBoxActive = !GuiWindowBox(layoutRecs2[0], CreateWindowBoxText);
                DrawTextEx(WindowTitleFont, "CREATE MENU", (Vector2){700, 130}, WindowTitleFont.baseSize, 2, WHITE);
                DrawLine(700, 165, 890, 165, WHITE);

                if (GuiTextBox(layoutRecs2[1], FileNameTextBoxText, 128, FileNameTextBoxEditMode)) FileNameTextBoxEditMode = !FileNameTextBoxEditMode;

                if (GuiSpinner(layoutRecs2[2], "", &NbStudentsSpinnerValue, 0, 100, NbStudentsSpinnerEditMode)) NbStudentsSpinnerEditMode = !NbStudentsSpinnerEditMode;

                GuiLabel(layoutRecs2[3], FileNameLabelText);

                GuiLabel(layoutRecs2[4], NbStudentLabelText);

                if (GuiButton(layoutRecs2[5], FinishCreateButtonText)) {
                    CreateWindowBoxActive = false;
                    AddWindowBoxActive = true;
                    // FinishCreateButton(FileNameTextBoxText, NbStudentsSpinnerValue);
                } 
            }
            //---------------------- END CREATE WINDOW ----------------------

            //----------------------- EDIT WINDOW --------------------------
            // Draw controls
            if (EditWindowActive)
            {
                EditWindowActive = !GuiWindowBox(layoutRecs3[0], EditWindowText);
                DrawTextEx(WindowTitleFont, "EDIT MENU", (Vector2){720, 80}, WindowTitleFont.baseSize, 2, WHITE);
                DrawLine(720, 115, 870, 115, WHITE);

                if (GuiTextBox(layoutRecs3[1], EditFileNameTextBoxText, 128, EditFileNameTextBoxEditMode)) EditFileNameTextBoxEditMode = !EditFileNameTextBoxEditMode;

                GuiLabel(layoutRecs3[2], EditFileNameLabelText);

                if (GuiButton(layoutRecs3[3], InsertStudentButtonText)) {
                    insertWindowActive = true;
                    EditWindowActive = false;
                } 

                if (GuiButton(layoutRecs3[4], SearchStudentButtonText)) {
                    SearchWindowBoxActive = true;
                    EditWindowActive = false;
                } 

                if (GuiButton(layoutRecs3[5], DeleteStudentButtonText)) {
                    DeleteWindowBoxActive = true;
                    EditWindowActive = false;
                }; 

                if (GuiButton(layoutRecs3[6], ModifyStudentButtonText)) {
                    ModifyWindowBoxActive = true;
                    EditWindowActive = false;
                }; 

            }
            //----------------------- END EDIT WINDOW --------------------------

            //------------------------- INSERT WINDOW ----------------------
            // Draw controls
            if (insertWindowActive)
            {
                insertWindowActive = !GuiWindowBox(layoutRecs4[0], insertWindowText);
                DrawTextEx(WindowTitleFont, "INSERT A STUDENT", (Vector2){780, 50}, WindowTitleFont.baseSize, 2, WHITE);
                DrawLine(780, 85, 1040, 85, WHITE);

                if (GuiTextBox(layoutRecs4[1], NameTextBoxText, 128, NameTextBoxEditMode)) NameTextBoxEditMode = !NameTextBoxEditMode;
                GuiLabel(layoutRecs4[2], nameLabelText);
                if (GuiTextBox(layoutRecs4[3], MatriculeTextBoxText, 128, MatriculeTextBoxEditMode)) MatriculeTextBoxEditMode = !MatriculeTextBoxEditMode;
                if (GuiTextBox(layoutRecs4[4], SurnameTextBoxText, 128, SurnameTextBoxEditMode)) SurnameTextBoxEditMode = !SurnameTextBoxEditMode;
                GuiLabel(layoutRecs4[5], matriculeLabelText);
                GuiLabel(layoutRecs4[6], surnameLabelText);
                if (GuiButton(layoutRecs4[7], insertWindowButtonText)) {
                    InsertWindowButton(EditFileNameTextBoxText, NameTextBoxText, SurnameTextBoxText, atoi(MatriculeTextBoxText));
                    insertWindowActive = false;
                    EditWindowActive = true;
                    strcpy(NameTextBoxText, "");
                    strcpy(SurnameTextBoxText, "");
                    strcpy(MatriculeTextBoxText, "");
                } 
            }
            //-------------------------- END INSERT WINDOW ---------------------------

            //-------------------------- ADD WINDOW ---------------------------------
            // Draw controls
            if (AddWindowBoxActive)
            {
                AddWindowBoxActive = !GuiWindowBox(layoutRecs5[0], AddWindowBoxText);
                if (GuiTextBox(layoutRecs5[1], AddNameTextBoxText, 128, AddNameTextBoxEditMode)) AddNameTextBoxEditMode = !AddNameTextBoxEditMode;
                if (GuiTextBox(layoutRecs5[2], AddKeyTextBoxText, 128, AddKeyTextBoxEditMode)) AddKeyTextBoxEditMode = !AddKeyTextBoxEditMode;
                if (GuiTextBox(layoutRecs5[3], AddSurnameTextBoxText, 128, AddSurnameTextBoxEditMode)) AddSurnameTextBoxEditMode = !AddSurnameTextBoxEditMode;
                GuiLabel(layoutRecs5[4], AddNameLabelText);
                GuiLabel(layoutRecs5[5], AddKeyLabelText);
                GuiLabel(layoutRecs5[6], AddSurnameLabelText);
                if (GuiButton(layoutRecs5[7], AddWindowButtonText)) {
                    if (creationCounter < NbStudentsSpinnerValue - 1)
                    {
                        StudentP student = AddWindowButton(AddNameTextBoxText, AddSurnameTextBoxText, atoi(AddKeyTextBoxText));
                        studentCopy(studentTab + creationCounter, student);
                        strcpy(AddNameTextBoxText, "");
                        strcpy(AddSurnameTextBoxText, "");
                        strcpy(AddKeyTextBoxText, "");
                        creationCounter++;
                    } else {
                        StudentP student = AddWindowButton(AddNameTextBoxText, AddSurnameTextBoxText, atoi(AddKeyTextBoxText));
                        studentCopy(studentTab + creationCounter, student);
                        char ch1[20], ch2[20];
                        strcpy(ch1, FileNameTextBoxText);
                        strcpy(ch2, FileNameTextBoxText);
                        strcat(ch1, ".bin");
                        strcat(ch2, ".txt");
                        creationCounter = 0;
                        strcpy(AddNameTextBoxText, "");
                        strcpy(AddSurnameTextBoxText, "");
                        strcpy(AddKeyTextBoxText, "");
                        AddWindowBoxActive = false;
                        createLOF(fichierLOF, ch1, studentTab, NbStudentsSpinnerValue);
                        extractLOF(fichierLOF, ch1, ch2);
                    }
                }
            }
            //-------------------------- END ADD WINDOW -------------------------------

            //---------------------------- SEARCH WINDOW -------------------------
            // Draw controls
            if (SearchWindowBoxActive)
            {
                SearchWindowBoxActive = !GuiWindowBox(layoutRecs6[0], SearchWindowBoxText);
                if (GuiButton(layoutRecs6[1], SearchWindowButtonText)) {
                    SearchWindowButton(EditFileNameTextBoxText, SearchWindowValueBoxValue);
                    SearchWindowBoxActive = false;
                    EditWindowActive = true;
                    SearchWindowValueBoxValue = 0;
                }
                GuiLabel(layoutRecs6[2], SearchWindowLabelText);
                if (GuiValueBox(layoutRecs6[3], "", &SearchWindowValueBoxValue, 0, 1000000, SearchWindowValueBoxEditMode)) SearchWindowValueBoxEditMode = !SearchWindowValueBoxEditMode;
            }
            //-------------------------- END SEARCH WINDOW ---------------------------

            //---------------------------- DELETE WINDOW --------------------------------
            // Draw controls
            if (DeleteWindowBoxActive)
            {
                DeleteWindowBoxActive = !GuiWindowBox(layoutRecs7[0], DeleteWindowBoxText);
                if (GuiButton(layoutRecs7[1], DeleteWindowButtonText)) {
                    DeleteWindowButton(EditFileNameTextBoxText, DeleteWindowValueBoxValue);
                    DeleteWindowBoxActive = false;
                    EditWindowActive = true;
                    DeleteWindowValueBoxValue = 0;
                } 
                GuiLabel(layoutRecs7[2], DeleteWindowLabelText);
                if (GuiValueBox(layoutRecs7[3], "", &DeleteWindowValueBoxValue, 0, 1000000, DeleteWindowValueBoxEditMode)) DeleteWindowValueBoxEditMode = !DeleteWindowValueBoxEditMode;
            }
            //-------------------------- END DELETE WINDOW ------------------------------

            //------------------------------- MODIFY WINDOW ----------------------------------
            // Draw controls
            if (ModifyWindowBoxActive)
            {
                ModifyWindowBoxActive = !GuiWindowBox(layoutRecs8[0], ModifyWindowBoxText);
                if (GuiTextBox(layoutRecs8[1], ModifySurnameTextBoxText, 128, ModifySurnameTextBoxEditMode)) ModifySurnameTextBoxEditMode = !ModifySurnameTextBoxEditMode;
                if (GuiTextBox(layoutRecs8[2], ModifyNameTextBoxText, 128, ModifyNameTextBoxEditMode)) ModifyNameTextBoxEditMode = !ModifyNameTextBoxEditMode;
                if (GuiButton(layoutRecs8[3], ModifyButtonText)) {
                    ModifyButton(EditFileNameTextBoxText, ModifyNameTextBoxText, ModifySurnameTextBoxText, ModifyValueBoxValue);
                    ModifyWindowBoxActive = false;
                    EditWindowActive = true;
                    ModifyValueBoxValue = 0;
                    strcpy(ModifyNameTextBoxText, "");
                    strcpy(ModifySurnameTextBoxText, "");
                }
                if (GuiValueBox(layoutRecs8[4], "", &ModifyValueBoxValue, 0, 1000000, ModifyValueBoxEditMode)) ModifyValueBoxEditMode = !ModifyValueBoxEditMode;
                GuiLabel(layoutRecs8[5], ModifyNameLabelText);
                GuiLabel(layoutRecs8[6], ModifySurnameLabelText);
                GuiLabel(layoutRecs8[7], ModifyKeyLabelText);
            }
            //---------------------------- END MODIFY WINDOW ----------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------

    }


    // Unload the font when done
    UnloadFont(EmizenFontBig);
    UnloadFont(EmizenFontSmall);
    UnloadFont(ButtonFont);
    UnloadFont(WindowTitleFont);
    UnloadFont(WindowButtonFont);
    UnloadFont(SuccesMessageFont);


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
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

//------------------------- INSERT WINDOW BUTTONS ------------------------
// Button: insertWindowButton logic
static void InsertWindowButton(char* ch, char* name, char* surname, int matricule)
{
    LOF_fileP fichierLOF;
    char ch1[20], ch2[20];
    strcpy(ch1, ch);
    strcpy(ch2, ch);
    strcat(ch1, ".bin");
    strcat(ch2, ".txt");
    StudentP student = malloc(sizeof(student));
    strcpy(student->name, name);
    strcpy(student->surname, surname);
    student->matricule = matricule;
    student->deleted = 0;
    
    fichierLOF = openLOF(fichierLOF, ch1, 'o');
    insertStudent(fichierLOF, ch1, student);
    extractLOF(fichierLOF, ch1, ch2);
}

//---------------------- ADD WINDOW BUTTONS --------------------------------
// Button: Button007 logic
static StudentP AddWindowButton(char* name, char*surname, int matricule)
{
    StudentP student = malloc(sizeof(student));
    strcpy(student->name, name);
    strcpy(student->surname, surname);
    student->matricule = matricule;
    student->deleted = 0;
    return student;
}

//-------------------------- SEARCH WINDOW BUTTONS --------------------------
// Button: SearchWindowButton logic
static void SearchWindowButton(char* ch, int matricule)
{
    int blockNB, positionNB, exist;
    LOF_fileP fichierLOF;
    char ch1[20];
    strcpy(ch1, ch);
    strcat(ch1, ".bin");
    SearchStudent(fichierLOF, ch1, matricule, &blockNB, &positionNB, &exist);
    if (exist)
        printf("\n\nETUDIANT TROUVE :\nBLOCK : %d\nPOSITION : %d\n\n", blockNB, positionNB);
    else
        printf("\n\nETUDIANT NON TROUVE\n\n");
}

//----------------------- DELETE WINDOW BUTTONS -----------------------------
// Button: DeleteWindowButton logic
static void DeleteWindowButton(char* ch, int matricule)
{
    LOF_fileP fichierLOF;
    char ch1[20], ch2[20];
    strcpy(ch1, ch);
    strcpy(ch2, ch);
    strcat(ch1, ".bin");
    strcat(ch2, ".txt");
    DeleteStudent(fichierLOF, ch1, matricule);
    extractLOF(fichierLOF, ch1, ch2);
}

//---------------------------- MODIFY WINDOW BUTTON -------------------------------
// Button: ModifyButton logic
static void ModifyButton(char* ch, char* name, char* surname, int matricule)
{
    LOF_fileP fichierLOF;
    char ch1[20], ch2[20];
    strcpy(ch1, ch);
    strcpy(ch2, ch);
    strcat(ch1, ".bin");
    strcat(ch2, ".txt");
    StudentP student = malloc(sizeof(student));
    strcpy(student->name, name);
    strcpy(student->surname, surname);
    student->matricule = matricule;
    student->deleted = 0;

    ModifyStudent(fichierLOF, ch1, student);
    extractLOF(fichierLOF, ch1, ch2);
}