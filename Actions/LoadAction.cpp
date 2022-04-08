#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Loading a file");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearDrawingArea();
	pOut->ClearStatusBar();
	ifstream input;
	pOut->PrintMsg("Enter the name of the file you want to load:");
	string fileName;
	fileName = pIn->GetSrting(pOut);
	input.open(fileName);
	if (!input.is_open())
	{
		pOut->PrintMsg("This file doesn't exist");
		return;
	}
	pManager->Load(input);
	input.close();
	pOut->PrintMsg("File is loaded");
}


void LoadAction::Undo()
{}

void LoadAction::Redo()
{}
