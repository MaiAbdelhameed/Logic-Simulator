#ifndef _AND3_H
#define _AND3_H

#include "Gate.h"

class AND3:public Gate
{
public:
	AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 3-input gate
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void Load(ifstream& input);
	void Label(string label);
	ActionType SelectedComponentType();
	void Save(ofstream& OutputFile, bool s);
	void Move(int x, int y);


};

#endif