#pragma once
struct Vec3
{
	double x;
	double y;
	double z;

	Vec3 operator*(double s) const { return {x * s, y * s, z * s}; }
	Vec3 operator+(const Vec3& v) const { return {x + v.x, y + v.y, z + v.z}; }
};

// Allow scalar on the left: double * Vec3
inline Vec3 operator*(double s, const Vec3& v) { return v * s; }

// Provide += to support expressions like `a += b` used in integrator
inline Vec3& operator+=(Vec3& a, const Vec3& b) { a = a + b; return a; }