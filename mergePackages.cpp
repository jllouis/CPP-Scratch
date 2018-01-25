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
        if (complementInt != arr.end())
            return {index, complementIndex};
        else
            m.insert(index, complementIndex);
    }
}

int main() {
    return 0;
}