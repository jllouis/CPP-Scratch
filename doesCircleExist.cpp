#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MOD(a, b)  (a < 0 ? (((a % b) + b) % b) : (a % b))

bool circular(string command) {

    vector<int> location{0, 0};
    std::vector<char> heading{'n', 'e', 's', 'w'};
    std::map<char, std::vector<int>> direction{{'n', {0,  1}},
                                               {'e', {1,  0}},
                                               {'s', {0,  -1}},
                                               {'w', {-1, 0}}};
    int pointing = 0;
    bool moved = false;

    for (unsigned i = 0; i < 4; i++)
        for (char c : command)
            switch (toupper(c)) {
                case 'G':
                    location[0] += direction[heading[MOD(pointing, 4)]][0];
                    location[1] += direction[heading[MOD(pointing, 4)]][1];
                    moved = true;
                    break;
                case 'R':
                    pointing++;
                    break;
                case 'L':
                    pointing--;
                    break;
                default:
                    cerr << "Invalid Command: " << (char) toupper(c) << endl;
                    return false;
            }

//    cout << "End location: {" << location[0] << "," << location[1] << "}, Dir:  " << heading[MOD(pointing, 4)] << endl;


    return ((!location[0] && !location[1]) && !MOD(pointing, 4)) || !moved;
}

vector<string> doesCircleExist(vector<string> commands) {
    vector<string> results;
    for (string command : commands) {
        if (circular(command))
            results.push_back("YES");
        else
            results.push_back("NO");
    }

    return results;
}

int main() {
    string commands;
    cout << "Enter commands: ";

    while (cin >> commands) {
        cout << circular(commands) << endl;
        cout << "Enter commands: ";
    }

    return 0;
}
