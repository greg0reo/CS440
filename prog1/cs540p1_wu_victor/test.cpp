/** Snippet test file taken from Dr. Kenneth Chiu's Assignment 1 test file. Testing only certain and limited functionality for partial points. */


#include <dlfcn.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <random>
#include <unistd.h>
#include "Deque.hpp"

bool int_less( int o1, int o2) {
    return o1 < o2;
}
Deque_DEFINE(int)

int main() {  
   printf("Testing\n");
   Deque_int deq;
   Deque_int_ctor(&deq, int_less);    
   assert(deq.size(&deq) == 0);
   assert(deq.empty(&deq));
   printf("---- %s, %d\n", deq.type_name, int(sizeof(deq.type_name)));
   deq.push_back(&deq, 1);
   deq.push_back(&deq, 2);
   deq.push_back(&deq, 3);
   deq.push_front(&deq, 0);
   deq.push_front(&deq, -1);

   printf("%d\n", deq.front(&deq));
   printf("%d\n", deq.back(&deq));
   assert(deq.front(&deq) == -1);
   assert(deq.back(&deq) == 3);

   deq.pop_front(&deq);
   deq.pop_back(&deq);
   printf("%d\n", deq.front(&deq));
   printf("%d\n", deq.back(&deq)); 
   assert(deq.front(&deq) == 0);
   assert(deq.back(&deq) == 2);
   assert(deq.size(&deq) == 3);
}
