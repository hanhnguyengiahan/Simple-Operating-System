#include <tests/vm.h>
#include <utils/page.h>
#include <tests/macros.h>

#define NBLOCKS 9
#define NPAGES_PER_BLOCK 28
#define TEST_ADDRESS 0x8000000000

/* called from pt_test */
static void
do_pt_test(char **buf)
{
    int i;

    /* set */
    for (int b = 0; b < NBLOCKS; b++) {
        for (int p = 0; p < NPAGES_PER_BLOCK; p++) {
          buf[b][p * PAGE_SIZE_4K] = p;
        }
    }

    /* check */
    for (int b = 0; b < NBLOCKS; b++) {
        for (int p = 0; p < NPAGES_PER_BLOCK; p++) {
          assert(buf[b][p * PAGE_SIZE_4K] == p);
        }
    }
}

static void stack_test() {
     /* need a decent sized stack */
    char buf1[NBLOCKS][NPAGES_PER_BLOCK * PAGE_SIZE_4K];
    char *buf1_ptrs[NBLOCKS];

    /* check the stack is above phys mem */
    for (int b = 0; b < NBLOCKS; b++) {
        buf1_ptrs[b] = buf1[b];
    }
    assert((void *) buf1 > (void *) TEST_ADDRESS);

    // /* stack test */
    do_pt_test(buf1_ptrs);
}

static void heap_test() {
    char *buf2[NBLOCKS];

    // /* heap test */
    for (int b = 0; b < NBLOCKS; b++) {
        buf2[b] = malloc(NPAGES_PER_BLOCK * PAGE_SIZE_4K);
        assert(buf2[b]);
    }
    do_pt_test(buf2);
    for (int b = 0; b < NBLOCKS; b++) {
        free(buf2[b]);
    }
}

void test_virtual_memory()
{
    printf("==========VIRTUAL MEMORY============\n");
    RUN_TEST(stack_test);
    RUN_TEST(heap_test);

    printf("Virtual memory test\tPassed\n");
}