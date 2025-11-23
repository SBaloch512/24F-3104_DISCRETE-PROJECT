// SetOperations.h
#ifndef SETOPERATIONS_H
#define SETOPERATIONS_H

class SetOperations {
public:
    struct Set {
        int* elements;
        int size;
        int capacity;
        
        Set();
        ~Set();
        void add(int elem);
        bool contains(int elem) const;
        void print() const;
    };
    
    Set* createSet();
    Set* unionSets(Set* A, Set* B);
    Set* intersectionSets(Set* A, Set* B);
    Set* differenceSets(Set* A, Set* B);
    void printPowerSet(Set* A);
    void demonstrateOperations();
};

#endif