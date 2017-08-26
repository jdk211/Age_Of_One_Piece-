#pragma once
#include "unit.h"

class unit_melee : public unit
{
private:
	
public:
	unit_melee();
	~unit_melee();

	virtual HRESULT init(string imageName);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void attack();
};

class melee_zoro : public unit_melee {
private:

public:
	virtual void attack() {

	}
};
