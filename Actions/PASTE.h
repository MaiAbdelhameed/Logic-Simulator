#ifndef _PASTE_H
#define _PASTE_H
#include "action.h"

class PASTE : public Action
{
public:
	PASTE(ApplicationManager* pApp);
	virtual ~PASTE(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
