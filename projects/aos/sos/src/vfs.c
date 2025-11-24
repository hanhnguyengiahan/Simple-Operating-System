#include <sossharedapi/vfs.h>
#include <stdlib.h>
#include <fcntl.h>
#include <aos/sel4_zf_logif.h>

int init_vfs(vfs_t **vfs) {
    *vfs = malloc(sizeof(vfs_t));
    if (!*vfs) {
        ZF_LOGE("Failed to alloc vfs");
        return -1;
    }
    for (int i = 0; i < PROCESS_MAX_FILES; i++) {
        (*vfs)->fd_table[i].is_opened = false;
        (*vfs)->fd_table[i].path = NULL;
        (*vfs)->fd_table[i].mode = -1;
    }
    (*vfs)->fd_table[CONSOLE_FD].is_opened = true;
    (*vfs)->fd_table[CONSOLE_FD].path = "console";
    (*vfs)->fd_table[CONSOLE_FD].mode = O_WRONLY;
    return 0;
}

void destroy_vfs(vfs_t *vfs) {
    for (int i = 4; i < PROCESS_MAX_FILES; i++) {
        // close all file descriptors
        if (vfs->fd_table[i].is_opened) {
            // TODO: call nfs wrapper for sos_close
        }
    }
    free(vfs);
}
int find_next_fd(vfs_t *vfs) {
    int fd = 4; // reserve 0,1,2 for stdin/out/err and 3 for network_console
    while (vfs->fd_table[fd].is_opened && fd < PROCESS_MAX_FILES) {
        fd += 1;
    }
    return fd;
}