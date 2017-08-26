#pragma once

#include "gameNode.h"

//�������� void �̰� �Ű������� void�� �Լ��� �ּҰ��� ���� �� �ִ� �����͸�
//CALLBACK_FUNCTION �� �̸����� �����ϰڴ�.
typedef void( *CALLBACK_FUNCTION )( void );
typedef void( *CALLBACK_FUNCTION_PARAMETER )( void* obj );

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN,
	BUTTONDIRECTION_OVER
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;
	const char * _imageName;
	image * _image;
	RECT _rc;
	float _x, _y;
	void* _obj;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;
	POINT _btnOverFramePoint;

	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

public:
	button();
	~button();

	HRESULT init(const char * imageName, int x, int y,
		POINT btnUpFramePoint, POINT btnDownFramePoint);

	HRESULT init(const char * imageName, int x, int y,
		POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint, CALLBACK_FUNCTION cbFunction);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void release();
	void update();
	void render();

	RECT getRc() { return _rc; }
};

