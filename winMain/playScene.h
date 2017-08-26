#pragma once
#include "gameNode.h"
#include "animation.h"
#include "menu.h"
#include "playerTown.h"

class unitManager;

class playScene : public gameNode
{
private:
	unitManager *_um;

	playerTown* _pTown;

	menu* _menu;

	animation* _bgAni;


public:
	playScene();
	~playScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

