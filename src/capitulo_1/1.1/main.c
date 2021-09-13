#include <stdio.h>
#include <stdlib.h>
#include "reciprocal.hpp"

int main(int argc, char const *argv[])
{
    int i;
    i = atoi(argv[1]);
    printf("The reciprocal of %d is %g\n", i, reciprocal(i));
    return 0;
}
