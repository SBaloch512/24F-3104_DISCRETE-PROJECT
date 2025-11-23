// LogicInference.cpp
#include "LogicInference.h"
#include <iostream>
using namespace std;

LogicInference::Rule::Rule() : antecedent1(-1), antecedent2(-1), 
                               consequent(-1), type('C') {}

LogicInference::LogicInference() : ruleCount(0), maxRules(50) {
    rules = new Rule[maxRules];
}

LogicInference::~LogicInference() {
    delete[] rules;
}

void LogicInference::addRule(int ant1, int ant2, int cons, char t) {
    if(ruleCount < maxRules) {
        rules[ruleCount].antecedent1 = ant1;
        rules[ruleCount].antecedent2 = ant2;
        rules[ruleCount].consequent = cons;
        rules[ruleCount].type = t;
        ruleCount++;
        cout << "Rule added successfully!\n";
    } else {
        cout << "Maximum rules limit reached!\n";
    }
}

bool LogicInference::verifyRule(int ant1, int ant2, int cons) {
    cout << "\n=== Logic Inference Verification ===\n";
    cout << "Verifying: If Faculty " << ant1 << " teaches Course " << ant2 
         << " => Lab " << cons << " must be assigned\n";
    
    for(int i = 0; i < ruleCount; i++) {
        if(rules[i].antecedent1 == ant1 && rules[i].antecedent2 == ant2) {
            if(rules[i].consequent == cons) {
                cout << "✓ Rule is VALID (matches stored rule)\n";
                return true;
            } else {
                cout << "✗ CONFLICT: Expected Lab " << rules[i].consequent 
                     << " but got Lab " << cons << "\n";
                return false;
            }
        }
    }
    
    cout << "⚠ No matching rule found in database\n";
    return false;
}

void LogicInference::inferConsequences(int ant1, int ant2) {
    cout << "\n=== Inferring Consequences ===\n";
    cout << "Given: Faculty " << ant1 << " teaches Course " << ant2 << "\n";
    cout << "Inferred consequences:\n";
    
    bool found = false;
    for(int i = 0; i < ruleCount; i++) {
        if(rules[i].antecedent1 == ant1 && rules[i].antecedent2 == ant2) {
            cout << "  => Lab " << rules[i].consequent << " must be assigned\n";
            found = true;
        }
    }
    
    if(!found) {
        cout << "  No consequences found for this assignment\n";
    }
}

void LogicInference::displayAllRules() {
    cout << "\n=== All Logic Rules ===\n";
    if(ruleCount == 0) {
        cout << "No rules defined yet.\n";
        return;
    }
    
    for(int i = 0; i < ruleCount; i++) {
        cout << "Rule " << (i+1) << ": ";
        cout << "If Faculty " << rules[i].antecedent1 
             << " teaches Course " << rules[i].antecedent2 
             << " => Lab " << rules[i].consequent << "\n";
    }
}