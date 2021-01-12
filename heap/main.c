#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "heap.h"

void test_newheap(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);
}

void test_sort(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   heap = heap_sort(heap);
   assert(heap->data[1] == 5);
   assert(heap->data[10] == 90);

}

void test_insert(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);


   heap = heap_insert(heap, 50);
   assert(heap_test(heap) == 1);


   heap = heap_insert(heap, 100);
   assert(heap_test(heap) == 1);

}

void test_heap_test(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);
   assert(heap_test(heap) == 1);
}

void test_get_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   assert(heap_get_max(heap) == 90);

}

void test_heap_extract_max(){
   int32_t data[] = {0, 10, 19, 39, 40, 90, 70, 64, 26, 5, 80};
   Heap h1 = heap_new(data, 10);
   Heap *heap = &h1;

   assert(heap_size(heap) == 10);

   assert(heap_extract_max(heap) == 90);

}

int main(){
   test_newheap();
   test_sort();
   test_insert();
   test_heap_test();
   test_get_max();
   test_heap_extract_max();

   return 0;
}
