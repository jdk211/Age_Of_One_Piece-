#pragma once
#include "gameNode.h"

class playerTown : public gameNode
{
private:
	int _level;
	int _exp;
	int _maxHp;
	int _hp;

public:
	playerTown();
	~playerTown();

	HRESULT init();
	void release();
	void update();
	void render();

	void townUpgrade();

	int getLevel() { return _level; }

};

