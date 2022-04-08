#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}

void Output::PrintLabel(string msg, int x , int y) const
{
	// Set the Message offset from the Status Bar
	int MsgX = x;
	int MsgY = y;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, MsgY, msg);
}

//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode
	ClearToolBar();
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\Menu_BUFFER.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\Menu_SWITCH.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_WIRES] = "images\\Menu\\Menu_WIRES.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\Menu_LABEL.jpg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\Menu_MOVE.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\Menu_SELECT.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\Menu_SIMULATION.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list
	/////////////////DONE////////////////////

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode

void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	ClearToolBar();
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	///////////////////////DONE//////////////////

	//First prepare List of images for each menu item

	string MenuItemImages[ITM_SIM_CNT];

	MenuItemImages[ITM_SIM] = "images\\Menu\\Menu_SIMULATION.jpg";
	MenuItemImages[ITM_DESIGN] = "images\\Menu\\Menu_DESIGN.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\Menu_TT.jpg";
	MenuItemImages[ITM_PROBE] = "images\\Menu\\Menu_PROBE.jpg";

	//Draw a line under the toolbar

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	


}
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

//TODO: Add similar functions to draw all components
//arwa: nand switch or xor
//malak: nor, xnor, inverter, buffer, led

//Draw AND Gate:
void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//Draw NOR Gate:
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}

//Draw XNOR Gate:
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}

//Draw Buffer Gate:
void Output::DrawBuffer2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Buffer2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buffer2.jpg";

	//Draw Buffer2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Buffer2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Buffer2_Width, UI.Buffer2_Height);
}

//Draw Inverter Gate:
void Output::DrawInverter2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOT2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT2.jpg";

	//Draw Inverter2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Inverter2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Inverter2_Width, UI.Inverter2_Height);
}

//Draw LED:
void Output::DrawLED2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_LED2_Hi.png";
	else
		GateImage = "Images\\Gates\\Gate_LED2.png";

	//Draw LED2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by LED2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED2_Width, UI.LED2_Height);
}

//Draw 3-input AND
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

//Draw 3-input NOR Gate:
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

//Draw 3-input XOR Gate:
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}
void Output::DrawSwitch2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Switch2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Switch2.jpg";

	//Draw switch2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by SWITCH2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch2_Width, UI.Switch2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	////////////////////DONE/////////////
	if (true == selected)
	{
		int midP = (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;
		pWind->SetPen(RED,5);

		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, midP, r_GfxInfo.y1, FRAME);
		pWind->DrawLine(midP, r_GfxInfo.y1,midP, r_GfxInfo.y2, FRAME);
		pWind->DrawLine(midP,r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	}
	else
	{
		int midP = (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;
		pWind->SetPen(BLUE, 5);

		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, midP, r_GfxInfo.y1, FRAME);
		pWind->DrawLine(midP, r_GfxInfo.y1, midP, r_GfxInfo.y2, FRAME);
		pWind->DrawLine(midP, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	}
	
}


Output::~Output()
{
	delete pWind;
}

