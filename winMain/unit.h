#pragma once
#include "gameNode.h"
#include "unitManager.h"


class unit : public gameNode
{
public:
	struct index {
		float time;
		float dealy;
		int indexNum, indexMax;
	};
	struct attack {
		float time;
		float delay;
		bool revenge;
		float range;
	};
private:
	image *_image;
	index _index;
	attack _attack;

	float _x, _y;
	RECT _rc;
	float _speed;
	float _sight;

	int _line; /* 1 or 2*/
	int _state;

	vector<unit> _vShotUnit;
private:
	enum { ENON = 0,EMOVE = 1, EATTACK = 2, EDIE = 3 };
public:
	unit();
	~unit();

	virtual HRESULT init(string imageName,int line);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void move(int dx);
	virtual void attack();

	virtual void setState(int st);

	float getX() { return _x; }
	float getY() { return _y; }

	float getSight() { return _sight; }
	float getAttackRange() { return _attack.range; }

	int getLine() { return _line; }

	bool isAttackTime();
};

/*
class unit2 {
public:
	struct index {
		float time;
		float dealy;
		int indexNum, indexMax;
	};
	struct attack {
		float time;
		float delay;
		bool revenge;
		float range;
	};
private:
	enum { EATTACK = 0, EDIE = 1 };
private:
	image *_image;
	index _index;
	attack _attack;

	unitManager * _um;
	vector<unit> _vShotUnit;

	int _state;
	int 
public:
	void update()
	{

		move();
		switch (state) {
		case EATTACK:
				attack();
			break;
		case EDIE:
			die();
			break;
		}

	}

	void move() {
		bool moveOn = false;
		for (int i = 0; i < _vShotUnit.size(); i++) {
			if (ux - ex > move_sight) {
				_x += dx*speed*dt;
			}
		}
	}

	void attack() {
		if (TIMEMANAGER->get월드타임() - _attack.time > _attack.delay) { // 딜레이시간 끝남
			_image = findImage("joro_attack");
			_index.indexNum = 0;
		}

		if (_index.indexNum == 6) {
			if (!_attackOn) {
				_attackOn = true;
				for (int i = 0; i<_vShotUnit.size; i++) {
					_vShotUnit->damege();
					if (!_one) {
						_one = true;
						break;
					}
				}
			}
		}
	}

	void die() {

	}

};
*/