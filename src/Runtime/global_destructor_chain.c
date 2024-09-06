#include "global.h"
#include "Runtime.PPCEABI.H/global_destructor_chain.h"

void __destroy_global_chain(void)
{

}

/* clang-format off */
DECL_SECTION(".dtors")
static void* const __destroy_global_chain_reference = __destroy_global_chain;
/* clang-format on */
