#include "rigid_body.hpp"

State range_kutta_4(const Cubesat& cubesat, double dt) {
	State k1 = derivative(cubesat);
	
	Cubesat temp_cubesat = cubesat;
	// Use Vec3/Quaternion * scalar and explicit addition instead of scalar * Vec3 and +=
	temp_cubesat.current_state.position = temp_cubesat.current_state.position + k1.position * (0.5 * dt);
	temp_cubesat.current_state.velocity = temp_cubesat.current_state.velocity + k1.velocity * (0.5 * dt);
	temp_cubesat.current_state.orientation = temp_cubesat.current_state.orientation + k1.orientation * (0.5 * dt);
	temp_cubesat.current_state.angular_velocity = temp_cubesat.current_state.angular_velocity + k1.angular_velocity * (0.5 * dt);
	State k2 = derivative(temp_cubesat);
	
	temp_cubesat.current_state.position = temp_cubesat.current_state.position + k2.position * (0.5 * dt);
	temp_cubesat.current_state.velocity = temp_cubesat.current_state.velocity + k2.velocity * (0.5 * dt);
	temp_cubesat.current_state.orientation = temp_cubesat.current_state.orientation + k2.orientation * (0.5 * dt);
	temp_cubesat.current_state.angular_velocity = temp_cubesat.current_state.angular_velocity + k2.angular_velocity * (0.5 * dt);
	State k3 = derivative(temp_cubesat);
	
	temp_cubesat.current_state.position = temp_cubesat.current_state.position + k3.position * dt;
	temp_cubesat.current_state.velocity = temp_cubesat.current_state.velocity + k3.velocity * dt;
	temp_cubesat.current_state.orientation = temp_cubesat.current_state.orientation + k3.orientation * dt;
	temp_cubesat.current_state.angular_velocity = temp_cubesat.current_state.angular_velocity + k3.angular_velocity * dt;
	State k4 = derivative(temp_cubesat);
	
	State new_state;
	new_state.position = cubesat.current_state.position + ((k1.position + k2.position * 2.0 + k3.position * 2.0 + k4.position) * (dt / 6.0));
	new_state.velocity = cubesat.current_state.velocity + ((k1.velocity + k2.velocity * 2.0 + k3.velocity * 2.0 + k4.velocity) * (dt / 6.0));
	new_state.orientation = cubesat.current_state.orientation + ((k1.orientation + k2.orientation * 2.0 + k3.orientation * 2.0 + k4.orientation) * (dt / 6.0));
	new_state.angular_velocity = cubesat.current_state.angular_velocity + ((k1.angular_velocity + k2.angular_velocity * 2.0 + k3.angular_velocity * 2.0 + k4.angular_velocity) * (dt / 6.0));
	
	return new_state;
}