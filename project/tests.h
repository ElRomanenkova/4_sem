#define UNITTEST( what, opera, truth) \
{\
    if(!((what) opera (truth)))\
        printf("FAIL test!!! %s != %s\n", #what, #truth);\
    else\
        printf("Test passed\n");\
};

void Testcase_dump();
void Testcase_insert_right_fixup();
void Testcase_insert_left_fixup();
void Testcase_tree_ctor_and_dtor();
void Testcase_node_ctor_and_dtor();
void Testcase_delete_and_fixup();
void Testcase_search();
void Testcase_max();
void Testcase_min();
void Testcase_foreach();
void Testcase_memfail();
