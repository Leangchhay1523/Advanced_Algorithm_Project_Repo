#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;


class GraphColoring {
    int numVertices; // Number of vertices
    std::vector<std::vector<int>> adjList; // Vector of adjacency lists

public:
    GraphColoring(int numVertices) : numVertices(numVertices) {
        adjList.resize(numVertices);
    }

    void addEdge(int u, int v) {
        if (u >= numVertices || v >= numVertices || u < 0 || v < 0) return;
        adjList[u].push_back(v);
    }

    void addConflictEdge(vector<string>& result){ // Result is the list of vertices
        for (int i = 0; i < result.size(); i++){
            for (int j = 0; j < result.size(); j++){
                if (result[i] == result[j]){
                    continue;
                }

                if (findConflict(result[i], result[j])){
                    addEdge(i, j);
                }
            }
        }
    }

    bool findConflict(string str1, string str2){
        return (str1.substr(0, 2) == str2.substr(0, 2) || str1.substr(2, 3) == str2.substr(2, 3));
    }

    void greedyColoring(vector<int>& result, vector<int>& colorCount) {
        
        result[0] = 0; 
        colorCount[0]++;

        for (int i = 1; i < numVertices; i++) {
            result[i] = -1; 
        }

        bool* available = new bool[numVertices]; 
        for (int cl = 0; cl < numVertices; cl++) {
            available[cl] = false;
        }

        for (int i = 1; i < numVertices; i++) {
            for (int j = 0; j < adjList[i].size(); j++) {
                if (result[adjList[i][j]] != -1) {
                    available[result[adjList[i][j]]] = true;
                }
            }

            int cl;
            for (cl = 0; cl < numVertices; cl++) {
                if (!available[cl] && colorCount[cl] < 2) {
                    break;
                }
            }

            result[i] = cl;
            colorCount[cl]++;

            for (int j = 0; j < adjList[i].size(); j++) {
                if (result[adjList[i][j]] != -1) {
                    available[result[adjList[i][j]]] = false;
                }
            }
        }
    }
};

#endif