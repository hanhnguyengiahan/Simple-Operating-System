#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <utils/time.h>
#include <syscalls.h>
/* Your OS header file */
#include <sos.h>

#define BUF_SIZ    6144
#define MAX_ARGS   32

//========================== OPEN ==========================

int test_open_console() {
    int in = open("console", O_RDONLY);
    assert(in == CONSOLE_FD);

    printf("✅ test_open_console\n");
}

int test_open_non_existent_file() {
    sos_stat_t sbuf;

    int fd = open("new_file.txt", O_RDONLY);
    assert(fd > 0);

    int res = sos_stat("new_file.txt", &sbuf);
    assert(res == 0);

    assert(sbuf.st_type == ST_FILE);
    // Non-existent 
    assert((sbuf.st_fmode & FM_READ) != 0);
    assert((sbuf.st_fmode & FM_WRITE) != 0);
    assert((sbuf.st_fmode & FM_EXEC) == 0);

    printf("✅ test_open_console\n");
}

int test_file_system() {
    test_open_console();
    test_open_non_existent_file();
}



