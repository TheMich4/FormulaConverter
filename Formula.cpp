//
// Created by Michal Dyczkowski on 16/06/2018.
//

#include <iostream>
#include "Formula.h"
#include "TruthColumn.h"
#include "Converter.h"

std::list<TruthColumn> Formula::getTruthTable() {
    return truthTable;
}

Formula::Formula(std::string formulaString) {
    this->formulaString = formulaString;
    this->reversePolishNotationFormulaString = Converter::Convert(formulaString);
    truthTable = Converter::Evaluate(reversePolishNotationFormulaString);
}

std::string Formula::getPDNF() {
    std::string str = "";

    for (int i = 0; i < sizeof(truthTable.Last().truthArray); i++) {
        if (truthTable.Last().truthArray[i]) {
            std::string subStr = "";
            for (int j = 0; j < 3; j++) {
                if (j < sizeof(truthTable)) {
                    if (sizeof(truthTable[j].stringDesc) == 1) {
                        subStr += truthTable[j].truthArray[i] ? truthTable[j].stringDesc : "!" + truthTable[j].stringDesc;
                    }
                }
            }
            str += str.length() == 0 ? subStr : "ν" + subStr;
        }
    }
    return str;
}

std::string Formula::getPCNF() {

    std::string str = "";
    for (int i = 0; i < sizeof(truthTable.Last().truthArray); i++) {
        if (!truthTable.Last().truthArray[i]) {
            std::string subStr = "(";
            for (int j = 0; j < 3; j++) {
                if (j < sizeof(truthTable) {
                    if (truthTable[j].stringDesc.Length == 1) {
                        subStr += subStr.Length == 1 ? "" : "ν";
                        subStr += !truthTable[j].truthArray[i] ? truthTable[j].stringDesc : "!" + truthTable[j].stringDesc;
                    }
                }
            }
            subStr += ")";
            str += subStr;
        }
    }
    return str;
}
