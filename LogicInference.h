// LogicInference.h
#ifndef LOGICINFERENCE_H
#define LOGICINFERENCE_H

class LogicInference {
private:
    struct Rule {
        int antecedent1;
        int antecedent2;
        int consequent;
        char type;
        
        Rule();
    };
    
    Rule* rules;
    int ruleCount;
    int maxRules;
    
public:
    LogicInference();
    ~LogicInference();
    
    void addRule(int ant1, int ant2, int cons, char t);
    bool verifyRule(int ant1, int ant2, int cons);
    void inferConsequences(int ant1, int ant2);
    void displayAllRules();
};

#endif