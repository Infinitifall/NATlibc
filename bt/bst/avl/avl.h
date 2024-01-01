#ifndef NAT_BT_BST_AVL_AVL_H
#define NAT_BT_BST_AVL_AVL_H


#include "../../../record.h"
#include "../../bt.h"
#include "../bst.h"


/**
 * @brief Right rotate binary (sub)tree
 * 
 * @param u Pointer to root node
 * @return B_Node* 
 */
B_Node* AVL_rotateRight(B_Node *u);


/**
 * @brief Left rotate binary (sub)tree
 * 
 * @param u Pointer to root node
 * @return B_Node* 
 */
B_Node* AVL_rotateLeft(B_Node *u);


#endif
