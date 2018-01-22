#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int consecutive(long num) {

    int count = 0;
    long long stop = (num / 2) + 1;

    for (long long left = 1, next = 2, sum = 1; next <= stop;) {

        while (sum < num)
            sum += next++;

        while (sum > num)
            sum -= left++;

        if (sum == num) {
            count++; // found an answer
            long long left_sum = 0;

            while ((left_sum + left) <= next) // add left to list of numbers to sub, and move right one to update range
                left_sum += left++;           // necessary to move to avoid getting stuck at this answer instance

            sum -= left_sum;
            sum += next++;
        }
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