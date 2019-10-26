#pragma once
#ifndef __CLASSINFOR_H__
#define __CLASSINFOR__
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Class chứa thông tin 
class ClassHero
{
protected:
	string ID;
	string Name;
	int Health;
	int Mana;
	int Agility;
	int Amor;

public:
	ClassHero();
	~ClassHero();

	virtual void inputHero(fstream &inFile);		//Hàm nhập thông tin Hero
	virtual void outputHero();		//Hàm xuất thông tin Hero

	bool checkMana();		//kiểm tra hero có còn mana, false: hết, true: còn
	bool checkHealth();		//kiểm tra hero có còn health, false: hết, true: còn

	string getID();				//lấy ID
	string getName();			//lấy Name
	int getHealth();			//lấy chỉ số Health
	int getMana();				//lấy chỉ số Mana
	int getAgility();			//lấy chỉ số Agility
	int getAmor();				//lấy chỉ số Amor
	virtual int getDame();		//lấy chỉ số tấn công tùy thuộc vào từng loại tướng

	void setID(string ID);				//cập nhật lại ID
	void setName(string Name);			//cập nhật lại Name
	void setHealth(int health);			//cập nhật lại Health
	void setMana(int mana);				//cập nhật lại Mana
	void setAgility(int agi);			//cập nhật lại Agility
	void setAmor(int amor);				//cập nhật lại Amor
	virtual void setDame(int dame);		//cập nhật lại chỉ số tấn công tùy thuộc vào từng loại tướng

	virtual void attack(int &healthPlayerB, int amorPlayerB);		//hàm tấn công
	
	virtual void tuongSinh(ClassHero* &);
	virtual void tuongKhac(ClassHero* &);
};

#endif // !__CLASSINFOR_H__