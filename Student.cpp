// Student.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : studentId(0) {
    name[0] = '\0';
}

Student::Student(int id, const char* n) : studentId(id) {
    strncpy(name, n, 49);
    name[49] = '\0';
}

void Student::enrollCourse(int courseId) {
    enrolledCourses.push_back(courseId);
}

void Student::completeCourse(int courseId) {
    completedCourses.push_back(courseId);
}

void Student::display() const {
    cout << "Student ID: " << studentId << "\n";
    cout << "Name: " << name << "\n";
    cout << "Enrolled Courses: ";
    enrolledCourses.print();
    cout << "\nCompleted Courses: ";
    completedCourses.print();
    cout << "\n";
}