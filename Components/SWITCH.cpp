#include "SWITCH.h"
#include <fstream>

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}

void SWITCH::Operate()//Calculates the output according to the inputs
{

}

void SWITCH::Draw(Output* pOut)	//for each component to Draw itself
{
	pOut->DrawSwitch2(m_GfxInfo, selected);
	//pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}


int SWITCH::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return m_OutputPin.getStatus();
}

int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}


void SWITCH::setInputPinStatus(int n, STATUS s)	//set status of Inputpin # n, to be used by connection class.
{
	return;
}


SWITCH::~SWITCH()
{

}
void SWITCH::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND2_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND2_Height + m_GfxInfo.y1;
}

void SWITCH::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;
}

void SWITCH::Label(string label) {
	m_Label = label;

}

ActionType SWITCH::SelectedComponentType()
{
	return ADD_Switch;
}

void SWITCH::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "SWITCH\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}


