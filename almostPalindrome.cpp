#include <bits/stdc++.h>

using namespace std;

int almostPalindrome(string word) {
    int count = 0;

    for (auto left = word.begin(), right = word.end() - 1; left < right; left++, right--)
        if ((*left) != (*right))
            count += 2;

    return count;
}

int main() {
    cout << almostPalindrome("aabdcaa");

    return 0;
}