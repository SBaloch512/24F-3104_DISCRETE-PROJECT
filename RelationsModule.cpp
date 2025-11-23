// RelationsModule.cpp
#include "RelationsModule.h"
#include <iostream>
using namespace std;

RelationsModule::RelationsModule() : relationCount(0), maxRelations(100) {
    relations = new Relation[maxRelations];
}

RelationsModule::~RelationsModule() {
    delete[] relations;
}

void RelationsModule::addRelation(int from, int to) {
    if(relationCount < maxRelations) {
        relations[relationCount].from = from;
        relations[relationCount].to = to;
        relationCount++;
        cout << "Relation (" << from << ", " << to << ") added successfully!\n";
    } else {
        cout << "Maximum relations limit reached!\n";
    }
}

bool RelationsModule::isReflexive(int* elements, int n) {
    // Check if (x, x) exists for all x in the set
    for(int i = 0; i < n; i++) {
        bool found = false;
        for(int j = 0; j < relationCount; j++) {
            if(relations[j].from == elements[i] && 
               relations[j].to == elements[i]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

bool RelationsModule::isSymmetric() {
    // Check if (x, y) exists, then (y, x) must also exist
    for(int i = 0; i < relationCount; i++) {
        if(relations[i].from == relations[i].to) continue; // Skip reflexive pairs
        
        bool found = false;
        for(int j = 0; j < relationCount; j++) {
            if(relations[i].from == relations[j].to && 
               relations[i].to == relations[j].from) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

bool RelationsModule::isTransitive() {
    // Check if (x, y) and (y, z) exist, then (x, z) must exist
    for(int i = 0; i < relationCount; i++) {
        for(int j = 0; j < relationCount; j++) {
            if(relations[i].to == relations[j].from) {
                bool found = false;
                for(int k = 0; k < relationCount; k++) {
                    if(relations[k].from == relations[i].from && 
                       relations[k].to == relations[j].to) {
                        found = true;
                        break;
                    }
                }
                if(!found) return false;
            }
        }
    }
    return true;
}

bool RelationsModule::isEquivalence(int* elements, int n) {
    return isReflexive(elements, n) && isSymmetric() && isTransitive();
}

void RelationsModule::checkProperties(int* elements, int n) {
    cout << "\n=== Relation Properties Analysis ===\n";
    
    bool reflexive = isReflexive(elements, n);
    bool symmetric = isSymmetric();
    bool transitive = isTransitive();
    
    cout << "Reflexive: " << (reflexive ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (Every element relates to itself)\n";
    
    cout << "Symmetric: " << (symmetric ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (If a→b then b→a)\n";
    
    cout << "Transitive: " << (transitive ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (If a→b and b→c then a→c)\n";
    
    if(reflexive && symmetric && transitive) {
        cout << "\n✓ This is an EQUIVALENCE RELATION!\n";
    } else {
        cout << "\n✗ This is NOT an equivalence relation.\n";
    }
}

void RelationsModule::printRelations() {
    cout << "\n=== Current Relations ===\n";
    if(relationCount == 0) {
        cout << "No relations defined yet.\n";
        return;
    }
    
    cout << "Relations = { ";
    for(int i = 0; i < relationCount; i++) {
        cout << "(" << relations[i].from << "," << relations[i].to << ")";
        if(i < relationCount - 1) cout << ", ";
    }
    cout << " }\n";
}