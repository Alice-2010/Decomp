#include "Engine/Classes/CMaterial.h"

extern s32 FUN_8041ec84();
extern void FUN_8000e10c(void*);

void CMaterial::deserialize(void* kfile, uint kfileID)
{
    if (kfileID == 0)
    {
        FUN_8000e10c(kfile);
        FUN_8000e10c(kfile);
    }
    if (kfileID == 0)
    {
        // rest of function
    }
    return;
}
