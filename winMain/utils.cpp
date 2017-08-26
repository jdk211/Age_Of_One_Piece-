#include "stdafx.h"
#include "utils.h"

namespace MY_UTIL
{
	float getDistance( float startX, float startY, float endX, float endY )
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf( x*x + y*y );
	}

	float getAngle( float startX, float startY, float endX, float endY )
	{
		float x = endX - startX;
		float y = endY - startY;

		float dist = sqrtf( x*x + y*y );
		float angle = acosf( x / dist );

		if ( y > 0 ) angle = PI2 - angle;

		return angle;
	}

	void TextOutplus(HDC hdc, int x, int y, LPCSTR lpString,int size, COLORREF color,int weight, LPCSTR ttf)
	{
		HFONT myFont = CreateFont(size, 0, 0, 0, weight, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, ttf);
		HFONT oldFont = (HFONT)SelectObject(hdc, myFont);
		//���� ����
		SetTextColor(hdc, color);
		TextOut(hdc, x, y, lpString, strlen(lpString));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
	}
	//     int nHeight,             // ����
	//     int nWidth,              // ��. 0�� �־��ָ� ���̿� �����
	//     int nEscapement,         // ���� ��ü ����
	//     int nOrientation,        // ���ؼ��� ������ �ְ� ���� ����
	//     int fnWeight,            // ��Ʈ�� �β� 0~1000
	//     DWORD fdwItalic,         // ���Ÿ�
	//     DWORD fdwUnderline,      // ����
	//     DWORD fdwStrikeOut,      // ��Ҽ�
	//     DWORD fdwCharSet,        // ĳ���� ��
	//     DWORD fdwOutputPrecision,  // ���е�
	//     DWORD fdwClipPrecision,  // ���е�
	//     DWORD fdwQuality,        // ���е�
	//     DWORD fdwPitchAndFamily,  // ���е�
	//     LPCTSTR lpszFace         // �۲��̸�
}

