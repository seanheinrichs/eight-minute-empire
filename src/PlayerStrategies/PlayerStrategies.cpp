#include <iostream>

#include "PlayerStrategies.h"

void GreedyComputer::selectAction(GameState &state, int turnIndex, std::vector<Cards*> topBoard, int currentTurn) {

    std::cout << "Greedy Computer want to DESTROY ALL HUMANS";

}

std::string GreedyComputer::displayCurrentStrategy() {
    return "Greedy Computer";
}

void HumanPlayer::selectAction(GameState &state, int turnIndex, std::vector<Cards*> topBoard, int currentTurn) {

    // player purchases a card
    state.deck->exchange(*state.players->at(turnIndex), topBoard, *state.deck);

    // player has the option to ignore card effect, effectively ending their turn
    bool endTurn = state.players->at(turnIndex)->ignore();
    if (endTurn) {
        return;
    }

    std::string action = *(state.players->at(turnIndex)->getGameHand()->at(currentTurn-1)->getAction());

    //if card action is of type "AND" or "OR" call andOrAction()
    if (action.find("OR") != std::string::npos || action.find("AND") != std::string::npos) {
        state.players->at(turnIndex)->andOrAction(action, *state.map, *state.players);
    }
    // otherwise call takeAction
    else {
        state.players->at(turnIndex)->takeAction(action, *state.map, *state.players);
    }

}

std::string HumanPlayer::displayCurrentStrategy() {
    return "Human Player";
}


void ModerateComputer::selectAction(GameState &state, int turnindex, std::vector<Cards*> topBoard, int currentTurn) {

    std::cout << "Moderate Computer wants to control ALL THE ZONES!";

}

std::string ModerateComputer::displayCurrentStrategy() {
    return "Moderate Computer";
}

// Utility Methods for Driver

bool validateChangeStrategy() {
    std::string answer;
    bool invalidAnswer = true;

    std::cout << "Would you like to change or set any player strategies (y/n)? ";
    do {
        std::cin >> answer;
        if (answer == "y" || answer == "n") {
            invalidAnswer = false;
        }
        else {
            std::cout << "Please enter a 'y' or 'n': ";
        }
    } while (invalidAnswer);

    return (answer == "y");
}

void changePlayerStrategy(std::vector<Player*> players) {
    bool continueChangingStrategy = true;

    while (continueChangingStrategy) {
        // display all players and their current strategies
        std::cout << "Please select a player to change their strategy (1 - " << players.size() << "): " << std::endl;
        for (int i = 1; i-1 < players.size(); i++) {
            std::cout << i << ") " << players.at(i-1)->getName() << ": " << players.at(i-1)->getPlayerStrategies()->displayCurrentStrategy() << std::endl;
        }

        int playerSelection;

        // allow user to select a player to change their strategy
        std::cout << std::endl;
        std::cin >> playerSelection;
        while (playerSelection < 1 || playerSelection > players.size()) {
            std::cout << "Please enter a number from (1 - " << players.size() << "): ";
            std::cin >> playerSelection;
        }

        // display choices
        std::cout << std::endl << "Please selection that player's new stratedgy: " << std::endl;
        std::cout << "1) Human Player" << std::endl << "2) Greedy Computer" << std::endl << "3) Moderate Computer" << std::endl;

        int strategySelection;

        // allow user to select a new strategy
        std::cout << std::endl;
        std:: cin >> strategySelection;
        while (strategySelection < 1 || strategySelection > 3) {
            std::cout << "Please enter a number from (1 - 3): ";
            std::cin >> strategySelection;
        }

        // change player strategy
        switch(strategySelection) {
            case (1):
                players.at(playerSelection-1)->setPlayerStrategy(new HumanPlayer());
                std::cout << players.at(playerSelection-1)->getName() << " is now a Human Player." << std::endl;
                break;
            case (2):
                players.at(playerSelection-1)->setPlayerStrategy(new GreedyComputer());
                std::cout << players.at(playerSelection-1)->getName() << " is now a Greedy Computer." << std::endl;
                break;
            case (3):
                players.at(playerSelection-1)->setPlayerStrategy(new ModerateComputer());
                std::cout << players.at(playerSelection-1)->getName() << " is now a Moderate Computer." << std::endl;
                break;
        }

        std::cout << "Would you like to change the strategy of another player? ";
        continueChangingStrategy = validateChangeStrategy();
    }
}