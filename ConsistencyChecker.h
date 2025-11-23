// ConsistencyChecker.h
#ifndef CONSISTENCYCHECKER_H
#define CONSISTENCYCHECKER_H

#include "Student.h"
#include "Course.h"

class ConsistencyChecker {
public:
    bool checkCourseOverlap(Student* students, int studentCount);
    bool checkStudentOverload(Student* students, int studentCount, 
                             Course* courses, int courseCount, int maxCredits);
    bool checkPrerequisiteViolations(Student* students, int studentCount, 
                                    Course* courses, int courseCount);
    void runAllChecks(Student* students, int studentCount, 
                     Course* courses, int courseCount, int maxCredits);
};

#endif