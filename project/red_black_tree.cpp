#include "red_black_tree.h"

RB_Node::RB_Node() {

    this->parent = nullptr;
    this->left_ch = nullptr;
    this->right_ch = nullptr;

    this->color = Poison_color;
    this->key = Poison_key;
}

RB_Node::RB_Node(int node_key) {
    this->parent = nullptr;
    this->left_ch = nullptr;
    this->right_ch = nullptr;

    this->color = Poison_color;
    this->key = node_key;
}

RB_Node::~RB_Node() {
    this->parent = nullptr;
    this->left_ch = nullptr;
    this->right_ch = nullptr;

    this->color = Poison_color;
    this->key = Poison_key;

    delete this;
}

void RB_Node::setColor(RB_Node * node, Colors new_color) {
    node->color = new_color;
}

//////////////////////////////////////////////////

RB_Tree::RB_Tree() {
    this->num_nodes = 0;

    this->nil = new RB_Node;

    this->nil->setColor(this->nil, Black);

    this->root = this->nil;
}

RB_Tree::~RB_Tree() {
    size_t counter = this->num_nodes;

    int ret = subtree_distruct(this->root, this->nil, &counter);

    if (counter != 0) {
        this->num_nodes = counter;
    }

    this->nil->~RB_Node();

    this->root = nullptr;
    this->nil = nullptr;
    this->num_nodes = 0;

    delete this;
}

/////////////////////////////////////////////////////

int RB_Tree::RB_insert(RB_Node * new_node) {
//int RB_Tree::RB_insert(int new_value) {
//    RB_Node * new_node = new RB_Node(new_value);

//    if (this == nullptr || new_node == nullptr)
//        return BAD_ARGS;

    RB_Node * Nil = this->nil;
    int new_key = new_node->key;

    RB_Node * cur_node = this->root;
    RB_Node * new_parent = Nil;

    while(cur_node != Nil) {
        new_parent = cur_node;

        if (new_key > cur_node->key)
            cur_node = cur_node->right_ch;
        else
            cur_node = cur_node->left_ch;
    }

    if (new_parent == Nil)
        this->root = new_node;
    else if(new_key > new_parent->key)
        new_parent->right_ch = new_node;
    else
        new_parent->left_ch = new_node;

    new_node->parent = new_parent;
    new_node->color = Red;
    new_node->left_ch = Nil;
    new_node->right_ch = Nil;

    (this->num_nodes)++;

    int ret_val = insert_fixup(new_node);

    if (ret_val != 0)
        return BAD_TREE_CONDITION;

    return 0;
}

int RB_Tree::RB_delete(RB_Node *node) {
    if (this == nullptr || node == nullptr)
        return BAD_ARGS;

    RB_Node * new_nil = this->nil;
    RB_Node * old = node;
    int old_orig_color = old->color;
    RB_Node * replaced = nullptr;

    if (node->right_ch == new_nil) {
        replaced = node->left_ch;
        int ret = node_transplant(node, replaced);
        if (ret < 0)
            return ret;
    }
    else if (node->left_ch == new_nil) {
        replaced = node->right_ch;
        int ret = node_transplant(node, replaced);
        if (ret < 0)
            return ret;
    }
    else {
        old = min_node(node->right_ch);
        if (old == nullptr)
            return ERROR;

        old_orig_color =  old->color;
        replaced = old->right_ch;
        if (old->parent == node)
            replaced->parent = old; // it heps us if replaced == nil
        else
        {
            int ret = node_transplant(old, old->right_ch);
            if (ret < 0)
                return ret;
            old->right_ch = node->right_ch;
            old->right_ch->parent = old;
        }
        node_transplant(node, old);
        old->left_ch = node->left_ch;
        old->left_ch->parent = old;
        old->color = node->color;
    }

    node->~RB_Node();

    (this->num_nodes)--;

    int ret = 0;
    if (old_orig_color == Black)
        ret = delete_fixup(replaced);

    return ret;
}

RB_Node * RB_Tree::RB_search(int key) {
    if (this == nullptr)
        return nullptr;

    RB_Node * cur_node = this->root;
    size_t counter = this->num_nodes;

    for(; counter > 0; counter--) {
        if (cur_node == this->nil)
            return nullptr;
        if (key > cur_node->key)
            cur_node = cur_node->right_ch;
        else if (key < cur_node->key)
            cur_node = cur_node->left_ch;
        else
            return cur_node;
    }

    return nullptr;
}

int RB_Tree::tree_dump(std::ofstream& out) {
//    if (out == nullptr || this == nullptr)
//        return BAD_ARGS;

    out << "digraph dump\n{\n";

    out << "\tnode [color = \"#000000\", shape = \"box\", fontsize = 20];\n"
                 "\tedge [color = \"#000000\", fontsize = 20];\n\n";

    out << "\t\troot_nil [label = \"root_nil\", shape = \"diamond\","
                 " color = \"#FFFFFF\", fontcolor = \"#000000\"];\n";


    if (this->num_nodes == 0) {
        out << "}\n";
        return 0;
    }

    size_t counter = this->num_nodes;
    int ret = node_dump(out, this->root, &counter);

    out << "\t\tkey_nil [label = \"nil\", shape = \"diamond\","
                 " color = \"#FFFFFF\", fontcolor = \"#000000\"];\n";

    out << "}\n";

    if (ret != 0)
        return BAD_TREE_CONDITION;

    return 0;
}

