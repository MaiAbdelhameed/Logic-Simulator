#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1200, height = 700,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 40,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 40;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = 50,		//AND2 Gate Image default width
						AND2_Height = 50;		//AND2 Gate Image default height
	
	static const int    NOR2_Width = 50,        //NOR2 Gate Image default width
		                NOR2_Height = 50;       //NOR2 Gate Image default height
	
	static const int    XNOR2_Width = 50,       //XNOR2 Gate Image default width
		                XNOR2_Height = 50;      //XNOR2 Gate Image default height

	static const int    Buffer2_Width = 50,     //Buffer Gate Image default width
		                Buffer2_Height = 50;    //Buffer Gate Image default height

	static const int    Inverter2_Width = 50,   //Inverter Gate Image default width
		                Inverter2_Height = 50;  //Inverter Gate Image default height

	static const int    LED2_Width = 50,        //LED2 Gate Image default width
		                LED2_Height = 50;       //LED2 Gate Image default height

	static const int    AND3_Width=50,          //AND3 Gate Image default width
		                AND3_Height = 50;       //AND3 Gate Image default height

	static const int    NOR3_Width=50,          //NOR3 Gate Image default width
		                NOR3_Height = 50;       //NOR3 Gate Image default height

	static const int    XOR3_Width=50,          //XOR3 Gate Image default width
		                XOR3_Height = 50;       //XOR3 Gate Image default height
	static const int	NAND2_Width = 50,		//NAND2 Gate Image default width
		NAND2_Height = 50;		//NAND2 Gate Image default height
	static const int	OR2_Width = 50,		//OR2 Gate Image default width
		OR2_Height = 50;		//OR2 Gate Image default height
	static const int	Switch2_Width = 50,		//Switch2 Gate Image default width
		Switch2_Height = 50;		//Switch2 Gate Image default height
	static const int	XOR2_Width = 50,		//XOR2 Gate Image default width
		XOR2_Height = 50;		//XOR2 Gate Image default height


}UI;	//create a single global object UI

#endif