//
// Created by Michal Dyczkowski on 16/06/2018.
//

#ifndef FORMULACONVERTER_CONVERTER_H
#define FORMULACONVERTER_CONVERTER_H

#include <list>
#include <string>
#include "TruthColumn.h"


class Converter {

public:
    static std::list<TruthColumn> Evaluate(std::string formulaString);
    static bool contains(std::string s, char c);

    static std::string Convert(std::string input);

    static bool IsOperator(char c);
    static bool IsOperand(char c);
    static int Priority(char c);
};


#endif //FORMULACONVERTER_CONVERTER_H
