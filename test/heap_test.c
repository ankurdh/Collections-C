#include "../src/heap.h"
#include "test.h"
#include <string.h>

void test_heap_insert();
void test_heap_pop();

int main(int argc, char **argv)
{
	cc_set_exit_on_failure(false);

	test_heap_insert();
	
	return cc_get_status();
}

void test_heap_insert()
{
	Heap *heap = heap_new();

	int a = 1, b = 2, c = 3;

	heap_insert(heap, &a);
	heap_insert(heap, &b);
	heap_insert(heap, &c);

}
