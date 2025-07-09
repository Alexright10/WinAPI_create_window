#pragma once
#include "framework.h"

using namespace std;

class Base
{
	map<int, int> ::iterator it;
public:
	map<int, int> ms;
	BOOL new_Win();
	void createMap();
	void paintg();
	void set(HDC hdc);


};