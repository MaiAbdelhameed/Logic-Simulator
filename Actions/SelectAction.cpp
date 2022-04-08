#include "SelectAction.h"
#include "..\ApplicationManager.h"


SelectAction::SelectAction(ApplicationManager* pApp1) : Action(pApp1)
{
	//Initilaize interface colors
	/*UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pwind. = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	*/
	//Output();
	pwind = NULL;
}

SelectAction::~SelectAction()
{
	//	delete pOut;
}

/*Component* SELECT:: Selected_Comp()
{
	clicktype click_type;
	int x, y;
	click_type = pwind->GetMouseClick(&x, &y);
	pManager->
}*/

void SelectAction::ReadActionParameters()
{

	/*UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	*/

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	//pwind = pOut->CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on a component to be selected:");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//Clear Status Bar
	pOut->ClearStatusBar();

}


void SelectAction::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();

	pComp = pManager->GetComp(Cx, Cy);

	if (pComp != NULL)
	{
		if (pComp->IsSelected())
		{
			pComp->SetSelection(false);
			//pComp->Draw(pOut, pComp->IsSelected());
		}

		else
		{
			pComp->SetSelection(true);
		}
		pManager->UpdateInterface();
	}
}

void SelectAction::Undo()
{

}

void SelectAction::Redo()
{

}
