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
	//�ֳʹ� ������Ʈ
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
	//�����Ҵ� �� �̵��� ������
	SAFE_DELETE(_vPlayerUnit[arrayNum]);
	//���� �̴ٱ� �ִ� �浵 ������
	_vPlayerUnit.erase(_vPlayerUnit.begin() + arrayNum);
	//erase �ȿ��� ���� �ּҰ��� ����. ����� ������ ���� error...
}

void unitManager::deleteEnemyUnit(int arrayNum)
{
	//�����Ҵ� �� �̵��� ������
	SAFE_DELETE(_vEnemyUnit[arrayNum]);
	//���� �̴ٱ� �ִ� �浵 ������
	_vEnemyUnit.erase(_vEnemyUnit.begin() + arrayNum);
	//erase �ȿ��� ���� �ּҰ��� ����. ����� ������ ���� error...
}

void unitManager::stateUnit()
{
	for (int i=0;i<_vPlayerUnit.size();i++) // �÷��̾�
	{
		bool boolOn = false;
		if (_vPlayerUnit[i]->isAttackTime()) { // �������� �� ���Ҵ�.
			for (int j = 0; j < _vEnemyUnit.size(); j++) // ��
			{
				if (_vPlayerUnit[i]->getLine() == _vEnemyUnit[j]->getLine()) continue;

				if (abs(_vPlayerUnit[i]->getX() - _vPlayerUnit[i]->getAttackRange()) < abs(_vPlayerUnit[i]->getX() - _vEnemyUnit[j]->getX()))
				{// ���ݹ��� �ȿ� ����.
					boolOn = true;
				}
			}
			if (boolOn)
				_vPlayerUnit[i]->setState(2); // �������� ��ȯ
			else
				_vPlayerUnit[i]->setState(1); // �̵����� ��ȯ
		}
		else // ������ �������̴�.
		{
			for (int j = 0; j < _vEnemyUnit.size(); j++) // ��
			{
				if (_vPlayerUnit[i]->getLine() == _vEnemyUnit[j]->getLine()) continue;

				if (abs(_vPlayerUnit[i]->getX() - _vPlayerUnit[i]->getSight()) > abs(_vPlayerUnit[i]->getX() - _vEnemyUnit[j]->getX()))
				{ // �̵����� �ۿ��ִ�..
					boolOn = true;
				}
			}
			if (boolOn)
				_vPlayerUnit[i]->setState(1); // �̵����� ��ȯ
			else
				_vPlayerUnit[i]->setState(0); // �������� ��ȯ
		}
	}
}
