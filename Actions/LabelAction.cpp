#include "LabelAction.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

LabelAction::LabelAction(ApplicationManager* pApp) :Action(pApp)
{}

void LabelAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Enter the component label:");
	Label = pIn->GetSrting(pOut);
	//Clear Status Bar
	pOut->ClearStatusBar();
}

void LabelAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->Label(Label);
	pOut->ClearDrawingArea();
	pManager->UpdateInterface();
}


void LabelAction::Undo()
{}

void LabelAction::Redo()
{}
