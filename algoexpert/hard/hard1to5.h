//
// Created by aolei.bao on 3/26/2023.
//

#ifndef LEARNCPP_ALGORITHM_HARD1TO5_H
#define LEARNCPP_ALGORITHM_HARD1TO5_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>
#include <unordered_set>

using namespace std;

tuple<int, int> getVertexWithMinDistances(vector<int> &distances, unordered_set<int> &visited) {
    int currentMinDistance = numeric_limits<int>::max();
    int vertex = -1;
    for (int i = 0; i < distances.size(); ++i) {
        int distance = distances[i];
        if (visited.find(i) != visited.end()) {
            continue;
        }
        if (distance <= currentMinDistance) {
            vertex = i;
            currentMinDistance = distance;
        }
    }
    return {vertex, currentMinDistance};
}

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int numberOfVertices = edges.size();
    vector<int> minDistances(numberOfVertices, numeric_limits<int>::max());
    minDistances[start] = 0;
    unordered_set<int> visited;
    while (visited.size() != numberOfVertices) {
        auto [vertex, currentMinDistance] = getVertexWithMinDistances(minDistances, visited);
        if(currentMinDistance == numeric_limits<int> ::max()){
            break;
        }
        visited.insert(vertex);
        for(auto edge : edges[vertex]){
            auto destination = edge[0];
            auto distanceToDestination = edge[1];
            if(visited.find(destination) != visited.end()){
                continue;
            }
            auto newPathDistance = currentMinDistance + distanceToDestination;
            auto currentDestinationDistance = minDistances[destination];
            if(newPathDistance < currentDestinationDistance){
                minDistances[destination] = newPathDistance;
            }
        }
    }

    vector<int> finalDistances;
    for (auto distance: minDistances) {
        if(distance == numeric_limits<int> ::max()){
            finalDistances.push_back(-1);
        }else{
            finalDistances.push_back(distance);
        }
    }
    return finalDistances;
}


#endif //LEARNCPP_ALGORITHM_HARD1TO5_H
