#include "calculator_ui.h"

using namespace std::literals;

CalculatorUI::CalculatorUI(Calculator& calc, std::ostream& out, std::ostream& err)
    :calc_{ calc }
    ,out_ { out  }
    ,err_ { err  }
{

}

bool CalculatorUI::Parse(std::istream& input) {
    Number operand;
    if (!ReadNumber(input, operand)) {
        return false;
    }
    calc_.Set(operand);

    std::string str;

    while (input >> str) {
        if (str == "+"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Add(operand);
        }
        else if (str == "-"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Sub(operand);
        }
        else if (str == "*"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Mul(operand);
        }
        else if (str == "/"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Div(operand);
        }
        else if (str == "**"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Pow(operand);
        }
        else if (str == "s"s) {
            calc_.Save();
        }
        else if (str == "l"s) {
            if (!calc_.HasMem()) {
                err_ << "Error: Memory is empty"s << std::endl;
                break;
            }
            calc_.Load();
        }
        else if (str == "="s) {
            out_ << calc_.GetNumberRepr() << std::endl;
        }
        else if (str == "c"s) {
            calc_.Set(0);
        }
        else if (str == "n"s) {
            calc_.Set(-calc_.GetNumber());
        }
        else if (str == ":"s) {
            if (!ReadNumber(input, operand)) {
                break;
            }
            calc_.Set(operand);
        }
        else if (str == "q"s) {
            return true;
        }
        else {
            err_ << "Error: Unknown token "s << str << std::endl;
            break;
        }
    }
    // Напишите здесь цикл чтения на основе функции RunCalculatorCycle.

    return !input.fail();
}

bool CalculatorUI::ReadNumber(std::istream& input, Number& result) const {
    if (!(input >> result)) {
        err_ << "Error: Numeric operand expected"s << std::endl;
        return false;
    }
    return true;
}