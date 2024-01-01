#include <stdlib.h>

#include "./record.h"


NAT_Record* NAT_createRecord(int value) {
    NAT_Record *r = malloc(sizeof(*r));

    static int record_count = 0;
    r->id = record_count;
    record_count++;

    r->value = value;

    return r;
}


void NAT_freeRecord(NAT_Record *r) {
    if (r == NULL) {
        return;
    }

    free(r);
}


int NAT_recordsCompare1(NAT_Record *r1, NAT_Record *r2) {
    if ((r1 == NULL) && (r2 == NULL)) {
        return 0;
        
    } else if (r1 == NULL) {
        return -1;

    } else if (r2 == NULL) {
        return 1;
    }

    int value_diff = r1->value - r2->value;
    int id_diff = r1->id - r2->id;

    if (value_diff != 0) {
        return id_diff;

    } else if (id_diff != 0) {
        return id_diff;

    } else {
        return 0;
    }
}
