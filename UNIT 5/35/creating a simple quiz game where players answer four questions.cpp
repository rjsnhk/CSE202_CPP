#include <iostream>
#include <string>

class Base {
public:
    virtual void game() = 0;
};

class Derived : public Base {
public:
    void game() override {
        std::string answers;
        std::getline(std::cin, answers);

        int score = 0;
        for (char c : answers) {
            if (std::isalpha(c)) {
                if (std::isupper(c)) {
                    score += 10;
                } else {
                    score -= 5;
                }
            }
        }

        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    Derived game;
    game.game();

    return 0;
}

