#include "CUT.h"
#include "..\ApplicationManager.h"

CUT::CUT(ApplicationManager* pApp) :Action(pApp)
{
}

CUT::~CUT(void)
{
}

void CUT::ReadActionParameters()
{
}

void CUT::Execute()
{
	pManager->SetClipboard(pManager->selectedcomponent());
	pManager->SetCompClipboard(pManager->GetClipboard()->SelectedComponentType());
	pManager->RemoveComponent();

}

void CUT::Undo()
{}

void CUT::Redo()
{}