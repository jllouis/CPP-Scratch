#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
 */

int main() {
    std::vector<std::string> words{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::pair<std::string, std::string>> pairs;
    std::vector<std::vector<std::string>> result;

    for (auto word : words) {
        auto tmp = word;
        std::sort(tmp.begin(), tmp.end());
        pairs.emplace_back(tmp, word);
    }

    std::sort(pairs.begin(), pairs.end());

    for (auto i = pairs.begin(); i < pairs.end();) {
        std::vector<std::string> tmp;

        for (auto j = i + 1; j != pairs.end() && j->first == i->first;) {
            tmp.push_back(j->second);
            pairs.erase(j);
        }

        tmp.push_back(i->second);
        pairs.erase(i);
        result.push_back(tmp);
    }

    for (auto &vector : result) {
        std::cout << "{ ";
        for (auto &word : vector)
            std::cout << word << " ";
        std::cout << "}" << std::endl;
    }

    return EXIT_SUCCESS;
}