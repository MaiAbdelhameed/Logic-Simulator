#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Components\Component.h"

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{
}

SaveAction::~SaveAction(void)
{
}

void SaveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Enter file name, for ex: filename.txt");

	//pOut->ClearStatusBar();

}

void SaveAction::Execute()
{
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Declaring variable for name of file
	string name;
	name = pIn->GetSrting(pOut);

	//Declaring variable of type ofstream to write in file
	ofstream OutputFile;

	//To write in file
	OutputFile.open(name, std::fstream::out | std::fstream::trunc);

	OutputFile << Component::count <<endl;

	pManager->Save(OutputFile);
	OutputFile << "-1" << endl;
	OutputFile.close();
	pOut->PrintMsg("Saved succesfully");

}

void SaveAction::Undo()
{}

void SaveAction::Redo()
{}
