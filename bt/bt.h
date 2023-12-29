#ifndef BT_BT_H_
#define BT_BT_H_

#include "../record.h"


/**
 * @brief Nodes of a binary tree
 * 
 */
typedef struct node {
    // Unique id for every node in tree
    int id;

    // Pointer to record
    Record *record;
    
    // Left subtree depth
    int depth_left;
    // Right subtree depth
    int depth_right;
    // Subtree child count
    int child_count;
    struct node *left;
    struct node *right;
} Node;


/**
 * @brief Binary tree
 * 
 */
typedef struct tree {
    // Unique id for every tree
    int id;

    // Pointer to the root node of the tree
    Node *root_node;

    // Function for comparing two records
    int (*recordsCompare) (Record *r1, Record *r2);
} Tree;


/**
 * @brief Create new empty binary tree
 * 
 * @param recordsCompare Comparison function for tree
 * @return Tree* 
 */
Tree* BT_createTree(int (*recordsCompare) (Record *r1, Record *r2));


/**
 * @brief Create new node for a binary tree
 * 
 * @param id The id field of the node
 * @param r Pointer to the record. Can be NULL
 * @return Node*
 */
Node* BT_createNode(Record *r);


/**
 * @brief Free binary tree
 * 
 * @param t Pointer to tree
 */
void BT_freeTree(Tree *t);


/**
 * @brief Free node and all child nodes along with all associated records
 * 
 * @param u Pointer to node
 */
void BT_freeNodesRecursive(Node *u);


/**
 * @brief Calculate depth of binary (sub)tree recursively
 * 
 * @param u Pointer to node
 * @return int 
 */
int BT_calculateDepth(Node *u);


/**
 * @brief Right rotate binary (sub)tree
 * 
 * @param u Pointer to root node
 * @return Node* 
 */
Node* BT_rotateRight(Node *u);


/**
 * @brief Left rotate binary (sub)tree
 * 
 * @param u Pointer to root node
 * @return Node* 
 */
Node* BT_rotateLeft(Node *u);


/**
 * @brief Search for record in node and all child nodes
 * 
 * @param u Pointer to node
 * @param r Pointer to record
 * @param recordsCompare Comparison function
 * @return Node* 
 */
Node* BT_searchRecursive(Node *u, Record *r, int (*recordsCompare) (Record *r1, Record *r2));


/**
 * @brief Search for record in binary tree
 * 
 * @param t 
 * @param r 
 * @return Node* 
 */
Node* BT_search(Tree *t, Record *r);


#endif
