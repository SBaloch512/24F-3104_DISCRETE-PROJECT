// StudentGroupCombination.h
#ifndef STUDENTGROUPCOMBINATION_H
#define STUDENTGROUPCOMBINATION_H

class StudentGroupCombination {
private:
    int factorial(int n);
    int nCr(int n, int r);
    void generateCombinationsHelper(int* students, int n, int r, int index, 
                                   int* data, int i);
    
public:
    void calculateCombinations(int numStudents, int groupSize);
    void generateGroups(int* studentIds, int n, int groupSize);
};

#endif