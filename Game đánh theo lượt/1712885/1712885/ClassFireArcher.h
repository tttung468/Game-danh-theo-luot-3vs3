#pragma once
#include "ClassFire.h"
#include "ClassArcher.h"

class ClassFireArcher:public ClassFire, public ClassArcher
{
public:
	ClassFireArcher();
	~ClassFireArcher();
	virtual void tuongSinh();
	virtual void tuongKhac();
};

