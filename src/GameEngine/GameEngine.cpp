#include <iostream>
#include "GameEngine.h"
#include "GameState.h"
#include "GameStartup.h"
#include "GameObservers.h"
#include "GameScore.h"

// Returns true if user selects tournament mode, and false otherwise
bool GameEngine::selectGameMode()
{
    std::cout << "  _____ _       _     _     __  __ _             _         _____                 _                  " << std::endl;          
    std::cout << " | ____(_) __ _| |__ | |_  |  \\/  (_)_ __  _   _| |_ ___  | ____|_ __ ___  _ __ (_)_ __ ___  ___    " << std::endl;
    std::cout << " |  _| | |/ _` | '_ \\| __| | |\\/| | | '_ \\| | | | __/ _ \\ |  _| | '_ ` _ \\| '_ \\| | '__/ _ \\/ __|   " << std::endl;
    std::cout << " | |___| | (_| | | | | |_  | |  | | | | | | |_| | ||  __/ | |___| | | | | | |_) | | | |  __/\\__ \\   " << std::endl;
    std::cout << " |_____|_|\\__, |_| |_|\\__| |_|  |_|_|_| |_|\\__,_|\\__\\___| |_____|_| |_| |_| .__/|_|_|  \\___||___/   " << std::endl;
    std::cout << "          |___/                                                           |_|                       " << std::endl << std::endl;                   

    std::cout << "Please Select a Game Mode: " << std::endl;
    std::cout << "\t1) Single Game" << std::endl;
    std::cout << "\t2) Tournament Game" << std:: endl;

    std:string userSelection;
    std::cin >> userSelection;

    while(userSelection != "1" && userSelection != "2"){
        std::cout << "Please enter either a '1' or a '2': ";
        cin >> userSelection;
    }

    return userSelection == "2";
}

void GameEngine::singleGame()
{
    // setting up the game
    GameState state = GameState(false);
    GameScore gameScore = GameScore();
    int firstPlayerIndex = startGame(state, false);
    int gameLength = state.determineGameLength();
    std::vector<Cards *> topBoard = state.deck->topBoardGenetor(*state.deck);
    std::string action;

    // Setting up the observers
    Observable subject{};
    auto *phase = new PhaseObserver("phase");
    auto *stats = new StatisticsObserver("stats");
    subject.attach(phase);
    subject.attach(stats);

    // number of game terms limited by number of players
    for (int i = 1; i <= gameLength; i++)
    {
        bool changeStrategy = validateChangeStrategy();

        if (changeStrategy)
        {
            changePlayerStrategy(*state.players);
        }

        std::cout << "Turn " << i << ". " << gameLength - i << " Turns remain." << endl
                  << endl;

        // each player gets to play once per turn
        for (int j = firstPlayerIndex; j < firstPlayerIndex + state.players->size(); j++)
        {

            int turnIndex = j % state.players->size();

            // infrom players on whose turn it is, display current state of the map
            std::cout << state.players->at(turnIndex)->getName() << ", it is now your turn." << std::endl;

            // action phase
            action = state.players->at(turnIndex)->getPlayerStrategies()->selectAction(state, turnIndex, topBoard, i);

            // notify
            subject.notify(state, state.players->at(turnIndex)->getName(), action);
        }
    }

    // generate the winner and display the results
    gameScore.generateWinner(*(state.players), *(state.map));
}

void GameEngine::tournamentGame()
{
    // setting up the game
    GameState state = GameState(true);
    GameScore gameScore = GameScore();
    int firstPlayerIndex = startGame(state, true);
    std::vector<Cards *> topBoard = state.deck->topBoardGenetor(*state.deck);
    std::string action;
    int cardInsertionLocation = 0;

    // Setting up the observers
    Observable subject{};
    auto *phase = new PhaseObserver("phase");
    auto *stats = new StatisticsObserver("stats");
    subject.attach(phase);
    subject.attach(stats);

    
    // Set the player strategies
    changePlayerStrategy(*state.players);


    // each player gets to play once per turn
    for (int i = 1; i <= 30; i++)
    {
        // increment only after each player has played
        if (i-1 % state.players->size() == 0) {
            cardInsertionLocation++;
        }

        std::cout << endl << "Turn " << i << ". " << 30 - i << " Turns remain." << endl << endl;

        int turnIndex = firstPlayerIndex % state.players->size() ;

        // infrom players on whose turn it is, display current state of the map
        std::cout << state.players->at(turnIndex)->getName() << ", it is now your turn." << std::endl;

        // action phase
        action = state.players->at(turnIndex)->getPlayerStrategies()->selectAction(state, turnIndex, topBoard, cardInsertionLocation);

        // notify
        subject.notify(state, state.players->at(turnIndex)->getName(), action);

        // increment turn order
        firstPlayerIndex++;
    }

    // generate the winner and display the results
    gameScore.generateWinner(*(state.players), *(state.map));
}