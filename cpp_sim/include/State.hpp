#pragma once
#include "Vec3.hpp"
#include "Quaternion.hpp"
struct State
{
	Vec3 position;
	Vec3 velocity;
	Quaternion orientation;
	Vec3 angular_velocity;
};
