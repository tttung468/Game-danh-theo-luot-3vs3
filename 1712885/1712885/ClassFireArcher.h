#pragma once
#include "ClassFire.h"
#include "ClassArcher.h"

class ClassFireArcher:public ClassFire, public ClassArcher
{
public:
	ClassFireArcher();
	~ClassFireArcher();

	virtual void tuongSinh(ClassHero* hero);				//chưa có tương sinh
	virtual void tuongKhac(ClassHero*& hero, char team);	//chưa có tương khắc
};

