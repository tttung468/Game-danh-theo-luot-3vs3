#pragma once
#include "ClassHorseman.h"
#include "ClassEarth.h"

class ClassEarthHorseman: public ClassEarth, public ClassHorseman
{
public:
	ClassEarthHorseman();
	~ClassEarthHorseman();
	virtual void tuongSinh();
	virtual void tuongKhac();
};

