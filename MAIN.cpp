// Main.cpp
#include<windows.h>
#include <iostream>
#include <cstring>
#include "CourseScheduling.h"
#include "StudentGroupCombination.h"
#include "InductionModule.h"
#include "LogicInference.h"
#include "SetOperations.h"
#include "RelationsModule.h"
#include "FunctionsModule.h"
#include "AutomatedProof.h"
#include "ConsistencyChecker.h"
#include "AlgorithmicEfficiency.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

// Global data arrays
Student students[50];
int studentCount = 0;
Faculty faculties[50];
int facultyCount = 0;

void displayHeader() {
    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║                 UNIDISC ENGINE                       ║\n";
    cout << "║         FAST University Management System            ║\n";
    cout << "║      Discrete Structures Implementation              ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
}

void displayMainMenu() {
    cout << "\n═══════════════════════════════════════════════════════\n";
    cout << "                    MAIN MENU\n";
    cout << "═══════════════════════════════════════════════════════\n";
    cout << " 1.  Course Scheduling & Sequences\n";
    cout << " 2.  Student Group Combinations\n";
    cout << " 3.  Induction & Strong Induction\n";
    cout << " 4.  Logic & Inference Engine\n";
    cout << " 5.  Set Operations\n";
    cout << " 6.  Relations Module\n";
    cout << " 7.  Functions Module\n";
    cout << " 8.  Automated Proof & Verification\n";
    cout << " 9.  Consistency Checker\n";
    cout << " 10. Algorithmic Efficiency Demo\n";
    cout << " 11. Data Management (Add/View Students, Courses, etc.)\n";
    cout << " 0.  Exit\n";
    cout << "═══════════════════════════════════════════════════════\n";
    cout << "Enter your choice: ";
}

void module1_CourseScheduling(CourseScheduling& scheduler) {
    int choice;
    do {
        cout << "\n--- Module 1: Course Scheduling ---\n";
        cout << "1. Add Course\n";
        cout << "2. Add Prerequisite\n";
        cout << "3. Display All Courses\n";
        cout << "4. Generate Valid Course Sequences\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, credits;
            char name[50];
            cout << "Enter Course ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Course Name: ";
            cin.getline(name, 50);
            cout << "Enter Credits: ";
            cin >> credits;

            scheduler.addCourse(id, name, credits);

        }
        else if (choice == 2) {
            int courseId, prereqId;
            cout << "Enter Course ID: ";
            cin >> courseId;
            cout << "Enter Prerequisite Course ID: ";
            cin >> prereqId;

            scheduler.addPrerequisite(courseId, prereqId);

        }
        else if (choice == 3) {
            scheduler.displayAllCourses();

        }
        else if (choice == 4) {
            scheduler.generateValidSequences();
        }
    } while (choice != 0);
}

void module2_StudentGroups(StudentGroupCombination& groupManager) {
    int numStudents, groupSize;

    cout << "\n--- Module 2: Student Group Combinations ---\n";
    cout << "Enter total number of students: ";
    cin >> numStudents;
    cout << "Enter group size: ";
    cin >> groupSize;

    if (numStudents > 0 && groupSize > 0 && groupSize <= numStudents) {
        groupManager.calculateCombinations(numStudents, groupSize);

        char generate;
        cout << "\nGenerate all groups? (y/n): ";
        cin >> generate;

        if (generate == 'y' || generate == 'Y') {
            int* studentIds = new int[numStudents];
            for (int i = 0; i < numStudents; i++) {
                studentIds[i] = i + 1;
            }
            groupManager.generateGroups(studentIds, numStudents, groupSize);
            delete[] studentIds;
        }
    }
    else {
        cout << "Invalid input!\n";
    }
}

void module3_Induction(CourseScheduling& scheduler) {
    int courseId;
    int numCompleted;

    cout << "\n--- Module 3: Induction & Strong Induction ---\n";
    scheduler.displayAllCourses();

    cout << "\nEnter Course ID to verify prerequisites: ";
    cin >> courseId;

    cout << "How many courses has the student completed? ";
    cin >> numCompleted;

    DynamicArray<int> completed;
    cout << "Enter completed course IDs:\n";
    for (int i = 0; i < numCompleted; i++) {
        int id;
        cout << "  Course " << (i + 1) << ": ";
        cin >> id;
        completed.push_back(id);
    }

    InductionModule inductionEngine(scheduler.getCourses(),
        scheduler.getCourseCount());
    inductionEngine.verifyPrerequisiteChain(courseId, completed);
}

