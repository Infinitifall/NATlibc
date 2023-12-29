#include <stdio.h>
#include <stdlib.h>

#include "record.h"


Record* NAT_createRecord(int value) {
    Record *r = malloc(sizeof(*r));

    static int record_count = 0;
    r->id = record_count;
    record_count++;

    r->value = value;

    return r;
}


int NAT_recordsCompare1(Record *r1, Record *r2) {
    int value_diff = r2->value - r1->value;
    int id_diff = r2->id - r1->id;

    if (value_diff != 0) {
        return id_diff;

    } else if (id_diff != 0) {
        return id_diff;

    } else {
        return 0;
    }
}
