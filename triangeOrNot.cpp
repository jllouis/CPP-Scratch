//
// Created by lael on 1/17/18.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> triangleOrNot(vector<int> a, vector<int> b, vector<int> c) {

    vector<int>::size_type i, max_size = max(a.size(), max(b.size(), c.size())), min_size = min(a.size(), min(b.size(),
                                                                                                              c.size()));

    vector<string> results;

    for (i = 0; i < min_size; i++)
        results.emplace_back(((a[i] < b[i] + c[i])
                              && (b[i] < a[i] + c[i])
                              && (c[i] < a[i] + b[i])) ? "Yes" : "No");

    for (i = 0; i < max_size - min_size; i++)
        results.emplace_back("No");


    return results;
}

int main() {
    vector<int> x{7, 10, 7}, y{2, 3, 4}, z{2, 7, 4};

    auto results = triangleOrNot(x, y, z);
    for (string r : results)
        cout << r << endl;

    return 0;
}