#pragma once
#include <stdio.h>
#include <set>
#include <list>
#include <string>
#include <unordered_map>


using namespace std;
typedef list<Outcome> OutcomeL;
typedef list<Outcome>::iterator OutcomeLI;


typedef enum Bin {
	UnknownT,
	ZERO, D_ZERO,
	ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTHTEEN , SIXTEEN, SEVENTEEN, EIGHTEEN, NINETEEN, TWENTY,
	TWENTY1,TWENTY2,TWENTY3,TWENTY4, TWENTY5, TWENTY6,TWENTY7,TWENTY8,TWENTY9,THIRTY,
};

class Outcome
{
public:
	Outcome(string name, int odds);
	virtual ~Outcome() {}
	const char* getName() { return (_name.c_str()); }
	int getOdds() { return _odds; }
private:
	string _name;
	int _odds;
};

typedef set<Outcome*> OutcomeS;
typedef set<Outcome*>::iterator OutcomeSI;
typedef unordered_map<string, int> StrToIntHash;

class OutcomeFactory
{
public:
	OutcomeFactory* getOutcomeFactory();
	virtual ~OutcomeFactory();
	Outcome* getOrCreateOutcome(char* outcomeName);
private:
	OutcomeFactory() {}
	void cleanOutcomes() { _outcomeSet.clear(); }
	Outcome* findOutcomeInSet(char* outcomeName);
	Outcome* createOutcome(char* outcomeName);
	int getOutcomeOddsFromName(char* name);
	int genOutcomeOddsFromNameHash();
private:
	OutcomeS _outcomeSet;
	static bool instanceFlag;
	static OutcomeFactory* outcomeFactoryP;
	StrToIntHash _nameToOddHash;
	
};


