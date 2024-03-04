#include <stdio.h>
#include "queue.h"

int main(){
    Queue* queue = queue_create(5);
    queue_enqueue(queue, 10);
    queue_print(queue);

    queue_enqueue(queue, 20);
    queue_enqueue(queue, 40);
    queue_print(queue);

    queue_dequeue(queue);
    queue_dequeue(queue);

    queue_destroy(queue);
    
    return 0;
}