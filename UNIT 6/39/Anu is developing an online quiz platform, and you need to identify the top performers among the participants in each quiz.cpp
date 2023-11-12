#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Quiz {
private:
    std::vector<T> scores;
public:
    void addScore(T score) {
        scores.push_back(score);
    }

    void findTopTwoScores() {
        std::sort(scores.rbegin(), scores.rend());
        std::cout << scores[0] << " " << scores[1] << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    Quiz<int> intQuiz;
    Quiz<float> floatQuiz;

    for (int i = 0; i < n; i++) {
        int score;
        std::cin >> score;
        intQuiz.addScore(score);
    }

    for (int i = 0; i < n; i++) {
        float score;
        std::cin >> score;
        floatQuiz.addScore(score);
    }

    intQuiz.findTopTwoScores();
    floatQuiz.findTopTwoScores();

    return 0;
}
