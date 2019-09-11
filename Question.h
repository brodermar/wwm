#include <string>
#pragma once

using namespace std;

class Question
{
public:
	Question(string inputQuestion, string inputAnswerA, string inputAnswerB, string inputAnswerC, string inputAnswerD, char inputRightAnswer);
	
	bool GetIsUsed();
	void SetIsUsed();

	string question;
	string answerA;
	string answerB;
	string answerC;
	string answerD;
	char rightAnswer;
private:
	bool isUsed;
};