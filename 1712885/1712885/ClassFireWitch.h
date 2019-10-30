#pragma once
#include "ClassFire.h"
#include "ClassWitch.h"

class ClassFireWitch:public ClassFire, public ClassWitch
{
public:
	ClassFireWitch();
	~ClassFireWitch();

	virtual void tuongSinh(ClassHero* hero);				//chưa có tương sinh
	virtual void tuongKhac(ClassHero*& hero, char team);	//chưa có tương khắc
};

