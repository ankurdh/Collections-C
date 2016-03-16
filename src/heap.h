#ifndef HEAP_H_
#define HEAP_H_

#include "common.h"
#include "array.h"

/**
 *   A Priority Queue implementation with a min heap
 */
typedef struct heap_s {
	Array *v;
	    
	void *(*mem_alloc)  (size_t size);
	void *(*mem_calloc) (size_t blocks, size_t size);
	void  (*mem_free)   (void *block);
} Heap;

typedef ArrayConf HeapConf;

void    heap_conf_init   (HeapConf *conf);

Heap   *heap_new         (void);
Heap   *heap_new_conf    (HeapConf *conf);
void    heap_destroy     (Heap *heap);
void    heap_destroy_free(Heap *heap);

bool    heap_insert        (Heap *heap, void *element);
void   *heap_delete       (Heap *heap);

size_t  heap_size        (Heap *heap);

void    heap_foreach     (Heap *heap, void (*op) (void *));

#endif /* HEAP_H_ */
