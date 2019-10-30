#pragma once
#include "ClassHero.h"
class ClassMetal
{
public:
	virtual void tuongSinh(ClassHero* hero) = 0;			//tương sinh với hero
	virtual void tuongKhac(ClassHero*& hero, char team) = 0;//tương khắc với hero, team = 'S' hoặc 'D' (chọn hero theo đồng minh hoặc địch)   

};

