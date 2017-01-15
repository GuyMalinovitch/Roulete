#pragma once
#include <string>
#include <list>

using namespace std;

// 1) place bets to Board by input
// 2) holds current money.
// 3) holds win-lose statistics
class Player
{
public:
	Player(string name);
	virtual ~Player() {};
	string getName() { return _name; }
	bool placeBet(int amount, string outcome);
	bool updateMoneyAmount(signed int delta);
	void Win(signed int amount);
	void Loose(signed int amount);
private:
	string _name;
	unsigned int _money;
	unsigned int _win_count;
	unsigned int _loose_count;
};

typedef vector<Player*> PlayerV;
typedef vector<Player*>::iterator PlayerVI;






