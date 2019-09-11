#include "QuestionCatalog.h"

QuestionCatalog::QuestionCatalog()
{
	questions.push_back(Question("Was kann man essen?", "Aktenkoffer", "Schulranzen", "Rucksack", "Apfeltasche", 'D'));
}

Question QuestionCatalog::GetQuestion()
{
	questions[0].SetIsUsed();
	return questions[0];
}
