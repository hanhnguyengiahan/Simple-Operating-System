#include <sossharedapi/vfs.h>

void vfs_init(void) {
    memset(&vfs, 0, sizeof(vfs_t));

    // Optional: mark 0, 1, 2 as "open" for terminal device
    vfs.sos_fd_table[0].is_opened = true;
    vfs.sos_fd_table[1].is_opened = true;
    vfs.sos_fd_table[2].is_opened = true;
    vfs.sos_fd_table[0].path = strdup("stdin");
    vfs.sos_fd_table[1].path = strdup("stdout");
    vfs.sos_fd_table[2].path = strdup("stderr");
}

int find_next_fd() {
    int fd = 4; // reserve 0,1,2 for stdin/out/err and 3 for network_console
    while (vfs.sos_fd_table[fd].is_opened && fd < MAX_NUM_FILES) {
        fd += 1;
    }
    return fd;
}