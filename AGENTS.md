# AGENTS.md

Guidance for agents working in this repository.

## Project Overview

NemaTode is a lightweight C++11 NMEA parser and GPS framework. The public API
lives under `include/nmeaparse/`, implementation files live under `src/`, and
`demo_simple.cpp` / `demo_advanced.cpp` are usage examples.

This repository is vendored under `thirdParty`, so keep changes narrow and avoid
large rewrites unless explicitly requested.

## Build and Verification

- Preferred local build:
  - `cmake -S . -B build_lib`
  - `cmake --build build_lib`
- Existing generated build output may already be present in `build/` and
  `build_lib/`. Do not edit generated CMake files by hand.
- There is no dedicated test suite in this checkout. For parser changes, build
  the library and, when useful, temporarily enable or compile the demo programs
  to exercise behavior against the included `nmea_log_*.txt` files.

## Coding Conventions

- Preserve C++11 compatibility.
- Keep public headers in `include/nmeaparse/` and matching implementations in
  `src/`.
- Prefer the existing style: tabs are common for alignment, braces are compact,
  and code uses the `nmea` namespace.
- Avoid introducing external dependencies; the library is currently dependency
  free.
- Keep API changes backward compatible unless the task explicitly requires an
  API break.

## CMake Notes

- `CMakeLists.txt` defines a static `NemaTode` target and installs headers plus
  a CMake package config.
- If source or header files are added or removed, update the `headers` or
  `sources` lists in `CMakeLists.txt`.
- Demo targets are currently commented out. Do not enable them permanently
  unless requested.

## Repository Hygiene

- Do not commit or modify generated build artifacts unless the user asks for
  vendored artifacts to be refreshed.
- Do not revert existing local changes. This checkout may contain user or vendor
  modifications relative to upstream.
- Avoid touching `.DS_Store`, generated CMake cache files, built libraries, or
  Xcode project output unless the requested task specifically involves them.
