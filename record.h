#ifndef RECORD_H_
#define RECORD_H_


typedef struct record {

    // Unique id for every record
    int id;

    int value;
    
    /**
     * Add extra fields here
     * 
     */

} Record;


/**
 * @brief Create a new Record object
 * 
 * @param id The id field of the record
 * @param value The value field of the record
 * @return Record* Pointer to the created record
 */
Record* NAT_createRecord(int value);


/**
 * @brief Compare two records (in order: value, id)
 * 
 * @param r1 
 * @param r2 
 * @return int Positive if r2 > r1, negative if r2 < r1 and 0 if they are equal
 */
int NAT_recordsCompare1(Record *r1, Record *r2);


/**
 * Add compare functions here
 * 
 */


#endif
