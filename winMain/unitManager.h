#pragma once
#include "gameNode.h"
#include <vector>

class unit;

class unitManager : public gameNode
{
private:
	typedef vector<unit*> vUnit;
	typedef vector<unit*>::iterator viUnit;

	vUnit _vPlayerUnit, _vEnemyUnit;
	viUnit _viPlayerUnit, _viEnemyUnit;
public:
	unitManager();
	~unitManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//유닛 셋팅 함수
	void addPlayerUnit(int line);
	void addEnemyUnit(int line);

	//유닛 제거 함수
	void deletePlayerUnit(int arrayNum);
	void deleteEnemyUnit(int arrayNum);

	//행동 판정 관리
	void stateUnit();
};

