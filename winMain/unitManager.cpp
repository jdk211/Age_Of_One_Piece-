#include "stdafx.h"
#include "unitManager.h"
#include "unit.h"


unitManager::unitManager()
{
}

unitManager::~unitManager()
{
}

HRESULT unitManager::init()
{
	return S_OK;
}

void unitManager::release()
{
}

void unitManager::update()
{
	//애너미 업데이트
	for (_viPlayerUnit = _vPlayerUnit.begin(); _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit) {
		(*_viPlayerUnit)->update();
		(*_viPlayerUnit)->move(1);
	}
	
	for (_viEnemyUnit = _vEnemyUnit.begin(); _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit) {
		(*_viEnemyUnit)->update();
		(*_viEnemyUnit)->move(-1);
	}
}

void unitManager::render()
{
	for (_viPlayerUnit = _vPlayerUnit.begin(); _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit)
		(*_viPlayerUnit)->render();
	
	for (_viEnemyUnit = _vEnemyUnit.begin(); _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit)
		(*_viEnemyUnit)->render();
}

void unitManager::addPlayerUnit(int line)
{
	unit* _unit;
	_unit = new unit;
	_unit->init("coby_stand", line);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addEnemyUnit(int line)
{
	unit* _unit;
	_unit = new unit;
	_unit->init("coby_stand", line);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::deletePlayerUnit(int arrayNum)
{
	//동적할당 된 쫄따구 날리고
	SAFE_DELETE(_vPlayerUnit[arrayNum]);
	//날라간 쫄다구 있는 방도 날리자
	_vPlayerUnit.erase(_vPlayerUnit.begin() + arrayNum);
	//erase 안에는 실제 주소값이 들어간다. 상수나 변수가 들어가면 error...
}

void unitManager::deleteEnemyUnit(int arrayNum)
{
	//동적할당 된 쫄따구 날리고
	SAFE_DELETE(_vEnemyUnit[arrayNum]);
	//날라간 쫄다구 있는 방도 날리자
	_vEnemyUnit.erase(_vEnemyUnit.begin() + arrayNum);
	//erase 안에는 실제 주소값이 들어간다. 상수나 변수가 들어가면 error...
}

void unitManager::stateUnit()
{
	for (int i=0;i<_vPlayerUnit.size();i++) // 플레이어
	{
		bool boolOn = false;
		if (_vPlayerUnit[i]->isAttackTime()) { // 공격쿨이 다 돌았다.
			for (int j = 0; j < _vEnemyUnit.size(); j++) // 적
			{
				if (_vPlayerUnit[i]->getLine() == _vEnemyUnit[j]->getLine()) continue;

				if (abs(_vPlayerUnit[i]->getX() - _vPlayerUnit[i]->getAttackRange()) < abs(_vPlayerUnit[i]->getX() - _vEnemyUnit[j]->getX()))
				{// 공격범위 안에 들어옴.
					boolOn = true;
				}
			}
			if (boolOn)
				_vPlayerUnit[i]->setState(2); // 공격으로 전환
			else
				_vPlayerUnit[i]->setState(1); // 이동으로 전환
		}
		else // 공격쿨 도는중이다.
		{
			for (int j = 0; j < _vEnemyUnit.size(); j++) // 적
			{
				if (_vPlayerUnit[i]->getLine() == _vEnemyUnit[j]->getLine()) continue;

				if (abs(_vPlayerUnit[i]->getX() - _vPlayerUnit[i]->getSight()) > abs(_vPlayerUnit[i]->getX() - _vEnemyUnit[j]->getX()))
				{ // 이동범위 밖에있다..
					boolOn = true;
				}
			}
			if (boolOn)
				_vPlayerUnit[i]->setState(1); // 이동으로 전환
			else
				_vPlayerUnit[i]->setState(0); // 멈춤으로 전환
		}
	}
}
