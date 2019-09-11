#include "Event.h"

Event::Event(unsigned int inputPrizeMoney, bool inputIsFallback) : isFallback(inputIsFallback), prizeMoney(inputPrizeMoney)
{
	isEnd = false;
}

void Event::SetEnd()
{
	prizeMoney = 0;
	isFallback = false;
	isEnd = true;
}
