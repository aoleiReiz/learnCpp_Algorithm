//
// Created by aolei.bao on 1/6/2023.
//

#ifndef LEARNCPP_ALGORITHM_EASHELEVENTOFIFTHTEEN_H
#define LEARNCPP_ALGORITHM_EASHELEVENTOFIFTHTEEN_H
#include <vector>
#include <algorithm>
#include <any>

using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

class EashElevenToFifthteen {
public:
    bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights);

    int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                      bool fastest);

    LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList);

    int getNthFib(int n);

//    int productSum(vector<any> array, int multiplier = 1) {
//        int sum = 0;
//        for(auto el : array){
//            if(el.type() == typeid(vector<any>)){
//                sum += productSum(any_cast<vector<any>>(el), multiplier + 1);
//            }else{
//                sum += any_cast<int>(el);
//            }
//        }
//        return sum * multiplier;
//    }
};


#endif //LEARNCPP_ALGORITHM_EASHELEVENTOFIFTHTEEN_H
