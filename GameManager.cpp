#include "GameManager.h"

GameManger::GameManger()
{
}

void GameManger::SetUserInteraction(InteractionFrame interaction)
{
}

OutputFrame GameManger::GetGameFrame()
{
	OutputFrame Frame;
	Frame.SetEvent(currentEvent);
	Frame.SetQuestion(currentQuestion);
	return Frame;
}
