#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "black_box.h"

struct node {
    void * data;
    struct node * next;
    struct node * prev;
};

struct list {
    int size;
    struct node * head;
    struct node * tail;

    struct black_box box;

};

struct black_box * ListCreate() {
    struct list * this = (struct list *) malloc(sizeof(struct list));

    this->size = 0;
    this->head = NULL;
    this->tail = NULL;

    this->box.size = ListSize;
    this->box.item = ListItem;
    this->box.push = ListPush;
    this->box.pop = ListPop;
    this->box.insert = ListInsert;
    this->box.swap = ListSwap;
    this->box.remove = ListRemove;
    this->box.print = ListPrint;
    this->box.destroy = ListDestroy;

    return (struct black_box *) this;
}

struct node * FindByIndex(struct list * this, int ind) {

    if (ind > this->size) {
        printf("This index doesn't exist\nsize of box - %d index - %d\n", this->size, ind);
        return NULL;
    }
    else {
        struct node * elem = this->head;
        for (int i = 0; i < ind; i++) {
            elem = elem->next;
        }
        return elem;
    }
}

int ListSize (struct black_box * box) {
    struct list * this = (struct list *) box;

    return this->size;
}

void * ListItem (struct black_box * box, int ind) {
    struct list * this = (struct list *) box;

    struct node * right_node = FindByIndex(this, ind);

    return right_node;
}

void ListPush (struct black_box * box, void * data) {
    struct list * this = (struct list *) box;

    struct node * new_elem = (struct node *) malloc(sizeof(struct node));
    new_elem->next = NULL;
    new_elem->prev = NULL;
    new_elem->data = data;

    if (this->size > 0) {
        this->tail->next = new_elem;
        new_elem->prev = this->tail;
        this->tail = new_elem;
    }
    else {
        this->head = new_elem;
        this->tail = new_elem;
    }

    this->size++;
}

void ListPop (struct black_box * box) {
    struct list * this = (struct list *) box;

    if (this->size < 1) {
        printf("The box is already empty\n");
    }

    struct node * pop_elem = this->tail;

    if (this->size == 1) {
        this->head = NULL;
        this->tail = NULL;
    }
    else {
        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }

    this->size--;

    free(pop_elem);
}

void ListInsert (struct black_box * box, int ind, void * data) {
    struct list * this = (struct list *) box;

    struct node * cur_node = FindByIndex(this, ind);
    if (cur_node == NULL)
        return;

    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->next = cur_node->next;
    new_node->prev = cur_node;
    new_node->data = data;

    if (cur_node->next)
        cur_node->next->prev = new_node;

    cur_node->next = new_node;

    this->size++;
}

void ListSwap (struct black_box * box, int ind1, int ind2) {
}

void ListRemove (struct black_box * box, int ind) {
    struct list * this = (struct list *) box;

    struct node * cur_node = FindByIndex(this, ind);
    if (cur_node == NULL)
        return;

    if (cur_node->prev)
        cur_node->prev->next = cur_node->next;
    else
        this->head = cur_node->next;

    if (cur_node->next)
        cur_node->next->prev = cur_node->prev;
    else
        this->tail = cur_node->prev;

    this->size--;

    free(cur_node);
}

void ListPrint (struct black_box * box) {
    struct list * this = (struct list *) box;

    printf("---------------------\n");
    printf("size: %d\n", this->size);

    struct node * cur_node = this->head;

    if (cur_node) {
        int size = this->size;
        for (int i = 0; i < size; i++) {
            printf("%d: %d\n", i, *((int *)cur_node->data));
            cur_node = cur_node->next;
        }
    }
    else
        printf("The box is empty\n");

    printf("---------------------\n");
}

void ListDestroy (struct black_box * box) {
    struct list * this = (struct list *) box;

    int size = this->size;

    for (int i = 0; i < size; i++)
        ListPop(box);

    free(this);
}