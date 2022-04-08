#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H
#include "Action.h"
#include "../Components\Connection.h"
class AddConnection :public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	int Sx, Sy, Dx, Dy; // Coordinates of source pin and destination pin
	ApplicationManager* pApp;
	Component* SrcCmpnt;
	Component* DstCmpnt;
	Output* pOut;
	GraphicsInfo r_GfxInfo;
	OutputPin* pSrcPin;
	InputPin pDstPin;


public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	void ReadActionParameters();
	//Execute action (code depends on action type)
	void Execute();

	void Undo();
	void Redo();

};


#endif