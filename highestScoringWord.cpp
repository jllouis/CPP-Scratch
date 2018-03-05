#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <sstream>

std::string highestScoringWord(const std::string &str) {

    std::vector<std::string> words;
    std::istringstream str_stream{str};
    std::vector<long> scores;

    // todo nothing at all
    // fixme nothing to fix

    while (str_stream) {
        std::string word;
        str_stream >> word;
        words.push_back(word);
    }

    for (std::string &word : words)
        scores.push_back((std::accumulate(word.begin(), word.end(), 0)) - (96 * word.size()));

    return words[std::distance(scores.begin(),
                               std::max_element(scores.begin(), scores.end()))];
}

int main() {
    std::cout << highestScoringWord("man i need a taxi up to ubud") << '\n';
    std::cout << highestScoringWord("what time are we climbing up the volcano") << '\n';
    std::cout << highestScoringWord("take me to semynak") << '\n';
    std::cout << highestScoringWord("massage yes massage yes massage") << '\n';
    std::cout << highestScoringWord("take two bintang and a dance please") << '\n';
}
