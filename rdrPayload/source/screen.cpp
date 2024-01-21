#include "../include/screen.h"
#include "../include/natives.h"

//
// This function is my WorldToScreen Implementation, that uses only Natives
// to achive it's goal.. It will convert the world (x, y, z) coordinates to
// screen (x, y) coordinates, that can be used for ex: drawing esp
// ----
// Return value:
// Upon success (true) will be returned, upon failure (false) will be returned
bool WorldToScreenRel(Vector3 worldOrigin, float *screenX, float *screenY) {
    // Default return value indicating failure
    bool wasSuccess = false;

    float x_result;
    float y_result;
    // Call native function GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD()
    // Returns screen coordinates in [0, 1] for both width and height, with (0, 0) at the top-left of the screen
    if (GET_SCREEN_COORD_FROM_WORLD_COORD(worldOrigin.x, worldOrigin.y, worldOrigin.z, &x_result, &y_result))
        wasSuccess = true;


    // Normalize screen coordinates to the range [-1, 1]
    *screenX = x_result;//(x_result - 0.5f) * 2.0f;
    *screenY = y_result;//(y_result - 0.5f) * 2.0f;

    return wasSuccess;
}

//
// Function gets the world coordinates of the requested bone and converts 
// them to the respective screen coordinates using the world-to-screen 
// implementation.
// ----
// Return value:
// Upon success (true) will be returned, upon failure (false) will be returned
bool get_bone_screen_coord(Player player, const char* boneName, fSerVec2* ScreenCoord) {
    // Bone index
    int boneIndex = GET_ENTITY_BONE_INDEX_BY_NAME(player, boneName);

    // Get the (X, Y, Z) Game World Coordinates for bone
    Vector3 world_bone_coord = GET_WORLD_POSITION_OF_ENTITY_BONE(player, boneIndex);

    // Now we use WorldToScreenRel to convert the world coordinates to screen
    // coordinates that can be used for the ESP feature
    return WorldToScreenRel(world_bone_coord, &ScreenCoord->x, &ScreenCoord->y);
}
