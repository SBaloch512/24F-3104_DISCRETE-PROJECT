
#ifndef STUDENT_H
#define STUDENT_H

#include "DynamicArray.h"
#include <cstring>

class Student {
public:
    int studentId;
    char name[50];
    DynamicArray<int> enrolledCourses;
    DynamicArray<int> completedCourses;
    
    Student();
    Student(int id, const char* n);
    void enrollCourse(int courseId);
    void completeCourse(int courseId);
    void display() const;
};

#endif