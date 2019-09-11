#include "Question.h"
#include "Event.h"
#pragma once

using namespace std;

// Diese Klasse erzeugt ein Objekt welches alle nötigen Komponenten für die Darstellung (CLI/GUI) enthält.
// Die Klasse enthält Getter und Setter, wobei die Setter nur der GameManager und Getter nur der "Darstller(CLI/GUI)" nutzen soll.
class OutputFrame
{
public:
	
	void SetQuestion(Question inputQuestion);
	void SetEvent(Event inputEvent);

	Question GetQuestion();
	Event GetEvent();
private:
	Question currentQuestion = Question("Dummy", "a", "b", "c", "d", 'a');
	Event currentEvent = Event(0, false);
};