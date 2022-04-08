#include "MoveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on a point to move the selected component");
	pIn->GetPointClicked(Cx,Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void MoveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	pManager->Move(Cx,Cy);

	pOut->ClearDrawingArea();
	pManager->UpdateInterface();
	
}


void MoveAction::Undo()
{}

void MoveAction::Redo()
{}
