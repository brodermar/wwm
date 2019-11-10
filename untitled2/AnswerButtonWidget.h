#ifndef ANSWERBUTTONWIDGET_H
#define ANSWERBUTTONWIDGET_H

#include <string>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QString>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#pragma once

class AnswerButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit AnswerButtonWidget(QWidget *parent = nullptr);
    void setLetter(std::string Letter);
    void setText(std::string Answer);
    void setInteractiv(bool setter);
    void setTrigger();
    void goGreen();
    void setGold();
    void TriggerPaintEvent();
    std::string IsSelected();
protected:
    void paintEvent(QPaintEvent *event);

private:
    void mousePressEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    std::string Letter;
    QString Text;

    QPixmap ButtonLeftDefault;
    QPixmap ButtonRightDefault;
    QPixmap ButtonCenterDefault;

    QPixmap ButtonLeftSelceted;
    QPixmap ButtonRightSelceted;
    QPixmap ButtonCenterSelceted;

    QPixmap ButtonLeftTrue;
    QPixmap ButtonRightTrue;
    QPixmap ButtonCenterTrue;

    QPixmap ButtonLeftGold;
    QPixmap ButtonRightGold;
    QPixmap ButtonCenterGold;

    QPixmap ButtonLeftPrint;
    QPixmap ButtonRightPrint;
    QPixmap ButtonCenterPrint;

    QRectF * MainRectangel;
    QRectF * TargetCenter;
    QRectF * TargetLeft;
    QRectF * TargetRight;

    bool interactive;
    bool blue;
    bool orange;
    bool green;
    bool gold;

    bool pressed;

signals:

public slots:
};

#endif // ANSWERBUTTONWIDGET_H