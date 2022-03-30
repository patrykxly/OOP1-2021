#include "Operation.h"

void Operation::print(std::ostream& os) const{
    if(_operat == '+'){
        int i;
        for(i = 0; i < _n-1; i++)
            os << _array[i] << " + ";
        os << _array[i++];
    }
    else{
        os << _x << " " << _operat << " " << _y;
    }
}

std::ostream& operator<<(std::ostream& os, const Operation& op){
    if(op._operat != '+')
        os << op.getX() << " " << op.op() << " " << op.getY() << " = " << op.eval() << std::endl;
    else{
        int i;
        for(i = 0; i<op._n-1; i++)
            os << op._array[i] << " + ";
        i = op._n-1;
        os << op._array[i] << " = " << op.eval() << std::endl;
    } 
    return os;
}

double& Operation::operator[](int ind) const{
    return _array[ind];
}