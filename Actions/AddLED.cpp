#include "AddLED.h"
#include "../ApplicationManager.h"
#include "..\Components\LED.h"


AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{

}

AddLED::~AddLED(void)
{

}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	//pwind = pOut->CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Click to add LED:");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
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
	LED* pA = new LED(GInfo, r_FanOut);
	pManager->AddComponent(pA);

}

void AddLED::Undo()
{

}

void AddLED::Redo()
{

}