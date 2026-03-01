//
// Created by berke on 3/1/2026.
//

#ifndef PLATFORMER_MAKER_VECTOR_H
#define PLATFORMER_MAKER_VECTOR_H
#include <cmath>

struct Vector2 {
    float x, y;
    Vector2(const float x=0, const float y=0) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    Vector2 operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
    Vector2 operator/(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }

    Vector2 operator +=(const Vector2& other) { x += other.x; y += other.y; return *this; }
    Vector2 operator -=(const Vector2& other) { x -= other.x; y -= other.y; return *this; }
    Vector2 operator *=(const Vector2& other) { x *= other.x; y *= other.y; return *this; }
    Vector2 operator /=(const Vector2& other) { x /= other.x; y /= other.y; return *this; }

    bool operator==(const Vector2& other) const { return x == other.x && y == other.y; }
    bool operator!=(const Vector2& other) const { return x != other.x || y != other.y; }

    [[nodiscard]] float length() const {return std::sqrt(x*x + y*y);}
};

#endif //PLATFORMER_MAKER_VECTOR_H