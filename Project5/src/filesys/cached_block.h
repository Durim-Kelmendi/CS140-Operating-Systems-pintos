#ifndef PROJECT5_CACHE_H
#define PROJECT5_CACHE_H
#include "../devices/block.h"
#include "../threads/synch.h"
#include "../threads/gio_synch.h"
#include "../lib/packed.h"

#define SECTOR_NUM (8 * 1024 * 1024 / BLOCK_SECTOR_SIZE)

struct cache_entry{
    char data[BLOCK_SECTOR_SIZE];
    struct lock lock;
    int holder;
    uint16_t dirty;
    uint16_t accessed;
}PACKED;

struct cached_block{
    struct block *block;
    int buffer_len;
    struct cache_entry *entries;
    int8_t *addr;
    struct rw_lock *locks;
}PACKED;

void fflush_all(struct cached_block *cache);
struct cached_block *cached_block_init(struct block *block, int buffer_elem);
void cached_block_read_segment(struct cached_block *cache, block_sector_t sector, int s, int e, void *buffer, int info);
void cached_block_read(struct cached_block *cache, block_sector_t sector, void *buffer, int info);

void cached_block_write_segment(struct cached_block *cache, block_sector_t sector, int s, int e,
                                const void *buffer, const void *full_buffer, int info);
void cached_block_write(struct cached_block *cache, block_sector_t sector, const void *buffer, int info);

block_sector_t cached_block_size (struct cached_block *cache);
#endif //PROJECT5_CACHE_H
