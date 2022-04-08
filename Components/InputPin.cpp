#include "InputPin.h"

InputPin::InputPin()
{
	connected = false;
}

void InputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

bool InputPin::IsConnected(void)
{
	return connected;
}
void InputPin::SetConnected(void)
{
	connected = true;
}
