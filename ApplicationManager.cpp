#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddNOTgate.h"
#include "Actions\AddBUFFERgate.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddNORgate3.h"
#include "Actions\LoadAction.h"
#include "Actions\SelectAction.h"
#include "Actions\MoveAction.h"
#include "Actions\SwitchToSimulationAction.h"
#include "Actions\LabelAction.h"
#include "Actions\AddSWITCH.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddConnection.h"
#include "Actions/COPY.h"
#include "Actions/CUT.h"
#include "Actions/DEL.h"
#include "Actions/PASTE.h"
#include "Actions/SaveAction.h"
#include <fstream>
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;
		case ADD_Buff:
			pAct = new AddBUFFERgate(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case SIM_MODE:
			pAct = new SwitchToSimulationAction(this);
			break;
		case ADD_Label:
			pAct = new LabelAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			break;
		case COPYCASE:
			pAct = new COPY(this);
			break;
		case CUTCASE:
			pAct = new CUT(this);
			break;
		case PASTECASE:
			pAct = new PASTE(this);
			break;
		case DELETECASE:
			pAct = new DEL(this);
			break;
		case SAVECASE:
			pAct = new SaveAction(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

///////////////////////////////////////////////////////////////////////
void ApplicationManager :: Load(ifstream& input) {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelection(false);
		delete CompList[i];
		CompList[i] = NULL;
	}
	CompCount = 0;
	int noOfComponents;
	input >> noOfComponents;
	string componentType;
	GraphicsInfo graphicsInfo;
	graphicsInfo.x1 = 0;
	graphicsInfo.y1 = 0;
	graphicsInfo.x2 = 0;
	graphicsInfo.y2 = 0;
	Component* component;
	for (int i = 0; i < noOfComponents; i++) {
		input >> componentType;
		if (componentType == "SWITCH") {
			component = new SWITCH(graphicsInfo, 5);
		}
		if (componentType == "AND2") {
			component = new AND2(graphicsInfo,5);
		}
		if (componentType == "AND3") {
			component = new AND3(graphicsInfo, 5);
		}
		if (componentType == "NOR2") {
			component = new NOR2(graphicsInfo, 5);
		}
		if (componentType == "NOR3") {
			component = new NOR3(graphicsInfo, 5);
		}
		if (componentType == "OR2") {
			component = new OR2(graphicsInfo, 5);
		}
		if (componentType == "NAND2") {
			component = new NAND2(graphicsInfo, 5);
		}
		if (componentType == "XOR2") {
			component = new XOR2(graphicsInfo, 5);
		}
		if (componentType == "XOR3") {
			component = new XOR3(graphicsInfo, 5);
		}
		if (componentType == "XNOR2") {
			component = new XNOR2(graphicsInfo, 5);
		}
		if (componentType == "NOT") {
			component = new NOT(graphicsInfo, 5);
		}
		if (componentType == "BUFFER") {
			component = new Buffer(graphicsInfo, 5);
		}
		component->Load(input);
		AddComponent(component);		
	}

}

void ApplicationManager::Move(int x, int y) {
	
	Component* component = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsSelected())
			component = CompList[i];
			
	}
	if (component != NULL) {
		component->Move(x, y);
		component->SetSelection(false);
	}
	

}

void ApplicationManager::Label(string label) {

	Component* component = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsSelected())
			component = CompList[i];

	}
	if (component != NULL) {
		component->Label(label);
		component->SetSelection(false);

	}


}

int ApplicationManager::GetCompList(Component* pcomp)
{
	pcomp = CompList[0];
	return CompCount;
}

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetComp(int x, int y) const
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->select(x, y))
			return CompList[i];
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::SetCompClipboard(ActionType selectedcomponenttype)
{
	CompClipboard = selectedcomponenttype;
}

ActionType ApplicationManager::GetCompClipboard()
{
	return CompClipboard;
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::SetClipboard(Component* selectedcomponent)
{
	Clipboard = selectedcomponent;
}

Component* ApplicationManager::GetClipboard()
{
	return Clipboard;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::PasteSelectedComponent(ActionType d)
{
	ExecuteAction(d);
}

void ApplicationManager::RemoveComponent()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsSelected())
		{
			CompList[i]->SetSelection(false);
			delete CompList[i];
			CompList[i] = NULL;
		}
		NumberofComponentsSelected = 0;
	}
	if (NumberofComponentsSelected == 0)
	{
		OutputInterface->PrintMsg("No Selected component to delete");
	}
	int j = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] != NULL)
		{
			CompList[j] = CompList[i];
			j++;
		}
	}
	CompCount = j;
	OutputInterface->ClearDrawingArea();
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager::selectedcomponent()
{
	bool a;
	for (int i = 0; i < CompCount; i++)
	{
		a = CompList[i]->IsSelected();
		if (a == true)
		{
			return CompList[i];
		}
	}
	Component* comp = NULL;
	return comp;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::Save(ofstream& OutputInterface)
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Save(OutputInterface, 1);

	for (int i = 0; i < CompCount; i++)
		CompList[i]->Save(OutputInterface, 0);
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}