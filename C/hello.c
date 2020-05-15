#include <stdio.h>

struct tmp1
{
    int i;
    char c;
    char d;
    long j;
};

struct tmp2
{
    short w[3];
    char c[3];
};

struct tmp3
{
    struct tmp2 a[2];
    struct tmp1 t;
};

int main()
{
    printf("%d\n", sizeof(struct tmp3));
    return 0;
}