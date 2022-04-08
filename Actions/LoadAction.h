#include "Action.h"
#include <fstream>

class LoadAction :public Action
{
public:

	LoadAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Loads the file
	virtual void Execute();
	void Undo();
	void Redo();
};