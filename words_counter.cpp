#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using WordsMap = std::map<std::string, unsigned int>;

void updateMap(WordsMap& map, const std::string& word) {
    auto it = map.find(word);

    if (it != map.end()) {
        map[word] = map[word] + 1;
    } else {
        map[word] = 1;
    }
}

void removeRedundantChars(std::string& word) {
    std::string chars = "#!(),.:;@#$%^&*-?\"<>";
    word.erase(std::remove_if(word.begin(), word.end(),
                        [&chars](const char &c) {
                            return chars.find(c) != std::string::npos;
                        }),
                        word.end());
}

bool parseLine(const std::string& line, WordsMap& map) {
    std::string word;
    std::stringstream line_stream(line);

    while (line_stream >> word) {
        removeRedundantChars(word);
        std::cout << "Word: " << word << std::endl;
        if (word.length() > 0) {
            updateMap(map, word);
        }
    }

    return true;
}

void printMap(WordsMap const& map) {
    for (auto it : map) {
        std::cout << "Word: " << it.first
                  << " | Times: " << it.second << std::endl;
    }
}

int main (int argc, char* argv[]) {
    std::cout << "You are welcome in the words counter util!" << std::endl;
    std::fstream s(DATA_FILE);
    if (!s.is_open()) {
        std::cout << "failed to open " << "text.txt" << '\n';
    } else {
        WordsMap map;
        std::string line;
        int lines = 0;

        while (std::getline(s, line)) {
            ++lines;
            std::cout << line << std::endl;
            if (!parseLine(line, map)) {
                std::cout << "Failed to parse line!" << std::endl;

                return -1;
            }
        }

        printMap(map);

        std::cout << "Total lines: " << lines << std::endl;
    }
    return 0;
}
