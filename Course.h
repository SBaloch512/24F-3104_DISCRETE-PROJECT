// Course.h
#ifndef COURSE_H
#define COURSE_H

#include "DynamicArray.h"
#include <cstring>

class Course {
public:
    int courseId;
    char courseName[50];
    DynamicArray<int> prerequisites;
    int credits;
    
    Course();
    Course(int id, const char* name, int cred = 3);
    void addPrerequisite(int prereqId);
    void display() const;
};

#endif