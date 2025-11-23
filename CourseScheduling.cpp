// CourseScheduling.cpp
#include "CourseScheduling.h"
#include <iostream>
using namespace std;

CourseScheduling::CourseScheduling() : courseCount(0), maxCourses(100) {
    courses = new Course[maxCourses];
}

CourseScheduling::~CourseScheduling() {
    delete[] courses;
}

void CourseScheduling::addCourse(int id, const char* name, int credits) {
    if(courseCount < maxCourses) {
        courses[courseCount++] = Course(id, name, credits);
        cout << "Course added successfully!\n";
    } else {
        cout << "Maximum courses limit reached!\n";
    }
}

void CourseScheduling::addPrerequisite(int courseId, int prereqId) {
    for(int i = 0; i < courseCount; i++) {
        if(courses[i].courseId == courseId) {
            courses[i].addPrerequisite(prereqId);
            cout << "Prerequisite added successfully!\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

void CourseScheduling::generateSequencesHelper(bool* taken, DynamicArray<int>& current, 
                                               int level, int total) {
    if(level == total) {
        cout << "Valid Sequence: ";
        for(int i = 0; i < current.getSize(); i++) {
            Course& c = courses[current[i]];
            cout << c.courseName;
            if(i < current.getSize() - 1) cout << " -> ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < courseCount; i++) {
        if(!taken[i]) {
            bool canTake = true;
            
            // Check if all prerequisites are taken
            for(int j = 0; j < courses[i].prerequisites.getSize(); j++) {
                int prereqId = courses[i].prerequisites[j];
                bool prereqTaken = false;
                
                for(int k = 0; k < current.getSize(); k++) {
                    if(courses[current[k]].courseId == prereqId) {
                        prereqTaken = true;
                        break;
                    }
                }
                
                if(!prereqTaken) {
                    canTake = false;
                    break;
                }
            }
            
            if(canTake) {
                taken[i] = true;
                current.push_back(i);
                generateSequencesHelper(taken, current, level + 1, total);
                current.pop_back();
                taken[i] = false;
            }
        }
    }
}

void CourseScheduling::generateValidSequences() {
    if(courseCount == 0) {
        cout << "No courses available!\n";
        return;
    }
    
    cout << "\n=== Generating Valid Course Sequences ===\n";
    bool* taken = new bool[courseCount];
    for(int i = 0; i < courseCount; i++) taken[i] = false;
    
    DynamicArray<int> current;
    generateSequencesHelper(taken, current, 0, courseCount);
    delete[] taken;
}

void CourseScheduling::displayAllCourses() {
    cout << "\n=== All Courses ===\n";
    for(int i = 0; i < courseCount; i++) {
        courses[i].display();
        cout << "------------------------\n";
    }
}

Course* CourseScheduling::getCourses() {
    return courses;
}

int CourseScheduling::getCourseCount() {
    return courseCount;
}

Course* CourseScheduling::findCourse(int courseId) {
    for(int i = 0; i < courseCount; i++) {
        if(courses[i].courseId == courseId) {
            return &courses[i];
        }
    }
    return nullptr;
}