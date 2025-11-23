// InductionModule.cpp
#include "InductionModule.h"
#include <iostream>
using namespace std;

InductionModule::InductionModule(Course* c, int count) : courses(c), courseCount(count) {}

bool InductionModule::verifyPrerequisitesRecursive(int courseId, 
                                                   DynamicArray<int>& completed, 
                                                   int depth) {
    Course* targetCourse = nullptr;
    for(int i = 0; i < courseCount; i++) {
        if(courses[i].courseId == courseId) {
            targetCourse = &courses[i];
            break;
        }
    }
    
    if(!targetCourse) {
        cout << "Course ID " << courseId << " not found!\n";
        return false;
    }
    
    // Base case (Mathematical Induction): No prerequisites
    if(targetCourse->prerequisites.getSize() == 0) {
        cout << "Base Case (Depth " << depth << "): Course '" 
             << targetCourse->courseName << "' has no prerequisites ✓\n";
        return true;
    }
    
    // Inductive step: Check all prerequisites
    cout << "Inductive Step (Depth " << depth << "): Checking prerequisites for '" 
         << targetCourse->courseName << "'\n";
    
    for(int i = 0; i < targetCourse->prerequisites.getSize(); i++) {
        int prereqId = targetCourse->prerequisites[i];
        
        if(!completed.contains(prereqId)) {
            cout << "  ✗ Missing prerequisite: Course ID " << prereqId << "\n";
            return false;
        }
        
        cout << "  ✓ Prerequisite Course ID " << prereqId << " is completed\n";
        
        // Strong induction: Verify prerequisites of prerequisites
        if(!verifyPrerequisitesRecursive(prereqId, completed, depth + 1)) {
            return false;
        }
    }
    
    return true;
}

bool InductionModule::verifyPrerequisiteChain(int courseId, 
                                              DynamicArray<int>& completedCourses) {
    cout << "\n=== Verifying Prerequisites Using Mathematical Induction ===\n";
    cout << "Checking if student can take Course ID " << courseId << "\n\n";
    
    bool result = verifyPrerequisitesRecursive(courseId, completedCourses, 0);
    
    cout << "\n" << (result ? "✓ VERIFICATION PASSED" : "✗ VERIFICATION FAILED") << "\n";
    return result;
}