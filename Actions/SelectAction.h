#ifndef _SELECT_H
#define _SELECT_H

#include "Action.h"
#include "..\Components/Component.h"

class SelectAction :public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	ApplicationManager* pApp;
	Component* pComp;
	window* pwind;
	Output* pOut;
public:

	SelectAction(ApplicationManager* pApp1);
	virtual ~SelectAction();
	//Component* Selected_Comp();
	void ReadActionParameters();
	void Execute();

	void Undo();
	void Redo();

};

#endif

