//
// Created by lael on 1/24/18.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;

vector<int> getIndicesOfItemWeights(const vector<int> &arr, int limit) {
    // your code goes here
    map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        auto w = arr[i];
        auto complementIndex = m.find(limit - w);
        if (complementIndex != m.end())
            return {i, complementIndex->first};
        else
            m.insert(std::make_pair(i, complementIndex->first));
    }
}

int main() {
    return 0;
}