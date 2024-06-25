#include <iostream>
#include <map>
#include <cctype>  
#include <vector>  
#include <algorithm>
#include<string>

std::map<char, int> count_characters(const std::string& text) {
    std::map<char, int> char_count;

    for (char ch : text) {

        char lower_ch = std::tolower(static_cast<unsigned char>(ch));

        if (std::isalnum(lower_ch)) {
            char_count[lower_ch]++;
        }
    }

    return char_count;
}

int main() {
    std::string text;
    std::cout << "Enter a text: ";

    std::cin >> std::ws;
    std::getline(std::cin, text);

    std::map<char, int> char_count = count_characters(text);

    std::vector<std::pair<char, int>> char_vector(char_count.begin(), char_count.end());

    std::sort(char_vector.begin(), char_vector.end(),
        [](const auto& left, const auto& right) {
            return left.second > right.second;
        });

    std::cout << "Character frequencies (descending order):" << std::endl;
    for (const auto& pair : char_vector) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
