//
// Created by Michal Dyczkowski on 16/06/2018.
//

#ifndef FORMULACONVERTER_FORMULA_H
#define FORMULACONVERTER_FORMULA_H

#include <list>
#include <string>
#include "TruthColumn.h"

class Formula {

public:
    std::list<TruthColumn> truthTable;
    std::list<TruthColumn> getTruthTable();
    std::string formulaString;
    std::string reversePolishNotationFormulaString;

    Formula(std::string formulaString);

    std::string principalDisjunctiveNormalForm;
    std::string getPDNF();

    std::string principalConjunctiveNormalForm;
    std::string getPCNF();
};


#endif //FORMULACONVERTER_FORMULA_H
