#include "inputconvertbase.h"
#include "controller.h"

InputConvertBase::InputConvertBase(Controller *controller) : QObject(controller), m_controller(controller)
{
    Q_ASSERT(controller);
}

InputConvertBase::~InputConvertBase() {}

void InputConvertBase::sendControlMsg(ControlMsg *msg)
{
    if (msg && m_controller) {
        m_controller->postControlMsg(msg);
    }
}

void InputConvertBase::sendVMouseCtrMsg(VMouseControl::VMouseState state,int xLocal = 0,int yLocal = 0,int xSize = 0,int ySize = 0)
{
    if (m_controller) {
        m_controller->getVmouseCtr()->sendMsg(state,xLocal,yLocal,xSize,ySize);
    }
}
