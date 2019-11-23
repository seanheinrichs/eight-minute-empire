#include <iostream>
#include "GameEngine.h"

// Returns true if user selects tournament mode, and false otherwise
bool GameEngine::selectGameMode()
{
    std::cout << "  _____ _       _     _     __  __ _             _         _____                 _                  " << std::endl;          
    std::cout << " | ____(_) __ _| |__ | |_  |  \/  (_)_ __  _   _| |_ ___  | ____|_ __ ___  _ __ (_)_ __ ___  ___    " << std::endl;
    std::cout << " |  _| | |/ _` | '_ \| __| | |\/| | | '_ \| | | | __/ _ \ |  _| | '_ ` _ \| '_ \| | '__/ _ \/ __|   " << std::endl;
    std::cout << " | |___| | (_| | | | | |_  | |  | | | | | | |_| | ||  __/ | |___| | | | | | |_) | | | |  __/\__ \   " << std::endl;
    std::cout << " |_____|_|\__, |_| |_|\__| |_|  |_|_|_| |_|\__,_|\__\___| |_____|_| |_| |_| .__/|_|_|  \___||___/   " << std::endl;
    std::cout << "          |___/                                                           |_|                       " << std::endl << std::endl;                   

    std::cout << "Please Select a Game Mode: " << std::endl;
    std::cout << "\t1) Single Game" << std::endl;
    std::cout << "\t2) Tournament Game" << std:: endl;

    char userSelection; 
    std::cin >> userSelection;

    while(userSelection != '1' || userSelection != '2'){
        std::cout << "Please enter either a '1' or a '2': ";
        cin >> userSelection;
    }

    return userSelection == 2;
}