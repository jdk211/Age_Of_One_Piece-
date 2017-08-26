#include "stdafx.h"
#include "view.h"

float GetReach(float X, float Y, float _X, float _Y) {
	return sqrt(pow(_X - X, 2) + pow(_Y - Y, 2));
}
float GetDir(float mX, float mY, float tX, float tY) { // 
	float dX, dY;
	float target_Dir;
	dX = tX - mX;
	dY = tY - mY;
	if (dX == 0) dX = 0.00001;

	target_Dir = (atan(dY / dX) * 180 / PI);

	if (mX > tX) {
		target_Dir += 180.0f;
	}
	else if (mY > tY) {
		target_Dir += 360.0f;
	}
	return target_Dir;
}

HRESULT view::init(int width, int height)
{
	_GameSize.x = width;
	_GameSize.y = height;

	_endX = _x = 100;
	_endY = _y = 100;
	_speed = 500;

	return S_OK;
}


HRESULT view::init(float x, float y, int width, int height)
{

	_GameSize.x = width;
	_GameSize.y = height;

	_endX = _x = x;
	_endY = _y = y;
	_speed = 500;

	return S_OK;
}

void view::update()
{
	int Px, Py;
	//_X -= 1024 / 2;
	//_Y -= 768 / 2;
	float dt = TIMEMANAGER->getElapsedTime();

	float TargetDir = GetDir(_x, _y, _endX, _endY);
	float TargetReach = GetReach(_x, _y, _endX, _endY);
	float ASpeed = _speed + 500 * (TargetReach / 100);


	float GoX = cosf(TargetDir * PI / 180)*ASpeed*dt;
	float GoY = sinf(TargetDir * PI / 180)*ASpeed*dt;

	int mapWidth = _GameSize.x; //_em->getWidth();
	int mapHeight = _GameSize.y; //_em->getHeight();

	if (TargetReach > ASpeed*dt) { // 이번프레임에 이동할 거리가 목표 거리보다 짧다.
		if (_x + GoX < WINSIZEX / 2) { // 왼쪽끝
			_x = WINSIZEX / 2;
		}
		else if (_x + GoX > mapWidth - WINSIZEX / 2) { // 오른쪽 끝
			_x = mapWidth - WINSIZEX / 2;
		}
		else { // 가운데
			_x += GoX;
		}

		if (_y + GoY < WINSIZEY / 2) { //위쪽끝
			_y = WINSIZEY / 2;
		}
		else if (_y + GoY > mapHeight - WINSIZEY / 2) { // 아래끝
			_y = mapHeight - WINSIZEY / 2;
		}
		else {
			_y += GoY;
		}
	}
	else {
		if (_x + GoX < WINSIZEX / 2) { // 왼쪽끝
			_x = WINSIZEX / 2;
		}
		else if (_x + GoX > mapWidth - WINSIZEX / 2) { // 오른쪽 끝
			_x = mapWidth - WINSIZEX / 2;
		}
		else { // 가운데
			_x = _endX;
		}

		if (_y + GoY < WINSIZEY / 2) { //위쪽끝
			_y = WINSIZEY / 2;
		}
		else if (_y + GoY > mapHeight - WINSIZEY / 2) 
		{ // 아래끝
			_y = mapHeight - WINSIZEY / 2;
		}
		else 
		{
			_y = _endY;
		}

	}

}

void view::updateX()
{
	int Px, Py;
	//_X -= 1024 / 2;
	//_Y -= 768 / 2;
	float dt = TIMEMANAGER->getElapsedTime();

	float TargetDir = GetDir(_x, _y, _endX, _endY);
	float TargetReach = GetReach(_x, _y, _endX, _endY);
	float ASpeed = _speed + 500 * (TargetReach / 100);


	float GoX = cosf(TargetDir * PI / 180)*ASpeed*dt;
	float GoY = sinf(TargetDir * PI / 180)*ASpeed*dt;

	int mapWidth = _GameSize.x; //_em->getWidth();
	int mapHeight = _GameSize.y; //_em->getHeight();

	if (TargetReach > ASpeed*dt) { // 이번프레임에 이동할 거리가 목표 거리보다 짧다.
		if (_x + GoX < WINSIZEX / 2) { // 왼쪽끝
			_x = WINSIZEX / 2;
		}
		else if (_x + GoX > mapWidth - WINSIZEX / 2) { // 오른쪽 끝
			_x = mapWidth - WINSIZEX / 2;
		}
		else { // 가운데
			_x += GoX;
		}
	}
	else {
		if (_x + GoX < WINSIZEX / 2) { // 왼쪽끝
			_x = WINSIZEX / 2;
		}
		else if (_x + GoX > mapWidth - WINSIZEX / 2) { // 오른쪽 끝
			_x = mapWidth - WINSIZEX / 2;
		}
		else { // 가운데
			_x = _endX;
		}
	}
}

void view::updateY()
{
	int Px, Py;
	//_X -= 1024 / 2;
	//_Y -= 768 / 2;
	float dt = TIMEMANAGER->getElapsedTime();

	float TargetDir = GetDir(_x, _y, _endX, _endY);
	float TargetReach = GetReach(_x, _y, _endX, _endY);
	float ASpeed = _speed + 500 * (TargetReach / 100);


	float GoX = cosf(TargetDir * PI / 180)*ASpeed*dt;
	float GoY = sinf(TargetDir * PI / 180)*ASpeed*dt;

	int mapWidth = _GameSize.x; //_em->getWidth();
	int mapHeight = _GameSize.y; //_em->getHeight();

	if (TargetReach > ASpeed*dt) { // 이번프레임에 이동할 거리가 목표 거리보다 짧다.

		if (_y + GoY < WINSIZEY / 2) { //위쪽끝
			_y = WINSIZEY / 2;
		}
		else if (_y + GoY > mapHeight - WINSIZEY / 2) { // 아래끝
			_y = mapHeight - WINSIZEY / 2;
		}
		else {
			_y += GoY;
		}
	}
	else {

		if (_y + GoY < WINSIZEY / 2) { //위쪽끝
			_y = WINSIZEY / 2;
		}
		else if (_y + GoY > mapHeight - WINSIZEY / 2)
		{ // 아래끝
			_y = mapHeight - WINSIZEY / 2;
		}
		else
		{
			_y = _endY;
		}

	}
}

void view::MoveTo(float x, float y)
{
	_endX = x;
	_endY = y;
}

FPOINT view::GetPlace()
{
	FPOINT pt;
	pt.x = _x;
	pt.y = _y;
	return pt;
}

float view::getPtx(float x)
{
	return CENTERX - (_x - x);
}

float view::getPty(float y)
{
	return CENTERY - (_y - y);
}


view::view()
{
}


view::~view()
{
}
