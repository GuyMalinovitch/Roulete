#pragma once
#include "Outcome.h"


// 1) holds how much money
// 2) hold what the outcome we bet on
// 3) which player placed the bet.
class Bet
{
public:
	Bet::Bet(Player* player, int amount, string outcome);
	virtual ~Bet() {};
	string getPlayerName() { return _player->getName(); }
	int getAmount() { return _amount; }
	string Print();
private:
	Player* _player;
	unsigned int _amount;
	string _printS;
	OutcomeL outcomeList;

};