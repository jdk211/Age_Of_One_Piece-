#include "stdafx.h"
#include "button.h"


button::button()
{
}


button::~button()
{
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnUpFramePoint, POINT btnDownFramePoint)
{
	_callbackFunction = NULL;

	_direction = BUTTONDIRECTION_NULL;

	_x = (float)x;
	_y = (float)y;

	_btnDownFramePoint = btnDownFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnOverFramePoint = pointMake(0, 0);

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(_imageName);

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint)
{
	_callbackFunction = NULL;

	_direction = BUTTONDIRECTION_NULL;

	_x = (float)x;
	_y = (float)y;

	_btnDownFramePoint = btnDownFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnOverFramePoint = btnOverFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(_imageName);

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint, CALLBACK_FUNCTION cbFunction)
{
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;
	_obj = NULL;

	_direction = BUTTONDIRECTION_NULL;

	_x = x;
	_y = y;

	_btnDownFramePoint = btnDownFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnOverFramePoint = btnOverFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(_imageName);

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnUpFramePoint, POINT btnDownFramePoint, POINT btnOverFramePoint, CALLBACK_FUNCTION_PARAMETER cbFunction, void * obj)
{
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;
	_obj = obj;

	_direction = BUTTONDIRECTION_NULL;

	_x = x;
	_y = y;

	_btnDownFramePoint = btnDownFramePoint;
	_btnUpFramePoint = btnUpFramePoint;
	_btnOverFramePoint = btnOverFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(_imageName);

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void button::release()
{
}

void button::update()
{
	if (_leftButtonDown && _direction == BUTTONDIRECTION_OVER)
	{
		_direction = BUTTONDIRECTION_DOWN;
	}

	if (PtInRect(&_rc, _ptMouse))
	{
		if (_leftButtonDown)
		{
			_direction = BUTTONDIRECTION_DOWN;
		}
		else if (!_leftButtonDown && _direction == BUTTONDIRECTION_DOWN)
		{
			_direction = BUTTONDIRECTION_UP;
			if (_obj == NULL && _callbackFunction != NULL) _callbackFunction();
			else if (_callbackFunction == NULL) return;
			else _callbackFunctionParameter(_obj);
		}
		
		if (!_leftButtonDown)
		{
			_direction = BUTTONDIRECTION_OVER;
		}
	}
	
	else _direction = BUTTONDIRECTION_NULL;
}

void button::render()
{
	switch (_direction)
	{
	case BUTTONDIRECTION_NULL:	case BUTTONDIRECTION_UP:
		_image->frameRender(getMemDC(), _rc.left, _rc.top,
			_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;

	case BUTTONDIRECTION_DOWN:
		_image->frameRender(getMemDC(), _rc.left, _rc.top,
			_btnDownFramePoint.x, _btnDownFramePoint.y);
		break;

	case BUTTONDIRECTION_OVER:
		_image->frameRender(getMemDC(), _rc.left, _rc.top,
			_btnOverFramePoint.x, _btnOverFramePoint.y);
		break;
	}
}
