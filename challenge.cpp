//
// Created by lael on 1/19/18.
//
#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

int getHostID(string s) {
    //get host_id from string
    string host;
    istringstream iss(s);
    std::getline(iss, host, ',');
    return atoi(host.c_str());
}

vector<string> paginate(int num, vector<string> results) {

    queue<string> leftOver;
    vector<string> output;
    bitset<1024> displayed;

    unsigned processed = 0, numLeftOver = 0;
    for (const string s : results) {

        if (processed == num && !leftOver.empty()) {
            displayed.reset();
            output.push_back("");
            processed = 0;

            for (unsigned i = 0; i < num && !leftOver.empty(); i++) {
                int host_id = getHostID(leftOver.front());

                if (displayed[(unsigned) host_id]) {
                    leftOver.push(leftOver.front());
                    leftOver.pop();

                } else {
                    output.push_back(s);
                    displayed.set((unsigned) host_id);
                    processed++;
                    numLeftOver--;
                };
            }
        }

        if (processed == num)
        {
            output.push_back("");
            processed = 0;
        }

        // may skip over current elem?
        if(processed < num) {
            int host_id = getHostID(s);

            //if not already displayed in this loop, enqueue
            if (displayed[(unsigned) host_id]) {
                leftOver.push(s);
                numLeftOver++;
            }
                // if not, display in this page
            else {
                output.push_back(s);
                displayed.set((unsigned) host_id);
                processed++;
            }
        }


}

    while(!leftOver.empty()) {
        for (unsigned i = 0; i < num && !leftOver.empty(); i++) {
            output.push_back(leftOver.front());
            leftOver.pop();
        }
        output.push_back("");
    }

    return output;
}

int main()
{

    return 0;
}