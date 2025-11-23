// SetOperations.cpp
#include "SetOperations.h"
#include <iostream>
using namespace std;

SetOperations::Set::Set() : size(0), capacity(50) {
    elements = new int[capacity];
}

SetOperations::Set::~Set() {
    delete[] elements;
}

void SetOperations::Set::add(int elem) {
    if(!contains(elem)) {
        if(size >= capacity) {
            capacity *= 2;
            int* newElems = new int[capacity];
            for(int i = 0; i < size; i++) {
                newElems[i] = elements[i];
            }
            delete[] elements;
            elements = newElems;
        }
        elements[size++] = elem;
    }
}

bool SetOperations::Set::contains(int elem) const {
    for(int i = 0; i < size; i++) {
        if(elements[i] == elem) return true;
    }
    return false;
}

void SetOperations::Set::print() const {
    cout << "{ ";
    for(int i = 0; i < size; i++) {
        cout << elements[i];
        if(i < size - 1) cout << ", ";
    }
    cout << " }";
}

SetOperations::Set* SetOperations::createSet() {
    return new Set();
}

SetOperations::Set* SetOperations::unionSets(Set* A, Set* B) {
    Set* result = new Set();
    for(int i = 0; i < A->size; i++) {
        result->add(A->elements[i]);
    }
    for(int i = 0; i < B->size; i++) {
        result->add(B->elements[i]);
    }
    return result;
}

SetOperations::Set* SetOperations::intersectionSets(Set* A, Set* B) {
    Set* result = new Set();
    for(int i = 0; i < A->size; i++) {
        if(B->contains(A->elements[i])) {
            result->add(A->elements[i]);
        }
    }
    return result;
}

SetOperations::Set* SetOperations::differenceSets(Set* A, Set* B) {
    Set* result = new Set();
    for(int i = 0; i < A->size; i++) {
        if(!B->contains(A->elements[i])) {
            result->add(A->elements[i]);
        }
    }
    return result;
}

void SetOperations::printPowerSet(Set* A) {
    int n = A->size;
    int powerSetSize = (1 << n);  // 2^n using bit manipulation
    
    cout << "\nPower Set (all subsets):\n";
    for(int counter = 0; counter < powerSetSize; counter++) {
        cout << "{ ";
        for(int j = 0; j < n; j++) {
            if(counter & (1 << j)) {
                cout << A->elements[j] << " ";
            }
        }
        cout << "}\n";
    }
}

void SetOperations::demonstrateOperations() {
    cout << "\n=== Set Operations Demonstration ===\n";
    
    Set* cs101Students = createSet();
    Set* math101Students = createSet();
    
    cout << "Adding students to CS101: {1, 2, 3, 5}\n";
    cs101Students->add(1);
    cs101Students->add(2);
    cs101Students->add(3);
    cs101Students->add(5);
    
    cout << "Adding students to Math101: {2, 3, 4, 6}\n";
    math101Students->add(2);
    math101Students->add(3);
    math101Students->add(4);
    math101Students->add(6);
    
    cout << "\nCS101 Students: ";
    cs101Students->print();
    cout << "\nMath101 Students: ";
    math101Students->print();
    cout << "\n";
    
    Set* unionResult = unionSets(cs101Students, math101Students);
    cout << "\nUnion (students in at least one course): ";
    unionResult->print();
    
    Set* intersectionResult = intersectionSets(cs101Students, math101Students);
    cout << "\nIntersection (students in BOTH courses): ";
    intersectionResult->print();
    
    Set* differenceResult = differenceSets(cs101Students, math101Students);
    cout << "\nDifference (CS101 - Math101): ";
    differenceResult->print();
    cout << "\n";
    
    delete cs101Students;
    delete math101Students;
    delete unionResult;
    delete intersectionResult;
    delete differenceResult;
}