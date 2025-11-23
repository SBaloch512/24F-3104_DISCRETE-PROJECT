// InductionModule.h
#ifndef INDUCTIONMODULE_H
#define INDUCTIONMODULE_H

#include "Course.h"
#include "DynamicArray.h"

class InductionModule {
private:
    Course* courses;
    int courseCount;
    
    bool verifyPrerequisitesRecursive(int courseId, DynamicArray<int>& completed, 
                                     int depth);
    
public:
    InductionModule(Course* c, int count);
    bool verifyPrerequisiteChain(int courseId, DynamicArray<int>& completedCourses);
};

#endif