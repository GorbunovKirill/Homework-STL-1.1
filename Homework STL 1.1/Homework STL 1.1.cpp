#include <iostream>
#include <map>
#include<string>
#include <cctype>  

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

void print_character_count(const std::map<char, int>& char_count) {
    for (const auto& pair : char_count) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::string text;
    std::cout << "Enter a text: ";

    std::cin >> std::ws;

 
    std::getline(std::cin, text);


    std::map<char, int> char_count = count_characters(text);

    std::cout << "Character frequencies (descending order):" << std::endl;
    print_character_count(char_count);

    return 0;
}
