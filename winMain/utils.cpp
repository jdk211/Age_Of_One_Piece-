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
		//글자 색상
		SetTextColor(hdc, color);
		TextOut(hdc, x, y, lpString, strlen(lpString));
		SelectObject(hdc, oldFont);
		DeleteObject(myFont);
	}
	//     int nHeight,             // 높이
	//     int nWidth,              // 폭. 0을 넣어주면 높이에 비례함
	//     int nEscapement,         // 글자 전체 기울기
	//     int nOrientation,        // 기준선이 정해져 있고 기우는 기울기
	//     int fnWeight,            // 폰트의 두께 0~1000
	//     DWORD fdwItalic,         // 이탤릭
	//     DWORD fdwUnderline,      // 밑줄
	//     DWORD fdwStrikeOut,      // 취소선
	//     DWORD fdwCharSet,        // 캐릭터 셋
	//     DWORD fdwOutputPrecision,  // 정밀도
	//     DWORD fdwClipPrecision,  // 정밀도
	//     DWORD fdwQuality,        // 정밀도
	//     DWORD fdwPitchAndFamily,  // 정밀도
	//     LPCTSTR lpszFace         // 글꼴이름
}

