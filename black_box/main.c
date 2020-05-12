#include "vector.h"
#include "list.h"
#include "black_box.h"
#include <stdio.h>

int main () {

    struct black_box * box_list = ListCreate();
    struct black_box * box_vector = VectorCreate();

    int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = 2*i;
        box_list->push(box_list, (void*) &arr[i]);
    }

    int hey = 9;
    box_list->insert(box_list, 3, &hey);

    int a[6];
    for (int i = 0; i < 5; i++) {
        a[i] = 2*i;
        box_vector->push(box_vector, &a[i]);
    }

    a[5] = 7;

    box_vector->insert(box_vector, 1, &a[5]);

    box_list->destroy(box_list);
    box_vector->destroy(box_vector);

    return 0;
}