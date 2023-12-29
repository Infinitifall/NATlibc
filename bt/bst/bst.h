#ifndef BT_BST_BST_H
#define BT_BST_BST_H


/**
 * @brief Search for record in node and all child nodes
 * 
 * @param u Pointer to node
 * @param r Pointer to record
 * @param recordsCompare Comparison function
 * @return Node* 
 */
Node* BST_searchRecursive(Node *u, Record *r, int (*recordsCompare) (Record *r1, Record *r2));


/**
 * @brief Search for node/record in binary tree
 * 
 * @param t 
 * @param r 
 * @return Node* 
 */
Node* BST_search(Tree *t, Record *r);


/**
 * @brief Insert node/record into binary tree
 * 
 * @param t 
 * @param r 
 * @return Node* 
 */
Node* BST_insert(Tree *t, Record *r);


/**
 * @brief Delete node/record from binary tree
 * 
 * @param t 
 * @param r 
 * @return Node* 
 */
Node* BST_insert(Tree *t, Record *r);


#endif
