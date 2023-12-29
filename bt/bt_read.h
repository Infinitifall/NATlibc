#ifndef BT_BT_READ_H_
#define BT_BT_READ_H_


/**
 * @brief Read in list of integers defining a valid tree and return pointer to root
 * 
 * @param node_list List of (int node_index, int value, int node_parent_index)
 * @param node_count Length of node_list
 * @return Node* 
 */
Node* BT_readInts(int **node_list, int node_count);


#endif
