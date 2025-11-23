// StudentGroupCombination.cpp
#include "StudentGroupCombination.h"
#include <iostream>
using namespace std;

int StudentGroupCombination::factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int StudentGroupCombination::nCr(int n, int r) {
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void StudentGroupCombination::generateCombinationsHelper(int* students, int n, int r, 
                                                         int index, int* data, int i) {
    if(index == r) {
        cout << "Group: { ";
        for(int j = 0; j < r; j++) {
            cout << "Student-" << data[j] << " ";
        }
        cout << "}\n";
        return;
    }
    
    if(i >= n) return;
    
    data[index] = students[i];
    generateCombinationsHelper(students, n, r, index + 1, data, i + 1);
    generateCombinationsHelper(students, n, r, index, data, i + 1);
}

void StudentGroupCombination::calculateCombinations(int numStudents, int groupSize) {
    cout << "\n=== Student Group Combinations ===\n";
    int total = nCr(numStudents, groupSize);
    cout << "Total possible groups of " << groupSize << " from " 
         << numStudents << " students: " << total << "\n\n";
}

void StudentGroupCombination::generateGroups(int* studentIds, int n, int groupSize) {
    cout << "Generating all possible groups:\n";
    int* data = new int[groupSize];
    generateCombinationsHelper(studentIds, n, groupSize, 0, data, 0);
    delete[] data;
}