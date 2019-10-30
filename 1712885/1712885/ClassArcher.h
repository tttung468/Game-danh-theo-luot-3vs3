#pragma once
#ifndef __CLASSARCHER_H__
#define __CLASSARCHER__
#include "ClassHero.h"

//Class nhân vật cung thủ
class ClassArcher :public ClassHero
{
public:
	ClassArcher();
	~ClassArcher();

	virtual void inputHero(fstream &inFile);
	virtual void outputHero();

	virtual int getDame();		//lấy chỉ số tấn công Agility

	virtual void setDame(int dame);		//cập nhật lại chỉ số tấn công Agility

	virtual void attack(int& healthPlayerB, int amorPlayerB);		//hàm tấn công


};


#endif // !__CLASSARCHER_H__