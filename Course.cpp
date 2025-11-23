// Course.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Course.h"
#include <iostream>
using namespace std;

Course::Course() : courseId(0), credits(3) {
    courseName[0] = '\0';
}

Course::Course(int id, const char* name, int cred) : courseId(id), credits(cred) {
    strncpy(courseName, name, 49);
    courseName[49] = '\0';
}

void Course::addPrerequisite(int prereqId) {
    prerequisites.push_back(prereqId);
}

void Course::display() const {
    cout << "Course ID: " << courseId << "\n";
    cout << "Name: " << courseName << "\n";
    cout << "Credits: " << credits << "\n";
    cout << "Prerequisites: ";
    if(prerequisites.getSize() == 0) {
        cout << "None";
    } else {
        for(int i = 0; i < prerequisites.getSize(); i++) {
            cout << prerequisites[i];
            if(i < prerequisites.getSize() - 1) cout << ", ";
        }
    }
    cout << "\n";
}