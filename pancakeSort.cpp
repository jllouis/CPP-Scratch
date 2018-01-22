#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void flip(vector<int>& arr, int k)
{
    reverse(arr.begin(), arr.begin()+k);
}


// 0  1  2  3  4
// {1, 5, 4, 3, 2};
// 4, 3, 2, 1, 5
vector<int> pancakeSort( const vector<int>& arr2 )
{
    vector <int> arr(arr2);
    vector<int>::size_type size = arr2.size();


    for(int i = size-1 ; i >= 0; i--) // size...1
    {
        // find largest element in scope
        int tmp  = INT_MIN, index; //tmp = INT_MIN
        for(int j = 0; j <= i; j++)
        {
            if (arr[j] > tmp)
            {
                tmp = arr[j];
                index = j;
            }

        }

        flip(arr, index+1);
        flip(arr, i+1);

        /*cout << "Scope " << i << ": ";
        for (int num : arr)
          cout << num << " ";
        cout << endl;*/
    }

    return arr;
}

int main() {

    vector<int> arr = {1, 5, 4, 3, 2};
    auto result = pancakeSort(arr);

    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}

/*
[1 5 4 3 2] -> [5 1 4 3 2] -> [2 3 4 1 5] -> [4 3 2 1 5] -> [1 2 3 4 5]
*/