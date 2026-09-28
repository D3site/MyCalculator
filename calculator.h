#pragma once

#include <string>

using Number = double;
using namespace std::literals;

class Calculator {
public:

    void Save();
    void Load();
    void Set(Number n);
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    bool RunCalculatorCycle();

    bool HasMem() const;
    bool ReadNumber(Number&);

    Number GetNumber() const;
    std::string GetNumberRepr() const;

private:
    Number value_in_memory_ = 0;

    bool has_mem_ = false;
};