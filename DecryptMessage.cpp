#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* for letter in encryption until encryption 1 (not 0, which is the first letter)
    intermediate[i] = encryption[i] - encryption[i-1]
    result[i] = add 26 to intermediate[i] until between 97 and 122

result[0] = encryption[0] - 1
*/

string decrypt(const string &word) {

    if (word.size() < 1)
        return "";

    // your code goes here
    vector<char> intermediate(word.size());
    for (unsigned i = word.size() - 1; i > 0; i--) {
        intermediate[i] = word[i] - word[i - 1];
        while (intermediate[i] < 97)
            intermediate[i] += 26;
    }

    // cout << "first char:" << intermediate[0] << endl;
    intermediate[0] = word[0] - 1;

    string result(intermediate.begin(), intermediate.end());

    return result;
}

int main() {

    //for (char& c : decrypt("dnotq"))
    //cout << int(c) << endl;

    cout << decrypt("dnotq") << endl;
}
/*
Add 1 to first letter
add value of prev letter to following letters
sub 26 from values until within a-z (97-122)

reverse:
value of string[0]; 
for every letter from string[1] to string[n-1], sub string[0] from them
adding 26 from letter until letter values are between 97 and 122
sub 1 from string[0]



c   r   i   m   e
100 110 111 116 113
|    |  |    |   | + m* 26
100 214 319 428 529
99 114 105 109 101

// r, 114 want to encryt
enc[n] = dec[n] + secondStep[n - 1] - 26m
110    =  114   +   100            - 26m

enc[n] = dec[n] + enc[n - 1] - 26 * m
enc[n] - enc[n-1] = dec[n] - 26m
enc[n] - enc[n-1] + 26m = dec[n]

for letters from last to first -1
  res[n] = value of word[n] - val of [n-1] 
    while (res[n]) is not within {97, 122}
      res[n]+= 26



*/

/*

100   110   111   116   113
      -100  -110  -111  -116
      10    1     5       -3
      +26m  +26m  +26m   +26m
      114    105   109    101
      
for letter in encryption until encryption 1 (not 0, which is the first letter)
    intermediate[i] = encryption[i] - encryption[i-1]
    result[i] = add 26 to intermediate[i] until between 97 and 122
    
result[0] = encryption[0] - 1

      
*/