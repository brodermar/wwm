#include <vector>
#include "Event.h"
#pragma once

using namespace std;

class EventCatalog
{
public:
	EventCatalog();
	Event GetNextEvent();
private:
	unsigned int eventCounter = 0;
	vector<Event> events;

};