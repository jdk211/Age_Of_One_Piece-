#pragma once
#include "gameNode.h"
#include "button.h"

//melee, archer, special
enum eUNITJOP
{
	MELEE_UNIT, 
	ARCHER_UNIT, 
	SPECIAL_UNIT,
	END_INDEX
};

class menu : public gameNode
{
private:
	int _level;

	char* _unitName[END_INDEX];

	button* _unitBtn[END_INDEX];

public:
	menu();
	~menu();

	HRESULT init(int level);
	void release();
	void update();
	void render();

	int getMenuLevel() { return _level; }

	//������ ������ �ö󰥼��� �ٲ��ִ� �Լ�
	void unitChange(int level);
};

