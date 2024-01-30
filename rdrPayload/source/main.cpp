#include "../include/types.h"
#include "../include/enums.h"
#include "../include/vars.h"
#include "../include/lib.h"
#include "../include/offsets.h"
#include "../include/natives.h"
#include "../include/gameFunctions.h"
#include "../include/drawing.h"
#include "../include/utils.h"
#include "../include/functions.h"
#include "../include/sermath.h"
#include "../include/screen.h"
#include "../include/bonehelper.h"

text_info *setTextData;

// CHeat features, config
bool drawPlayerBox = false;
bool shouldDrawNames = false;
bool shouldDrawSkeleton = false;

#define SCREEN_MAX_X 1280
#define SCREEN_MAX_Y 720

fSerVec2 intCoordToFloat(int x, int y) {
    // If the x/y value is bigger than maximum x/y
    // return an empty 2D vector
    if (x > SCREEN_MAX_X || y > SCREEN_MAX_Y)
        return fSerVec2(0, 0);

    // Now we begin to convert the integer version's of the
    // coordinates to their float representations
    fSerVec2 result(
        (double)x / (double)SCREEN_MAX_X,
        (double)y / (double)SCREEN_MAX_Y
    );

    // Return the converted coordinate as a new 2D vector
    return result;
}

// Draws a regular string (non formatted), on the screen
void DrawTextOnScreen(const char *text, fSerVec2 pos, SerCol fg) {
    SET_TEXT_FONT(0);
    SET_TEXT_SCALE_s(0.25f, 0.25f);
    SET_TEXT_COLOR_s(fg.r, fg.g, fg.b, fg.a);
    _BG_DISPLAY_TEXT(
        CREATE_STRING(10, "LITERAL_STRING", text),
        pos.x, pos.y);
}


// NOTE: Number has to be less or equal to 10000!
void DrawNumberOnScreen(fSerVec2 pos, SerCol fg, int intValue) {
    // If the number, exceeds the max size of <10000>
    // then return early...
    if (intValue > 10000) return;

    // Define a buffer that can hold max, 4 characters
    // then format the string using value of <boneNum> 
    char buff[7] = { 0 }; // "00000"
    sprintf(buff, "%d", intValue);

    // Then begin to draw the formatted str on screen
    SET_TEXT_FONT(0);
    SET_TEXT_SCALE_s(0.23f, 0.23f);
    SET_TEXT_COLOR_s(fg.r, fg.g, fg.b, fg.a);
    _BG_DISPLAY_TEXT(
        CREATE_STRING(10, "LITERAL_STRING", buff),
        pos.x, pos.y);
}

// Function to check and toggle drawing settings based on user input
void cheatEnableCheck() {
    // Check if user presses RB + Square...
    // if true then Toggle drawing player box on/off
    if (IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RB) &&
        IS_CONTROL_JUST_RELEASED(0, INPUT_FRONTEND_X))
        drawPlayerBox = !drawPlayerBox;

    // Check if user presses RB + Triangle...
    // if true then Toggle drawing names on/off
    if (IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RB) &&
        IS_CONTROL_JUST_RELEASED(0, INPUT_FRONTEND_Y))
        shouldDrawNames = !shouldDrawNames;

    // Check if user presses RB + Arrow up...
    // if true then Toggle skeleton drawing on/off
    if (IS_DISABLED_CONTROL_PRESSED(0, INPUT_FRONTEND_RB) &&
        IS_CONTROL_JUST_RELEASED(0, INPUT_FRONTEND_UP))
        shouldDrawSkeleton = !shouldDrawSkeleton;

}

#define CalcArrayLen(x) (sizeof(x) / sizeof(x[0]))

// Function to draw the skeleton of the player character on the screen
void draw_player_skeleton() {
    // Get the entity ID of the player character
    Ped playerPed = PLAYER_PED_ID();

    // Check if the player entity exists and if the player is in control
    if (!DOES_ENTITY_EXIST(playerPed) || !IS_PLAYER_CONTROL_ON(PLAYER_ID()))
        return;

    // Array to store 2D screen coordinates for each bone (maximum of 59 bones)
    fSerVec2 boneScreenPos[CalcArrayLen(boneNames)]; // 59

    // Number of bone names, present inside of <boneNames> array (59)
    int totalNames = CalcArrayLen(boneNames);

    // Iterate through each bone name in the array and attempt
    // to obtain the screen coordinates for each bone
    for (int i = 0; i < totalNames; i++) {
        // Call the function get_bone_screen_coord() to get the screen
        // coordinates for the current bone specified by boneNames[i].
        // Save the converted screen coordinates in the current index of boneScreenPos.
        if (get_bone_screen_coord(playerPed, boneNames[i], &boneScreenPos[i])) {
            // Draw the bone number on the screen at the obtained bone coordinates
            DrawNumberOnScreen(
                boneScreenPos[i],          // Screen Coordinate (x, y) of the bone
                SerCol(255, 0, 0, 255),  // Text should be Red
                i);                        // The bone (number) (2 be drawn)
        }
    }
}

void draw_player_name() {
    Ped playerPed = PLAYER_PED_ID();
    // If the Current Player Entity doesn't exist or if it's in cutscene 
    // don't do anything
    if (!DOES_ENTITY_EXIST(playerPed) || !IS_PLAYER_CONTROL_ON(PLAYER_ID()))
        return;

    // Obtain information related to the current player's head and feet bone
    fSerVec2 screenHeadBone;
    if (!get_bone_screen_coord(playerPed, "SKEL_Head", &screenHeadBone))
        return;

    DrawTextOnScreen(
        "LOCALPLAYER",
        fSerVec2(screenHeadBone.x, screenHeadBone.y - 0.03f),
        SerCol(255, 0, 0, 255)
    );
}

void draw_feature_status() {
    // Draw the title, for the area displaying what features are enabled or not
    DrawTextOnScreen("(PS4) RDR2 ESP Menu (coded by a0zhar)", fSerVec2(0.10f, 0.10f), SerCol(255, 255, 255, 255));
    DrawTextOnScreen("====================", fSerVec2(0.10f, 0.13f), SerCol(255, 255, 255, 255));

    // Begin to draw the features, including if they are enabled or disabled
    DrawTextOnScreen(
        shouldDrawNames ? "(RB+TRIANGLE) Names: ON" : "(RB+TRIANGLE) Names: OFF",
        fSerVec2(0.10f, 0.16f),
        shouldDrawNames ? SerCol(0, 255, 0, 255) : SerCol(255, 0, 0, 255)
    );

    DrawTextOnScreen(
        shouldDrawSkeleton ? "(RB+UP) Draw Skeletons: ON" : "(RB+UP) Draw Skeletons: OFF",
        fSerVec2(0.10f, 0.19f),
        shouldDrawSkeleton ? SerCol(0, 255, 0, 255) : SerCol(255, 0, 0, 255)
    );
}


void esp_thread_looping() {
    draw_feature_status();
    if (shouldDrawSkeleton) draw_player_skeleton();
    if (shouldDrawNames)    draw_player_name();
}

extern "C" void _main(void) {
    if (!init) {
        initLibs();
        setTextData = reinterpret_cast<text_info *>(TEXT_INFO_POINTER);
        init = true;
    }

    int FrameCount = GET_FRAME_COUNT();
    if (FrameCount > frameCount) {
        frameCount = FrameCount;
        esp_thread_looping();
        cheatEnableCheck();
    }
}
