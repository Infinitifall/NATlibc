#include <stdio.h>
#include <stdlib.h>

#include "record.h"
#include "bt/bt.h"
#include "bt/bt_read.h"
#include "bt/bt_print.h"
#include "bt/bst/bst.h"


int main(int argc, char const *argv[]) {

    // nodes defining a tree
    // value, parent_index
    int eg_nodes[][3] = {
        {2,  -1},
        {5,  0},
        {7,  1},
        {33, 2},
        {19, 0},
        {8,  4},
        {9,  4},
        {11, 6},
        {14, 6}
    };
    
    // convert 2D array to pointer to pointers
    int eg_nodes_count = sizeof(eg_nodes) / sizeof(*eg_nodes);
    int **eg_pointer = malloc(eg_nodes_count * sizeof(&eg_nodes));
    for (int i = 0; i < eg_nodes_count; i++) {
        eg_pointer[i] = eg_nodes[i];
    }

    // convert to tree
    Node *u = BT_readInts(eg_pointer, eg_nodes_count);

    // print tree
    printf("\n");
    BT_print2D(u);
    printf("\n");
    BT_printFlat(u);

    // free up everything
    free(eg_pointer);
    BT_freeNodesRecursive(u);

    return 0;
}
