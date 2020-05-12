#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "black_box.h"

struct vector {
    int size;
    int capacity;
    void ** dataset;

    struct black_box box;
};

struct black_box * VectorCreate() {
    struct vector * this = (struct vector *) malloc(sizeof(struct vector));

    this->size = 0;
    this->capacity = 0;
    this->dataset = NULL;

    this->box.size = VectorSize;
    this->box.item = VectorItem;
    this->box.push = VectorPush;
    this->box.pop = VectorPop;
    this->box.insert = VectorInsert;
    this->box.swap = VectorSwap;
    this->box.remove = VectorRemove;
    this->box.print = VectorPrint;
    this->box.destroy = VectorDestroy;

    return (struct black_box *) this;
}

void Incr (struct vector * this) {
    if (this->capacity == 0) {
        this->capacity = 4;
    }
    else {
        this->capacity *= 4;
    }

    this->dataset = (void **) realloc(this->dataset,this->capacity * sizeof(void *));
}

void Decr (struct vector * this) {
    this->capacity /= 4;
    this->dataset = (void **) realloc(this->dataset,this->capacity * sizeof(void *));
}

int VectorSize (struct black_box * box) {
    struct vector * this = (struct vector *) box;

    return this->size;
}

void * VectorItem (struct black_box * box, int ind) {
    struct vector * this = (struct vector *) box;

    if (ind > this->size) {
        printf("This index doesn't exist\nsize of box - %d index - %d\n", this->size, ind);
        return NULL;
    }
    else {
        return this->dataset[ind];
    }
}

void VectorPush (struct black_box * box, void * data) {
    struct vector * this = (struct vector *) box;

    if (this->size > this->capacity) {
        Incr(this);
    }

    this->dataset[this->size] = data;  //this->size++

}

void VectorPop (struct black_box * box) {
    struct vector * this = (struct vector *) box;

    this->dataset[this->size] = NULL;  //--this->size

    if ((this->capacity + 1) / 4 > this->size) {
        Decr(this);
    }
}

void VectorInsert (struct black_box * box, int ind, void * data) {
    struct vector * this = (struct vector *) box;

    if (ind > this->size) {
        printf("This index doesn't exist\nsize of box - %d index - %d\n", this->size, ind);
    }

    if (this->size > this->capacity) {
        Incr(this);
    }

    for (int i = this->size; i > ind; i--) {
        this->dataset[i] = this->dataset[i - 1];
    }

    this->dataset[ind + 1] = data;
    this->size++;
}

void VectorSwap (struct black_box * box, int ind1, int ind2) {
}

void VectorRemove (struct black_box * box, int ind) {
    struct vector * this = (struct vector *) box;

    if (ind > this->size) {
        printf("This index doesn't exist\nsize of box - %d index - %d\n", this->size, ind);
    }

    for (int i = ind; i < this->size; i++) {
        this->dataset[i] = this->dataset[i + 1];
    }

    if ((this->capacity + 1) / 4 > this->size) {
        Decr(this);
    }

    this->size--;

}

void VectorPrint (struct black_box * box) {
    struct vector * this = (struct vector *) box;

    printf("---------------------\n");
    printf("size: %d\n", this->size);
    printf("capacity: %d\n", this->capacity);

    if (this->dataset) {
        int size = this->size;
        for (int i = 0; i < size; i++) {
            printf("%d: %d\n", i, *((int *)this->dataset[i]));
        }
    }
    else
        printf("The box is empty\n");

    printf("---------------------\n");

}

void VectorDestroy (struct black_box * box) {
    struct vector * this = (struct vector *) box;

    this->size = 0;
    this->capacity = 0;
    free(this->dataset);

    free(this);
}
