#include "DEL.h"
#include "..\ApplicationManager.h"

DEL::DEL(ApplicationManager* pApp) :Action(pApp)
{
}

DEL::~DEL(void)
{
}

void DEL::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Deleting a selected component");
}

void DEL::Execute()
{
	ReadActionParameters();
	pManager->RemoveComponent();
}

void DEL::Undo()
{}

void DEL::Redo()
{}