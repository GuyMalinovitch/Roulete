#include <iostream>
#include <string>
#include "Player.h"
#include "Outcome.h"
#include "Bet.h"
#include "Board.h"


Player::Player(string name)
{
	_name = name;
	_money = 100;
	_win_count = 0;
	_loose_count = 0;
}

bool Player::placeBet(int amount, string outcome)
{
	Bet* myBet = new Bet(this, amount, outcome);
	Board* myBoard = Board::getBoard();
	bool ret;
	ret = myBoard->registerBet(myBet);
	if (ret) {
		cout << "[Player " << getName() << " ]" << " Register Bet - " << myBet->Print() << endl;
	}
	else {
		cout << "[Player " << getName() << " ]" << "Resgister Bet Failed ... " << endl;
	}
	return ret;
}
bool Player::updateMoneyAmount(signed int delta)
{
	_money += delta;
}
void Player::Win(signed int amount)
{
	if (amount = 0) return;
	updateMoneyAmount(amount);
	_win_count++;
	cout << "Player" << getName() << ": Win $" << amount;
}
void Player::Loose(signed int amount)
{
	if (amount = 0) return;
	signed int signedAmount = 0 - amount;
	updateMoneyAmount(signedAmount);
	_loose_count++;
	cout << "Player " << getName() << ": Loose $" << amount;
}

