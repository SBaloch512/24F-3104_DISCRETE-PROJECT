// FunctionsModule.cpp
#include "FunctionsModule.h"
#include <iostream>
using namespace std;

FunctionsModule::FunctionsModule() : mappingCount(0), maxMappings(100) {
    mappings = new Mapping[maxMappings];
}

FunctionsModule::~FunctionsModule() {
    delete[] mappings;
}

void FunctionsModule::addMapping(int from, int to) {
    if(mappingCount < maxMappings) {
        mappings[mappingCount].domain = from;
        mappings[mappingCount].codomain = to;
        mappingCount++;
        cout << "Mapping added: " << from << " -> " << to << "\n";
    } else {
        cout << "Maximum mappings limit reached!\n";
    }
}

bool FunctionsModule::isInjective() {
    // One-to-one: Different inputs map to different outputs
    for(int i = 0; i < mappingCount; i++) {
        for(int j = i + 1; j < mappingCount; j++) {
            if(mappings[i].codomain == mappings[j].codomain && 
               mappings[i].domain != mappings[j].domain) {
                return false;
            }
        }
    }
    return true;
}

bool FunctionsModule::isSurjective(int* codomain, int codomainSize) {
    // Onto: Every element in codomain is mapped to
    for(int i = 0; i < codomainSize; i++) {
        bool found = false;
        for(int j = 0; j < mappingCount; j++) {
            if(mappings[j].codomain == codomain[i]) {
                found = true;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

bool FunctionsModule::isBijective(int* codomain, int codomainSize) {
    return isInjective() && isSurjective(codomain, codomainSize);
}

void FunctionsModule::checkFunctionProperties(int* codomain, int codomainSize) {
    cout << "\n=== Function Properties Analysis ===\n";
    
    bool injective = isInjective();
    bool surjective = isSurjective(codomain, codomainSize);
    bool bijective = isBijective(codomain, codomainSize);
    
    cout << "Injective (One-to-One): " << (injective ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (Each course assigned to different faculty)\n";
    
    cout << "Surjective (Onto): " << (surjective ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (Every faculty has at least one course)\n";
    
    cout << "Bijective (One-to-One & Onto): " << (bijective ? "YES ✓" : "NO ✗") << "\n";
    cout << "  (Perfect one-to-one correspondence)\n";
    
    if(injective) {
        cout << "\n✓ Every course is assigned to exactly one faculty!\n";
    }
}

void FunctionsModule::printMappings() {
    cout << "\n=== Current Function Mappings ===\n";
    if(mappingCount == 0) {
        cout << "No mappings defined yet.\n";
        return;
    }
    
    cout << "Course -> Faculty mappings:\n";
    for(int i = 0; i < mappingCount; i++) {
        cout << "  Course " << mappings[i].domain 
             << " -> Faculty " << mappings[i].codomain << "\n";
    }
}