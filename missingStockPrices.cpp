//
// Created by lael on 1/21/18.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> fillMissing(const vector<string> &data) {
    // naive solution, insert average of adjacent days


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned length;
    string input;
    vector<string> data;
    cin >> length;

    for (int i = 0; i < length; i++) {
        cin >> input;
        data.push_back(input);
    }

    auto result = fillMissing(data);

    for (string row : result)
        cout << row << endl;

    return 0;
}

