#ifndef _ADD_LED_H
#define _ADD_LED_H
#include "Action.h"
#include "..\Components\LED.h"

class AddLED :public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	OutputPin* Outpin;
	GraphicsInfo GInfo;
	int r_FanOut;

public:

	AddLED(ApplicationManager* pApp);
	~AddLED(void);
	void ReadActionParameters();
	void Execute();

	void Undo();
	void Redo();

};

#endif
