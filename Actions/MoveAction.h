#include "Action.h"

class MoveAction :public Action
{
private:
	int Cx, Cy;
public:

	MoveAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Loads the file
	virtual void Execute();
	void Undo();
	void Redo();
};