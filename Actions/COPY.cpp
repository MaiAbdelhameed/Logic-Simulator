#include "COPY.h"
#include "..\ApplicationManager.h"

COPY::COPY(ApplicationManager* pApp) :Action(pApp)
{
}

COPY::~COPY(void)
{
}

void COPY::ReadActionParameters()
{
}


void COPY::Execute()
{
	pManager->SetClipboard(pManager->selectedcomponent());
	pManager->SetCompClipboard(pManager->GetClipboard()->SelectedComponentType());
}


void COPY::Undo()
{}

void COPY::Redo()
{}