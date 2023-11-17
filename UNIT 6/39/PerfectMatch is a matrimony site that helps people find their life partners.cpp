#include <iostream>
#include <vector>

template <size_t N>
struct Profile {
    int attributes[N];
};

template <size_t N>
int calculateCompatibilityScore(const Profile<N>& profile1, const Profile<N>& profile2) {
    int score = 0;

    for (size_t i = 0; i < N; i++) {
        if (profile1.attributes[i] == profile2.attributes[i]) {
            score += 10;
        }
    }

    return score;
}

int main() {
    const size_t NUM_ATTRIBUTES = 3;
    Profile<NUM_ATTRIBUTES> profile1, profile2;

    for (size_t i = 0; i < NUM_ATTRIBUTES; i++) {
        std::cin >> profile1.attributes[i];
    }

    for (size_t i = 0; i < NUM_ATTRIBUTES; i++) {
        std::cin >> profile2.attributes[i];
    }

    int compatibilityScore = calculateCompatibilityScore(profile1, profile2);

    std::cout << "Compatibility Score: " << compatibilityScore << std::endl;

    return 0;
}

