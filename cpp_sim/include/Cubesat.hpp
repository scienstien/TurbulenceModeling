#pragma once
#include "State.hpp"
struct Cubesat
{    //state of the cubesat at the current and previous time steps
	State current_state;
	State previous_state;

	// Physical properties of the cubesat
	double mass;
	Vec3 inertia; // Assuming a diagonal inertia tensor for simplicity

	// Aerodynamic properties of Drogue parachute
	double Cd; // Drag coefficient
	double area; // Cross-sectional area for drag calculations
	Vec3 r_attach; // Distance from the center of mass to the point of force application

};