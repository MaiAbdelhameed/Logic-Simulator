#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int ID;
	string m_Label;
	bool selected;
public:
	static int count;
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	virtual void Load(ifstream& input) = 0;
	virtual void Move(int x,int y) = 0;
	virtual void Label( string label) = 0;
	bool IsSelected();
	void SetSelection(bool s);
	bool select(int x, int y);

	virtual ActionType SelectedComponentType() = 0; //to know type of component that was copied or cut to clipboard
	virtual void Save(ofstream& OutputFile, bool s) = 0; //to save every component
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
