// ConsistencyChecker.cpp
#include "ConsistencyChecker.h"
#include <iostream>
using namespace std;

bool ConsistencyChecker::checkCourseOverlap(Student* students, int studentCount) {
    cout << "\n=== Checking for Duplicate Course Enrollments ===\n";
    bool conflict = false;
    
    for(int i = 0; i < studentCount; i++) {
        for(int j = 0; j < students[i].enrolledCourses.getSize(); j++) {
            for(int k = j + 1; k < students[i].enrolledCourses.getSize(); k++) {
                if(students[i].enrolledCourses[j] == students[i].enrolledCourses[k]) {
                    cout << "✗ CONFLICT: Student " << students[i].name 
                         << " (ID: " << students[i].studentId 
                         << ") enrolled in course " << students[i].enrolledCourses[j] 
                         << " twice!\n";
                    conflict = true;
                }
            }
        }
    }
    
    if(!conflict) {
        cout << "✓ No duplicate course enrollments detected\n";
    }
    return !conflict;
}

bool ConsistencyChecker::checkStudentOverload(Student* students, int studentCount, 
                                              Course* courses, int courseCount, 
                                              int maxCredits) {
    cout << "\n=== Checking Student Credit Overload ===\n";
    cout << "Maximum allowed credits: " << maxCredits << "\n\n";
    
    bool overload = false;
    
    for(int i = 0; i < studentCount; i++) {
        int totalCredits = 0;
        
        for(int j = 0; j < students[i].enrolledCourses.getSize(); j++) {
            int courseId = students[i].enrolledCourses[j];
            
            // Find course credits
            for(int k = 0; k < courseCount; k++) {
                if(courses[k].courseId == courseId) {
                    totalCredits += courses[k].credits;
                    break;
                }
            }
        }
        
        cout << "Student " << students[i].name << " (ID: " << students[i].studentId 
             << "): " << totalCredits << " credits";
        
        if(totalCredits > maxCredits) {
            cout << " ✗ OVERLOAD!\n";
            overload = true;
        } else {
            cout << " ✓\n";
        }
    }
    
    if(!overload) {
        cout << "\n✓ No student overload detected\n";
    }
    return !overload;
}

bool ConsistencyChecker::checkPrerequisiteViolations(Student* students, 
                                                     int studentCount, 
                                                     Course* courses, 
                                                     int courseCount) {
    cout << "\n=== Checking Prerequisite Violations ===\n";
    bool violation = false;
    
    for(int i = 0; i < studentCount; i++) {
        for(int j = 0; j < students[i].enrolledCourses.getSize(); j++) {
            int courseId = students[i].enrolledCourses[j];
            
            // Find the course
            Course* currentCourse = nullptr;
            for(int k = 0; k < courseCount; k++) {
                if(courses[k].courseId == courseId) {
                    currentCourse = &courses[k];
                    break;
                }
            }
            
            if(currentCourse) {
                // Check if all prerequisites are completed
                for(int p = 0; p < currentCourse->prerequisites.getSize(); p++) {
                    int prereqId = currentCourse->prerequisites[p];
                    
                    if(!students[i].completedCourses.contains(prereqId)) {
                        cout << "✗ VIOLATION: Student " << students[i].name 
                             << " enrolled in " << currentCourse->courseName 
                             << " without completing prerequisite (ID: " 
                             << prereqId << ")\n";
                        violation = true;
                    }
                }
            }
        }
    }
    
    if(!violation) {
        cout << "✓ No prerequisite violations detected\n";
    }
    return !violation;
}

void ConsistencyChecker::runAllChecks(Student* students, int studentCount, 
                                     Course* courses, int courseCount, 
                                     int maxCredits) {
    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║        COMPREHENSIVE CONSISTENCY CHECK               ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    
    bool check1 = checkCourseOverlap(students, studentCount);
    bool check2 = checkStudentOverload(students, studentCount, courses, 
                                       courseCount, maxCredits);
    bool check3 = checkPrerequisiteViolations(students, studentCount, 
                                             courses, courseCount);
    
    cout << "\n═══════════════════════════════════════════════════════\n";
    if(check1 && check2 && check3) {
        cout << "✓✓✓ ALL CONSISTENCY CHECKS PASSED ✓✓✓\n";
    } else {
        cout << "✗✗✗ CONSISTENCY VIOLATIONS DETECTED ✗✗✗\n";
    }
    cout << "═══════════════════════════════════════════════════════\n";
}