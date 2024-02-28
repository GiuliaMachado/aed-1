#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "array.h"

int main(){
    Array* a = array_create(20);
    int size = array_size(a);
    printf("%d", size);
    return 0;
}