#include "EventCatalog.h"

EventCatalog::EventCatalog()
{
	events.push_back(Event(50,false));
	events.push_back(Event(100, false));

	Event EndEventObj(0, false);
	EndEventObj.SetEnd();

	events.push_back(EndEventObj);
}

Event EventCatalog::GetNextEvent()
{
	eventCounter++;
	return events[eventCounter - 1];
}
