#include "stdafx.h"
#include "playerTown.h"


playerTown::playerTown()
{
}


playerTown::~playerTown()
{
}

HRESULT playerTown::init()
{
	_level = 1;

	_exp = 0;

	_hp = _maxHp = 500;

	return S_OK;
}

void playerTown::release()
{
}

void playerTown::update()
{
	townUpgrade();
}

void playerTown::render()
{

}

void playerTown::townUpgrade()
{
	if (_exp < 4000)
	{
		_level = 1;
		_maxHp = 500;
	}
	else if (_exp >= 4000 && _exp < 8000)
	{
		_level = 2;
		_maxHp = 1000;
	}
	else if (_exp >= 8000 && _exp < 12000)
	{
		_level = 3;
		_maxHp = 1500;
	}
	else if (_exp >= 12000 && _exp < 16000)
	{
		_level = 4;
		_maxHp = 2000;
	}
	else if (_exp >= 16000 && _exp < 20000)
	{
		_level = 5;
		_maxHp = 2500;
	}
}
