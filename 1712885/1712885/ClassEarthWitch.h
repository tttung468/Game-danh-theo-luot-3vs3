#pragma once
#include "ClassEarth.h"
#include "ClassWitch.h"

class ClassEarthWitch:public ClassEarth, public ClassWitch
{
public:
	ClassEarthWitch();
	~ClassEarthWitch();

	virtual void tuongSinh(ClassHero* hero);
	virtual void tuongKhac(ClassHero*& hero, char team);
};

