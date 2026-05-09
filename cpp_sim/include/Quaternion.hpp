#pragma once
struct Quaternion
{
	double w;
	double x;
	double y;
	double z;

	Quaternion operator*(double s) const { return {w * s, x * s, y * s, z * s}; }
	Quaternion operator+(const Quaternion& q) const { return {w + q.w, x + q.x, y + q.y, z + q.z}; }
};

// Allow scalar on the left: double * Quaternion
inline Quaternion operator*(double s, const Quaternion& q) { return q * s; }

// Provide += to support expressions like `a += b` used in integrator
inline Quaternion& operator+=(Quaternion& a, const Quaternion& b) { a = a + b; return a; }