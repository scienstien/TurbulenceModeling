//derivative function for rigid body dynamics
#include "rigid_body.hpp"
#include "State.hpp"
#include "Cubesat.hpp"
#include "Vec3.hpp"
#include "Quaternion.hpp"
Vec3 gravity = { 0, 0, -9.81 }; // Gravitational acceleration vector
State derivative(const Cubesat& cubesat) {
	Vec3 position_dot = cubesat.current_state.velocity;
	Vec3 velocity_dot = gravity; // Assuming only gravity acts on the cubesat
	Quaternion orientation_dot = { 0,0,0,0 };
	Vec3 omega_dot = { 0,0,0 };
	return { position_dot, velocity_dot, orientation_dot, omega_dot };
}
