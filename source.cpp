#include <vector>
#include <string>
#include <iostream>
#include <sstream>

void generate_permutations_of_length(std::vector<std::string>& items, std::vector<std::string>& permutation, int length) {
    if (permutation.size() == length) {
        for (const auto& item : permutation) {
            std::cout << item;
        }
        std::cout << std::endl;
        return;
    }

    for (int i = 0; i < items.size(); ++i) {
        permutation.push_back(items[i]);
        generate_permutations_of_length(items, permutation, length);
        permutation.pop_back();
    }
}

void generate_permutations(std::vector<std::string>& items, int max_length) {
    std::vector<std::string> permutation;
    for (int length = 1; length <= max_length; ++length) {
        generate_permutations_of_length(items, permutation, length);
    }
}

std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> items;
    int max_length = 0;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find("--items=") == 0) {
            items = split(arg.substr(8), ',');
        } else if (arg.find("--max_length=") == 0) {
            max_length = std::stoi(arg.substr(13));
        }
    }

    generate_permutations(items, max_length);

    return 0;
}