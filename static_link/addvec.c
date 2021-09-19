
int addcnt = 0;

void addvec( int *x, int*y, int*z, int n)
{
    int i;
    addcnt += 1;

    for ( i = 0; i < n; i += 1)
    {
        z[i] = x[i] + y[i];
    }// for i

    return;
}
