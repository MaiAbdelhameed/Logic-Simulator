#include "AddConnection.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"


AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{

}

AddConnection::~AddConnection(void)
{

}

//Reads parameters required for action to execute
void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	//pwind = pOut->CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Click on the source pin:");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	Sx = Cx;
	Sy = Cy;

	//Clear Status Bar
	pOut->ClearStatusBar();


	//Print Action Message
	pOut->PrintMsg("Click on the destination pin:");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Dx = Cx;
	Dy = Cy;

	//Clear Status Bar
	pOut->ClearStatusBar();

}

//Execute action (code depends on action type)
void AddConnection::Execute()
{
	GraphicsInfo Grfx;
	ReadActionParameters();
	SrcCmpnt = pManager->GetComp(Sx, Sy);
	Grfx.x1 = Sx;
	Grfx.y1 = Sy;
	DstCmpnt = pManager->GetComp(Dx, Dy);
	Grfx.x2 = Dx;
	Grfx.y2 = Dy;
	Connection* pA = new Connection(Grfx, pSrcPin, &pDstPin);
	pOut->DrawConnection(Grfx, false);
	pManager->AddComponent(pA);

}


void AddConnection::Undo()
{

}

void AddConnection::Redo()
{

}


