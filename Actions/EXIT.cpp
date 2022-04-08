#include "EXIT.h"
#include "..\ApplicationManager.h"
#include "SAVE.h"

EXIT::EXIT(ApplicationManager* pApp1):Action(pApp1)
{
	pwind = NULL;
}

EXIT::~EXIT()
{

}

void EXIT::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	//pwind = pOut->CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	pIn = pManager->GetInput();

	//Clear Status Bar
	pOut->PrintMsg("Click anywhere to exit..");

}

void EXIT::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	pOut->PrintMsg("Do you want to save the file before exit? (yes/no)");
	string s;
	s = pIn->GetSrting(pOut);
	if (s == "yes")
	{
		Action* pAct = new SAVE(pManager);
		pAct->Execute();
	}
	    ReadActionParameters();
		pIn->GetPointClicked(Cx, Cy);
		pOut->ClearStatusBar();

}

void EXIT::Undo()
{

}

void EXIT::Redo()
{

}
