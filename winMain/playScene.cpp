#include "stdafx.h"
#include "playScene.h"
#include "unit.h"
#include "unitManager.h"


playScene::playScene()
{
}


playScene::~playScene()
{
}

HRESULT playScene::init()
{
	//유닛 매니저
	_um = new unitManager;
	_um->init();
	//_unit->init("coby_move", false, 2);
	
	//메뉴 클래스
	_menu = new menu;
	_menu->init(6);

	//타운 클래스 
	_pTown = new playerTown;
	_pTown->init();

	//카메라 매니저
	VIEWMANAGER->init(750, 720 / 2, _mapSizeX, _mapSizeY);
	
	//바다 움직이는 애니메이션
	_bgAni = new animation;
	_bgAni->init(6400, 768, 1600, 768);
	_bgAni->setDefPlayFrame(false, true);
	_bgAni->setFPS(4);
	_bgAni->start();

	return S_OK;
}

void playScene::release()
{
	_um->release();
	SAFE_DELETE(_um);
	_menu->release();
	SAFE_DELETE(_menu);
	_pTown->release();
	SAFE_DELETE(_pTown);
}

void playScene::update()
{
	float vx, vy;
	vx = VIEWMANAGER->getPtx(VIEWMANAGER->getPlaceX());
	vy = VIEWMANAGER->getPty(VIEWMANAGER->getPlaceY());

	if (_ptMouse.x < 50) { // 왼쪽
		if (VIEWMANAGER->getendX() > CENTERX) {
			VIEWMANAGER->MoveTo(VIEWMANAGER->getendX() - 7, vy);
		}
	}
	else if (_ptMouse.x > WINSIZEX - 50) { // 오른쪽
		if (VIEWMANAGER->getendX() < _mapSizeX - CENTERX) {
			VIEWMANAGER->MoveTo(VIEWMANAGER->getendX() + 7, vy);
		}
	}
	else 
	{
		if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON)) {
			_um->addPlayerUnit(RND->getFromIntTo(1,2));
		}
		if (KEYMANAGER->isOnceKeyDown(MK_RBUTTON)) {
			_um->addPlayerUnit(RND->getFromIntTo(1, 2));
		}
		//	VIEWMANAGER->MoveTo(vx, vy);
	}
	
	_um->update();
	//_unit->update();
	_menu->update();
	_pTown->update();

	VIEWMANAGER->updateX();

	_bgAni->frameUpdate(TIMEMANAGER->getElapsedTime());
}

void playScene::render()
{
	//배경
	IMAGEMANAGER->render("map", getMemDC(), -VIEWMANAGER->getPlaceX() + CENTERX, 0);
	IMAGEMANAGER->findImage("seaFrame")->aniRender(getMemDC(), -VIEWMANAGER->getPlaceX() + CENTERX, 0, _bgAni);
	//아군 본진
	IMAGEMANAGER->frameRender("castle", getMemDC(), 
		VIEWMANAGER->getPtx(32 * 4) - IMAGEMANAGER->findImage("castle")->getFrameWidth()/2, 
		VIEWMANAGER->getPty(32 * 13) - 100*IMAGEMANAGER->findImage("castle")->getFrameHeight()/135, 0, 0);
	//적 본진
	IMAGEMANAGER->frameRender("castle", getMemDC(),
		VIEWMANAGER->getPtx(32 * (50-4)) - IMAGEMANAGER->findImage("castle")->getFrameWidth() / 2,
		VIEWMANAGER->getPty(32 * 13) - 100 * IMAGEMANAGER->findImage("castle")->getFrameHeight() / 135, 1, 0);
	//Rectangle(getMemDC(), (vx - CENTERX) + 100, 0, (vx + CENTERX) - 100, WINSIZEY);
	

	//int plusX = 20;
	//int plusY = 1;
	//int px = 650;
	////테스트 유닛
	//IMAGEMANAGER->render("unit_cho", getMemDC(), px, 10);
	//MY_UTIL::TextOutplus(getMemDC(), px + plusX, 10 + plusY, "Sanji", 24, RGB(180, 140, 110), 800, "BlackChancery");
	//MY_UTIL::TextOutplus(getMemDC(), px + 10 + plusX, 10 + 75 + plusY, "1000", 24, RGB(180, 140, 110), 800, "BlackChancery");

	//IMAGEMANAGER->render("unit_cho", getMemDC(), px+110, 10);
	//MY_UTIL::TextOutplus(getMemDC(), px + 110 + plusX,10+ plusY,"Joro",24,RGB(180,140,110),800,"BlackChancery");
	//MY_UTIL::TextOutplus(getMemDC(), px + 110 + 10 + plusX, 10 + 75 + plusY, "500", 24, RGB(180, 140, 110), 800, "BlackChancery");
	//
	//IMAGEMANAGER->render("unit_cho", getMemDC(), px+220, 10);
	//MY_UTIL::TextOutplus(getMemDC(), px + 220 + plusX - 7, 10+ plusY, "Luppy", 24, RGB(180, 140, 110), 800, "BlackChancery");
	//MY_UTIL::TextOutplus(getMemDC(), px + 220 + 10+plusX, 10 + 75 + plusY, "500", 24, RGB(180, 140, 110), 800, "BlackChancery");
	//
	_um->render();
	_menu->render();

	char str[100];
	sprintf_s(str, "%d %d", _ptMouse.x,_ptMouse.y);
	MY_UTIL::TextOutplus(getMemDC(), 10, 100, str,40,RGB(255,20,255),1000,"Dynalight"); // BlackChancery, Dynalight
	
	//_unit->render();

	/*for (int i = 0; i < 2; i++) {
		sprintf_s(str, "[%d] %0.2f %0.2f",_unit[i].getLine(), _unit[i].getX(), _unit[i].getY());
		MY_UTIL::TextOutplus(getMemDC(), 300, 10+i*30, str, 25, RGB(100, 200, 100));
	}*/

	//스크롤
	LineMake(getMemDC(), 50, 0, 50, WINSIZEY);
	LineMake(getMemDC(), WINSIZEX - 50, 0, WINSIZEX - 50, WINSIZEY);
}
