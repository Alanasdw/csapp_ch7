
#include <stdio.h>

#ifdef COMPILETIME

#include <stdlib.h>

void *mymalloc( size_t size)
{
    void *ptr = malloc( size);
    printf("malloc( %d) = %p\n", ( int)size, ptr);
    return ptr;
}

void myfree( void *ptr)
{
    free(ptr);
    printf("free(%p)\n", ptr);
    return;
}

#elif LINKTIME

void *__real_malloc( size_t size);
void __real_free( void *ptr);

void *__wrap_malloc( size_t size)
{
    void *ptr = __real_malloc( size);
    printf("malloc( %d) = %p\n", ( int)size, ptr);
    return ptr;
}

void __wrap_free( void *ptr)
{
    __real_free(ptr);
    printf("free(%p)\n", ptr);
    return;
}


#elif RUNTIME

#include <stdlib.h>
#include <dlfcn.h>

void *malloc( size_t size)
{
    void *( * mallocp)( size_t);
    char *error;

    mallocp = dlsym( RTLD_NEXT, "malloc");
    if (( error = dlerror()) != NULL)
    {
        fputs( error, stderr);
        exit(1);
    }// if
    
    void *ptr = mallocp( size);
    printf("malloc(%d) = %p\n", ( int)size, ptr);
    return ptr;
}


void free( void *ptr)
{
    void *( freep)( void *);
    char *error;

    freep = dlsym( RTLD_NEXT, "free");
    if (( error = dlerror()) != NULL)
    {
        fputs( error, stderr);
        exit(1);
    }// if
    
    freep( ptr);
    printf("free(%p)\n", ptr);
    return;
}

#endif
