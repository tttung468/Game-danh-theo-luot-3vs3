#pragma once
#ifndef __CLASSGAME_H__
#define __CLASSGAME__
#define _CRT_SECURE_NO_WARNINGS
#include "ClassEarthHorseman.h"
#include "ClassEarthWitch.h"
#include "ClassFireArcher.h"
#include "ClassFireWitch.h"
#include "ClassMetalArcher.h"
#include "ClassMetalHorseman.h"
#include <vector>

//class Game quản lí nhân vật, điều khiển trận đấu
class ClassGame
{
private:
	vector<ClassHero*> heroList;	//danh sách các hero được sử dụng trong trận đấu
	vector<ClassHero*> heroListA;	//danh sách các hero sử dụng ở sân đấu bên phải
	vector<ClassHero*> heroListB;	//danh sách các hero sử dụng ở sân đấu bên trái

public:
	ClassGame();
	~ClassGame();

	void inputHeroList();				//hàm nhập danh sách các hero được sử dụng
	void outputHeroListSide(char team);	//hàm in danh sách các hero thuộc 1 team, 'A': trái, 'B': phải
	void outputHeroesName();			//hàm in danh sách tên của các hero được sử dụng

	void attackHeroAHeroB(ClassHero* &heroA, ClassHero* &heroB);	//hàm tấn công giữa 2 hero
	void attackListAListB();				//hàm tấn công giữa heroListA và heroListB
	
	bool checkHeroInList(string name);		//hàm kiểm tra hero có trong heroList

	int countHeroesRemainHealth(char team);	//hàm kiểm tra có bao nhiêu hero còn máu trong List
	int countHeroesRemainMana(char team);	//hàm kiểm tra có bao nhiêu hero (còn sống) còn mana trong List

	ClassHero* initHero(string name);		//hàm khởi tạo 1 hero mới từ tên, hero đó phải có trong heroList

	void chooseHeroForList(char team);		//hàm chọn hero cho sân đấu, tùy thuộc vào team, 'A':trái, 'B':phải

	void tinhTuongSinhCungTeam(int i, char team);	//hàm tính tương sinh các tướng cùng team
	void tinhTuongKhacCungTeam(int i, char team);	//hàm tính tương khắc các tướng cùng team
	void tinhTuongKhacKhacTeam(int i, int j);		//hàm tính tương khắc các khác cùng team

	void resultMatch();	//hàm xuất kết quả trận đấu

	void match();		//hàm điều khiển trận đấu
};


#endif // !__CLASSGAME_H__