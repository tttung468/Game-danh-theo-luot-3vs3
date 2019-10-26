#pragma once
#ifndef __CLASSWITCH_H__
#define __CLASSWITCH__
#include "ClassHero.h"

//Class nhân vật phù thủy
class ClassWitch :public ClassHero
{
protected:
	int Intelligent;

public:
	ClassWitch();
	~ClassWitch();

	virtual void inputHero(fstream &inFile);		//Hàm nhập thông tin Hero
	virtual void outputHero();		//Hàm xuất thông tin Hero

	virtual int getDame();		//lấy chỉ số tấn công Intelligent

	virtual void setDame(int dame);		//cập nhật lại chỉ số tấn công Intelligent
	
	virtual void attack(int& healthPlayerB, int amorPlayerB);		//hàm tấn công

};

#endif // ! __CLASSWITCH_H__