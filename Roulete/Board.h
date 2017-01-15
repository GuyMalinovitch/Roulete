#pragma once
#include <vector>
#include <list>
#include "Outcome.h"
#include "Player.h"

typedef list<Bet> BetV;
typedef list<Bet>::iterator BetVI;

// singelton class
// book keeper
// 1) hold all current betsduring initial time. 
// 2) get winning number from wheel.
// 3) calculate winning bets.
// 4) when told by game - distribute money.
class Board
{
public:
	static Board* getBoard();
	virtual ~Board() {}
	bool registerBet(Bet* bet);
	void cleanBetList();
	Bet* getBetByOutcome(Outcome* out);
	BetVI getAllBetsVI() { return allBets.begin(); }
	void addBetToList(Bet* bet) { allBets.push_back(*bet); }
	void cleanBetList() { allBets.clear(); }
private:
	Board();
	static bool instanceFlag;
	static Board* BoardP;
	BetV allBets;

};

