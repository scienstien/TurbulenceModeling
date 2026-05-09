# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

**Build (Debug x64):**
```
msbuild cpp_sim.slnx /p:Configuration=Debug /p:Platform=x64
```

**Run:**
```
cpp_sim\x64\Debug\cpp_sim.exe
```

**Configurations:** Debug/Release, x64/Win32

**Compiler:** MSVC v145, C++20, SDL checks enabled

## Architecture

C++20 Windows application simulating CubeSat 6-DOF dynamics. Organized by subsystem:

### Core Data Types (Foundation Layer)
- **Vec3** - 3D vector with x,y,z components; operators: `*`, `+`, `+=` (scalar/vector)
- **Quaternion** - Attitude representation with w,x,y,z components; operators: `*`, `+`, `+=`
- **State** - Complete state vector: position, velocity, orientation, angular_velocity
- **Cubesat** - Vehicle container: mass, inertia, Cd, area, force attachment point

### Physics & Integration
- **rigid_body** - Rigid body dynamics (derivative computation)
- **integrator** - RK4 numerical integration (`range_kutta_4`)
- **forces** - External force calculations (drag, gravity, etc.) - *placeholder*
- **dryden** - Dryden wind turbulence model - *placeholder*

### Infrastructure
- **simulator** - Main simulation loop orchestration
- **logger** - Logging/telemetry infrastructure - *placeholder*

All code under `cpp_sim/` with headers in `include/` and sources in `src/`.

## Module Dependency Graph

```
Vec3.hpp ─┐
          ├─→ State.hpp ─→ Cubesat.hpp ─┬─→ rigid_body.hpp ─→ integrator.hpp
Quaternion┘                            └─→ simulator.hpp
```

## Key Functions

| Function | Location | Description |
|----------|----------|-------------|
| `derivative(const Cubesat&)` | rigid_body.cpp | Computes state time derivatives |
| `range_kutta_4(const Cubesat&, double dt)` | integrator.cpp | RK4 time stepping |
| `run_simulation(Cubesat&, duration, dt)` | simulator.cpp | Main simulation loop |

## Coding Conventions

- **Headers**: `#pragma once` guards
- **Naming**: PascalCase structs, snake_case functions/members
- **Design**: POD structs with free functions (no member methods except operators)
- **Passing**: `const&` for Cubesat, value returns for State
- **Math**: Operator overloads enable algebraic expressions (`dt * state.position`)

## Implementation Status

| Module | Status |
|--------|--------|
| Vec3/Quaternion operators | Complete |
| State/Cubesat structs | Complete |
| RK4 integrator | Complete |
| Rigid body derivative | Placeholder (gravity only) |
| Forces (drag, aerodynamics) | Not implemented |
| Dryden turbulence | Not implemented |
| Logger | Not implemented |
| main.cpp integration | Stub (Hello World) |

## Extension Points

- Add forces in `forces.cpp`: drag, lift, thrust, perturbations
- Add torques in `rigid_body.cpp`: aerodynamic, gravity gradient, control
- Implement Dryden model in `dryden.cpp` for atmospheric turbulence
- Add logging calls in `simulator.cpp` for telemetry output
