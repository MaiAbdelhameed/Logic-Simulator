#ifndef _DEL_H
#define _DEL_H
#include "action.h"

class DEL : public Action
{
public:
	DEL(ApplicationManager* pApp);
	virtual ~DEL(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
