#include "../threads.h"
int handle_sos_my_id() {
    return current_thread->assigned_pid;
}