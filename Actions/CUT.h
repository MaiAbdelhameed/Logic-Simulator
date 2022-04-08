#ifndef _CUT_H
#define _CUT_H
#include "action.h"

class CUT : public Action
{
public:
	CUT(ApplicationManager* pApp);
	virtual ~CUT(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
