/************************************************************
 * <bsn.cl v=2014 v=onl>
 * </bsn.cl>
 ************************************************************
 *
 *
 *
 ***********************************************************/
#ifndef __ONLP_SHLOCKS_H__
#define __ONLP_SHLOCKS_H__

#include <onlp/onlp_config.h>
#include <pthread.h>
#include <sys/shm.h>

typedef struct onlp_shlock_s onlp_shlock_t;

/**
 * @brief Create or retreive a shared memory region.
 * @param id The shared memory id.
 * @param size The size of the shared memory region (Only applicable for creation).
 * @param rv [out] Receives the shared memory pointer.
 * @returns 1 if the shared memory was newly created.
 * @returns 0 if the shared memory already existing.
 * @returns < 0 on error.
 */
int onlp_shmem_create(key_t id, uint32_t size, void** rv);


/**
 * @brief Create a shared memory IPC mutex with the given id.
 * @param The shared memory id.
 * @param rv Receives the shared mutex.
 */
int onlp_shlock_create(key_t id, onlp_shlock_t** rv,
                       const char* name, ...);

/**
 * @brief Destroy a shared memory IPC mutex.
 * @param shlock The shared mutex.
 */
int onlp_shlock_destroy(onlp_shlock_t* shlock);

/**
 * @brief Take a shared memory lock.
 * @param shlock The shared lock.
 */
int onlp_shlock_take(onlp_shlock_t* shlock);

/**
 * @brief Give a shared memory lock.
 * @param shlock The shared lock.
 */
int onlp_shlock_give(onlp_shlock_t* shlock);

/**
 * @brief Get a shared lock's name
 * @param lock The lock.
 */
const char* onlp_shlock_name(onlp_shlock_t* lock);


/**
 * A single global lock is always initialized
 * and ready at startup.
 */
#define ONLP_SHLOCK_GLOBAL_KEY 0xF00DF00D

/**
 * @brief Initialize the global lock.
 * @note You don't normally need to call this as
 * it is performed at module initialization time.
 */
void onlp_shlock_global_init(void);

/**
 * @brief Take the global lock.
 */
int onlp_shlock_global_take(void);

/**
 * @brief Give the global lock.
 */
int onlp_shlock_global_give(void);


#endif /* __ONLP_SHLOCKS_H__ */