#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char* argv[]) {
    std::cout << "You are welcome in the words counter util!" << std::endl;
    std::fstream s(DATA_FILE, s.in);
    if (!s.is_open()) {
        std::cout << "failed to open " << "text.txt" << '\n';
    } else {
        std::string line;
        while (std::getline(s, line)) {
            std::cout << line << std::endl;
        }
    }
    return 0;
}
