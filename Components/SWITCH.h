#ifndef _SWITCH_
#define _SWITCH_

#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "Gate.h"

class SWITCH :public Gate
{
private:
	//OutputPin m_OutputPin;	//The Gate output pin
	int r_FanOut;
public:

	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	void Operate();	//Calculates the output according to the inputs
	void Draw(Output* pOut);	//for each component to Draw itself


	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void Load(ifstream& input);
	void Label(string label);
	ActionType SelectedComponentType();
	void Save(ofstream& OutputFile, bool s);
	void Move(int x, int y);
	~SWITCH();
};

#endif