//
// Created by aolei.bao on 1/6/2023.
//

#include "EashElevenToFifthteen.h"


bool EashElevenToFifthteen::classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());
    if(redShirtHeights[0] == blueShirtHeights[0]){
        return false;
    }
    bool flag = redShirtHeights[0] > blueShirtHeights[0];
    for (int i = 0; i < redShirtHeights.size(); ++i) {
        if ( redShirtHeights[i] == blueShirtHeights[i]){
            return false;
        }
        if (flag != redShirtHeights[i] > blueShirtHeights[i]){
            return false;
        }
    }

    return true;
}

int EashElevenToFifthteen::tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    int totalSpeed = 0;
    int n = redShirtSpeeds.size();
    if (fastest){
        for (int i = 0; i < n; ++i) {
            totalSpeed += (redShirtSpeeds[i] > blueShirtSpeeds[n - i - 1] ? redShirtSpeeds[i] : blueShirtSpeeds[n - i - 1]);
        }
    }else{
        for (int i = 0; i < n; ++i) {
            totalSpeed += (redShirtSpeeds[i] > blueShirtSpeeds[i] ? redShirtSpeeds[i] : blueShirtSpeeds[i]);
        }
    }
    return totalSpeed;
}

LinkedList *EashElevenToFifthteen::removeDuplicatesFromLinkedList(LinkedList *linkedList) {
    LinkedList * p = linkedList;
    while (p && p->next){
        if (p->value == p->next->value){
            p->next = p->next->next;
        }else{
            p = p->next;
        }
    }
    return linkedList;
}

int EashElevenToFifthteen::getNthFib(int n) {
    if (n <= 2){
        return n - 1;
    }
    int prev = 0, curr = 1;
    for (int i = 3; i <=n ; ++i) {
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}
