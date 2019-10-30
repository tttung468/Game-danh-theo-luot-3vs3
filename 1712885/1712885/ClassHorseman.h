#pragma once
#ifndef __CLASSHORSEMAN_H__
#define __CLASSHORSEMAN__
#include "ClassHero.h"

//Class nhân vật kị sĩ
class ClassHorseman :public ClassHero
{
protected:
	int Strength;

public:
	ClassHorseman();
	~ClassHorseman();

	virtual void inputHero(fstream& inFile);		//Hàm nhập thông tin Hero
	virtual void outputHero();		//Hàm xuất thông tin Hero

	virtual int getDame();		//lấy chỉ số tấn công Strength

	virtual void setDame(int dame);		//cập nhật lại chỉ số tấn công Strength

	virtual void attack(int& healthPlayerB, int amorPlayerB);		//hàm tấn công


};


#endif // !__CLASSHORSEMAN_H__