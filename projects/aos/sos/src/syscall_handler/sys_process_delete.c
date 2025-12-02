#include "../user_process.h"
#include "sys_process_delete.h"

int handle_sos_process_delete() {
    int pid = seL4_GetMR(1);
    // printf("handle_sos_proc_delete: %d\n", pid);

    return delete_user_process(pid);
}