void module4_LogicInference(LogicInference& logicEngine) {
    int choice;
    do {
        cout << "\n--- Module 4: Logic & Inference Engine ---\n";
        cout << "1. Add Logic Rule\n";
        cout << "2. Verify Rule\n";
        cout << "3. Infer Consequences\n";
        cout << "4. Display All Rules\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int facultyId, courseId, labId;
            cout << "Enter Faculty ID: ";
            cin >> facultyId;
            cout << "Enter Course ID: ";
            cin >> courseId;
            cout << "Enter Lab ID (consequence): ";
            cin >> labId;

            logicEngine.addRule(facultyId, courseId, labId, 'F');

        }
        else if (choice == 2) {
            int facultyId, courseId, labId;
            cout << "Enter Faculty ID: ";
            cin >> facultyId;
            cout << "Enter Course ID: ";
            cin >> courseId;
            cout << "Enter Expected Lab ID: ";
            cin >> labId;

            logicEngine.verifyRule(facultyId, courseId, labId);

        }
        else if (choice == 3) {
            int facultyId, courseId;
            cout << "Enter Faculty ID: ";
            cin >> facultyId;
            cout << "Enter Course ID: ";
            cin >> courseId;

            logicEngine.inferConsequences(facultyId, courseId);

        }
        else if (choice == 4) {
            logicEngine.displayAllRules();
        }
    } while (choice != 0);
}

void module5_SetOperations(SetOperations& setOps) {
    int choice;
    do {
        cout << "\n--- Module 5: Set Operations ---\n";
        cout << "1. Demonstrate Set Operations (Pre-defined)\n";
        cout << "2. Custom Set Operations\n";
        cout << "3. Generate Power Set\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            setOps.demonstrateOperations();

        }
        else if (choice == 2) {
            int sizeA, sizeB;
            cout << "Enter size of Set A: ";
            cin >> sizeA;

            SetOperations::Set* setA = setOps.createSet();
            cout << "Enter elements of Set A:\n";
            for (int i = 0; i < sizeA; i++) {
                int elem;
                cout << "  Element " << (i + 1) << ": ";
                cin >> elem;
                setA->add(elem);
            }

            cout << "Enter size of Set B: ";
            cin >> sizeB;

            SetOperations::Set* setB = setOps.createSet();
            cout << "Enter elements of Set B:\n";
            for (int i = 0; i < sizeB; i++) {
                int elem;
                cout << "  Element " << (i + 1) << ": ";
                cin >> elem;
                setB->add(elem);
            }

            cout << "\nSet A: "; setA->print();
            cout << "\nSet B: "; setB->print();

            SetOperations::Set* unionSet = setOps.unionSets(setA, setB);
            cout << "\n\nUnion (A ∪ B): "; unionSet->print();

            SetOperations::Set* intersectionSet = setOps.intersectionSets(setA, setB);
            cout << "\nIntersection (A ∩ B): "; intersectionSet->print();

            SetOperations::Set* differenceSet = setOps.differenceSets(setA, setB);
            cout << "\nDifference (A - B): "; differenceSet->print();
            cout << "\n";

            delete setA;
            delete setB;
            delete unionSet;
            delete intersectionSet;
            delete differenceSet;

        }
        else if (choice == 3) {
            int size;
            cout << "Enter set size (max 10 for visibility): ";
            cin >> size;

            if (size > 10) {
                cout << "Warning: Large power sets have 2^n elements!\n";
                return;
            }

            SetOperations::Set* mySet = setOps.createSet();
            cout << "Enter elements:\n";
            for (int i = 0; i < size; i++) {
                int elem;
                cout << "  Element " << (i + 1) << ": ";
                cin >> elem;
                mySet->add(elem);
            }

            cout << "\nOriginal Set: "; mySet->print();
            setOps.printPowerSet(mySet);
            delete mySet;
        }
    } while (choice != 0);
}

void module6_Relations(RelationsModule& relations) {
    int choice;
    int elements[20];
    int elemCount = 0;

    do {
        cout << "\n--- Module 6: Relations ---\n";
        cout << "1. Add Relation\n";
        cout << "2. Display Relations\n";
        cout << "3. Check Relation Properties\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int from, to;
            cout << "Enter relation (from, to):\n";
            cout << "From: ";
            cin >> from;
            cout << "To: ";
            cin >> to;

            relations.addRelation(from, to);

            // Track unique elements
            bool foundFrom = false, foundTo = false;
            for (int i = 0; i < elemCount; i++) {
                if (elements[i] == from) foundFrom = true;
                if (elements[i] == to) foundTo = true;
            }
            if (!foundFrom) elements[elemCount++] = from;
            if (!foundTo) elements[elemCount++] = to;

        }
        else if (choice == 2) {
            relations.printRelations();

        }
        else if (choice == 3) {
            relations.checkProperties(elements, elemCount);
        }
    } while (choice != 0);
}

