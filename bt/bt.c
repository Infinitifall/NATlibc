#include <stdlib.h>

#include "../record.h"
#include "./bt.h"


B_Tree* BT_createTree(int (*recordsCompare) (NAT_Record *r1, NAT_Record *r2)) {
    B_Tree *t = malloc(sizeof(*t));
    
    static int tree_count = 0;
    t->id = tree_count;
    tree_count++;

    t->root_node = NULL;
    t->recordsCompare = recordsCompare;

    return t;
}


B_Node* BT_createNode(NAT_Record *record) {
    B_Node *u = malloc(sizeof(*u));
    
    static int node_count = 0;
    u->id = node_count;
    node_count++;
    
    u->record = record;
    
    u->child_count = 0;
    u->depth_left = u->depth_right = 0;
    u->left = u->right = NULL;

    return u;
}


void BT_freeTree(B_Tree *t) {
    if (t == NULL) {
        return;
    }

    BT_freeNodesR(t->root_node);
    free(t);
}


void BT_freeNode(B_Node *u) {
    if (u == NULL) {
        return;
    }

    NAT_freeRecord(u->record);
    free(u);
}


void BT_freeNodesR(B_Node *u) {
    if (u == NULL) {
        return;
    }

    BT_freeNodesR(u->left);
    BT_freeNodesR(u->right);
    BT_freeNode(u);
}


B_Node* BT_getInOrderMin(B_Node *u) {
    if (u == NULL) {
        return NULL;
    }

    while (u->left != NULL) {
        u = u->left;
    }

    return u;
}


B_Node* BT_getInOrderMax(B_Node *u) {
    if (u == NULL) {
        return NULL;
    }

    while (u->right != NULL) {
        u = u->right;
    }

    return u;
}


static B_Node* BT_getRandLeaf(B_Node *u) {
    if (u == NULL) {
        return NULL;
    }

    B_Node *random_branch_1, *random_branch_2;
    int choose_branch = rand() % 2;
    if (choose_branch == 0) {
        random_branch_1 = u->left;
        random_branch_2 = u->right;

    } else {
        random_branch_1 = u->right;
        random_branch_2 = u->left;
    }

    if (random_branch_1 != NULL) {
        return BT_getRandLeaf(random_branch_1);

    } else if (random_branch_2 != NULL) {
        return BT_getRandLeaf(random_branch_2);
    }

    return u;
}


int BT_calcDepth(B_Node *u) {
    if (u == NULL) {
        return 0;
    }

    int depth_left = BT_calcDepth(u->left);
    int depth_right = BT_calcDepth(u->right);
    
    if (depth_right > depth_left) {
        return 1 + depth_right;
    
    } else {
        return 1 + depth_left;
    }
}


B_Node* BT_searchR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2)) {
    if (u == NULL) {
        return NULL;
    }
    
    int compare_value = (*f)(r, u->record);
    if (compare_value == 0) {
        return u;
    }

    B_Node *search_left = BT_searchR(u->left, r, f);
    if (search_left != NULL) {
        return search_left;
    }
    
    B_Node *search_right = BT_searchR(u->right, r, f);
    if (search_right != NULL) {
        return search_right;
    }

    return NULL;
}


B_Node* BT_search(B_Tree *t, NAT_Record *r) {
    return BT_searchR(t->root_node, r, t->recordsCompare);
}


void BT_insert(B_Tree *t, NAT_Record *r) {
    t->root_node = BT_insertR(t->root_node, r);
}


B_Node* BT_insertR(B_Node *u, NAT_Record *r) {
    if (u == NULL) {
        return BT_createNode(r);
    }

    int choose_branch = rand() % 2;
    // TODO: depth and child calculations
    // TODO: non random, uniform filling
    if (choose_branch == 0) {
        u->left = BT_insertR(u->left, r);
        
    } else {
        u->right = BT_insertR(u->right, r);
    }

    return u;
}


void BT_delete(B_Tree *t, NAT_Record *r) {
    if (t == NULL) {
        return;
    }

    t->root_node = BT_deleteR(t->root_node, r, t->recordsCompare);
}


B_Node* BT_deleteR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2)) {
    if (u == NULL) {
        return NULL;
    }
    
    int compare_value = (*f)(r, u->record);
    if (compare_value == 0) {
        // TODO: depth and child calculations
        // TODO: non random, uniform leaf choose (?)
        // TODO: delete parent link of random_leaf
        B_Node *random_leaf = BT_getRandLeaf(u);
        random_leaf->right = u->right;
        random_leaf->left = u->left;
        BT_freeNode(u);
        u = random_leaf;
    }
    
    if (u->right != NULL) {
        u->right = BT_deleteR(u->right, r, f);
    }
    
    if (u->left != NULL) {
        u->left = BT_deleteR(u->left, r, f);
    }

    // TODO: does this delete all nodes with record r?
    return u;
}
