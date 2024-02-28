//caso queira mudar o tipo modificar somente o element.h e element.c
//arquivo de INTERFACE precisa de definições para evitar erros de compilação
#ifndef ELEMENT_C
#define ELEMENT_C
//os projetos Array e Array Dinamico utilizam o Element com tipo int
//o projeto StringBuffer utiliza o Element com tipo char
//Versão atual: tipo char - StringBuffer está utilizando o Element
typedef char Element;

void print_element(Element e);
#endif