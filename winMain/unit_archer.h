#pragma once
#include "unit.h"

class unit_archer : public unit
{
public:
	/*class bullet {
	private:
		image _image;
		float _x, _y;
		float _speed;
		float _radius;
		int _dir;
	public:
		HRESULT init();
		virtual void release();
		virtual void update();
		virtual void render();
	};*/
private:

public:
	unit_archer();
	~unit_archer();

	virtual HRESULT init(string imageName);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void attack();
};

