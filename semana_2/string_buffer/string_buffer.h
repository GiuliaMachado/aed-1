#ifndef STRING_BUFFER_H
#define STRING_BUFFER_H

typedef struct StringBuffer StringBuffer;

//funcoes
StringBuffer* string_buffer_create();
void string_buffer_destroy(StringBuffer* sb);
void string_buffer_append(StringBuffer* sb, char* string);
char* string_buffer_toString(StringBuffer* sb);

#endif