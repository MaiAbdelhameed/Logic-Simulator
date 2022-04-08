#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Component* Clipboard; //Destination of gate that was cut or copied
	int NumberofComponentsSelected;
	ActionType CompClipboard;


public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	void Save(ofstream& OutputInterface);

	void Load(ifstream& input); 
	void Move(int, int);
	void Label(string label);
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	int GetCompList(Component* pcomp);
	Component* GetComp(int x, int y) const;

	Component* selectedcomponent();
	//To copy and paste components
	void SetClipboard(Component* selectedcomponent);
	Component* GetClipboard();

	void SetCompClipboard(ActionType selectedcomponent);
	ActionType GetCompClipboard();

	void PasteSelectedComponent(ActionType d);

	//To delete component
	void RemoveComponent();

	//destructor
	~ApplicationManager();
};

#endif