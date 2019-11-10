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
#include <iostream>
#pragma once

class AnswerButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit AnswerButtonWidget(QWidget *parent = nullptr);
    void ButtonGold(bool setter);
    void ButtonStatic(bool setter);
    void ButtonDefault(bool setter);
    void setVisible2(bool setter);
    void setLetter(std::string Letter);
    void setText(std::string Answer);
    void ResourceSelector();
    void setInteractiv(bool setter);
    void setTrigger();
    void goGreen();
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

    QPixmap ButtonHidden;

    QRectF * MainRectangel;
    QRectF * TargetCenter;
    QRectF * TargetLeft;
    QRectF * TargetRight;

    bool interactive;
    bool blue;
    bool orange;
    bool green;
    bool gold;

    bool visible;

signals:

public slots:
};

#endif // ANSWERBUTTONWIDGET_H
