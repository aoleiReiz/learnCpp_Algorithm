#include <iostream>
#include "hashmap/MyHashMap.h"

using namespace  std;

int main() {

    MyHashMap myHashMap;
    myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
    myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
    myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
    myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
    myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
    myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
    myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
    myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]

    return 0;
}
