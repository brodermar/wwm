#pragma once

using namespace std;

class Event
{
public:
	Event(unsigned int inputPrizeMoney, bool inputIsFallback);
	void SetEnd();
private:
	unsigned int prizeMoney;
	bool isFallback;
	bool isEnd;
};