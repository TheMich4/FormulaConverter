//
// Created by Michal Dyczkowski on 16/06/2018.
//

#ifndef FORMULACONVERTER_TRUTHCOLUMN_H
#define FORMULACONVERTER_TRUTHCOLUMN_H


class TruthColumn {

public:
    TruthColumn(int position, int count, std::string letter);
    TruthColumn(bool* array, std::string desc);
    static std::string stringDesc;
    bool* getTruthArray();

    static TruthColumn Negate(TruthColumn &ts);
    static TruthColumn Evaluate(TruthColumn &left, TruthColumn &right, char operation);

    static bool* truthArray;

};


#endif //FORMULACONVERTER_TRUTHCOLUMN_H
