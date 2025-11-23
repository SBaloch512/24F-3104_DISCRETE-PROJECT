// AutomatedProof.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "AutomatedProof.h"
#include <iostream>
using namespace std;

void AutomatedProof::provePrerequisiteChain(Course* courses, int courseCount, 
                                           int targetCourseId, 
                                           DynamicArray<int>& completed) {
    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║        AUTOMATED FORMAL PROOF                        ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    
    cout << "\nTheorem: Student can enroll in Course ID " << targetCourseId 
         << " if and only if all prerequisites are satisfied.\n";
    
    cout << "\n--- PROOF ---\n";
    
    Course* target = nullptr;
    for(int i = 0; i < courseCount; i++) {
        if(courses[i].courseId == targetCourseId) {
            target = &courses[i];
            break;
        }
    }
    
    if(!target) {
        cout << "✗ Course not found. Proof cannot proceed.\n";
        return;
    }
    
    cout << "\nStep 1: Identify the target course\n";
    cout << "  Target: " << target->courseName << " (ID: " << targetCourseId << ")\n";
    
    cout << "\nStep 2: Check Base Case (Mathematical Induction)\n";
    if(target->prerequisites.getSize() == 0) {
        cout << "  Base case holds: Course has no prerequisites.\n";
        cout << "  ∴ Student can enroll immediately.\n";
        cout << "\n✓ QED (Quod Erat Demonstrandum - Proof Complete)\n";
        return;
    }
    
    cout << "  Course has " << target->prerequisites.getSize() 
         << " prerequisite(s).\n";
    
    cout << "\nStep 3: Apply Inductive Hypothesis\n";
    cout << "  Assume: If prerequisites are completed, student can enroll.\n";
    
    cout << "\nStep 4: Verify each prerequisite\n";
    bool allSatisfied = true;
    for(int i = 0; i < target->prerequisites.getSize(); i++) {
        int prereqId = target->prerequisites[i];
        
        // Find prerequisite course name
        char prereqName[50] = "Unknown";
        for(int j = 0; j < courseCount; j++) {
            if(courses[j].courseId == prereqId) {
                strncpy(prereqName, courses[j].courseName, 49);
                break;
            }
        }
        
        if(completed.contains(prereqId)) {
            cout << "  ✓ Prerequisite " << (i+1) << ": Course ID " << prereqId 
                 << " (" << prereqName << ") is completed\n";
        } else {
            cout << "  ✗ Prerequisite " << (i+1) << ": Course ID " << prereqId 
                 << " (" << prereqName << ") is NOT completed\n";
            allSatisfied = false;
        }
    }
    
    cout << "\nStep 5: Conclusion\n";
    if(allSatisfied) {
        cout << "  All prerequisites are satisfied.\n";
        cout << "  By inductive hypothesis: Student CAN enroll.\n";
        cout << "\n✓ QED (Proof Complete)\n";
    } else {
        cout << "  Not all prerequisites are satisfied.\n";
        cout << "  By logical negation: Student CANNOT enroll.\n";
        cout << "\n✗ Proof shows enrollment is NOT permitted.\n";
    }
}

void AutomatedProof::proveSetEquality(int* setA, int sizeA, int* setB, int sizeB) {
    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║        PROOF: Set Equality                           ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    
    cout << "\nTheorem: Two sets A and B are equal iff A ⊆ B and B ⊆ A\n";
    
    cout << "\nSet A = { ";
    for(int i = 0; i < sizeA; i++) {
        cout << setA[i];
        if(i < sizeA - 1) cout << ", ";
    }
    cout << " }\n";
    
    cout << "Set B = { ";
    for(int i = 0; i < sizeB; i++) {
        cout << setB[i];
        if(i < sizeB - 1) cout << ", ";
    }
    cout << " }\n";
    
    cout << "\n--- PROOF ---\n";
    cout << "Step 1: Check if A ⊆ B (A is subset of B)\n";
    bool aSubsetB = true;
    for(int i = 0; i < sizeA; i++) {
        bool found = false;
        for(int j = 0; j < sizeB; j++) {
            if(setA[i] == setB[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "  ✗ Element " << setA[i] << " in A but not in B\n";
            aSubsetB = false;
        }
    }
    if(aSubsetB) cout << "  ✓ A ⊆ B holds\n";
    
    cout << "\nStep 2: Check if B ⊆ A (B is subset of A)\n";
    bool bSubsetA = true;
    for(int i = 0; i < sizeB; i++) {
        bool found = false;
        for(int j = 0; j < sizeA; j++) {
            if(setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "  ✗ Element " << setB[i] << " in B but not in A\n";
            bSubsetA = false;
        }
    }
    if(bSubsetA) cout << "  ✓ B ⊆ A holds\n";
    
    cout << "\nStep 3: Conclusion\n";
    if(aSubsetB && bSubsetA) {
        cout << "  Both conditions satisfied: A ⊆ B ∧ B ⊆ A\n";
        cout << "  ∴ A = B\n";
        cout << "\n✓ QED: Sets are EQUAL\n";
    } else {
        cout << "  Conditions not satisfied.\n";
        cout << "  ∴ A ≠ B\n";
        cout << "\n✗ Sets are NOT equal\n";
    }
}