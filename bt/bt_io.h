#ifndef NAT_BT_BT_IO_H_
#define NAT_BT_BT_IO_H_


#include "../record.h"
#include "./bt.h"


/**
 * @brief Print tree t, one node per line
 * 
 * @param t Pointer to tree
 */
void BT_printFlat(B_Tree *t);


/**
 * @brief Print (sub)tree with root u, one node per line
 * 
 * @param u Pointer to (sub)tree root
 */
void BT_printFlatR(B_Node *u);


/**
 * @brief Print tree, one node per line but with tabs and dashes
 * 
 * @param t Pointer to tree
 */
void BT_print2D(B_Tree *t);


/**
 * @brief Print (sub)tree with root u, one node per line but with tabs and dashes
 * 
 * @param u Pointer to (sub)tree root
 */
void BT_print2DR(B_Node *u);


/**
 * @brief Read list of integers defining a valid tree and return pointer to root
 * 
 * @param node_list List of (int node_index, int value, int node_parent_index)
 * @param node_count Length of node_list
 * @return B_Node* 
 */
B_Tree* BT_readInts(int **node_list, int node_count, int (*recordsCompare) (NAT_Record *r1, NAT_Record *r2));


#endif
