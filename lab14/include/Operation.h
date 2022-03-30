#pragma once
#include <string>
#include <iostream>
#include <cstdio>

class Operation{
    protected:
        std::string _name;
        char _operat;
        double* _array;
        double _x;
        double _y;
        double _n;
    public:
        Operation();
        Operation(std::string str, char op, double x, double y) : _name{str}, _operat(op),_x{x},_y{y}{};
        Operation(std::string str, char op, double* arr, double size) : _name{str}, _operat{op}, _array{arr}, _n{size}{};
        virtual ~Operation(){};

        double getX() const{return _x;};
        double getY() const{return _y;};
        std::string getName() const{return _name;};

        virtual void print(std::ostream& os = std::cout) const;
        virtual std::string name() const {return _name;};
        virtual double eval() const = 0;
        virtual char op() const {return _operat;};

        double& operator[](int ind) const;

        friend std::ostream& operator<<(std::ostream& os, const Operation& op);

};

class Div : public Operation{
    public:
        Div(const double x,const double y) : Operation{"Dzielenie",'/',x,y}{};
        double eval() const override {return _x/_y;};
};



