#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int consecutive(long num) {

    int count = 0;
    unsigned stop = (num/2)+1;
    for (unsigned start = 1, sum; start < stop; start++) {
        sum = 0;

        for (unsigned i = start; sum < num; i++)
            sum += i;

        if (sum == num)
            count++;

    }

    return count;
}

int main() {

    long num;

    cout << "enter num: ";
    cin >> num;

    steady_clock::time_point start = steady_clock::now();
    cout << num << ": " << consecutive(num) << endl;
    cout << "Exec time: " << duration_cast<microseconds>(steady_clock::now() - start).count() << endl;

    return 0;
}
