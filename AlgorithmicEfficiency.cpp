// AlgorithmicEfficiency.cpp
#include "AlgorithmicEfficiency.h"
#include <iostream>
using namespace std;

AlgorithmicEfficiency::AlgorithmicEfficiency() {
    for(int i = 0; i < 100; i++) {
        fibMemo[i] = -1;
    }
}

int AlgorithmicEfficiency::fibonacciRecursive(int n) {
    if(n <= 1) return n;
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int AlgorithmicEfficiency::fibonacciMemoization(int n) {
    if(n <= 1) return n;
    
    if(fibMemo[n] != -1) {
        return fibMemo[n];
    }
    
    fibMemo[n] = fibonacciMemoization(n-1) + fibonacciMemoization(n-2);
    return fibMemo[n];
}

int AlgorithmicEfficiency::powerOfTwo(int n) {
    return (1 << n);  // Bit manipulation: left shift is equivalent to 2^n
}

void AlgorithmicEfficiency::demonstrateMemoization() {
    cout << "\n=== Memoization Demonstration ===\n";
    cout << "Computing Fibonacci numbers with memoization:\n\n";
    
    for(int i = 0; i <= 10; i++) {
        cout << "Fib(" << i << ") = " << fibonacciMemoization(i) << "\n";
    }
    
    cout << "\n✓ Time Complexity: O(n) with memoization\n";
    cout << "  (vs O(2^n) without memoization)\n";
}

void AlgorithmicEfficiency::demonstrateBitManipulation() {
    cout << "\n=== Bit Manipulation for Efficiency ===\n";
    cout << "Computing powers of 2 using bit shift (1 << n):\n\n";
    
    for(int i = 0; i <= 10; i++) {
        cout << "2^" << i << " = " << powerOfTwo(i);
        cout << " (Binary: ";
        
        // Show binary representation
        int val = powerOfTwo(i);
        bool started = false;
        for(int j = 15; j >= 0; j--) {
            if(val & (1 << j)) {
                cout << "1";
                started = true;
            } else if(started) {
                cout << "0";
            }
        }
        if(!started) cout << "0";
        
        cout << ")\n";
    }
    
    cout << "\n✓ Bit manipulation is O(1) constant time!\n";
}

void AlgorithmicEfficiency::compareComplexity() {
    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║     ALGORITHMIC COMPLEXITY COMPARISON                ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";
    
    cout << "\n1. Fibonacci Without Memoization:\n";
    cout << "   Time Complexity: O(2^n) - Exponential\n";
    cout << "   Space Complexity: O(n) - Recursion stack\n";
    cout << "   Problem: Recalculates same values repeatedly\n";
    
    cout << "\n2. Fibonacci With Memoization:\n";
    cout << "   Time Complexity: O(n) - Linear\n";
    cout << "   Space Complexity: O(n) - Memoization array\n";
    cout << "   Benefit: Each value calculated only once!\n";
    
    cout << "\n3. Bit Manipulation (Power of 2):\n";
    cout << "   Time Complexity: O(1) - Constant\n";
    cout << "   Space Complexity: O(1) - Constant\n";
    cout << "   Benefit: Fastest possible operation!\n";
    
    cout << "\n4. Set Operations (Intersection):\n";
    cout << "   Time Complexity: O(n*m) where n,m are set sizes\n";
    cout << "   Can be optimized with sorted arrays to O(n+m)\n";
    
    cout << "\n═══════════════════════════════════════════════════════\n";
    cout << "Key Takeaway: Choose right algorithm for efficiency!\n";
    cout << "═══════════════════════════════════════════════════════\n";
}