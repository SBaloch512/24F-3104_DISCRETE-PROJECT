// AutomatedProof.h
#ifndef AUTOMATEDPROOF_H
#define AUTOMATEDPROOF_H

#include "Course.h"
#include "DynamicArray.h"

class AutomatedProof {
public:
    void provePrerequisiteChain(Course* courses, int courseCount, 
                               int targetCourseId, DynamicArray<int>& completed);
    void proveSetEquality(int* setA, int sizeA, int* setB, int sizeB);
};

#endif