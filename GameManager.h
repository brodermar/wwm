#include "Event.h"
#include "QuestionCatalog.h"
#include "EventCatalog.h"
#include "OutputFrame.h"
#include "InteractionFrame.h"
#pragma once


using namespace std;


class GameManger
{
public:
	GameManger();
	void SetUserInteraction(InteractionFrame);
	OutputFrame GetGameFrame();
private:
	
	Question currentQuestion = Question("Dummy","a","b","c","d",'a');
	Event currentEvent = Event(0,false);

	EventCatalog eventCatalog = EventCatalog();
	QuestionCatalog questionCatalog = QuestionCatalog();
};