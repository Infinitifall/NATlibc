#ifndef NAT_RECORD_H_
#define NAT_RECORD_H_


typedef struct nat_record {
    // unique id for record
    int id;

    int value;
    
    /**
     * Add extra fields here
     * 
     */

} NAT_Record;


/**
 * @brief Create new record
 * 
 * @param value The "value" field of the created record
 * @return NAT_Record* Pointer to created record
 */
NAT_Record* NAT_createRecord(int value);


/**
 * @brief Free record r
 * 
 * @param r Pointer to record
 */
void NAT_freeRecord(NAT_Record *r);


/**
 * @brief A function to compare records. Compares by: value, id
 * 
 * @param r1 Pointer to record 1
 * @param r2 Pointer to record 2
 * @return int > 0 if |r1| > |r2|, < 0 if |r1| < |r2|, == 0 if |r1| == |r2|
 */
int NAT_recordsCompare1(NAT_Record *r1, NAT_Record *r2);


/**
 * Add compare functions here
 * 
 */


#endif
