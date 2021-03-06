#include "AddBUFFERgate.h"
#include "..\ApplicationManager.h"
#include "..\Components\Buffer.h"

AddBUFFERgate::AddBUFFERgate(ApplicationManager *pApp):Action(pApp)
{
}

AddBUFFERgate::~AddBUFFERgate(void)
{
}

void AddBUFFERgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddBUFFERgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.Buffer2_Width;
	int Wdth = UI.Buffer2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	Buffer *pA=new Buffer(GInfo, AND2_FANOUT); 
	pManager->AddComponent(pA);
}

void AddBUFFERgate::Undo()
{}

void AddBUFFERgate::Redo()
{}

