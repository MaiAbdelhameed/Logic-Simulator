#include "SwitchToSimulationAction.h"
#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"


SwitchToSimulationAction::SwitchToSimulationAction(ApplicationManager* pApp) :Action(pApp)
{}

void SwitchToSimulationAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void SwitchToSimulationAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->CreateSimulationToolBar();
}


void SwitchToSimulationAction::Undo()
{}

void SwitchToSimulationAction::Redo()
{}
