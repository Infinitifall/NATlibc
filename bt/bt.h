#ifndef NAT_BT_BT_H_
#define NAT_BT_BT_H_


#include "../record.h"


/**
 * @brief Node of a binary tree
 * 
 */
typedef struct b_node {
    // unique id for node
    int id;

    // node data
    NAT_Record *record;

    int child_count;
    int depth_left, depth_right;
    struct b_node *left, *right;
} B_Node;


/**
 * @brief Binary tree
 * 
 */
typedef struct b_tree {
    // unique id for tree
    int id;

    // root node of tree
    B_Node *root_node;
    
    // function to compare two records
    int (*recordsCompare) (NAT_Record *r1, NAT_Record *r2);
} B_Tree;


/**
 * @brief Create new tree with comparison function f
 * 
 * @param f The "recordsCompare" field of created tree
 * @return B_Tree* Pointer to created tree
 */
B_Tree* BT_createTree(int (*f) (NAT_Record *r1, NAT_Record *r2));


/**
 * @brief Create new node with record r
 * 
 * @param r The "record" field of created record
 * @return B_Node* Pointer to created node
 */
B_Node* BT_createNode(NAT_Record *r);


/**
 * @brief Free tree t, along with all associated child nodes, records
 * 
 * @param t Pointer to tree
 */
void BT_freeTree(B_Tree *t);


/**
 * @brief Free (sub)tree with root u, along with all associated child nodes, records
 * 
 * @param u Pointer to (sub)tree root node
 */
void BT_freeNodesR(B_Node *u);


/**
 * @brief Free node u, along with associated record
 * 
 * @param u Pointer to node
 */
void BT_freeNode(B_Node *u);


/**
 * @brief Get in-order minimum leaf node in (sub)tree with root u
 * 
 * @param u Pointer to (sub)tree root node
 * @return B_Node* Pointer to min leaf node
 */
B_Node* BT_getInOrderMin(B_Node *u);


/**
 * @brief Get in-order maximum leaf node in (sub)tree with root u
 * 
 * @param u Pointer to (sub)tree root
 * @return B_Node* Pointer to max leaf node
 */
B_Node* BT_getInOrderMax(B_Node *u);


/**
 * @brief Calculate depth of (sub)tree with root u, from scratch
 * 
 * @param u Pointer to (sub)tree root
 * @return int Depth of (sub)tree
 */
int BT_calcDepth(B_Node *u);


/**
 * @brief Search for first node with record r in tree t
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 * @return B_Node* Pointer to node if found else NULL
 */
B_Node* BT_search(B_Tree *t, NAT_Record *r);


/**
 * @brief Search for first node with record r in (sub)tree with root u
 * 
 * @param u Pointer to (sub)tree root
 * @param r Pointer to record
 * @param f Pointer to recordsCompare function
 * @return B_Node* Pointer to node if found else NULL
 */
B_Node* BT_searchR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2));


/**
 * @brief Insert node with record r as random leaf in tree t. Duplicates allowed.
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 */
void BT_insert(B_Tree *t, NAT_Record *r);


/**
 * @brief (Create and) Insert node with record r as a random leaf node in (sub)tree with root u. Duplicates allowed.
 * 
 * @param u Pointer to (sub)tree root
 * @param r Pointer to record
 * @return B_Node* Pointer to new (sub)tree root
 */
B_Node* BT_insertR(B_Node *u, NAT_Record *r);


/**
 * @brief Delete (and free) all nodes with record r in tree t
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 */
void BT_delete(B_Tree *t, NAT_Record *r);


/**
 * @brief Delete (and free) all nodes with record r in (sub)tree with root u
 * 
 * @param u Pointer to (sub)tree root
 * @param r Pointer to record
 * @param f Pointer to recordsCompare function
 * @return B_Node* Pointer to new (sub)tree root
 */
B_Node* BT_deleteR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2));


#endif
