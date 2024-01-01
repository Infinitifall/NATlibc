#include <stdio.h>
#include <stdlib.h>

#include "../../record.h"
#include "../bt.h"
#include "bst.h"


B_Node* BST_searchR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2)) {
    if (u == NULL) {
        return NULL;
    }
    
    int compare_value = (*f)(r, u->record);
    if (compare_value < 0) {
        return BST_searchR(u->left, r, f);

    } else if (compare_value > 0) {
        return BST_searchR(u->right, r, f);
    }
    
    return u;
}


B_Node* BST_search(B_Tree *t, NAT_Record *r) {
    return BST_searchR(t->root_node, r, t->recordsCompare);
}
