// RelationsModule.h
#ifndef RELATIONSMODULE_H
#define RELATIONSMODULE_H

class RelationsModule {
private:
    struct Relation {
        int from;
        int to;
    };
    
    Relation* relations;
    int relationCount;
    int maxRelations;
    
public:
    RelationsModule();
    ~RelationsModule();
    
    void addRelation(int from, int to);
    bool isReflexive(int* elements, int n);
    bool isSymmetric();
    bool isTransitive();
    bool isEquivalence(int* elements, int n);
    void checkProperties(int* elements, int n);
    void printRelations();
};

#endif