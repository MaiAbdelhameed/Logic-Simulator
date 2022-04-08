#include "Action.h"
#include <string>

class LabelAction :public Action
{
private:
	std::string  Label;
public:

	LabelAction(ApplicationManager* pApp);
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Loads the file
	virtual void Execute();
	void Undo();
	void Redo();
};