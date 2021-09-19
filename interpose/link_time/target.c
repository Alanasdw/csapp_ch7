
#include <stdio.h>
#include <stdlib.h>

int main( void)
{
    int *p = ( int *)malloc( sizeof( int));
    free( p);
    return 0;
}
