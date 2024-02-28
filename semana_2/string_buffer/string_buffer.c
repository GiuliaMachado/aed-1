#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_buffer.h"
#include "../array_dinamico/array_dinamico.h"

struct StringBuffer{
    ArrayDinamico* data;
};

StringBuffer* string_buffer_create(){
    StringBuffer* sb = malloc(sizeof(StringBuffer));
    sb->data = array_dinamico_create();

    return sb;
}

void string_buffer_destroy(StringBuffer* sb){
    array_dinamico_destroy(sb->data);
    free(sb);
}

void string_buffer_append(StringBuffer* sb, char* string){
    for(int i = 0; i < strlen(string); i++){
        array_dinamico_add(sb->data, string[i]);
    }
}

char* string_buffer_toString(StringBuffer* sb){
    char* string = malloc(sizeof(char)* (array_dinamico_size(sb->data)+1));

    for(int i = 0; i< array_dinamico_size(sb->data); i++){
        string[i] = array_dinamico_get(sb->data, i);
    }
    string[array_dinamico_size(sb->data)] = '\0';
    return string;
}