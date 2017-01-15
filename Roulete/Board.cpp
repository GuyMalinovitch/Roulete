#include <iostream>
#include "Board.h"
#include "Bet.h"

bool Board::instanceFlag = false;
Board* Board::BoardP = NULL;

Board::Board()
{
	cleanBetList();
}

Board::~Board()
{
	Bet* bet = NULL;
	BetVI betVI = getAllBetsVI();
	while ((bet = *(betVI++))) 
	{
		delete bet;
	}
}

Board* Board::getBoard()
{
	if (!instanceFlag) {
		BoardP = new Board();
		instanceFlag = true;
		return BoardP;
	}
	else {
		return BoardP;
	}
}

bool Board::registerBet(Bet* bet)
{
	if (bet->getAmount() < 1) return false;
	addBetToList(bet);
	cout << "[Board]: Registered Bet:" << bet->getPlayerName() << " " << bet->Print() << endl;
	return true;
}



