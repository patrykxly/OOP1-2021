#pragma once 
#include "Operation.h"

class OpComp{
    private:
        Operation* _oper;
    public:
        OpComp(Operation* oper): _oper(oper){};
        bool operator()(const Operation* op) const{return (_oper->op() == op->op());};
};