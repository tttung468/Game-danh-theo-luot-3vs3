#pragma once
#include "ClassFire.h"
#include "ClassWitch.h"

class ClassFireWitch:public ClassFire, public ClassWitch
{
public:
	ClassFireWitch();
	~ClassFireWitch();
	virtual void tuongSinh();
	virtual void tuongKhac();
};

