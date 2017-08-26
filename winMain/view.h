#pragma once
#include "singletonBase.h"

class view : public singletonBase<view>
{
private:
	float _x, _y;
	float _endX, _endY;
	float _speed;
	POINT _GameSize;

public:
	HRESULT init(int width, int height);
	HRESULT init(float x, float y, int width, int height);
	void update();
	void updateX();
	void updateY();

	void MoveTo(float x, float y);

	FPOINT GetPlace();
	float getPlaceX() { return _x; }
	float getPlaceY() { return _y; }

	POINT GetendPlace() { POINT pt; pt.x = _endX; pt.y = _endY; return pt; }
	float getendX() { return _endX; }
	float getendY() { return _endY; }

	float getPtx(float x);
	float getPty(float y);
	
	//맵 메모리 링크
	//void setMapsMemoryLink(maps* em) { _em = em; }
	int getGameSizeX() { return _GameSize.x; }
	int getGameSizeY() { return _GameSize.y; }
	POINT getGameSize() { return _GameSize; }

	view();
	~view();
};

