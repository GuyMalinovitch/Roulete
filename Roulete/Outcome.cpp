#include <algorithm>
#include "Outcome.h"

using namespace std;

Outcome::Outcome(string name, int odds)
{
	_name = name;
	_odds = odds;
}

struct findByName {
	findByName(const string & name) : name(name) {}
	bool operator()(Outcome & outcome) {
		return (name.compare(outcome.getName()) == 0 ? true : false);
	}
private:
	string name;
};

bool OutcomeFactory::instanceFlag = false;
OutcomeFactory* OutcomeFactory::outcomeFactoryP = NULL;

OutcomeFactory::OutcomeFactory()
{
	cleanOutcomes();
	genOutcomeOddsFromNameHash();
}
OutcomeFactory::~OutcomeFactory() 
{
	cleanOutcomes();
	_nameToOddHash.clear();
}
OutcomeFactory* OutcomeFactory::getOutcomeFactory()
{
	if (!instanceFlag) {
		outcomeFactoryP = new OutcomeFactory();
		instanceFlag = true;
	}
	return outcomeFactoryP;
}

string dupAndToUpper(char* str)
{
	string dup = string(str);
	for (int i = 0; i < dup.length(); i++)
	{
		dup[i] = toupper(dup[i]);
	}
	return dup;
}

Outcome* OutcomeFactory::findOutcomeInSet(char* outcomeName)
{
	string name = dupAndToUpper(outcomeName);
	
	OutcomeSI it = std::find_if(_outcomeSet.begin, _outcomeSet.end, findByName(name.c_str()));
	if (it != _outcomeSet.end()) {
		return *it;
	}
	else {
		return NULL;
	}
}
Outcome* OutcomeFactory::createOutcome(char* outcomeName)
{
	int odds = getOutcomeOddsFromName(outcomeName);
	return (new Outcome(outcomeName, odds));
}

Outcome* OutcomeFactory::getOrCreateOutcome(char* outcomeName)
{
	Outcome* out = findOutcomeInSet(outcomeName);
	if (out == NULL) {
		out = createOutcome(outcomeName);
	}
	return out;
}

int OutcomeFactory::getOutcomeOddsFromName(char* name) {
	StrToIntHash::iterator it = _nameToOddHash.find(name);
	if (it == _nameToOddHash.end()) {
		return 0;
	}
	else {
		return it->second;
	}
}

typedef std::pair<string, int> nameToOddP;

int OutcomeFactory::genOutcomeOddsFromNameHash()
{
	_nameToOddHash.emplace("ZERO",0);
	_nameToOddHash.emplace("DOUBLE_ZERO", 0);
	_nameToOddHash.emplace("ONE", 0);
	_nameToOddHash.emplace("TWO", 0);
	_nameToOddHash.emplace("THREE", 0);
	_nameToOddHash.emplace("FOUR", 0);
	_nameToOddHash.emplace("FIVE", 0);
	_nameToOddHash.emplace("SIX", 0);
	_nameToOddHash.emplace("SEVEN", 0);
	_nameToOddHash.emplace("EIGHT", 0);
	_nameToOddHash.emplace("NINE", 0);
	_nameToOddHash.emplace("TEN", 0);
}
