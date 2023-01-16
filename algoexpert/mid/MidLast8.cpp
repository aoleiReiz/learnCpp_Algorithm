//
// Created by aolei.bao on 1/13/2023.
//

#include "MidLast8.h"

bool MidLast8::oneEdit(string stringOne, string stringTwo) {
    int oneLength = stringOne.length();
    int twoLength = stringTwo.length();
    if (oneLength - twoLength > 1 || oneLength - twoLength < -1){
        return false;
    }
    int indexOne = 0, indexTwo = 0;
    bool madeEdit = false;
    while (indexOne < oneLength && indexTwo < twoLength){
        if (stringOne[indexOne] != stringTwo[indexTwo]){
            if (madeEdit){
                return false;
            }
            madeEdit = true;
            if (oneLength > twoLength){
                indexOne ++;
            } else if (twoLength > oneLength){
                indexTwo ++;
            }else{
                indexOne ++;
                indexTwo ++;
            }
        }else{
            indexOne ++;
            indexTwo ++;
        }
    }
    return true;
}
