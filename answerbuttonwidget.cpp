#include "AnswerButtonWidget.h"

AnswerButtonWidget::AnswerButtonWidget(QWidget *parent) : QPushButton(parent)
{
    ButtonLeftDefault = QPixmap(":resources/DialogDefaultLeft.png");
    ButtonRightDefault = QPixmap(":resources/DialogDefaultRight.png");
    ButtonCenterDefault = QPixmap(":resources/DialogDefaultCenter.png");

    ButtonLeftSelceted = QPixmap(":resources/DialogLeftPush.png");
    ButtonRightSelceted = QPixmap(":resources/DialogRightPush.png");
    ButtonCenterSelceted = QPixmap(":resources/DialogCenterPush.png");

    ButtonLeftTrue = QPixmap(":resources/DialogTrueLeft.png");
    ButtonRightTrue = QPixmap(":resources/DialogTrueRight.png");
    ButtonCenterTrue = QPixmap(":resources/DialogCenterTrue.png");

    ButtonLeftGold = QPixmap(":resources/DialogLeftWin.png");
    ButtonRightGold = QPixmap(":resources/DialogRightWin.png");
    ButtonCenterGold = QPixmap(":resources/DialogCenterWin.png");

    ButtonHidden = QPixmap(":resources/HiddenButton.png");

    MainRectangel = new QRectF(0.0, 0.0, 0.0, 0.0);

    ButtonLeftPrint = ButtonLeftDefault;
    ButtonRightPrint = ButtonRightDefault;
    ButtonCenterPrint = ButtonCenterDefault;
    visible = true;

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

 void AnswerButtonWidget::ButtonGold(bool setter)
 {
     if(setter)
     {
        green = false;
        gold = true;
        orange = false;
        blue = false;
        interactive = true;
     }
     else
     {
        this->ButtonDefault(true);
     }
 }

 void AnswerButtonWidget::ButtonStatic(bool setter)
 {
     if(setter)
     {
         green = false;
         gold = false;
         orange = false;
         blue = true;
         interactive = false;
     }
     else
     {
         this->ButtonDefault(true);
     }
 }

 void AnswerButtonWidget::ButtonDefault(bool setter)
 {
     if(setter)
     {
         green = false;
         gold = false;
         orange = false;
         blue = true;
         interactive = true;
     }
 }
void AnswerButtonWidget::setTrigger()
{
    green = false;
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

void AnswerButtonWidget::ResourceSelector()
{
    if(visible)
        {
            if(orange)
            {
                ButtonLeftPrint = ButtonLeftSelceted;
                ButtonRightPrint = ButtonRightSelceted;
                ButtonCenterPrint = ButtonCenterSelceted;
            }

            else if(green)
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
            else if(orange)
            {
                ButtonLeftPrint = ButtonLeftSelceted;
                ButtonRightPrint = ButtonRightSelceted;
                ButtonCenterPrint = ButtonCenterSelceted;
            }
            else if(blue && !gold && visible)
            {
                 ButtonLeftPrint = ButtonLeftDefault;
                 ButtonRightPrint = ButtonRightDefault;
                 ButtonCenterPrint = ButtonCenterDefault;
            }
        }
        else
        {
            ButtonLeftPrint = ButtonHidden;
            ButtonRightPrint = ButtonHidden;
            ButtonCenterPrint = ButtonHidden;
        }
}


void AnswerButtonWidget::paintEvent(QPaintEvent *)
{
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

void AnswerButtonWidget::setVisible2(bool setter)
{
    visible = setter;
    if(!setter)
    {
        interactive = false;
        Text = "";
    }
    TriggerPaintEvent();
}

void AnswerButtonWidget::mousePressEvent(QMouseEvent *)
{
    if(interactive)
    {
        blue = false;
        orange = true;
        green = false;
        gold = false;
        emit click();
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
    ResourceSelector();
    this->repaint();
}
