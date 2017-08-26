#include "stdafx.h"
#include "unit.h"


unit::unit()
{
}


unit::~unit()
{
}

HRESULT unit::init(string imageName, int line)
{
	_x = 1000;
	_y = RND->getFromFloatTo(-15,15);
	_speed = 150 + RND->getFromFloatTo(-30,30);
	_image = IMAGEMANAGER->findImage(imageName);

	_index.time = TIMEMANAGER->getWorldTime();
	_index.dealy = 0.25;
	_index.indexMax = 8;
	_index.indexNum = 0;

	_line = line;

	return S_OK;
}

void unit::release()
{
}

void unit::update()
{

	if (TIMEMANAGER->getWorldTime() - _index.time > _index.dealy) {
		_index.time = TIMEMANAGER->getWorldTime();
		_index.indexNum++;
		if (_index.indexNum >= _index.indexMax) {
			_index.indexNum = 0;
		}
	}

	_x -= _speed * TIMEMANAGER->getElapsedTime();
	if (_x < 100) {
		_x = _mapSizeX - 100;
	}

	_rc = RectMakeCenter(_x,_y - _image->getFrameHeight()/2,_image->getFrameWidth(),_image->getFrameHeight());
}

void unit::render()
{
	if (_line == 1)
	{
		_image->frameRender(getMemDC(), VIEWMANAGER->getPtx(_rc.left), 340 + _rc.top, _index.indexNum, 0);
		char str[100];
		sprintf_s(str, "%d", _index.indexNum);
		MY_UTIL::TextOutplus(getMemDC(), 200, 30, str, 25, RGB(255, 20, 255), 1000, "Dynalight"); // BlackChancery
	}
	else if (_line == 2)
	{
		_image->frameRender(getMemDC(), VIEWMANAGER->getPtx(_rc.left), 530 + _rc.top, _index.indexNum, 0);
		char str[100];
		sprintf_s(str, "%d", _index.indexNum);
		MY_UTIL::TextOutplus(getMemDC(), 200, 60, str, 25, RGB(255, 20, 255), 1000, "Dynalight"); // BlackChancery
	}

	
}


void unit::move(int dx)
{
	_x += dx*_speed*TIMEMANAGER->getElapsedTime();
}

void unit::attack()
{
}

void unit::setState(int st)
{
	switch (st) {
	case ENON:
		_image = IMAGEMANAGER->findImage("coby_stand");
		_state = ENON;
		_index.indexNum = 0;
		break;
	case EMOVE:
		_image = IMAGEMANAGER->findImage("coby_move");
		_state = EMOVE;
		break;
	case EATTACK:
		_image = IMAGEMANAGER->findImage("coby_attack");
		_state = EATTACK;
		_index.indexNum = 0;
		break;
	case EDIE:
		_image = IMAGEMANAGER->findImage("coby_die");
		_state = EDIE;
		_index.indexNum = 0;
		break;
	}
}

bool unit::isAttackTime()
{
	if (TIMEMANAGER->getWorldTime() - _attack.time > _attack.delay) {
		_attack.time = TIMEMANAGER->getWorldTime();
		return true;
	}
	return false;
}
