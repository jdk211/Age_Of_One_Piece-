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

	//���� ���� �Լ�
	void addPlayerUnit(int line);
	void addEnemyUnit(int line);

	//���� ���� �Լ�
	void deletePlayerUnit(int arrayNum);
	void deleteEnemyUnit(int arrayNum);

	//�ൿ ���� ����
	void stateUnit();
};

