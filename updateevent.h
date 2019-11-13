#ifndef UPDATEEVENT_H
#define UPDATEEVENT_H

#include <QEvent>

class UpdateEvent : public QEvent
{

public:
    static const QEvent::Type updateEventType;

    UpdateEvent();
    ~UpdateEvent();

};

#endif // UPDATEEVENT_H
