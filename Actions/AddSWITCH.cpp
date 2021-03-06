#include "AddSWITCH.h"
#include "../ApplicationManager.h"
#include "../Components/SWITCH.h"


AddSWITCH::AddSWITCH(ApplicationManager* pApp) :Action(pApp)
{

}

AddSWITCH::~AddSWITCH(void)
{

}

void AddSWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	//pwind = pOut->CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Click to add switch:");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddSWITCH::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.Switch2_Width;
	int Wdth = UI.Switch2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the switch

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	SWITCH* pA = new SWITCH(GInfo, r_FanOut);
	pManager->AddComponent(pA);

}

void AddSWITCH::Undo()
{

}

void AddSWITCH::Redo()
{

}

