#include "vector.h"
#include "list.h"
#include "black_box.h"
#include <stdio.h>

int main () {

    struct black_box * box_list = ListCreate();
    struct black_box * box_vector = VectorCreate();

    box_list->destroy(box_list);
    box_vector->destroy(box_vector);

    return 0;
}