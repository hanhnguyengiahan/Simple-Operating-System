int handle_sos_process_wait() {
    int pid = seL4_GetMR(1);

    if (pid == -1) {
        /* choose a pid whose process is still running */
    }
}