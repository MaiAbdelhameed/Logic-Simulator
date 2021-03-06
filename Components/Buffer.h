#ifndef _Buffer_H
#define _Buffer_H


#include "Gate.h"

class Buffer:public Gate
{
public:
	Buffer(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	
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