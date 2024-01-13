# Where i'm at currently!!

```c++
//
// iSerVec2: 2D vector used to store positions, sizes etc. 
// Usage examples: 
//  1. iSerVec2 <variable-name>(<x>, <y>); 
//  2. iSerVec2(<x>, <y>);
// -----
// SRC: ImVec2 from ImGUI repository on GitHub
struct iSerVec2 {
    int x;
    int y;

    // Constructor's
    constexpr iSerVec2(): x(0), y(0) {}
    constexpr iSerVec2(int _x, int _y) :
        x(_x), y(_y) {}
};

//
// fSerVec2: 2D vector used to store positions, sizes, etc.
// Usage examples: 
//  1. fSerVec <variable-name>(<x>, <y>); 
//  2. fSerVec(<x>, <y>);
// -----
// SRC: ImVec2 from ImGUI repository on GitHub
struct fSerVec2 {
    float x;
    float y;

    // Initialization list in the constructor
    constexpr fSerVec2(): x(0.0f), y(0.0f) {}
    constexpr fSerVec2(float _x, float _y) :
        x(_x), y(_y) {}
};

// Function used for converting World Coordinates to Screen Coordinates
int WorldToScreenCoordinate(Vector3 worldcoord, float* screenX, float* screenY) {
    // Default return value indicating failure
    int wasSuccess = 0;

    // Call native function GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD()
    // Returns screen coordinates in [0, 1] for both width and height, with (0, 0) at the top-left of the screen
    if (GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(worldcoord.x, worldcoord.y, worldcoord.z, screenX, screenY)) {

        // Normalize screen coordinates to the range [-1, 1]
        *screenX = (*screenX - 0.5f) * 2.0f;
        *screenY = (*screenY - 0.5f) * 2.0f;

        // Set the value of wasSuccess to indicate success
        wasSuccess = 1;
    }

    // Return the value of <wasSuccess> which depending on 
    // whether the function failed or not is either 0 or 1
    return wasSuccess;
}

```
