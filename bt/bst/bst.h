#ifndef NAT_BT_BST_BST_H
#define NAT_BT_BST_BST_H


#include "../../record.h"
#include "../bt.h"


/**
 * @brief Search for node with record r in (sub)tree with root u
 * 
 * @param u Pointer to node
 * @param r Pointer to record
 * @param f Pointer to recordsCompare function
 * @return B_Node* Pointer to node if found else NULL
 */
B_Node* BST_searchR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2));


/**
 * @brief Search for node with record r in tree t
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 * @return B_Node* Pointer to node if found else NULL
 */
B_Node* BST_search(B_Tree *t, NAT_Record *r);


/**
 * @brief (Create and) Insert node with record r in (sub)tree with root u. 
 * Doesn't insert duplicates, instead returns pre-existing node.
 * 
 * @param u Pointer to (sub)tree root
 * @param r Pointer to record
 * @param f Pointer to recordsCompare function
 * @return B_Node* 
 */
B_Node* BST_insertR(B_Node *u, NAT_Record *r, int (*f) (NAT_Record *r1, NAT_Record *r2));


/**
 * @brief (Create and) Insert node with record r in tree t. 
 * Doesn't insert duplicates, instead returns pre-existing node.
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 * @return B_Node* 
 */
void BST_insert(B_Tree *t, NAT_Record *r);


/**
 * @brief Delete node with record r from tree t
 * 
 * @param t Pointer to tree
 * @param r Pointer to record
 * @return B_Node* 
 */
B_Node* BST_delete(B_Tree *t, NAT_Record *r);


#endif
