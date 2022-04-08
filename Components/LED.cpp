#include "LED.h"
#include <fstream>

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(r_Inputs, 0)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}

void LED::Operate()//Calculates the output according to the inputs
{

}

void LED::Draw(Output* pOut)	//for each component to Draw itself
{
	pOut->DrawLED2(m_GfxInfo, selected);
	//pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}


int LED::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return -1;
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();
}


void LED::setInputPinStatus(int n, STATUS s)	//set status of Inputpin # n, to be used by connection class.
{
	return;
}


LED::~LED()
{

}
void LED::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND2_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND2_Height + m_GfxInfo.y1;
}

void LED::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;
}

void LED::Label(string label) {
	m_Label = label;

}

ActionType LED::SelectedComponentType()
{
	return ADD_LED;
}

void LED::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "LED\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}


