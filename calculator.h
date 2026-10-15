#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once

#include <string>

using Number = double;
using namespace std::literals;

class Calculator {
public:
    void Set(Number n);
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

    Number GetNumber() const;
    std::string GetNumberRepr() const;

private:
    Number init_number = 0, right = 0;
};

#endif // CALCULATOR_H
