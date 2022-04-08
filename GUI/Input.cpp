//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	string userInput;
	char keyPressed;
	while(1){
		pWind->WaitKeyPress(keyPressed);

		if(keyPressed == 27 )	
			return "";	
		if(keyPressed == 13 )	
			return userInput;
		if(keyPressed == 8 ){
			if (!userInput.empty())
				userInput.pop_back();
		}
		else{
			userInput+=keyPressed;
		}
		pOut->PrintMsg(userInput);					
	}

	return NULL;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;       
			case ITM_XOR2: return ADD_XOR_GATE_2;       
			case ITM_XNOR2: return ADD_XNOR_GATE_2;      
			case ITM_AND3: return ADD_AND_GATE_3;       
			case ITM_NOR3: return ADD_NOR_GATE_3;       
			case ITM_XOR3: return ADD_XOR_GATE_3;      
			case ITM_NOT: return ADD_INV;        
			case ITM_BUFFER: return ADD_Buff;     
			case ITM_SWITCH: return ADD_Switch;   
			case ITM_LED: return ADD_LED;        
			case ITM_WIRES: return ADD_CONNECTION;      
			case ITM_SIMULATE: return SIM_MODE;        
			case ITM_LABEL: return ADD_Label;      
			case ITM_MOVE: return MOVE;
			case ITM_CUT: return CUTCASE;        
			case ITM_COPY: return COPYCASE;       
			case ITM_PASTE: return PASTECASE;      
			case ITM_SELECT: return SELECT;    
			case ITM_DELETE: return DELETECASE;     
			case ITM_LOAD: return LOAD;       
			case ITM_SAVE: return SAVECASE;       
			case ITM_EXIT: return EXIT;	
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}

	else	//Application is in Simulation mode
	{
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{
				case ITM_SIM: return Change_Switch;	
				case ITM_TRUTH: return Create_TruthTable;	
				case ITM_DESIGN: return DSN_MODE;      
				case ITM_PROBE: return PROBE;
				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;
		}
		
		return STATUS_BAR;
	}

}


Input::~Input()
{
}
