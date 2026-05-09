#include "integrator.hpp"
#include "rigid_body.hpp"
#include "Cubesat.hpp"
#include "State.hpp"


// Run the simulation for a given cubesat instance
namespace Simulator {
    void run_simulation(Cubesat &cubesat, double duration = 10.0, double dt = 0.01) {
        double t = 0.0; // Simulation time
        while (t < duration) { // Simulate for `duration` seconds
            // Update the cubesat's state using the Runge-Kutta 4 integrator
            cubesat.current_state = range_kutta_4(cubesat, dt);

            // Update previous state for the next iteration
            cubesat.previous_state = cubesat.current_state;

            // Increment time
            t += dt;
        }
    }
}