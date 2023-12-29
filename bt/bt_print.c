#include <stdio.h>
#include <stdlib.h>

#include "bt.h"
#include "bt_print.h"


void BT_printFlatTree(Tree *t) {
    BT_printFlat(t->root_node);
}


void BT_printFlat(Node *u) {
    if (u == NULL) {
        return;
    }

    BT_printFlat(u->left);
    printf("%d: %d\n",  u->id, u->record->value);
    BT_printFlat(u->right);
}


void BT_print2DTree(Tree *t) {
    BT_print2D(t->root_node);
}


static void BT_print2DChild(Node *u, int tabs) {
    if (u == NULL) {
        return;
    }

    BT_print2DChild(u->left, tabs + 1);

    for (int i = 0; i < tabs - 1; i++) {
        printf("|      ");
    }
    if (tabs > 0) {
        printf("|______");
    }
    printf("%d,%d\n", u->id, u->record->value);

    BT_print2DChild(u->right, tabs + 1);
}


void BT_print2D(Node *u) {
	return BT_print2DChild(u, 0);
}