int RB_Tree::node_dump(std::ofstream& out, RB_Node * node, size_t * counter) {
    if (node == nullptr || this == nullptr || counter == nullptr)
        return BAD_ARGS;

    if (*counter == 0)
        return ERROR;
    (*counter)--;

    out << "\t\tkey_" << node->key << " [label = \"" << node->key << "\", ";
    if (node->color == Red)
        out << "color = \"#FF0000\", style = \"filled\", "
                     "fillcolor = \"#FF0000\", fontcolor = \"#FFFFFF\"";
    else
        out << "color = \"#000000\", style = \"filled\", "
                     "fillcolor = \"#000000\", fontcolor = \"#FFFFFF\"";
    out << "];\n";

    if (node->parent == nullptr)
        return ERROR;

    if (node->parent == this->nil)
        out << "\t\tkey_" << node->key << " -> root_nil";
    else
        out << "\t\tkey_" << node->key << " -> key_" << node->parent->key;
    out << "[label = \"parent\"];\n";

    if (node->left_ch == nullptr)
        return ERROR;

    if (node->left_ch == this->nil)
        out << "\t\tkey_" << node->key << " -> key_nil [label = \"left\"];\n";
    else {
        out << "\t\tkey_" << node->key << " -> key_" << node->left_ch->key << " [label = \"left\"];\n";
        int ret = node_dump(out, node->left_ch, counter);
        if (ret < 0)
            return ret;
    }

    if (node->right_ch == nullptr)
        return ERROR;

    if (node->right_ch == this->nil)
        out << "\t\tkey_" << node-> key << " -> key_nil [label = \"right\"];\n";
    else {
        out << "\t\tkey_" << node->key << " -> key_" << node->right_ch->key << " [label = \"right\"];\n";

        int ret = node_dump(out, node->right_ch, counter);
        if (ret < 0)
            return ret;
    }

    return 0;
}

int RB_Tree::insert_fixup(RB_Node * new_node) {
//    NOT_NULL(tree);
//    NOT_NULL(new_node);

    RB_Node * cur_node = new_node;
    int ret_val = 0;

    while (cur_node->parent->color == Red) {
        if (cur_node->parent->parent->left_ch == cur_node->parent) { // left branch
            RB_Node * uncle = cur_node->parent->parent->right_ch;
            if (uncle->color == Red) {
                cur_node->parent->color = Black;
                uncle->color = Black;

                cur_node = cur_node->parent->parent;
                cur_node->color = Red;
            }
            else {
                if(cur_node->parent->right_ch == cur_node) {
                    cur_node = cur_node->parent;
                    left_rotate(cur_node);
                }
                cur_node->parent->color = Black;
                cur_node->parent->parent->color = Red;

                right_rotate(cur_node->parent->parent);
            }
        }
        else {// right branch
            RB_Node * uncle = cur_node->parent->parent->left_ch;
            if (uncle->color == Red) {
                cur_node->parent->color = Black;
                uncle->color = Black;

                cur_node = cur_node->parent->parent;
                cur_node->color = Red;
            }
            else {
                if (cur_node->parent->left_ch == cur_node) {
                    cur_node = cur_node->parent;
                    right_rotate(cur_node);
                }
                cur_node->parent->parent->color = Red;
                cur_node->parent->color = Black;
                left_rotate(cur_node->parent->parent);
            }
        }
    }

    this->root->color = Black;

    return 0;
}

void RB_Tree::left_rotate(RB_Node * node) {
    RB_Node * child = node->right_ch;

    child->parent = node->parent;

    if (child->parent->left_ch == node)
        child->parent->left_ch = child;
    else if (child->parent->right_ch == node)
        child->parent->right_ch = child;

    node->parent = child;
    if (child->parent == this->nil)
        this->root = child;

    node->right_ch = child->left_ch;

    if (node->right_ch != this->nil)
        node->right_ch->parent = node;

    child->left_ch = node;
}

void RB_Tree::right_rotate(RB_Node* node) {
    RB_Node * child = node->left_ch;

    child->parent = node->parent;

    if (child->parent->left_ch == node)
        child->parent->left_ch = child;
    else if (child->parent->right_ch == node)
        child->parent->right_ch = child;

    node->parent = child;
    if (child->parent == this->nil)
        this->root = child;

    node->left_ch = child->right_ch;

    if (node->left_ch != this->nil)
        node->left_ch->parent = node;

    child->right_ch = node;
}

