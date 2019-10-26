#pragma once
#include "ClassMetal.h"
#include "ClassArcher.h"

class ClassMetalArcher: public ClassMetal, public ClassArcher
{
public:
	ClassMetalArcher();
	~ClassMetalArcher();
	virtual void tuongSinh();
	virtual void tuongKhac();
};

