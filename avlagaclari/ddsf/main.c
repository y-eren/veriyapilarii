#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[] = "sesli";

    char *p = &x;

    char **pp = &p;

    char ***ppp = &pp;

    printf("%c", *(**ppp[3]));
    return 0;
}
