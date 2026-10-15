#include <iostream>
#include <cmath>
#include "calculator.h"

void Calculator::Add(Number n) {
    init_number += n;
}
void Calculator::Sub(Number n) {
    init_number -= n;
}
void Calculator::Mul(Number n) {
    init_number *= n;
}
void Calculator::Div(Number n) {
    init_number /= n;
}
void Calculator::Pow(Number n) {
    init_number = std::pow(init_number, n);
}

void Calculator::Set(Number n) {
    init_number = n;
}

std::string Calculator::GetNumberRepr() const {
    return std::to_string(init_number);
}

Number Calculator::GetNumber() const {
    return init_number;
}
