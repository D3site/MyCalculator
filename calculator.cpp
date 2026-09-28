#include <iostream>
#include <cmath>
#include "calculator.h"

Number init_number = 0, right = 0;

bool Calculator::ReadNumber(Number& init_number) {
    if (!(std::cin >> init_number)) {
        std::cerr << "Error: Numeric operand expected"s << std::endl;
        return false;
    }
    return true;
}
bool Calculator::RunCalculatorCycle() {

    if (!ReadNumber(init_number)) {
        return false;
    }

    Calculator calc;
    calc.Set(init_number);

    Number right;
    std::string token;

    while (std::cin >> token) {
        if (token == "+"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Add(right);
        }
        else if (token == "-"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Sub(right);
        }
        else if (token == "*"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Mul(right);
        }
        else if (token == "/"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Div(right);
        }
        else if (token == "**"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Pow(right);
        }
        else if (token == "s"s) {
            calc.Save();
        }
        else if (token == "l"s) {
            if (!calc.HasMem()) {
                std::cerr << "Error: Memory is empty"s << std::endl;
                break;
            }
            calc.Load();
        }
        else if (token == "="s) {
            std::cout << calc.GetNumberRepr() << std::endl;
        }
        else if (token == "c"s) {
            calc.Set(0);
        }
        else if (token == "n"s) {
            calc.Set(-calc.GetNumber());
        }
        else if (token == ":"s) {
            if (!ReadNumber(right)) {
                break;
            }
            calc.Set(right);
        }
        else if (token == "q"s) {
            return true;
        }
        else {
            std::cerr << "Error: Unknown token "s << token << std::endl;
            break;
        }
    }
    return false;
}

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
void Calculator::Save() {
    value_in_memory_ = init_number;
    has_mem_ = true;
}
void Calculator::Load() {
    init_number = value_in_memory_;
}
void Calculator::Set(Number n) {
    init_number = n;
}
bool Calculator::HasMem() const {
    return has_mem_;
}

std::string Calculator::GetNumberRepr() const {
    return std::to_string(init_number);
}

Number Calculator::GetNumber() const {
    return init_number;
}