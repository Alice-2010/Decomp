# Contributing
## Ghidra
- Server connection details can be found at [ghidra.decomp.dev](https://ghidra.decomp.dev)

### Ghidra MCP
- Install Ghidra Extension [GhidraMCP by LaurieWired](github.com/LaurieWired/GhidraMCP), enable it and restart Ghidra
- Install VSCode Extension [konekotech.ghidramcp](https://marketplace.visualstudio.com/items?itemName=konekotech.ghidramcp)
- Configure VSCode Extension (`.vscode/settings.json`)
    - Set bridge script path, e.g: `"ghidramcp.bridgeScriptPath": "/path/to/Alice-Decomp/tools/ghidra_scripts/bridge_mcp_ghidra.py"`
    - Optionally set a virtual env path e.g: `"ghidramcp.venvPath": "/path/to/Alice-Decomp/.venv"`
- In VSCode Command Palette, run `Start Ghidra Server`
- Connect VSCode integrated agent (e.g: Github Copilot) to the MCP server `http://127.0.0.1:8081/sse`

## Decompiling
- Configure and build the project using the following commands
    - `python3 configure.py -v [GAME ID]`
    - `ninja`
- Write C++ code that creates matching assembly code
    - Use the following string as the build flags
    - Compiler `Wii MW 1.0RC1`
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
