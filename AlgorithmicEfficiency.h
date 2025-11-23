// AlgorithmicEfficiency.h
#ifndef ALGORITHMICEFFICIENCY_H
#define ALGORITHMICEFFICIENCY_H

class AlgorithmicEfficiency {
private:
    int fibMemo[100];
    
public:
    AlgorithmicEfficiency();
    
    int fibonacciRecursive(int n);
    int fibonacciMemoization(int n);
    int powerOfTwo(int n);
    void demonstrateMemoization();
    void demonstrateBitManipulation();
    void compareComplexity();
};

#endif