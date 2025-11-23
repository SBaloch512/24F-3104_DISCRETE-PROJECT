// FunctionsModule.h
#ifndef FUNCTIONSMODULE_H
#define FUNCTIONSMODULE_H

class FunctionsModule {
private:
    struct Mapping {
        int domain;
        int codomain;
    };
    
    Mapping* mappings;
    int mappingCount;
    int maxMappings;
    
public:
    FunctionsModule();
    ~FunctionsModule();
    
    void addMapping(int from, int to);
    bool isInjective();
    bool isSurjective(int* codomain, int codomainSize);
    bool isBijective(int* codomain, int codomainSize);
    void checkFunctionProperties(int* codomain, int codomainSize);
    void printMappings();
};

#endif