#include <stdio.h>
#include <stdlib.h>

#include "../record.h"
#include "./bt.h"
#include "./bt_io.h"


void BT_printFlat(B_Tree *t) {
    BT_printFlatR(t->root_node);
}


void BT_printFlatR(B_Node *u) {
    if (u == NULL) {
        return;
    }

    BT_printFlatR(u->left);
    fprintf(stdout, "%d: %d\n", u->id, u->record->value);
    BT_printFlatR(u->right);
}


static void BT_print2DChild(B_Node *u, int tabs) {
    if (u == NULL) {
        return;
    }

    BT_print2DChild(u->left, tabs + 1);

    for (int i = 0; i < tabs - 1; i++) {
        fprintf(stdout, "|      ");
    }

    if (tabs > 0) {
        fprintf(stdout, "|______");
    }

    fprintf(stdout, "%d,%d\n", u->id, u->record->value);

    BT_print2DChild(u->right, tabs + 1);
}


void BT_print2D(B_Tree *t) {
    BT_print2DR(t->root_node);
}


void BT_print2DR(B_Node *u) {
	return BT_print2DChild(u, 0);
}


B_Tree* BT_readInts(int **node_list, int node_count, int (*recordsCompare) (NAT_Record *r1, NAT_Record *r2)) {
	if (node_count == 0) {
		return NULL;
	}
	
	// create records
	NAT_Record **record_pointers = malloc(node_count * sizeof(*record_pointers));
	for (int i = 0; i < node_count; i++) {
		record_pointers[i] = NAT_createRecord(node_list[i][0]);
	}

	// create nodes
	B_Node **node_pointers = malloc(node_count * sizeof(*node_pointers));
	for (int i = 0; i < node_count; i++) {
		node_pointers[i] = BT_createNode(record_pointers[i]);
	}

	B_Node *root_node = NULL;

	// link child and parent nodes
	for (int i = 0; i < node_count; i++) {
		B_Node *curr = node_pointers[i];

		// if parent index is negative, assume root
		if (node_list[i][1] < 0) {
			fprintf(stderr, "Note: node %d at %p has no parents, setting as root node.\n", i, curr);
			root_node = node_pointers[i];
			continue;

		} else if (node_list[i][1] > node_count) {
			fprintf(stderr, "Warn: node %d at %p has invalid parent %d\n", i, curr, node_list[i][1]);
			continue;

		} else if (node_list[i][1] == i) {
			fprintf(stderr, "Warn: node %d at %p cannot have self as parent\n", i, curr);
			continue;
		}

		B_Node *parent = node_pointers[node_list[i][1]];

		if (parent->left == NULL) {
			parent->left = curr;

		} else if (parent->right == NULL) {
			parent->right = curr;

		} else {
			fprintf(stderr, "Warn: node at %p is full, cannot insert B_Node at %p as child\n", node_pointers[node_list[i][2]], curr);
		}
	}

	if (root_node == NULL) {
		fprintf(stderr, "Err: no root node detected! Aborting.\n");
		
		// free all records and nodes
		for (int i = 0; i < node_count; i++) {
			NAT_freeRecord(record_pointers[i]);
			BT_freeNode(node_pointers[i]);
		}

		free(record_pointers);
		free(node_pointers);

		// TODO: memory leak check

		return NULL;
	}

	B_Tree *return_tree = BT_createTree(recordsCompare);
	return_tree->root_node = root_node;
	
	return return_tree;
}



