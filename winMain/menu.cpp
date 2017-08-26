#include "stdafx.h"
#include "menu.h"


menu::menu()
{
}


menu::~menu()
{
}

HRESULT menu::init(int level)
{
	_level = level;

	unitChange(level);

	_unitName[SPECIAL_UNIT] = "luffy";

	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i] = new button;
		_unitBtn[i]->init(_unitName[i], (680 + (i * 110)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
	}
	
	//int plusX = 20;
	//int plusY = 1;
	/*MY_UTIL::TextOutplus(getMemDC(), px + plusX, 10 + plusY, _unitName[MELEE_UNIT], 24, RGB(180, 140, 110), 800, "BlackChancery");*/
	/*MY_UTIL::TextOutplus(getMemDC(), px + 10 + plusX, 10 + 75 + plusY, "20", 24, RGB(180, 140, 110), 800, "BlackChancery");*/

	return S_OK;
}

void menu::release()
{
}

void menu::update()
{
	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i]->update();
	}
}

void menu::render()
{
	IMAGEMANAGER->findImage("board")->render(getMemDC(), 620, 10);

	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i]->render();
	}

}

void menu::unitChange(int level)
{
	switch (level)
	{
	case 1:
		_unitName[MELEE_UNIT] = "zoro";
		_unitName[ARCHER_UNIT] = "nami";
		break;
	case 2:
		_unitName[MELEE_UNIT] = "sanji";
		_unitName[ARCHER_UNIT] = "usopp";
		break;
	case 3:
		_unitName[MELEE_UNIT] = "chopper";
		_unitName[ARCHER_UNIT] = "robin";
		break;
	case 4:
		_unitName[MELEE_UNIT] = "franky";
		_unitName[ARCHER_UNIT] = "hancock";
		break;
	case 5:
		_unitName[MELEE_UNIT] = "brook";
		_unitName[ARCHER_UNIT] = "kuma";
		break;
	}
}
