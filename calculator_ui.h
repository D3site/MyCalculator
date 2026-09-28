#pragma once

#include <iostream>

#include "calculator.h"

class CalculatorUI {
public:
    // Реализуйте конструктор. Он должен сохранить ссылки 
    // на потоки и калькулятор внутрь класса.
    // Используйте для этого список инициализации.
    CalculatorUI(Calculator& calc, std::ostream& out, std::ostream& err);

    // Заготовки следующих двух методов есть в .cpp-файле.
    // Дополните их.
    bool Parse(std::istream& input);

private:
    Calculator calc_;

    const std::ostream& out_;
    const std::ostream& err_;
    bool ReadNumber(std::istream& input, Number& result) const;
};