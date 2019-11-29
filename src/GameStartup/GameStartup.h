#pragma once
#include "GameState.h"

// Runs the startup phase of the game:
// 1) Adds three armies for each player to the start region
// 2) If two players, distributes netural armies
// 3) Runs the bidding phase
// returns the index of the player who goes first
int startGame(GameState &state, bool isTournament);

// Adds apppropriate number of armies to starting region
void addArmiesToStart(GameState &state);

// Players add ten neutral armies to the board
void addNeutralArmies(GameState &state);