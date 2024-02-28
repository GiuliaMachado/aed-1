#include "string_lib.h"

#include <stdio.h>
#include <stdlib.h>

String* string_create(char* data, int length) {
    String* str = malloc(sizeof(String));

    str->data = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        str->data[i] = data[i];
    }

    str->length = length;

    return str;
}

void string_destroy(String* str) {
    free(str->data);
    free(str);
}

void string_print(String* str) {
    for (int i = 0; i < str->length; i++) {
        printf("%c", str->data[i]);
    }
    printf("\n");
}

String* string_reverse(String* str){
    
    String* nova = string_create(str->data, str->length);

    for(int i = 0; i < str->length; i++){
        nova->data[i] = str->data[str->length - i - 1];
    }
    nova->data[str->length] = '\0';
    nova->length = str->length;

    return nova;
}
void string_append(String *str1, String* str2){

    int novo_tamanho = str1->length + str2->length + 1;
    str1->data = realloc(str1->data, (novo_tamanho) * sizeof(char));
    for(int i = 0; i< str2->length; i++){
        str1->data[str1->length + i] = str2->data[i];
    }
    str1->data[novo_tamanho] = '\0';
    str1->length = novo_tamanho;
}