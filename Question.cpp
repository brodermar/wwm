#include "Question.h"

Question::Question(string inputQuestion, string inputAnswerA, string inputAnswerB, string inputAnswerC, string inputAnswerD, char inputRightAnswer) :
	rightAnswer(inputRightAnswer), question(inputQuestion), answerA(inputAnswerA), answerB(inputAnswerB), answerC(inputAnswerC), answerD(inputAnswerD)
{
	isUsed = false;
}

bool Question::GetIsUsed()
{
	return isUsed;
}

void Question::SetIsUsed()
{
	isUsed = true;
}
