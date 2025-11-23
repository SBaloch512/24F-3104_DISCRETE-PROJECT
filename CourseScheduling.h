// CourseScheduling.h
#ifndef COURSESCHEDULING_H
#define COURSESCHEDULING_H

#include "Course.h"
#include "DynamicArray.h"

class CourseScheduling {
private:
    Course* courses;
    int courseCount;
    int maxCourses;
    
    void generateSequencesHelper(bool* taken, DynamicArray<int>& current, 
                                 int level, int total);
    
public:
    CourseScheduling();
    ~CourseScheduling();
    
    void addCourse(int id, const char* name, int credits = 3);
    void addPrerequisite(int courseId, int prereqId);
    void generateValidSequences();
    void displayAllCourses();
    Course* getCourses();
    int getCourseCount();
    Course* findCourse(int courseId);
};

#endif