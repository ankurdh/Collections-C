#include "../src/heap.h"
#include "test.h"
#include "../src/array.h"

void test_heap_insert();

int main(int argc, char **argv)
{

	test_heap_insert();
	return cc_get_status();
}

void print_val(void *val)
{
	printf("%d ", *(int*)val);
}

void test_heap_insert()
{
	printf("Hello World\n");
	Heap *heap = heap_new();

	int a = 1, b = 2, c = 3, d = 9, e = 5;

	heap_insert(heap, &a);
	heap_foreach(heap, print_val);
	printf("\n");

	heap_insert(heap, &d);
	heap_foreach(heap, print_val);
	printf("\n");

	heap_insert(heap, &e);
	heap_foreach(heap, print_val);
	printf("\n");

	heap_insert(heap, &b);
	heap_foreach(heap, print_val);
	printf("\n");

	heap_insert(heap, &c);
	heap_foreach(heap, print_val);
	printf("\n");

	//cc_assert(*(int *)array_get(heap->v, 2) == c, cc_msg("stack_pop: Top stack element not as expected"));

}
