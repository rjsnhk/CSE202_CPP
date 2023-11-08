#include <iostream>
#include <string>

class SearchEngine {
private:
    std::string text;

public:
    SearchEngine(const std::string& _text) : text(_text) {}

    bool operator/(const std::string& substring) const {
        return text.find(substring) != std::string::npos;
    }
};

int main() {
    std::string mainText, substring;
    std::getline(std::cin, mainText);
    std::getline(std::cin, substring);

    SearchEngine engine(mainText);

    if (engine / substring) {
        std::cout << "Substring is present" << std::endl;
    } else {
        std::cout << "substring is not present" << std::endl;
    }

    return 0;
}

