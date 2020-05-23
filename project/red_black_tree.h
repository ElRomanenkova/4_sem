#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <fstream>

enum errors{
    BAD_ARGS = -1,
    ERROR = -2,
    BAD_TREE_CONDITION = -3,
    WRONG_OPERATION = -4,
    E_TOO_MUCH_ELEM = -5,
    EMPTY_TREE = -6
};

enum Colors {
    Red = 1, // not 0 for simpler search via warning
    Black = 2,
    Poison_color = 3
};

enum Poisons {
    Poison_key
};

class RB_Node {
public:

    RB_Node();
    explicit RB_Node(int node_key);
    ~RB_Node();

    void setColor(RB_Node * node, Colors new_color);

//private:
    struct RB_Node * parent;
    struct RB_Node * left_ch;
    struct RB_Node * right_ch;
    int color;
    int key;
};

//RB_Node RB_node;

class RB_Tree {
public:
    RB_Tree();
    ~RB_Tree();

//    int RB_insert(int new_value);
    int RB_insert(RB_Node * new_node);
    int RB_delete(RB_Node * node);
    int foreach(int (*func)(RB_Tree *, RB_Node *, void *), void *);
    RB_Node * RB_search(int key);
    int tree_dump(std::ofstream& out);


//private:
    struct RB_Node * nil;
    struct RB_Node * root;
    size_t num_nodes;

    int insert_fixup(RB_Node * new_node);
    void left_rotate(RB_Node * node);
    void right_rotate(RB_Node * node);
    RB_Node * min_node(RB_Node * node);
    RB_Node * max_node(RB_Node * node);
    int node_dump(std::ofstream& out, RB_Node * node, size_t * counter);
    int delete_fixup(RB_Node * extra_black);
    int node_transplant(RB_Node * to, RB_Node * who);
    int subtree_distruct(RB_Node * root, RB_Node * nil, size_t * counter);
    int call(RB_Node * node, int (*func)(RB_Tree *, RB_Node *, void *), void * data, size_t counter);
};

//RB_Tree RB_tree;

//int tree_dump(FILE* out, RB_tree* tree);
//RB_tree* tree_ctor();  //RB_Tree()
//int tree_dtor(RB_tree* tree); //~RB_Tree
//int RB_insert(RB_tree* tree, RB_node* new_node);
//int RB_delete(RB_tree* tree, RB_node* node);
//int foreach(RB_tree* tree, int (*func)(RB_tree*, RB_node*, void*), void*);
//RB_node* min_node(RB_tree* tree, RB_node* root);
//RB_node* max_node(RB_tree* tree, RB_node* root);
//RB_node* RB_search(RB_tree* tree, int key);
//
//int tree_dump(FILE* out, RB_tree* tree);
//RB_tree* tree_ctor();  //RB_Tree()
//RB_node* node_ctor(int node_key); //RB_Node(int node_key)
//int tree_dtor(RB_tree* tree); //~RB_Tree
//int node_dtor(RB_node* node); //~RB_Node
//int RB_insert(RB_tree* tree, RB_node* new_node);
//int RB_delete(RB_tree* tree, RB_node* node);
//int foreach(RB_tree* tree, int (*func)(RB_tree*, RB_node*, void*), void*);
//RB_node* min_node(RB_tree* tree, RB_node* root);
//RB_node* max_node(RB_tree* tree, RB_node* root);
//RB_node* RB_search(RB_tree* tree, int key);
//
//static RB_node* node_create();
//
////private:
//static int insert_fixup(RB_tree* tree, RB_node* new_node);
//static void left_rotate(RB_tree* tree, RB_node* node);
//static void right_rotate(RB_tree* tree, RB_node* node);
//static int node_dump(FILE* out, RB_node* node, RB_tree* tree, size_t* counter);
//static int delete_fixup();
//static int node_transplant(RB_tree* tree, RB_node* to, RB_node* who);
//static int subtree_distruct(RB_node* root, RB_node* nil, size_t* counter);
//static int call(RB_node* node, RB_tree* tree,
//                int (*func)(RB_tree*, RB_node*, void*), void* data, size_t counter);
