#include "PASTE.h"
#include "..\ApplicationManager.h"

PASTE::PASTE(ApplicationManager* pApp) :Action(pApp)
{
}

PASTE::~PASTE(void)
{
}

void PASTE::ReadActionParameters()
{
}


void PASTE::Execute()
{
	pManager->PasteSelectedComponent(pManager->GetCompClipboard());
}

void PASTE::Undo()
{}

void PASTE::Redo()
{}