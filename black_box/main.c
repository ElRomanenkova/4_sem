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
        list->push(list, (void*) &arr[i]);
    }

    int hey = 9;
    list->insert(list, 3, &hey);
    list->dump(list);

    int a[6];
    for (int i = 0; i < 5; i++) {
        a[i] = 2*i;
        vector->push(vector, &a[i]);
    }

    a[5] = 7;

    vector->insert(vector, 1, &a[5]);
    vector->dump(vector);

    box_list->destroy(box_list);
    box_vector->destroy(box_vector);

    return 0;
}