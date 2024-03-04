#include <stdio.h>

#include "student_list.h"

int main(void) {
    StudentList* list = list_create();

    list_insertFirst(list, 123, "John Doe", 7.5);
    list_insertFirst(list, 456, "Mary Jane", 5.5);
    list_insertFirst(list, 789, "Peter Parker", 6.5);
    list_insertFirst(list, 101, "Alice Cooper", 4.5);
    list_insertAfter(list, 2, 999, "Bruce Wayne", 3.5);
    list_print(list);

    //testes das funcoes novas
    Student* found_student = list_findByRa(list, 453);
    if(found_student != NULL){
        student_print(found_student);
    }else{
        printf("O estudante não foi encontrado.\n");
    }

    //list_incrementGrades(list, 0.5);
    //list_print(list);

    printf("Média da sala: %.2f\n", list_averageGrade(list));
    StudentList* new_list = list_filterFailed(list);
    printf("Reprovados.\n");
    list_print(new_list);

    printf("Aprovados.\n");
    StudentList* new_list2 = list_filterPassed(list);
    list_print(new_list2);

    printf("Exame.\n");
    StudentList* new_list3 = list_filterExam(list);
    list_print(new_list3);

    list_destroy(list);
    list_destroy(new_list);
    list_destroy(new_list2);
    list_destroy(new_list3);

    return 0;
}
