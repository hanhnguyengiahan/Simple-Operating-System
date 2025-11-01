#pragma once
#include "frame_table.h"

/*  Evict a page from its allocated frame using the second-chance replacement policy.
    Returns the respective frame for next use.
*/
frame_t *evict_page();

void init_page_swap();