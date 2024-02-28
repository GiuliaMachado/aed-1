#include <stdio.h>
#include <stdlib.h>
#include "string_lib.h"

int main(){

    String* string = string_create("Giulia", 6);
    string_print(string);
    string_print(string_reverse(string));

    string_destroy(string);

    return 0;
}