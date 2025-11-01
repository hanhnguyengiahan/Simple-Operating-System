#include <sos/gen_config.h>
#include "page_swap.h"

#ifdef CONFIG_SOS_FRAME_LIMIT
const size_t PAGES_QUEUE_MAX_SIZE = (CONFIG_SOS_FRAME_LIMIT == 0ul) ? (1 << 19) : CONFIG_SOS_FRAME_LIMIT;
#else
const size_t PAGES_QUEUE_MAX_SIZE = (1 << 19);
#endif

typedef struct pages_queue {
    frame_t* arr[PAGES_QUEUE_MAX_SIZE];
    size_t i;
    size_t j;
} pages_queue_t;

pages_queue_t pages_queue;

SGLIB_DEFINE_QUEUE_FUNCTIONS(pages_queue_t, frame_t*, arr, i, j, PAGES_QUEUE_MAX_SIZE)

frame_t *evict_page() {
    // gets content from current page

    // writes content to pagefile

    // uses seL4_ARM_Page_Unmap to unmap vaddr?
}
