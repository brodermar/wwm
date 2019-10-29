#include "AnswerButtonWidget.h"

AnswerButtonWidget::AnswerButtonWidget(QWidget *parent) : QWidget(parent)
{
    ButtonLeftDefault = QPixmap("C:/Qt/Resouces/DialogDefaultLeft.png");
    ButtonRightDefault = QPixmap("C:/Qt/Resouces/DialogDefaultRight.png");
    ButtonCenterDefault = QPixmap("C:/Qt/Resouces/DialogDefaultCenter.png");

    ButtonLeftSelceted = QPixmap("C:/Qt/Resouces/DialogLeftPush.png");
    ButtonRightSelceted = QPixmap("C:/Qt/Resouces/DialogRightPush.png");
    ButtonCenterSelceted = QPixmap("C:/Qt/Resouces/DialogCenterPush.png");

    ButtonLeftTrue = QPixmap("C:/Qt/Resouces/DialogTrueLeft.png");
    ButtonRightTrue = QPixmap("C:/Qt/Resouces/DialogTrueRight.png");
    ButtonCenterTrue = QPixmap("C:/Qt/Resouces/DialogCenterTrue.png");

    MainRectangel = new QRectF(0.0, 0.0, 0.0, 0.0);

    ButtonLeftPrint = ButtonLeftDefault;
    ButtonRightPrint = ButtonRightDefault;
    ButtonCenterPrint = ButtonCenterDefault;

    pressed = false;
    hover = false;
    interactiv = true;

    green = false;
    gold = false;
}

void AnswerButtonWidget::setInteractiv(bool setter)
{
    interactiv = setter;
}

void AnswerButtonWidget::setTrigger()
{
    green = false;
    pressed = false;
    interactiv = true;
}

void AnswerButtonWidget::setLetter(std::string Letter)
{
    this->Letter = Letter;
}
void AnswerButtonWidget::setText(std::string Answer)
{
    if(Letter.length() == 0)
    {
        Text = QString::fromStdString(Answer);
    }
    else
    {
        Text = QString::fromStdString(Letter + ": " + Answer);
    }
    TriggerPaintEvent();
}

void AnswerButtonWidget::paintEvent(QPaintEvent *)
{
    if(green)
    {
        ButtonLeftPrint = ButtonLeftTrue;
        ButtonRightPrint = ButtonRightTrue;
        ButtonCenterPrint = ButtonCenterTrue;
    }
    if(interactiv)
    {
        if(pressed || hover)
        {
            ButtonLeftPrint = ButtonLeftSelceted;
            ButtonRightPrint = ButtonRightSelceted;
            ButtonCenterPrint = ButtonCenterSelceted;
        }
        else
        {
            ButtonLeftPrint = ButtonLeftDefault;
            ButtonRightPrint = ButtonRightDefault;
            ButtonCenterPrint = ButtonCenterDefault;
        }
    }
    //the painter wich paints all graphic element of AnswerButtonWidget
    QPainter * Painter = new QPainter(this);

    //paints the center bar of AnswerButtonWidge
    TargetCenter = new QRectF(this->height() * (ButtonLeftPrint.height()/ButtonLeftPrint.width()), 0.0, this->width() - ((this->height() * (ButtonLeftPrint.height()/ButtonLeftPrint.width()) + (this->height() * (ButtonRightPrint.height()/ButtonRightPrint.width())))), this->height());
    Painter->drawPixmap(*TargetCenter, ButtonCenterPrint, *MainRectangel);

    //paints the left side element of AnswerButtonWidget
    TargetLeft = new QRectF(0.0, 0.0, this->height() * (ButtonLeftPrint.height()/ButtonLeftPrint.width()) + 2, this->height());
    Painter->drawPixmap(*TargetLeft, ButtonLeftPrint, *MainRectangel);

    //paints the right side element of AnswerButtonWidget
    TargetRight = new QRectF(-(this->height() * (ButtonRightPrint.height()/ButtonRightPrint.width())) + this->width(), 0.0, (this->height() * (ButtonRightPrint.height()/ButtonRightPrint.width())), this->height());
    Painter->drawPixmap(*TargetRight, ButtonRightPrint, *MainRectangel);

    //paints the text of AnswerButtonWidget
    Painter->drawText(QPoint(this->height() * (ButtonLeftPrint.height()/ButtonLeftPrint.width()),(this->height()/2) + 8), Text);

    delete TargetCenter;
    delete TargetRight;
    delete TargetLeft;
    delete Painter;
}

void AnswerButtonWidget::goGreen()
{
    green = true;
    TriggerPaintEvent();
}

std::string AnswerButtonWidget::IsSelected()
{
    if(pressed)
    {
        return Letter;
    }
    else
    {
        return "n";
    }

}

void AnswerButtonWidget::mousePressEvent(QMouseEvent *event)
{
    pressed = true;
    TriggerPaintEvent();
}

void AnswerButtonWidget::enterEvent(QEvent * event)
{
    //if statement to prevent crash
    if(hover)
    {}
    else
    {
    hover = true;
    TriggerPaintEvent();
    }
}

void AnswerButtonWidget::leaveEvent(QEvent *event)
{
    hover = false;
    TriggerPaintEvent();
}


void AnswerButtonWidget::TriggerPaintEvent()
{
    this->setHidden(true);
    this->setHidden(false);
}
