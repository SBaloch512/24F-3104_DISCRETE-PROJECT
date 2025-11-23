// Faculty.h
#ifndef FACULTY_H
#define FACULTY_H

#include "DynamicArray.h"
#include <cstring>

class Faculty {
public:
    int facultyId;
    char name[50];
    DynamicArray<int> assignedCourses;
    
    Faculty();
    Faculty(int id, const char* n);
    void assignCourse(int courseId);
    void display() const;
};

#endif