void module7_Functions(FunctionsModule& functions) {
    int choice;
    int codomain[50];
    int codomainSize = 0;

    do {
        cout << "\n--- Module 7: Functions ---\n";
        cout << "1. Add Function Mapping\n";
        cout << "2. Display Mappings\n";
        cout << "3. Check Function Properties\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int from, to;
            cout << "Enter mapping (Course -> Faculty):\n";
            cout << "Course ID: ";
            cin >> from;
            cout << "Faculty ID: ";
            cin >> to;

            functions.addMapping(from, to);

            // Track codomain
            bool found = false;
            for (int i = 0; i < codomainSize; i++) {
                if (codomain[i] == to) {
                    found = true;
                    break;
                }
            }
            if (!found) codomain[codomainSize++] = to;

        }
        else if (choice == 2) {
            functions.printMappings();

        }
        else if (choice == 3) {
            if (codomainSize == 0) {
                cout << "Please add mappings first!\n";
            }
            else {
                functions.checkFunctionProperties(codomain, codomainSize);
            }
        }
    } while (choice != 0);
}

void module8_AutomatedProof(CourseScheduling& scheduler, AutomatedProof& proofEngine) {
    int choice;
    do {
        cout << "\n--- Module 8: Automated Proof & Verification ---\n";
        cout << "1. Prove Prerequisite Chain\n";
        cout << "2. Prove Set Equality\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int courseId, numCompleted;

            scheduler.displayAllCourses();
            cout << "\nEnter Course ID for proof: ";
            cin >> courseId;

            cout << "How many courses completed? ";
            cin >> numCompleted;

            DynamicArray<int> completed;
            cout << "Enter completed course IDs:\n";
            for (int i = 0; i < numCompleted; i++) {
                int id;
                cout << "  Course " << (i + 1) << ": ";
                cin >> id;
                completed.push_back(id);
            }

            proofEngine.provePrerequisiteChain(scheduler.getCourses(),
                scheduler.getCourseCount(),
                courseId, completed);

        }
        else if (choice == 2) {
            int sizeA, sizeB;
            cout << "Enter size of Set A: ";
            cin >> sizeA;
            int* setA = new int[sizeA];
            cout << "Enter elements of Set A:\n";
            for (int i = 0; i < sizeA; i++) {
                cout << "  Element " << (i + 1) << ": ";
                cin >> setA[i];
            }

            cout << "Enter size of Set B: ";
            cin >> sizeB;
            int* setB = new int[sizeB];
            cout << "Enter elements of Set B:\n";
            for (int i = 0; i < sizeB; i++) {
                cout << "  Element " << (i + 1) << ": ";
                cin >> setB[i];
            }

            proofEngine.proveSetEquality(setA, sizeA, setB, sizeB);

            delete[] setA;
            delete[] setB;
        }
    } while (choice != 0);
}

void module9_ConsistencyChecker(CourseScheduling& scheduler,
    ConsistencyChecker& checker) {
    cout << "\n--- Module 9: Consistency Checker ---\n";

    if (studentCount == 0) {
        cout << "No students in the system. Please add students first.\n";
        return;
    }

    int maxCredits;
    cout << "Enter maximum allowed credits per semester: ";
    cin >> maxCredits;

    checker.runAllChecks(students, studentCount,
        scheduler.getCourses(),
        scheduler.getCourseCount(),
        maxCredits);
}

void module10_AlgorithmicEfficiency(AlgorithmicEfficiency& efficiency) {
    int choice;
    do {
        cout << "\n--- Module 10: Algorithmic Efficiency ---\n";
        cout << "1. Demonstrate Memoization\n";
        cout << "2. Demonstrate Bit Manipulation\n";
        cout << "3. Compare Complexity Analysis\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            efficiency.demonstrateMemoization();
        }
        else if (choice == 2) {
            efficiency.demonstrateBitManipulation();
        }
        else if (choice == 3) {
            efficiency.compareComplexity();
        }
    } while (choice != 0);
}

