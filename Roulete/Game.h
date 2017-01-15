#pragma once

#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Board.h"
#include "Wheel.h"
#include "Player.h"
#include "Outcome.h"

// singelton class.
// 1) register new players
// 2) register house player.
// 3) manager of the game
//		i. measure time for bets.
//	   ii. spin wheel
//	  iii. tell board to disterbute money.
class Game
{
public:
	static Game* getGame();
	virtual ~Game();
	void startGame();
	void startRound();
	bool registerAllPlayers();
private:
	Game();
	void roundOfBets();
	void spinWheel();
	bool registerPlayer(string pName);
private:
	static Game* GameP;
	static bool instanceFlag;
	PlayerV allPlayers;
};

