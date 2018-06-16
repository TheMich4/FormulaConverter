//
// Created by Michal Dyczkowski on 16/06/2018.
//

#include <list>
#include <stack>
#include "Converter.h"
#include "TruthColumn.h"

std::list<TruthColumn> Converter::Evaluate(std::string formulaString) {

    std::list<TruthColumn> columns;

    bool hasA = contains(formulaString, 'A');
    bool hasB = contains(formulaString, 'B');
    bool hasC = contains(formulaString, 'C');

    int count = 0;
    count += hasA ? 1 : 0;
    count += hasB ? 1 : 0;
    count += hasC ? 1 : 0;

    TruthColumn *aColumn = nullptr;
    TruthColumn *bColumn = nullptr;
    TruthColumn *cColumn = nullptr;

    if (hasA) {
        aColumn = new TruthColumn(1, count, "A");
        columns.push_back(aColumn);
    }
    if (hasB) {
        bColumn = new TruthColumn(hasA ? 2 : 1, count, "B");
        columns.push_back(bColumn);
    }
    if (hasC) {
        int position = 1;
        position += hasA ? 1 : 0;
        position += hasB ? 1 : 0;
        cColumn = new TruthColumn(position, count, "C");
        columns.push_back(cColumn);
    }

    std::stack<TruthColumn> stack;

    for (int i = 0; i < formulaString.length(); i++) {
        if (IsOperator(formulaString[i])) {
            if (formulaString[i] == '!') {
                TruthColumn op1 = stack.pop();
                TruthColumn result = TruthColumn::Negate(op1);
                stack.push(result);
                columns.push_back(result);
            }
            else {
                TruthColumn op2 = stack.pop();
                TruthColumn op1 = stack.pop();
                TruthColumn result = TruthColumn::Evaluate(op1, op2, formulaString[i]);
                stack.push(result);
                columns.push_back(result);
            }
        }
        else if (IsOperand(formulaString[i])) {
            switch (formulaString[i]) {
                case 'A':
                    stack.push(aColumn);
                    break;
                case 2:
                    stack.push(bColumn);
                    break;
                case 3:
                    stack.push(cColumn);
                    break;
            }
        }
    }
    return columns;
}

bool Converter::contains(std::string s, char c) {
    return s.find(c) > 0;
}

std::string Converter::Convert(std::string input) {
    std::stack<char> stack;
    std::string str = input.replace(" ", "");
    StringBuilder formula = new StringBuilder();
    for (char x : str) {
        if (x == '(')
            stack.push(x);
        else if (x == ')')
        {
            while (stack.size() > 0 && stack.top() != '(')
                formula.Append(stack.pop());
            stack.pop();
        }
        else if (IsOperand(x))
        {
            formula.Append(x);
        }
        else if (IsOperator(x))
        {
            while (stack.size() > 0 && stack.top() != '(' && Priority(x) <= Priority(stack.top()))
                formula.Append(stack.Pop());
            stack.push(x);
        }
        else
        {
            char y = stack.pop();
            if (y != '(')
                formula.Append(y);
        }
    }
    while (stack.size() > 0)
    {
        formula.Append(stack.pop());
    }
    return formula.ToString();
}

bool Converter::IsOperator(char c) {
    return (c == '!' || c == 'ν' || c == '^' || c == '~' || c == '→');
}

bool Converter::IsOperand(char c) {
    return (c == 'A' || c == 'B' || c == 'C');
}

int Converter::Priority(char c) {
    switch (c)
    {
        case '~':
            return 1;
        case '→':
            return 2;
        case 'ν':
            return 3;
        case '^':
            return 4;
        case '!':
            return 5;
// TODO
//        default:
//            throw new ArgumentException("Wrong parameter");
    }
}
