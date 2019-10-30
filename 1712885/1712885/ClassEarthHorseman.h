#pragma once
#include "ClassHorseman.h"
#include "ClassEarth.h"

class ClassEarthHorseman: public ClassEarth, public ClassHorseman
{
public:
	ClassEarthHorseman();
	~ClassEarthHorseman();

	virtual void tuongSinh(ClassHero* hero);				//Tương sinh với Hỏa, Hỏa sinh Thổ
	virtual void tuongKhac(ClassHero*& hero, char team);	//chưa có tương khắc
};

