#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy(const vector<vector<int>> &inputMatrix) {
    // your code goes here
    int x_length = inputMatrix[0].size();  // rows
    int y_length = inputMatrix.size();     // columns

    int matrix_size = x_length * y_length;

    int count = 0;
    vector<int> result;

    // [[1]]
    int x = 0, y = 0;  // startX, startY
    int startX = 0;
    int startY = 0;

    while (count < matrix_size) {

        startX = x; // remember horizontal starting point
        // traverse right, horizontal
        for (; x < x_length; x++) {
            cout << "Inserting: " << inputMatrix[x][y] << endl;
            result.push_back(inputMatrix[x][y]);
            count++;
        }

        x--;  // bring back last column
        y++;  // work on next row

        startY = y; // remember vertical starting point
        // traverse down
        for (; y < y_length; y++) // x = ? , start value y should you go to last row, 10, 15, 20
        {
            cout << "Inserting: " << inputMatrix[x][y] << endl;
            result.push_back(inputMatrix[x][y]);
            count++;
        }

        y--; // bring back to last row
        x--; // column next to last column

        //traverse left
        for (; x >= startX; x--)  // startX
        {
            cout << "Inserting: " << inputMatrix[x][y] << endl;
            result.push_back(inputMatrix[x][y]);
            count++;
        }

        x++;
        y--;

        for (; y > startY; y--)  // startY
        {
            cout << "Inserting: " << inputMatrix[x][y] << endl;
            result.push_back(inputMatrix[x][y]);
            count++;
        }

        x++;
        y--;

        x_length -= 2;
        y_length -= 2;
    }

    return result;
}

int main() {

    vector<vector<int>> inputMatrix = {{1},
                                       {2}};
    auto result = spiralCopy(inputMatrix);

    //cout << "Size of result i"
    for (int i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}