# Contributing
## Ghidra
- Server connection details can be found at [ghidra.decomp.dev](https://ghidra.decomp.dev)

## Decompiling
- Configure and build the project using the following commands
    - `python3 configure.py -v [GAME ID]`
    - `ninja`
- Write C++ code that creates matching assembly code
    - Use the following string as the build flags
    - Compiler `4.3 build 188 (Wii MW 1.5)`
    - `-O4,s -lang=c++ -RTTI off -enum int -fp hard -enc SJIS -fp_contract on -str reuse -inline auto -use_lmw_stmw on`
- While decompiling, please try to self document functions or variables, including information like
    - Game ID
    - Symbol Address
    - Symbol Size
- The Ghidra Repository contains a game named `XXL2`
    - This game is a Remaster of another one of the developers games using the same engine
    - This binary contains DWARF information and was compiled for x86_64 Mach-O
        - This debug information will not be exactly the same as Alice

### Submitting PRs (Pull Requests)
- Submitting changes via Pull Request are mandatory
    - This will display changes to matched code via the [decomp.dev](https://decomp.dev) Github Bot
    - It also ensures only code that builds correctly is merged to the master branch
