#include "red_black_tree.h"
//#include "tests.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ctime>
#include <map>

int main() {

    std::ofstream my_res ("my_res.txt");

    struct timespec my_str_begin{}, my_str_end{};
    clock_gettime(CLOCK_MONOTONIC, &my_str_begin);
//    std::cout << "1 " << my_str_begin.tv_sec + my_str_begin.tv_nsec * 0.000000001 << std::endl;

    RB_Tree * tree = new RB_Tree;

    std::ifstream data("data2.txt");

    if (data.is_open()) {
        int count = 0;
        while (!data.eof()) {
            int value;
            data >> value;
            RB_Node * cur_node = new RB_Node(value);
            if (tree->RB_search(value) == nullptr) {
                tree->RB_insert(cur_node);
            }
            count++;
            if (count % 1000 == 0) {
                clock_gettime(CLOCK_MONOTONIC, &my_str_end);
                my_res << (my_str_end.tv_sec - my_str_begin.tv_sec) + (my_str_end.tv_nsec - my_str_begin.tv_nsec) * 0.000000001 << std::endl;
            }
        }
    }
    else {
        std::cout << "ERROR1" << std::endl;
    }
    data.close();

    clock_gettime(CLOCK_MONOTONIC, &my_str_end);
//    std::cout << "2 " << my_str_end.tv_sec + my_str_end.tv_nsec * 0.000000001 << std::endl;

    std::cout << (my_str_end.tv_sec - my_str_begin.tv_sec) + (my_str_end.tv_nsec - my_str_begin.tv_nsec) * 0.000000001 << std::endl;

    std::ofstream out("dump_tree.txt");

    if (out.is_open()) {
        int dump_empty_tree = tree->tree_dump(out);
        if (dump_empty_tree < 0) {
            std::cout << "NOOOO" << std::endl;
        }
    }
    else {
        std::cout << "ERROR2" << std::endl;
    }
    out.close();

    my_res.close();

////////////////////////////////////////////////////////////////////////////////////////////
    std::ofstream stl_res ("stl_res.txt");

    struct timespec stl_begin{}, stl_end{};
    clock_gettime(CLOCK_MONOTONIC, &stl_begin);
//    std::cout << "3 " << stl_begin.tv_sec + stl_begin.tv_nsec * 0.000000001 << std::endl;

    std::map<int, int> stl_map;

    std::ifstream new_data("data2.txt");

    if (new_data.is_open()) {
        int count = 0;
        while (!new_data.eof()) {
            int value;
            new_data >> value;
            stl_map[value] = 0;
            count++;
            if (count % 1000 == 0) {
                clock_gettime(CLOCK_MONOTONIC, &stl_end);
                stl_res << (stl_end.tv_sec - stl_begin.tv_sec) + (stl_end.tv_nsec - stl_begin.tv_nsec) * 0.000000001 << std::endl;
            }
        }
    }
    else {
        std::cout << "ERROR3" << std::endl;
    }
    new_data.close();

    clock_gettime(CLOCK_MONOTONIC, &stl_end);
//    std::cout << "4 " << stl_end.tv_sec + stl_end.tv_nsec * 0.000000001 << std::endl;

    std::cout << (stl_end.tv_sec - stl_begin.tv_sec) + (stl_end.tv_nsec - stl_begin.tv_nsec) * 0.000000001 << std::endl;


    stl_res.close();

    return 0;
}

