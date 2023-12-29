#include <stdio.h>
#include <stdlib.h>

#include "../bt.h"
#include "bst.h"


Node* BST_searchRecursive(Node *u, Record *r, int (*recordsCompare) (Record *r1, Record *r2)) {
    if (u == NULL) {
        return NULL;
    }
    
    int compare_value = (*recordsCompare)(r, u->record);
    if (compare_value > 0) {
        return BST_searchRecursive(u->right, r, recordsCompare);

    } else if (compare_value < 0) {
        return BST_searchRecursive(u->left, r, recordsCompare);

    } else {
        return u;
    }
}


Node* BST_search(Tree *t, Record *r) {
    return BST_searchRecursive(t->root_node, r, t->recordsCompare);
}
