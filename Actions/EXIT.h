#ifndef _EXIT_H
#define _EXIT_H

#include "Action.h"
#include "..\Components\Component.h"

class EXIT :public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	ApplicationManager* pApp;
	Component* pComp;
	window* pwind;
	Output* pOut;
	Input* pIn;

public:
	EXIT(ApplicationManager* pApp1);
	virtual ~EXIT();
	void ReadActionParameters();
	void Execute();

	void Undo();
	void Redo();

};

#endif

