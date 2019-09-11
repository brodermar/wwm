#include <vector>
#include "Question.h"
#pragma once

using namespace std;

class QuestionCatalog
{
public:
	QuestionCatalog();
	Question GetQuestion();
private:
	vector<Question> questions;
};
