# Repository Purpose

This repository contains the decompilation of Alice in Wonderland, released in March 2010, for the Nintendo Wii.

## Goals

- Byte match the decompilation to the original game, where possible.

## When analysing code

- Make use of Ghidra, and use it as the single point of truth.

## When writing code

- View the diff between the compiled and original game assembly for a given function
    - Use `./build/tools/objdiff-cli.exe diff -1 ./build/<GAME VERSION ID>/src/<path/to/compiled>.o -2 ./build/<GAME VERSION ID>/obj/<path/to/original>.o <SYMBOL NAME>`

## Compiling the decompiled source code

- Update ninja script with new config - `python configure.py [-v {GAME_ID:~SALP4Q}]`
  - If no GAME_ID is provided, it defaults to `SALP4Q` (PAL release)
- Build and compile the project - `ninja`
- Diff compiled ELF file - `ninja diff`
- Apply symbols.txt updates - `ninja apply`
- Output current project progress - `ninja progress`

## Resources

- GameCube & Wii TU Splitting Guide - https://celestialamber.github.io/GC-Wii-Decomp-Splitting-Guide
