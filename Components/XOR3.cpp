#include "XOR3.h"
#include <fstream>

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}


void XOR3::Operate()
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
void XOR3::Draw(Output* pOut)
{
	//Call output class  pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo,selected);

	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void XOR3::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND3_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND3_Height + m_GfxInfo.y1;
}
void XOR3::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;

}

void XOR3::Label(string label) {
	m_Label = label;

}

ActionType XOR3::SelectedComponentType()
{
	return ADD_XOR_GATE_3;
}

void XOR3::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "XOR3\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}
