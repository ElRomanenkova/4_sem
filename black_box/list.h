#ifndef BLACK_BOX_LIST_H
#define BLACK_BOX_LIST_H

struct black_box * ListCreate();

int    ListSize    (struct black_box * box);
void * ListItem    (struct black_box * box, int ind);
void   ListPush    (struct black_box * box, void * data);
void   ListPop     (struct black_box * box);
void   ListInsert  (struct black_box * box, int ind, void * data);
void   ListSwap    (struct black_box * box, int ind1, int ind2);
void   ListRemove  (struct black_box * box, int ind);
void   ListPrint   (struct black_box * box);
void   ListDestroy (struct black_box * box);

#endif //BLACK_BOX_LIST_H
