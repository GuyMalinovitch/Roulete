
#include "Game.h"

bool Game::instanceFlag = false;
Game* Game::GameP = NULL;

Game::Game()
{
	allPlayers.clear();
	// instanciate dummy house player
	registerPlayer("House");
}


Game::~Game()
{
	instanceFlag = false;
}


Game* Game::getGame()
{
	if (!instanceFlag) {
		GameP = new Game();
		instanceFlag = true;
		return GameP;
	}
	else {
		return GameP;
	}
}

void Game::startGame()
{
	// generate player list.
	registerAllPlayers();
	// start round
	startRound();
	return;
}

void Game::startRound()
{
	// gets bets.
	roundOfBets();
	// spin wheel.
	spinWheel();
	// declare winners.

}

bool Game::registerPlayer(string pName)
{
	if (pName.empty()) {
		cout << "[Game]: ERROR - Player name is empty" << endl;
		return false;
	}
	Player* p = new Player(pName);
	allPlayers.push_back(p);
	cout << "[Game]: New player registered: " << p->getName() << endl;
	return true;
}

bool Game::registerAllPlayers()
{
	int numOfPlayers = 0;
	int cnt = 0;
	do {
		cout << "[Game]: Please enter number of Players:";
		cin >> numOfPlayers;
		cnt++;
		if (cnt == 3) {
			cout << "[Game]: ERROR - Too many wrong enteries" << endl;
			return false;
		}
	} while (numOfPlayers < 1);
	for (int i = 0; i < numOfPlayers; i++) {
		string pName;
		cout << "[Game]: Please enter name of Player " << i << endl;
		cin >> pName;
		registerPlayer(pName);
	}
	cout << "Done registering players." << endl;
}

void Game::spinWheel()
{
	Wheel* w = Wheel::getWheel();
	w->
}