#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> findArrayQuadruplet(const vector<int> &arr2, int s) {
    vector<int> arr(arr2);
    sort(arr.begin(), arr.end());

    // [0, 1, 2, 3, 4, 5, 7, 9]
    for (vector<int>::size_type i = 0; i < arr.size() - 3; i++)
        for (vector<int>::size_type j = i + 1; j < arr.size() - 2; j++) {
            vector<int>::size_type l = j + 1, r = arr.size() - 1;
            while (l < r) {
                if (arr[l] + arr[r] > s - (arr[i] + arr[j]))
                    r--;
                else if (arr[l] + arr[r] < s - (arr[i] + arr[j]))
                    l++;
                else // == s - (arr[i]+arr[j]))
                    return {arr[i], arr[j], arr[l], arr[r]};
            }
        }

    return {};
}

int main() {

    vector<int> arr = {2, 7, 4, 0, 9, 5, 1, 3};
    vector<int> arr2 = {};
    int s = 20;
    auto res = findArrayQuadruplet(arr, s);
    cout << "test";
    for (auto elem : res)
        cout << elem << " ";
    return 0;
}

/*
  arr = sort(arr);
  traversing from 0 to n -1; 
  sum = 0;
  for elem in arr:
    if 
   
    0,1,2,3,4,5,7,9
    0,1,3,7
 
*/