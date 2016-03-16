#include "array.h"
#include "heap.h"


/**
 * Initializes the fields of the HeapConf struct to default values.
 *
 * @param[in, out] conf the configuration object that is being initialized
 */
void heap_conf_init(HeapConf *conf)
{
	array_conf_init(conf);
}

/**
 * Returns a new empty heap, or NULL if the space allocation fails.
 *
 * @return a new empty heap, or NULL.
 */
Heap *heap_new()
{
    HeapConf conf;
    heap_conf_init(&conf);
    return heap_new_conf(&conf);
}

/**
 * Returns a new empty heap based on the HeapConf struct.
 *
 * The heap is allocated using the allocators specified in the HeapConf
 * struct. The allocation may fail if the undlying allocator fails.
 *
 * @param[in] conf the heap configuration
 *
 * @return a new empty heap, or NULL if the allocation fails
 */
Heap *heap_new_conf(HeapConf *conf)
{
	Heap *h       = conf->mem_calloc(1, sizeof(Heap));
	h->v          = array_new_conf(conf);

	h->mem_alloc  = conf->mem_alloc;
	h->mem_calloc = conf->mem_calloc;
	h->mem_free   = conf->mem_free;

	return h;
}

/**
 * Destroys the specified heap structure, while leaving the data it holds
 * intact.
 *
 * @param[in] heap the heap to be destroyed
 */
void heap_destroy(Heap *heap)
{
	array_destroy(heap->v);
	heap->mem_free(heap);
}

/**
 * Destroys the specified heap structure along with all the data it holds.
 *
 * @param[in] heap the heap to be destroyed
 */
void heap_destroy_free(Heap *heap)
{
	array_destroy_free(heap->v);
	free(heap);
}

/**
 * Adds an element to the heap.
 *
 * @param[in] heap the heap in which the element is to be added
 * @param[in] element the element which is supposed to be added
 */
bool heap_insert(Heap *heap, void *element)
{
	size_t pos = array_size(heap->v) + 1;
	
	for(; pos > 1; pos = pos/2 )
		if(element > array_get(heap->v, pos/2))
			if(!array_add_at(heap->v, array_get(heap->v, pos/2), pos))
				return false;

	if(pos > array_capacity(heap->v))
	       	return array_add(heap->v, element);
			
	return array_add_at(heap->v, element, pos);
}

/**
 * A heap foreach loop function that invokes the specified function on
 * each element of the heap.
 *
 * @param[in] heap the heap on which this operation being performed
 * @param[in] op the operation function that is to be invoked on each
 *            element of the heap
 */
void heap_foreach(Heap *heap, void (*op) (void *))
{
	array_foreach(heap->v, op);
}
