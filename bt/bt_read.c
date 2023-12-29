#include <stdio.h>
#include <stdlib.h>

#include "bt.h"
#include "bt_read.h"


Node* BT_readInts(int **node_list, int node_count) {
	if (node_count == 0) {
		return NULL;
	}
	
	// create records
	Record **record_pointers = malloc(node_count * sizeof(*record_pointers));
	for (int i = 0; i < node_count; i++) {
		record_pointers[i] = NAT_createRecord(node_list[i][0]);
	}

	// create nodes
	Node **node_pointers = malloc(node_count * sizeof(*node_pointers));
	for (int i = 0; i < node_count; i++) {
		node_pointers[i] = BT_createNode(record_pointers[i]);
	}

	Node *root_node = NULL;

	// link child and parent nodes
	for (int i = 0; i < node_count; i++) {
		Node *curr = node_pointers[i];

		// if parent index is negative, its the root
		if (node_list[i][1] < 0) {
			fprintf(stderr, "Warn: node %d at %p has no parents, setting as root node.\n", i, curr);
			root_node = node_pointers[i];
			continue;

		} else if (node_list[i][1] > node_count) {
			fprintf(stderr, "Err: node %d at %p has invalid parent %d\n", i, curr, node_list[i][1]);
			continue;

		} else if (node_list[i][1] == i) {
			fprintf(stderr, "Err: node %d at %p cannot have self as parent\n", i, curr);
			continue;
		}

		Node *parent = node_pointers[node_list[i][1]];

		if (parent->left == NULL) {
			parent->left = curr;

		} else if (parent->right == NULL) {
			parent->right = curr;

		} else {
			fprintf(stderr, "Err: node at %p is full, cannot insert Node at %p as child\n", node_pointers[node_list[i][2]], curr);
		}
	}

	if (root_node == NULL) {
		fprintf(stderr, "Err: no root node detected!");
	}
	
	return root_node;
}