void module11_DataManagement(CourseScheduling& scheduler) {
    int choice;
    do {
        cout << "\n--- Module 11: Data Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Enroll Student in Course\n";
        cout << "4. Mark Course as Completed\n";
        cout << "5. Add Faculty\n";
        cout << "6. Display All Faculty\n";
        cout << "0. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (studentCount >= 50) {
                cout << "Maximum student limit reached!\n";
                continue;
            }

            int id;
            char name[50];
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Student Name: ";
            cin.getline(name, 50);

            students[studentCount++] = Student(id, name);
            cout << "Student added successfully!\n";

        }
        else if (choice == 2) {
            cout << "\n=== All Students ===\n";
            for (int i = 0; i < studentCount; i++) {
                students[i].display();
                cout << "------------------------\n";
            }

        }
        else if (choice == 3) {
            int studentId, courseId;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cout << "Enter Course ID: ";
            cin >> courseId;

            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].studentId == studentId) {
                    students[i].enrollCourse(courseId);
                    cout << "Student enrolled successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found!\n";

        }
        else if (choice == 4) {
            int studentId, courseId;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cout << "Enter Completed Course ID: ";
            cin >> courseId;

            bool found = false;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].studentId == studentId) {
                    students[i].completeCourse(courseId);
                    cout << "Course marked as completed!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found!\n";

        }
        else if (choice == 5) {
            if (facultyCount >= 50) {
                cout << "Maximum faculty limit reached!\n";
                continue;
            }

            int id;
            char name[50];
            cout << "Enter Faculty ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Faculty Name: ";
            cin.getline(name, 50);

            faculties[facultyCount++] = Faculty(id, name);
            cout << "Faculty added successfully!\n";

        }
        else if (choice == 6) {
            cout << "\n=== All Faculty ===\n";
            for (int i = 0; i < facultyCount; i++) {
                faculties[i].display();
                cout << "------------------------\n";
            }
        }
    } while (choice != 0);
}

void initializeSampleData(CourseScheduling& scheduler) {
    // Add sample courses
    scheduler.addCourse(101, "Introduction to Programming", 3);
    scheduler.addCourse(102, "Data Structures", 3);
    scheduler.addCourse(201, "Algorithms", 3);
    scheduler.addCourse(202, "Database Systems", 3);
    scheduler.addCourse(301, "Software Engineering", 3);

    // Add prerequisites
    scheduler.addPrerequisite(102, 101); // DS needs Intro
    scheduler.addPrerequisite(201, 102); // Algo needs DS
    scheduler.addPrerequisite(301, 201); // SE needs Algo
    scheduler.addPrerequisite(202, 102); // DB needs DS

    // Add sample students
    students[studentCount++] = Student(1, "Ali Ahmed");
    students[studentCount++] = Student(2, "Fatima Khan");
    students[studentCount++] = Student(3, "Hassan Raza");

    // Add sample faculty
    faculties[facultyCount++] = Faculty(1, "Dr. Muhammad Ali");
    faculties[facultyCount++] = Faculty(2, "Dr. Ayesha Malik");

    cout << "\n✓ Sample data initialized!\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    CourseScheduling scheduler;
    StudentGroupCombination groupManager;
    LogicInference logicEngine;
    SetOperations setOps;
    RelationsModule relations;
    FunctionsModule functions;
    AutomatedProof proofEngine;
    ConsistencyChecker checker;
    AlgorithmicEfficiency efficiency;

    displayHeader();

    char loadSample;
    cout << "\nLoad sample data? (y/n): ";
    cin >> loadSample;
    if (loadSample == 'y' || loadSample == 'Y') {
        initializeSampleData(scheduler);
    }

    int choice;
    while (true) {
        displayMainMenu();
        cin >> choice;

        if (choice == 0) {
            cout << "\n╔══════════════════════════════════════════════════════╗\n";
            cout << "║   Thank you for using UNIDISC ENGINE!               ║\n";
            cout << "║   FAST University - Discrete Structures Project     ║\n";
            cout << "╚══════════════════════════════════════════════════════╝\n";
            break;
        }

        switch (choice) {
        case 1:
            module1_CourseScheduling(scheduler);
            break;
        case 2:
            module2_StudentGroups(groupManager);
            break;
        case 3:
            module3_Induction(scheduler);
            break;
        case 4:
            module4_LogicInference(logicEngine);
            break;
        case 5:
            module5_SetOperations(setOps);
            break;
        case 6:
            module6_Relations(relations);
            break;
        case 7:
            module7_Functions(functions);
            break;
        case 8:
            module8_AutomatedProof(scheduler, proofEngine);
            break;
        case 9:
            module9_ConsistencyChecker(scheduler, checker);
            break;
        case 10:
            module10_AlgorithmicEfficiency(efficiency);
            break;
        case 11:
            module11_DataManagement(scheduler);
            break;
        default:
            cout << "\n✗ Invalid choice! Please try again.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}