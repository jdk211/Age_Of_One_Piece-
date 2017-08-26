#include "stdafx.h"
#include "gameStudy.h"
#include "titleScene.h"
#include "playScene.h"

gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init(true);
	//테스트 이미지
	IMAGEMANAGER->addImage("unit_cho", "image/mainSceneBg/unit_cho.bmp", 80, 116, false, false);
	IMAGEMANAGER->addFrameImage("coby_stand", "image/mainSceneBg/coby_stand.bmp", 250, 100, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("coby_move", "image/mainSceneBg/coby_move.bmp", 640, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("castle", "image/mainSceneBg/castle.bmp", 730, 405, 4, 3, true, TRANSCOLOR);

	//타이틀 이미지
	IMAGEMANAGER->addImage("title", "image/title_scene/title.bmp", WINSIZEX, WINSIZEY, false, false);
	IMAGEMANAGER->addFrameImage("start", "image/title_scene/button_start_frame.bmp", 320, 225, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("exit", "image/title_scene/button_exit_frame.bmp", 320, 225, 1, 3, true, TRANSCOLOR);

	//맵 배경
	IMAGEMANAGER->addImage("map", "image/mainSceneBg/Untitled-1.bmp", 1600, 768, false, false);
	IMAGEMANAGER->addFrameImage("seaFrame", "image/mainSceneBg/sea_frame.bmp", 6400, 768, 4, 1, true, TRANSCOLOR);

	//HUD menu button 이미지
	IMAGEMANAGER->addImage("board", "image/hud/board.bmp", 337, 129, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy", "image/unit/playerUnit/luffy/luffy_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	//1
	IMAGEMANAGER->addFrameImage("zoro", "image/unit/playerUnit/zoro/zoro_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami", "image/unit/playerUnit/nami/nami_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	//2
	IMAGEMANAGER->addFrameImage("usopp", "image/unit/playerUnit/usopp/usopp_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("sanji", "image/unit/playerUnit/sanji/sanji_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	//3
	IMAGEMANAGER->addFrameImage("robin", "image/unit/playerUnit/robin/robin_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("chopper", "image/unit/playerUnit/chopper/chopper_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	//4
	IMAGEMANAGER->addFrameImage("franky", "image/unit/playerUnit/franky/franky_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock", "image/unit/playerUnit/hancock/hancock_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	//5
	IMAGEMANAGER->addFrameImage("brook", "image/unit/playerUnit/brook/brook_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma", "image/unit/playerUnit/kuma/kuma_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);

	//씬 추가
	SCENEMANAGER->addScene("playerScene", new playScene);
	SCENEMANAGER->addScene("title", new titleScene);
	
	//시작 씬
	SCENEMANAGER->changeScene("title");

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	SCENEMANAGER->update();

	gameNode::update();
}

void gameStudy::render( )
{
	//백버퍼에서 뿌려줌
	/*HDC backDC = this->getBackBuffer()->getMemDC();*/
	PatBlt( getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS );
	//============================================================
	SCENEMANAGER->render();

	TIMEMANAGER->render( getMemDC() );
	//============================================================
	//백버퍼에 있는 그림을 HDC에 그리자
	this->getBackBuffer()->render( getHDC(), 0, 0 );
}

