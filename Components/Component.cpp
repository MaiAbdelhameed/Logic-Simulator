#include "Component.h"
int Component::count = 0;
Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}

bool Component::select(int x, int y)
{
	bool b=false;

	if ((x > m_GfxInfo.x1 && x < m_GfxInfo.x2))
	{
		if ((y > m_GfxInfo.y1 && y < m_GfxInfo.y2))
			b = true;
		else
			b = false;
	}

	return b;
}

bool Component::IsSelected()
{
	if (selected == true)
		return true;
	else return false;
}

void Component::SetSelection(bool s)
{
	selected = s;
}

Component::Component()
{}

Component::~Component()
{}

