#pragma once
#include <aos/sel4_zf_logif.h>
#include "threads.h"
#include <sossharedapi/process.h>

typedef struct
{
    int thread_index;
    pid_t expected_pid;
    sos_stat_t sos_stat;
    st_type_t st_type;
    int status;
} nfs_stat_cb_args_t;
void nfs_stat_cb(int err, struct nfs_context *nfs, void *data, void *private_data);
int nfs_stat_wrapper(unsigned char *temp_path_buf, nfs_stat_cb_args_t* args);
typedef struct
{
    uint32_t thread_index;
    pid_t expected_pid;
    int bytes_read;
    unsigned char *read_buf;
} nfs_pread_cb_args_t;

void nfs_pread_cb(int status, struct nfs_context *nfs, void *data, void *private_data);

/**
 * A wrapper function to call nfs_pread_async. The function will block the current thread, waiting for `nfs_pread_cb` to finish execution.
 * 
 * @returns 0 on success, -1 otherwise.
 */
int nfs_pread_wrapper(struct nfsfh* fh, nfs_pread_cb_args_t* args, uint64_t offset, uint64_t count);

typedef struct
{
    size_t thread_index;
    pid_t expected_pid;
    int status;
} nfs_close_cb_args_t;
void nfs_close_cb(int status, struct nfs_context *nfs, void *data, void *private_data);
int nfs_close_wrapper(struct nfsfh* fh, nfs_close_cb_args_t* args);