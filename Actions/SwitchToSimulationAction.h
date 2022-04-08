#include "Action.h"

class SwitchToSimulationAction :public Action
{
public:

	SwitchToSimulationAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Loads the file
	virtual void Execute();
	void Undo();
	void Redo();
};