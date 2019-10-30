#pragma once
#include "ClassMetal.h"
#include "ClassArcher.h"

class ClassMetalArcher: public ClassMetal, public ClassArcher
{
public:
	ClassMetalArcher();
	~ClassMetalArcher();

	virtual void tuongSinh(ClassHero* hero);				//tương sinh Thổ, Thổ sinh kim
	virtual void tuongKhac(ClassHero*& hero, char team);	//tương khắc Hỏa, Hỏa khắc Kim
};

