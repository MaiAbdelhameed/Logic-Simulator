#include "NOR2.h"
#include <fstream>

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}

void NOR2::Operate()
{
	for (int i = 0; i < m_Inputs - 1; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			m_OutputPin.setStatus(LOW);
			return;
		}
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(Output* pOut)
{

	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, selected);
	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR2::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND2_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND2_Height + m_GfxInfo.y1;
}

void NOR2::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;
}

void NOR2::Label(string label) {
	m_Label = label;

}

ActionType NOR2::SelectedComponentType()
{
	return ADD_NOR_GATE_2;
}

void NOR2::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "NOR2\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}
