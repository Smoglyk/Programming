#include "main.h"
#include <assert.h>

void Test()
{
    int size = 10;
    char *c = (char *)malloc(size * sizeof(char));
    if(c == 0)
        exit(1);

    assert(isEmpty(c) == 1);
    
    free(c);
}

#undef main

int main()
{
    Test();
    printf("Test have done");
    return 0;
}
