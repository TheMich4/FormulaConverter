//
// Created by Michal Dyczkowski on 16/06/2018.
//

#include <iostream>
#include "TruthColumn.h"


TruthColumn::TruthColumn(int position, int count, std::string letter) {
    switch (count) {
        case 1:
            truthArray = new bool[2] {false, true};
            break;
        case 2:
            switch (position) {
                case 1:
                    truthArray = new bool[4] {false, false, true, true};
                    break;
                case 2:
                    truthArray = new bool[4] {false, true, false, true};
                    break;
            }
        case 3:
            switch (position) {
                case 1:
                    truthArray = new bool[8] { false, false, false, false, true, true, true, true };
                    break;
                case 2:
                    truthArray = new bool[8] { false, false, true, true, false, false, true, true };
                    break;
                case 3:
                    truthArray = new bool[8] { false, true, false, true, false, true, false, true };
                    break;
            }
            break;
    }
    stringDesc = letter;
}

TruthColumn::TruthColumn(bool* array, std::string desc) {
    truthArray = array;
    stringDesc = desc;
}

bool* TruthColumn::getTruthArray() {
    return truthArray;
}

static TruthColumn TruthColumn::Negate(TruthColumn &ts) {
    truthArray = new bool[sizeof(ts.truthArray)];

    if (stringDesc.size() == 1) {
        stringDesc = "!" + ts.stringDesc;
    }
    else {
        stringDesc = "!(" + ts.stringDesc + ")";
    }

    for (int i = 0; i < sizeof(ts.truthArray); i++) {
        truthArray[i] = !ts.truthArray[i];
    }

    return TruthColumn(truthArray, stringDesc);
}

TruthColumn TruthColumn::Evaluate(TruthColumn &left, TruthColumn &right, char operation) {

    if (sizeof(left.truthArray) == sizeof(right.truthArray)) {

        bool* truthArray = new bool[sizeof(left.truthArray)];

        stringDesc = left.stringDesc + operation + right.stringDesc;

        for (int i = 0; i < sizeof(left.truthArray); i++) {
            switch (operation)
            {
                case '^':
                    truthArray[i] = left.truthArray[i] && right.truthArray[i];
                    break;
                case 'ν':
                    truthArray[i] = left.truthArray[i] || right.truthArray[i];
                    break;
                case '~':
                    truthArray[i] = (left.truthArray[i] && right.truthArray[i]) || (!left.truthArray[i] && !right.truthArray[i]);
                    break;
                case '→':
                    truthArray[i] = !left.truthArray[i] || right.truthArray[i];
                    break;
            }
        }

        return TruthColumn(truthArray, stringDesc);
    }
    // TODO
//    else {
//        throw new Exception("Different truth array length.");
//    }
}




