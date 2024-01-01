#include <stdio.h>
#include <stdlib.h>

#include "../../../record.h"
#include "../../bt.h"
#include "../bst.h"
#include "./avl.h"


B_Node* AVL_rotateRight(B_Node *u) {
	if (u == NULL) {
        return NULL;

    } else if (u->left == NULL) {
        return u;
    }

	B_Node *new_root = u->left;
    u->left = new_root->right;
	new_root->right = u;

    return new_root;
}


B_Node* AVL_rotateLeft(B_Node *u) {
	if (u == NULL) {
        return NULL;

    } else if (u->right == NULL) {
        return u;
    }

	B_Node *new_root = u->right;
    u->right = new_root->left;
	new_root->left = u;

    return new_root;
}