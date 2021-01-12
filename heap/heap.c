#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

static void _swap_(int32_t *num1, int32_t *num2){
  int32_t temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}


static void _heapify_(int32_t data[], uint32_t len, uint32_t parent) {
   assert(len > 0 && len < HEAP_MAX_SIZE && parent > 0);

   uint32_t child = 2 * parent;

   while (child <= len) {
      if(child + 1 <= len){
           if(data[child + 1] > data[child]){
              ++child;
        }
      }
      if(data[parent] >= data[child]){
           break;
      }
      _swap_(&data[parent], &data[child]);
      parent = child;
      child = 2 * parent;

  }
}

static void _test_heap_(int32_t data[], uint32_t len){
       for(uint32_t child = len; child > 1; --child){
         assert(data[child] <= data[child/2]);
   }
}


Heap heap_new(int32_t data[], uint32_t len) {
   assert(len > 0 && len < HEAP_MAX_SIZE);

   Heap heap;

   for (uint32_t idx = len / 2; idx > 0; --idx){
      _heapify_(data, len, idx);
   }
   heap.size = len;
   memcpy(heap.data, data, (len+1) * sizeof(int32_t));
   _test_heap_(heap.data, heap.size);

   return heap;
}


Heap* heap_sort(Heap *heap){

    assert(heap->size > 0 && heap->size < HEAP_MAX_SIZE);

    uint32_t idx = heap->size;

    for(idx = heap->size; idx > 1; --idx){
      _swap_(&heap->data[idx], &heap->data[1]);
      _heapify_(heap->data, idx - 1, 1);
   }


   return heap;
}


uint32_t heap_size(Heap *heap){
   assert(heap != NULL);

   return heap->size;
}

Heap* heap_insert(Heap *heap, int32_t key){
   assert(heap != NULL && heap->size > 0);
   heap->data[++heap->size] = key;

   // O(nlogn)
   //for (uint32_t idx = heap->size / 2; idx > 0; --idx){
   //   _heapify_(heap->data, heap->size, idx);
   //}

   // O(logn)
   for(int32_t idx = heap->size; idx > 1; idx = idx / 2){
       if(heap->data[idx] < heap->data[idx / 2]){
          break;
       } else {
          _swap_(&heap->data[idx], &heap->data[idx / 2]);
       }
   }

   return heap;

}

int8_t heap_test(Heap *heap){
   assert(heap != NULL && heap->size > 0);

   for(uint32_t child = heap->size; child > 1; --child){
         if(heap->data[child] > heap->data[child/2]){
           return 0;
         }
   }

   return 1;
}

int32_t heap_get_max(Heap *heap){
   assert(heap != NULL && heap->size > 0);

   return heap->data[1];
}

int32_t heap_extract_max(Heap *heap){
   assert(heap != NULL && heap->size > 0);

   int32_t max;
   max = heap->data[1];
   _swap_(&heap->data[heap->size], &heap->data[1]);
   heap->data[heap->size] = 0;
   --heap->size;

   for (uint32_t idx = (heap->size -1) / 2; idx > 0; --idx){
      _heapify_(heap->data, heap->size, idx);
   }

   return max;
}
