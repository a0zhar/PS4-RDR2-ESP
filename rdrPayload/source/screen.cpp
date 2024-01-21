#include "../include/screen.h"
#include "../include/natives.h"


// Function used for converting World Coordinates to Screen Coordinates
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

    // Return the value of <wasSuccess> which depending on 
    // whether the function failed or not is either 0 or 1
    return wasSuccess;
}
bool get_bone_screen_coord(Player player, const char *boneName, fSerVec2 *ScreenCoord) {
    Vector3 world_bone_coord;
    int boneIndex = -1;

    // Bone index
    boneIndex = GET_ENTITY_BONE_INDEX_BY_NAME(player, boneName);

    // Get the (X, Y, Z) Game World Coordinates for bone   
    world_bone_coord = GET_WORLD_POSITION_OF_ENTITY_BONE(player, boneIndex);

    // Now we use WorldToScreenRel to convert the world coordinates to screen
    // coordinates that can be used for esp feature
    if (!WorldToScreenRel(world_bone_coord, &ScreenCoord->x, &ScreenCoord->y))
        return false;

    return true;
}