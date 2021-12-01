#include <iostream>
#include <random>
#include <fstream>
#include <map>

constexpr char OUTPUT_FILE_NAME[] = "input.txt";

constexpr int MAX_NUMBER_VERTICES = 20;

using namespace std;

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;
};

int custom_rand(int left, int right) {
    return left + rand() % (right - left);
}

int main() {
    ofstream out(OUTPUT_FILE_NAME);
    
    srand(100);
    int verticesNumber = 10;
    int roadsNumber = verticesNumber * (verticesNumber - 1) / 2;
    vector<Edge> edges;
    
    vector<vector<bool> > isExist(verticesNumber + 10, vector<bool>(verticesNumber + 10));

    for (int i = 0; i < verticesNumber + 10; i++) {
        isExist[i][i] = 1;
    }

    for (int i = 0; i < roadsNumber; i++) {
        int fromVertex, toVertex, weight;
        do {
            fromVertex = custom_rand(1, verticesNumber + 1);
            toVertex = custom_rand(1, verticesNumber + 1);
            weight = rand() % 101;
        } while(isExist[fromVertex][toVertex]);

        edges.push_back({fromVertex, toVertex, weight});
        isExist[fromVertex][toVertex] = true;
        isExist[toVertex][fromVertex] = true;
    }

    out << verticesNumber << ' ' << roadsNumber << "\n";
    for (auto edge : edges) {
        out << edge.fromVertex << ' ' << edge.toVertex << ' ' << edge.weight << "\n";
    }

    out.close();

    return 0;
}