import json
import subprocess
import os

os.chdir(r"D:\Users\Andrew Craig\Documents\coding\Alice-Decomp")
syms = [
    "__ct__19IKLoadingInterfacesFv",
    "__dt__19IKLoadingInterfacesFv",
    "IsKindOfClass__19IKLoadingInterfacesFUl",
    "IsKindOfClass__16CKLoadingManagerFUl",
    "GetLevelNumber__16CKLoadingManagerFv",
]
for sym in syms:
    p = subprocess.run(
        [
            "./build/tools/objdiff-cli.exe",
            "diff",
            "-1",
            "./build/SALP4Q/src/K/KCore/Serialization/CKLoadingManager.o",
            "-2",
            "./build/SALP4Q/obj/K/KCore/Serialization/CKLoadingManager.o",
            "-o",
            "-",
            "--format",
            "json",
            sym,
        ],
        capture_output=True,
        text=True,
    )
    if p.returncode != 0:
        print(sym, "FAILED", p.stderr[:200])
        continue
    d = json.loads(p.stdout)
    hit = next((s for s in d["left"]["symbols"] if s.get("name") == sym), None)
    if hit is None:
        print(sym, "missing in left")
    else:
        print(f"{sym}: {hit.get('match_percent')}% size={hit.get('size')}")
