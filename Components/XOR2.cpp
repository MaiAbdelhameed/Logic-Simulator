#include "XOR2.h"
#include <fstream>
XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}


void XOR2::Operate()
{
	int c1 = 0;
	for (int i = 0; i < m_Inputs - 1; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
			c1 = c1 + 1;
	}
	if (c1 % 2 == 0)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);

}


// Function Draw
// Draws 2-input XOR gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, selected);
	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void XOR2::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND2_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND2_Height + m_GfxInfo.y1;
}

void XOR2::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;
}

void XOR2::Label(string label) {
	m_Label = label;

}

ActionType XOR2::SelectedComponentType()
{
	return ADD_XOR_GATE_2;
}

void XOR2::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "XOR2\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}
