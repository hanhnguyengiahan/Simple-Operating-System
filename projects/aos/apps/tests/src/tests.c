#include <stdio.h>
#include <tests/file_system.h>
#include <tests/vm.h>

int main(void) {
    printf("❗❗Running SOS test suite...❗❗\n");
    test_file_system();
    test_virtual_memory();
    return 0;
}