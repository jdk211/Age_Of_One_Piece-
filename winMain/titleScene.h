#pragma once
#include "gameNode.h"
#include "button.h"

struct stBUTTON
{
	image* img;		//��ư �̹���
	button* btn;	//��ư Ŭ����
	int x, y;		//�׷��� ��ġ ��ǥ
};

class titleScene : public gameNode
{
private:
	stBUTTON _start;	//��ŸƮ ��ư
	stBUTTON _exit;		//���� ��ư	

public:
	titleScene();
	~titleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	static void start();	//button init�Լ��� ��� �� ��ŸƮ �Լ�, ���� �����Ѵ�
	static void exit();		//button init�Լ��� ��� �� ���� �Լ�, ���� �Ѵ�
};

