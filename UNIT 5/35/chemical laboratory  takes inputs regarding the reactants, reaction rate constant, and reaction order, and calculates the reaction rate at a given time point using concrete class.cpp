#include <bits/stdc++.h>

class ChemicalReaction {
public:
    ChemicalReaction(int numReactants, const std::vector<double>& reactantConcentrations, double reactionRateConstant, int reactionOrder, double time)
        : numReactants(numReactants), reactantConcentrations(reactantConcentrations),
        reactionRateConstant(reactionRateConstant), reactionOrder(reactionOrder), time(time) {}

    double calculateReactionRate() {
        double reactionRate = reactionRateConstant;
        for (int i = 0; i < numReactants; i++) {
            reactionRate *= pow(reactantConcentrations[i], reactionOrder);
        }
        return reactionRate;
    }

    void printReactionRate() {
        double rate = calculateReactionRate();
        std::cout << "The reaction rate at time " << time << " is: " << rate << std::endl;
    }

private:
    int numReactants;
    std::vector<double> reactantConcentrations;
    double reactionRateConstant;
    int reactionOrder;
    double time;
};

int main() {
    int numReactants;
    std::cin >> numReactants;

    std::vector<double> reactantConcentrations(numReactants);
    for (int i = 0; i < numReactants; i++) {
        std::cin >> reactantConcentrations[i];
    }

    double reactionRateConstant;
    int reactionOrder;
    double time;

    std::cin >> reactionRateConstant;
    std::cin >> reactionOrder;
    std::cin >> time;

    ChemicalReaction reaction(numReactants, reactantConcentrations, reactionRateConstant, reactionOrder, time);
    reaction.printReactionRate();

    return 0;
}

