#ifndef BLACK_BOX_BLACK_BOX_H
#define BLACK_BOX_BLACK_BOX_H

struct black_box {
    // list of function pointers

    int    (* size)    (struct black_box * box);
    void * (* item)    (struct black_box * box, int ind);
    void   (* push)    (struct black_box * box, void * data);
    void   (* pop)     (struct black_box * box);
    void   (* insert)  (struct black_box * box, int ind, void * data);
    void   (* swap)    (struct black_box * box, int ind1, int ind2); //not written
    void   (* remove)  (struct black_box * box, int ind);
    void   (* print)   (struct black_box * box);
    void   (* destroy) (struct black_box * box);

};

#endif //BLACK_BOX_BLACK_BOX_H
