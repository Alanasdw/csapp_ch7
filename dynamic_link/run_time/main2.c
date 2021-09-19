
#include <stdio.h>

#include <dlfcn.h>

int x[2] = { 1, 2};
int y[2] = { 3, 4};
int z[2];

int main( void)
{
    void *handle;
    // function pointer that has a void return type
    void (* addvec)( int *, int *, int *, int);
    char *error;

    handle = dlopen("./libvector.so", RTLD_LAZY);
    if ( handle == NULL)
    {
        fprintf( stderr, "%s\n", dlerror());
        exit(1);
    }// if
    
    addvec = dlsym( handle, "addvec");

    if (( error = dlerror()) != NULL)
    {
        fprintf( stderr, "%s\n", error);
        exit(1);
    }// if
    
    addvec( x, y, z, 2);
    printf("z = [ %d %d]\n", z[0], z[1]);

    if ( dlclose( handle) == -1)
    {
        fprintf( stderr, "%s\n", dlerror());
        exit(1);
    }// if
    
    return 0;
}
