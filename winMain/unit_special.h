#pragma once
class unit_special
{
private:
	int _level;
public:
	unit_special();
	~unit_special();

	virtual HRESULT init(string imageName);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void attack();
};

