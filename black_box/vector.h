#ifndef BLACK_BOX_VECTOR_H
#define BLACK_BOX_VECTOR_H

struct black_box * VectorCreate();

int    VectorSize    (struct black_box * box);
void * VectorItem    (struct black_box * box, int ind);
void   VectorPush    (struct black_box * box, void * data);
void   VectorPop     (struct black_box * box);
void   VectorInsert  (struct black_box * box, int ind, void * data);
void   VectorSwap    (struct black_box * box, int ind1, int ind2);
void   VectorRemove  (struct black_box * box, int ind);
void   VectorPrint   (struct black_box * box);
void   VectorDestroy (struct black_box * box);

#endif
