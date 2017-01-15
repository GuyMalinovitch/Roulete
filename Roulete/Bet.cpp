#include "Bet.h"
#include "Player.h"
#include "Outcome.h"

Bet::Bet(Player* player, int amount, string outcome)
{
	_player = player;
	_amount = amount;
	_printS.clear;
	_printS = outcome + " - $" + to_string(_amount);

}

string Bet::Print()
{
	return _printS.c_str();
}