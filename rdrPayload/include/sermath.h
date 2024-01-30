#pragma once
#ifndef SERMATH_HH
#define SERMATH_HH


//
// Used for 2D vector used to store positions, sizes etc.
// Usage examples: 
//  1. iSerVec2 <variable name>(<x>, <y>); 
//  2. iSerVec2(<x>, <y>);
struct iSerVec2 {
    int x;
    int y;

    // Constructor's
    constexpr iSerVec2(): x(0), y(0) {}
    constexpr iSerVec2(int _x, int _y) :
        x(_x), y(_y) {}
};

//
// Used for 2D vector used to store positions, sizes etc.
// Usage examples: 
//  1. iSerVec2 <variable name>(<x>, <y>); 
//  2. iSerVec2(<x>, <y>);
struct fSerVec2 {
    float x;
    float y;

    // Initialization list in the constructor
    constexpr fSerVec2(): x(0.0f), y(0.0f) {}
    constexpr fSerVec2(float _x, float _y) :
        x(_x), y(_y) {}
};

//
// Used for 3D vector used to store positions etc.
struct iSerVec3 {
    int x;
    int y;
    int z;

    // Constructor's
    constexpr iSerVec3(): x(0), y(0), z(0) {}
    constexpr iSerVec3(int _x, int _y, int _z) :
        x(_x), y(_y), z(_z) {}
};

//
// Used for 3D vector used to store positions etc.
struct fSerVec3 {
    float x;
    float y;
    float z;

    // Constructor's
    constexpr fSerVec3(): x(0.f), y(0.f), z(0.f) {}
    constexpr fSerVec3(float _x, float _y, float _z) :
        x(_x), y(_y), z(_z) {}
};

//
// Custom implementation of the Windows (RECT struct)
// Used to handle 2D rectangles (such as the Screen)
//
// NOTE:
// All struct members, are of (+/-) integer type. 
struct iSerRECT {
    int left;   // The X-coordinate of the rectangle's upper-left corner
    int top;    // The Y-coordinate of the rectangle's upper-left corner
    int right;  // The X-coordinate of the rectangle's lower-right corner
    int bottom; // The Y-coordinate of the rectangle's lower-right corner

    // Using Initialization list in the constructors
    constexpr iSerRECT(): left(0), top(0), right(0), bottom(0) {}
    constexpr iSerRECT(int _left, int _top, int _right, int _bottom) :
        left(_left), top(_top), right(_right), bottom(_bottom) {}
};

//
// Custom implementation of the Windows (RECT struct)
// Used to handle 2D rectangles (such as the Screen)
//
// NOTE:
// All struct members, are of (+/-) float type. 
struct fSerRECT {
    float left;   // The X-coordinate of the rectangle's upper-left corner
    float top;    // The Y-coordinate of the rectangle's upper-left corner
    float right;  // The X-coordinate of the rectangle's lower-right corner
    float bottom; // The Y-coordinate of the rectangle's lower-right corner

    // Using Initialization list in the constructors
    constexpr fSerRECT(): left(0.0f), top(0.0f), right(0.0f), bottom(0.0f) {}
    constexpr fSerRECT(float _left, float _top, float _right, float _bottom) :
        left(_left), top(_top), right(_right), bottom(_bottom) {}
};

//
// Custom implementation of the Windows (RECT struct)
// Used to handle 2D rectangles (such as the Screen)
//
// NOTE:
// All struct members, are of (+/-) float type. 
struct fSerBox {
    float x;
    float y;
    float w;
    float h;

    // Using Initialization list in the constructors
    constexpr fSerBox(): x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
    constexpr fSerBox(float _x, float _y, float _w, float _h) :
        x(_x), y(_y), w(_w), h(_h) {}
};



//
// Used for RGB/RGBA colors, originally inspired by the ImColor
// created by ImGui...
struct SerCol {
    int r; // Red
    int g; // Green
    int b; // Blue
    int a; // Alpha (Transparency)

    // Using Initialization list in the constructors   
    constexpr SerCol(): r(0), g(0), b(0), a(255) {}
    constexpr SerCol(int _r, int _g, int _b, int _a = 255) :
        r(_r), g(_g), b(_b), a(_a) {}

    // ------------------------------------
    // Commonly used RGB/RGBA Colors predefined

    static SerCol black(int _a = 255) { return { 0, 0, 0, _a }; }
    static SerCol white(int _a = 255) { return { 255, 255, 255, _a }; }
    static SerCol red(int _a = 255) { return { 255, 0, 0, _a }; }
    static SerCol green(int _a = 255) { return { 0, 255, 0, _a }; }
    static SerCol blue(int _a = 255) { return { 0, 0, 255, _a }; }
};

#endif
