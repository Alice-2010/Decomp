## Creating Issues

## Decompiling the code
Configure and build the project using the following commands
- `python3 configure.py -v [GAME ID]`
- `ninja`

This will populate the `config/[GAME ID]/splits.txt` and `config/[GAME ID]/symbols.txt`
This will also generate `.s` (assembly) files inside the `build/[GAME ID]/asm` folder
- Each `.s` assembly file here corresponds to 1 file of source code

- Pick a function from one of the assembly files that has not yet been decompiled
- Place the function contents into a new scratch in [decomp.me](https://decomp.me)
- Write C++ code that creates matching assembly code
    - Use the following string as the build flags
    - `-O2,p -lang=c++ -RTTI off -enum int -fp hard -enc SJIS -fp_contract on -str reuse -inline auto -use_lmw_stmw on`
- When placing the function or variable into this repository, mark in a comment the address of the symbol
    - For example `// symbol 0x80395304`

### Submitting PRs (Pull Requests)
If applicable, please note the issue number that the Pull Request is addressing
- Using the `#<issue number>` format