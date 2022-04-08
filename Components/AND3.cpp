#include "AND3.h"
#include <fstream>

AND3::AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}


void AND3::Operate()
{
	for (int i = 0; i < m_Inputs - 1; i++)
	{
		if (m_InputPins[i].getStatus() == LOW)
		{
			m_OutputPin.setStatus(LOW);
			return;
		}
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo,selected);

	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

//returns status of outputpin
int AND3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void AND3::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND3_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND3_Height + m_GfxInfo.y1;
}
void AND3::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND3_Width / 2;
	m_GfxInfo.x2 = x + UI.AND3_Width / 2;
	m_GfxInfo.y1 = y - UI.AND3_Height / 2;
	m_GfxInfo.y2 = y + UI.AND3_Height / 2;

}

void AND3::Label(string label) {
	m_Label = label;

}

ActionType AND3::SelectedComponentType()
{
	return ADD_AND_GATE_3;
}

void AND3::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "AND3\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}
