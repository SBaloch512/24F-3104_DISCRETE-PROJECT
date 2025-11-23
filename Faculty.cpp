// Faculty.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty() : facultyId(0) {
    name[0] = '\0';
}

Faculty::Faculty(int id, const char* n) : facultyId(id) {
    strncpy(name, n, 49);
    name[49] = '\0';
}

void Faculty::assignCourse(int courseId) {
    assignedCourses.push_back(courseId);
}

void Faculty::display() const {
    cout << "Faculty ID: " << facultyId << "\n";
    cout << "Name: " << name << "\n";
    cout << "Assigned Courses: ";
    assignedCourses.print();
    cout << "\n";
}