RB_Node * RB_Tree::min_node(RB_Node * node) {
    if (this == nullptr || node == nullptr)
        return nullptr;

    size_t counter = this->num_nodes;
    RB_Node * new_nil = this->nil;
    RB_Node * min = node;

    for(; counter > 0; counter--) {
        if (min->left_ch == new_nil)
            return min;
        min = min->left_ch;
    }

    return nullptr;
}

RB_Node * RB_Tree::max_node(RB_Node * node) {
    if (this == nullptr || node == nullptr)
        return nullptr;

    size_t counter = this->num_nodes;
    RB_Node * new_nil = this->nil;
    RB_Node * max = this->root;

    for (; counter > 0; counter--)
    {
        if (max->right_ch == new_nil)
            return max;
        max = max->right_ch;
    }

    return nullptr;
}

int RB_Tree::delete_fixup(RB_Node * extra_black) {
    if (this == nullptr || extra_black == nullptr)
        return BAD_ARGS;

    RB_Node * new_root = this->root;

    while(extra_black->color == Black && extra_black != new_root) {
        if (extra_black->parent->left_ch == extra_black) {
            RB_Node * bro = extra_black->parent->right_ch;
            if (bro->color == Red) {
                extra_black->parent->color = Red;
                bro->color = Black;

                left_rotate(extra_black->parent);

                bro = extra_black->parent->right_ch;
            }
            if (bro->left_ch->color == Black && bro->right_ch->color == Black) {
                bro->color = Red;
                extra_black = extra_black->parent;
            }
            else {
                if (bro->right_ch->color == Black) {
                    bro->color = Red;
                    bro->left_ch->color = Black;

                    right_rotate(bro);

                    bro = extra_black->parent->right_ch;
                }

                bro->color = extra_black->parent->color;
                extra_black->parent->color = Black;
                bro->right_ch->color = Black;

                left_rotate(extra_black->parent);

                extra_black = new_root;
            }
        }
        else {
            RB_Node * bro = extra_black->parent->left_ch;

            if (bro->color == Red) {
                bro->color = Black;
                extra_black->parent->color = Red;

                right_rotate(extra_black->parent);

                bro = extra_black->parent->left_ch;
            }
            if (bro->left_ch->color == Black && bro->right_ch->color == Black) {
                bro->color = Red;
                extra_black = extra_black->parent;
            }
            else {
                if (bro->left_ch->color == Black) {
                    bro->right_ch->color = Black;
                    bro->color = Red;

                    left_rotate(bro);

                    bro = extra_black->parent->left_ch;
                }

                bro->color = extra_black->parent->color;
                extra_black->parent->color = Black;
                bro->left_ch->color = Black;

                right_rotate(extra_black->parent);

                extra_black = new_root;
            }
        }
    }
    extra_black->color = Black;

    return 0;
}

int RB_Tree::node_transplant(RB_Node * to, RB_Node * who) {
    if (this == nullptr || to == nullptr || who == nullptr)
        return BAD_ARGS;

    RB_Node * new_nil = this->nil;

    if (to->parent == new_nil)
        this->root = who;
    else if (to == to->parent->left_ch)
        to->parent->left_ch = who;
    else
        to->parent->right_ch = who;

    who->parent = to->parent;

    return 0;
}

int RB_Tree::subtree_distruct(RB_Node * cur_root, RB_Node * cur_nil, size_t * counter) {
    if (cur_root == nullptr || cur_nil == nullptr || counter == nullptr)
        return BAD_ARGS;

    if (cur_root == cur_nil)
        return 0;

    int ret = 0;

    if (cur_root->left_ch != cur_nil || cur_root->left_ch != nullptr) {
        ret = subtree_distruct(cur_root->left_ch, cur_nil, counter);
        if (ret != 0)
            return ret;
    }

    if (cur_root->right_ch != cur_nil || cur_root->right_ch != nullptr) {
        ret = subtree_distruct(cur_root->right_ch, cur_nil, counter);
        if (ret != 0)
            return ret;
    }

    if (*counter == 0)
        return E_TOO_MUCH_ELEM;

    (*counter)--;

    cur_root->~RB_Node();

    return ret;
}

int RB_Tree::call(RB_Node * node, int (*func)(RB_Tree *, RB_Node *, void *), void * data, size_t counter) {
    if (node == nullptr || this == nullptr || func == nullptr)
        return BAD_ARGS;

    RB_Node * new_nil = this->nil;
    if (node == new_nil)
        return EMPTY_TREE;

    int ret = 0;

    if (counter <= 0)
        return E_TOO_MUCH_ELEM;

    if (node->left_ch != new_nil) {
        ret = call(node->left_ch, func, data, counter - 1);
        if (ret < 0)
            return ret;
    }

    ret = func(this, node, data);
    if (ret < 0)
        return ret;

    if (node->right_ch != new_nil) {
        ret = call(node->right_ch, func, data, counter - 1);
        if (ret < 0)
            return ret;
    }

    return 0;
}