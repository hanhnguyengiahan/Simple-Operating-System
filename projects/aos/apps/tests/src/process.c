#include <sos.h>
#include <assert.h>
#include <tests/macros.h>

#define APP_NAME    "console_test"

int test_process_create_and_destroy() {
    pid_t pid = sos_process_create(APP_NAME);
    assert(pid >= 0);

    int result = sos_process_delete(pid);
    assert(result == 0);
}

int test_process() {
    RUN_TEST(test_process_create_and_destroy);
}