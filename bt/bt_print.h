#ifndef BT_BT_PRINT_H_
#define BT_BT_PRINT_H_


/**
 * @brief Print binary tree, one node per line
 * 
 * @param t Pointer to tree
 */
void BT_printFlatTree(Tree *t);


/**
 * @brief Print (sub)tree, one node per line
 * 
 * @param u Pointer to node
 */
void BT_printFlat(Node *u);


/**
 * @brief Print binary tree in 2d tabbed format
 * 
 * @param t Pointer to tree
 */
void BT_print2DTree(Tree *t);


/**
 * @brief Print (sub)tree in 2d tabbed format
 * 
 * @param u Pointer to node
 */
void BT_print2D(Node *u);


#endif
