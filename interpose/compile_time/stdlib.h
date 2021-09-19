
#pragma once

#define malloc(size) mymalloc(size)
#define free(ptr) myfree(ptr)

#include <stddef.h>

void *mymalloc( size_t size);
void myfree( void *ptr);
