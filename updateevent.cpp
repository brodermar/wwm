#include "updateevent.h"

const QEvent::Type UpdateEvent::updateEventType = static_cast<QEvent::Type>(QEvent::registerEventType());

UpdateEvent::UpdateEvent() : QEvent(UpdateEvent::updateEventType)
{

}

UpdateEvent::~UpdateEvent()
{

}
