#pragma once
#include "ClassMetal.h"
#include "ClassHorseman.h"

class ClassMetalHorseman: public ClassMetal, public ClassHorseman
{
public:
	ClassMetalHorseman();
	~ClassMetalHorseman();
	virtual void tuongSinh();
	virtual void tuongKhac();
};

