#pragma once
#include "gameNode.h"
#include "button.h"

struct stBUTTON
{
	image* img;		//버튼 이미지
	button* btn;	//버튼 클래스
	int x, y;		//그려줄 위치 좌표
};

class titleScene : public gameNode
{
private:
	stBUTTON _start;	//스타트 버튼
	stBUTTON _exit;		//종료 버튼	

public:
	titleScene();
	~titleScene();

	HRESULT init();
	void release();
	void update();
	void render();

	static void start();	//button init함수에 들어 갈 스타트 함수, 씬을 변경한다
	static void exit();		//button init함수에 들어 갈 종료 함수, 종료 한다
};

