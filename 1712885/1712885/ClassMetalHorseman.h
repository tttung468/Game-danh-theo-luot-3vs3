#pragma once
#include "ClassMetal.h"
#include "ClassHorseman.h"

class ClassMetalHorseman: public ClassMetal, public ClassHorseman
{
public:
	ClassMetalHorseman();
	~ClassMetalHorseman();

	virtual void tuongSinh(ClassHero* hero);				//tương sinh Thổ, Thổ sinh kim
	virtual void tuongKhac(ClassHero*& hero, char team);	//tương khắc Hỏa, Hỏa khắc Kim
};

