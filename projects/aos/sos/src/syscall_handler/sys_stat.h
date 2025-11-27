#pragma once
#include <stdint.h>
#include <sossharedapi/vfs.h>
#include <sel4/shared_types_gen.h>
#include <aos/sel4_zf_logif.h>
#include <sossharedapi/process.h>

/**
 * @brief Handles the sos_stat syscall for a user process.
 *
 * Copies the file path from user memory, performs an asynchronous NFS stat
 * operation (or handles special paths like "console"), waits for completion,
 * and writes the resulting file status structure back to user memory.
 *
 * @return 0 on success, or -1 on failure.
 */
int handle_sos_stat();
