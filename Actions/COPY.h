#ifndef _COPY_H
#define _COPY_H

#include "action.h"



class COPY : public Action
{
public:
	COPY(ApplicationManager* pApp);
	virtual ~COPY(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif
