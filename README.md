# TurbulenceModeling

This folder serve as the root direcctory of the entire project. The cpp based simulation will be handled in cpp_sim and later down the line we will add folders for python based physics surrogate model and the C# based Unity visualiser, with each getting a separate folder.

## Repository Layout

```text
TurbulenceModeling/
  CLAUDE.md
  CMakeLists.txt
  cpp_sim/
    CMakeLists.txt
    include/
    src/
```

## Build

From the repository root:

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

The `cpp_sim` target is defined inside the `cpp_sim/` subproject and built through the root CMake entry point.
