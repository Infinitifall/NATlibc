#include <stdlib.h>
#include <stdint.h>

#include "../record.h"
#include "bt.h"


Tree* BT_createTree(int (*recordsCompare) (Record *r1, Record *r2)) {
    Tree *t = malloc(sizeof(*t));
    
    static int tree_count = 0;
    t->id = tree_count;
    tree_count++;

    t->root_node = NULL;
    t->recordsCompare = recordsCompare;

    return t;
}


Node* BT_createNode(Record *r) {
    Node *u = malloc(sizeof(*u));
    
    static int node_count = 0;
    u->id = node_count;
    node_count++;
    
    u->record = r;
    
    u->depth_left = 0;
    u->depth_right = 0;
    u->child_count = 0;
    u->left = NULL;
    u->right = NULL;

    return u;
}


void BT_freeTree(Tree *t) {
    if (t == NULL) {
        return;
    }

    BT_freeNodesRecursive(t->root_node);
    free(t);
}


void BT_freeNode(Node *u) {
    if (u == NULL) {
        return;
    }

    free(u->record);
    free(u);
}


void BT_freeNodesRecursive(Node *u) {
    if (u == NULL) {
        return;
    }

    BT_freeNodesRecursive(u->left);
    BT_freeNodesRecursive(u->right);
    BT_freeNode(u);
}


int BT_calculateDepth(Node *u) {
    if (u == NULL) {
        return 0;
    }

    int depth_left = BT_calculateDepth(u->left);
    int depth_right = BT_calculateDepth(u->right);

    int depth_max;
    if (depth_right > depth_left) {
        depth_max = depth_right;
    } else {
        depth_max = depth_left;
    }
    
    return depth_max + 1;
}


Node* BT_rotateRight(Node *u) {
	if (u == NULL) {
        return NULL;

    } else if (u->left == NULL) {
        return u;
    }

	Node *new_root = u->left;
    u->left = new_root->right;
	new_root->right = u;

    return new_root;
}


Node* BT_rotateLeft(Node *u) {
	if (u == NULL) {
        return NULL;

    } else if (u->right == NULL) {
        return u;
    }

	Node *new_root = u->right;
    u->right = new_root->left;
	new_root->left = u;

    return new_root;
}


Node* BT_searchRecursive(Node *u, Record *r, int (*recordsCompare) (Record *r1, Record *r2)) {
    if (u == NULL) {
        return NULL;
    }
    
    int compare_value = (*recordsCompare)(r, u->record);
    if (compare_value == 0) {
        return u;
    }

    Node *search_left = BT_searchRecursive(u->left, r, recordsCompare);
    if (search_left != NULL) {
        return search_left;
    }
    
    Node *search_right = BT_searchRecursive(u->right, r, recordsCompare);
    if (search_right != NULL) {
        return search_right;
    }

    return NULL;
}


Node* BT_search(Tree *t, Record *r) {
    return BT_searchRecursive(t->root_node, r, t->recordsCompare);
}
