#pragma once
#include "Cubesat.hpp"
#include "State.hpp"

State range_kutta_4(const Cubesat& cubesat, double dt);