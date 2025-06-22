#include "Revolution/OS.h" // IWYU pragma: export

void __OSModuleInit(void) {
    OS_FIRST_REL = OS_LAST_REL = NULL;
    OS_REL_NAME_TABLE = NULL;
}
