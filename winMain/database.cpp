#include "stdafx.h"
#include "database.h"


database::database()
{
}


database::~database()
{
}

HRESULT database::init()
{
	loadDatabase( "database.txt" );

	return S_OK;
}

void database::release()
{
	iterElement mIter = _mTotalElement.begin();

	for ( ; mIter != _mTotalElement.end(); )
	{
		if ( mIter->second )
		{
			SAFE_DELETE( mIter->second );
			mIter = _mTotalElement.erase( mIter );
		}
		else
			++mIter;
	}

	_mTotalElement.clear();
}

void database::loadDatabase( string name )
{
	//데이터를 읽어오자
	arrElements vTemp;
	vTemp = TXTDATA->txtLoad( name.c_str() );

	string str;
	int count = 0;

	for ( unsigned int i = 0; i < vTemp.size(); i++ )
	{
		if ( vTemp[i] == "|" )
		{
			elements* em = new elements;
			str = vTemp[i + 1];
			_mTotalElement.insert( pair<string, elements*>( str, em ) );
			if ( i != 0 ) count += 7;
			continue;
		}

		iterElement mIter = _mTotalElement.find( str );
		if ( i == count + 1 ) mIter->second->name = vTemp[i].c_str();
		else if ( i == count + 2 ) mIter->second->increaseSpeed = (float) atof( vTemp[i].c_str() );
		else if ( i == count + 3 ) mIter->second->maxSpeed = (float) atof( vTemp[i].c_str() );
		else if ( i == count + 4 ) mIter->second->angle = (float) atof( vTemp[i].c_str() );
		else if ( i == count + 5 ) mIter->second->currentHP = atoi( vTemp[i].c_str() );
		else if ( i == count + 6 ) mIter->second->maxHP = atoi( vTemp[i].c_str() );
	}

	vTemp.clear();
}

void database::setElementDataIncreaseSpeed( string str, float is )
{
	iterElement mIter = _mTotalElement.find( str );
	mIter->second->increaseSpeed = is;
}

void database::setElementDataMaxSpeed( string str, float ms )
{
	iterElement mIter = _mTotalElement.find( str );
	mIter->second->maxSpeed = ms;
}

void database::setElementDataAngle( string str, float a )
{
	iterElement mIter = _mTotalElement.find( str );
	mIter->second->angle = a;
}

void database::setElementDataCurrentHP( string str, int ch )
{
	iterElement mIter = _mTotalElement.find( str );
	mIter->second->currentHP = ch;
}

void database::setElementDataMaxHP( string str, int mh )
{
	iterElement mIter = _mTotalElement.find( str );
	mIter->second->maxHP = mh;
}
