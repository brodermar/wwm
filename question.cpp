#include "question.h"

Question::Question(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, char rightAnswer)
{
    this->question = question;

    this->answerA = new Answer(answerA);
    this->answerB = new Answer(answerB);
    this->answerC = new Answer(answerC);
    this->answerD = new Answer(answerD);

    if(rightAnswer == 'a' || rightAnswer == 'A')
    {
        this->rightAnswer = this->answerA;
    }
    else if(rightAnswer == 'b' || rightAnswer == 'B')
    {
        this->rightAnswer = this->answerB;
    }
    else if(rightAnswer == 'c' || rightAnswer == 'C')
    {
        this->rightAnswer = this->answerC;
    }
    else if(rightAnswer == 'd' || rightAnswer == 'D')
    {
        this->rightAnswer = this->answerD;
    }
    else {
        throw std::invalid_argument("the value \"rightAnswer\" hasn't a correct value");
    }
    qDebug() << "initialized new Question" << endl;
}

Question::~Question()
{
    delete answerA;
    delete answerB;
    delete answerC;
    delete answerD;
    qDebug() << "~Question() called" << endl;
}

Question* Question::pullNewQuestion()
{  
    srand (time(NULL));
    std::ifstream csvread;
    csvread.open(":/resources/Fragenkatalog.csv", std::ios::in);
    if(csvread){
        std::string s="";
        int id_numb = 12;
        //length = 7*id_numb +1
        const int length = 85;
        std::string question[length];
        int i=0;
        while(getline(csvread, s, ';'))
        {
            question[i]=s;
            i++;
        }
        csvread.close();
        int a=0;
        int tempx = 0;
        int rand_question = rand() % id_numb+1;
        for (;a<length;a++) {
            std::string s = question[a];
            std::stringstream geek(s);
            int temp = 0;
            geek >> temp;
            if(temp == rand_question) {
                tempx = a;
                break;
            }
        }
        std::string x = question[tempx+6];
        char check[2];
        strcpy(check, x.c_str());

        std::string newQuestion = question[tempx+1];
        std::string answerA = question[tempx+2];
        std::string answerB = question[tempx+3];
        std::string answerC = question[tempx+4];
        std::string answerD = question[tempx+5];
        return new Question(newQuestion, answerA, answerB, answerC, answerD, check[0]);
    }
    else{
        qDebug() << "Fehler beim lesen" << endl;
    }
}

bool Question::evaluateAnswer(std::string answer)
{
    qDebug() << "evaluateAnswer() called" << endl;
    return(answer == rightAnswer->getAnswer());
}

std::string Question::getQuestion()
{
    return question;
}

Answer* Question::getAnswerA()
{
    return answerA;
}

Answer* Question::getAnswerB()
{
    return answerB;
}

Answer* Question::getAnswerC()
{
    return answerC;
}

Answer* Question::getAnswerD()
{
    return answerD;
}

Answer* Question::getRightAnswer()
{
    return rightAnswer;
}


