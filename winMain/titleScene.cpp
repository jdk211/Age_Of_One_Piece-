#include "stdafx.h"
#include "titleScene.h"


titleScene::titleScene()
{
}

titleScene::~titleScene()
{
}

HRESULT titleScene::init()
{
	//시작 버튼
	_start.img = IMAGEMANAGER->findImage("start");
	_start.x = CENTERX - 200;
	_start.y = CENTERY;
	_start.btn = new button;
	_start.btn->init("start", _start.x, _start.y, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1), start);

	//종료 버튼
	_exit.img = IMAGEMANAGER->findImage("exit");
	_exit.x = CENTERX - 200;
	_exit.y = CENTERY + 120;
	_exit.btn = new button;
	_exit.btn->init("exit", _exit.x, _exit.y, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1), exit);

	return S_OK;
}

void titleScene::release()
{
	_start.btn->release();
	SAFE_DELETE(_start.btn);
	_exit.btn->release();
	SAFE_DELETE(_exit.btn);
}

void titleScene::update()
{
	_start.btn->update();
	_exit.btn->update();
}

void titleScene::render()
{
	IMAGEMANAGER->findImage("title")->render(getMemDC());

	_start.btn->render();
	_exit.btn->render();
}

void titleScene::start()
{
	//메인씬으로 변경
	SCENEMANAGER->changeScene("playerScene");
}

void titleScene::exit()
{
	PostMessage(_hWnd, WM_DESTROY, 0, 0);
}
