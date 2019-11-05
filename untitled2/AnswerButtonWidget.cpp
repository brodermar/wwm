#include "AnswerButtonWidget.h"

AnswerButtonWidget::AnswerButtonWidget(QWidget *parent) : QWidget(parent)
{
    ButtonLeftDefault = QPixmap("Resouces/DialogDefaultLeft.png");
    ButtonRightDefault = QPixmap("Resouces/DialogDefaultRight.png");
    ButtonCenterDefault = QPixmap("Resouces/DialogDefaultCenter.png");

    ButtonLeftSelceted = QPixmap("Resouces/DialogLeftPush.png");
    ButtonRightSelceted = QPixmap("Resouces/DialogRightPush.png");
    ButtonCenterSelceted = QPixmap("Resouces/DialogCenterPush.png");

    ButtonLeftTrue = QPixmap("Resouces/DialogTrueLeft.png");
    ButtonRightTrue = QPixmap("Resouces/DialogTrueRight.png");
    ButtonCenterTrue = QPixmap("Resouces/DialogCenterTrue.png");

    ButtonLeftGold = QPixmap("Resouces/DialogLeftWin.png");
    ButtonRightGold = QPixmap("Resouces/DialogRightWin.png");
    ButtonCenterGold = QPixmap("Resouces/DialogCenterWin.png");

    MainRectangel = new QRectF(0.0, 0.0, 0.0, 0.0);

    ButtonLeftPrint = ButtonLeftDefault;
    ButtonRightPrint = ButtonRightDefault;
    ButtonCenterPrint = ButtonCenterDefault;

    interactive = true;

    orange = false;
    blue = true;
    green = false;
    gold = false;
}

void AnswerButtonWidget::setInteractiv(bool setter)
{
    interactive = setter;
}

 void AnswerButtonWidget::setGold()
 {
     green = false;
     pressed = false;
     gold = true;
     orange = false;
     blue = false;
     interactive = true;
 }

void AnswerButtonWidget::setTrigger()
{
    green = false;
    pressed = false;
    gold = false;
    orange = false;
    blue = true;
    interactive = true;
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
    else if(gold)
    {
        ButtonLeftPrint = ButtonLeftGold;
        ButtonRightPrint = ButtonRightGold;
        ButtonCenterPrint = ButtonCenterGold;
    }
    if(interactive)
    {
        if(orange)
        {
            ButtonLeftPrint = ButtonLeftSelceted;
            ButtonRightPrint = ButtonRightSelceted;
            ButtonCenterPrint = ButtonCenterSelceted;
        }
        else if(blue && !gold)
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
    orange = false;
    blue = false;
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

void AnswerButtonWidget::mousePressEvent(QMouseEvent *)
{
    if(interactive)
    {
        blue = false;
        orange = true;
        green = false;
        gold = false;
        TriggerPaintEvent();
        interactive = false;
    }
}

void AnswerButtonWidget::enterEvent(QEvent *)
{
    if(interactive)
    {
        blue = false;
        orange = true;
        TriggerPaintEvent();
    }
}

void AnswerButtonWidget::leaveEvent(QEvent *)
{
    if(interactive)
    {
        blue = true;
        orange = false;
        TriggerPaintEvent();
    }
}


void AnswerButtonWidget::TriggerPaintEvent()
{
    this->repaint();
}
