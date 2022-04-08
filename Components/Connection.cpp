#include "Connection.h"
#include <fstream>

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin) :Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}

void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, selected);

	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
void Connection::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND2_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND2_Height + m_GfxInfo.y1;
}

void Connection::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;
}

void Connection::Label(string label) {
	m_Label = label;

}

ActionType Connection::SelectedComponentType()
{
	return ADD_CONNECTION;
}

void Connection::Save(ofstream& OutputFile, bool s)
{
	if (s == 0)
	{
	}
}
