
#include <stdio.h>

#if defined(COMPILETIME)

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

#elif defined(LINKTIME)

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


#elif defined(RUNTIME)

// this is for RTLD_NEXT
// #define _GNU_SOURCE
// it does not work inside file?????

// don't use printf since it uses malloc

#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>
#include <unistd.h>

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

    
    char *ptr = mallocp( size);
    char buff[100];
    sprintf( buff, "malloc(%d) = %p\n", ( int)size, ptr);
    write( STDOUT_FILENO, buff, strlen( buff));

    return ptr;
}


void free( void *ptr)
{
    void (* freep)( void *);
    char *error;

    freep = dlsym( RTLD_NEXT, "free");
    if (( error = dlerror()) != NULL)
    {
        fputs( error, stderr);
        exit(1);
    }// if
    
    freep( ptr);
    char buff[100];
    sprintf( buff, "free(%p)\n", ptr);
    write( STDOUT_FILENO, buff, strlen( buff));

    return;
}

#endif
