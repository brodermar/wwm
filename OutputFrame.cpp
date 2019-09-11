#include "OutputFrame.h"

void OutputFrame::SetQuestion(Question inputQuestion)
{
	currentQuestion = inputQuestion;
}

void OutputFrame::SetEvent(Event inputEvent)
{
	currentEvent = inputEvent;
}

Question OutputFrame::GetQuestion()
{
	return currentQuestion;
}

Event OutputFrame::GetEvent()
{
	return currentEvent;
}
