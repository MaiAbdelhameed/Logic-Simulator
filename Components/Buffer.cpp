#include "Buffer.h"
#include <fstream>

Buffer::Buffer(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	ID = count++;
	selected = false;
}


void Buffer::Operate()
{
	if (m_InputPins[0].getStatus() == LOW)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
}


// Function Draw

void Buffer::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuffer2(m_GfxInfo,selected);

	pOut->PrintLabel(m_Label, m_GfxInfo.x1, m_GfxInfo.y2);
}

//returns status of outputpin
int Buffer::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buffer::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
void Buffer::Load(ifstream& input)
{
	input >> ID;
	input >> m_Label;
	input >> m_GfxInfo.x1;
	input >> m_GfxInfo.y1;
	m_GfxInfo.x2 = UI.AND3_Width + m_GfxInfo.x1;
	m_GfxInfo.y2 = UI.AND3_Height + m_GfxInfo.y1;
}
void Buffer::Move(int x, int y) {
	m_GfxInfo.x1 = x - UI.AND2_Width / 2;
	m_GfxInfo.x2 = x + UI.AND2_Width / 2;
	m_GfxInfo.y1 = y - UI.AND2_Height / 2;
	m_GfxInfo.y2 = y + UI.AND2_Height / 2;

}

void Buffer::Label(string label) {
	m_Label = label;

}

ActionType Buffer::SelectedComponentType()
{
	return ADD_Buff;
}

void Buffer::Save(ofstream& OutputFile, bool s)
{
	if (s == 1)
	{
		OutputFile << "BUFFER\t";
		OutputFile << ID << "\t" << m_Label << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
	}
}
