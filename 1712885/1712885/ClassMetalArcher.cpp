#include "ClassMetalArcher.h"

ClassMetalArcher::ClassMetalArcher() {

}

ClassMetalArcher::~ClassMetalArcher() {

}

void ClassMetalArcher::tuongSinh(ClassHero* hero) {
	string id = hero->getID();

	//tương sinh Thổ, Thổ sinh kim
	if (id[3] == 'E') {
		this->Agility *= 1.1;		//Cộng 10 % sức tấn công
		this->Mana *= 1.2;			//Cộng 20 % sức mana
	}
}

void ClassMetalArcher::tuongKhac(ClassHero*& hero, char team) {
	string id = hero->getID();

	//tương khắc Hỏa, Hỏa khắc Kim
	if (id[3] == 'F') {
		if (team == 'S') {		//cùng team
			//tướng khắc
			this->Mana *= 0.9;

			//tướng bị khắc
			hero->setMana(hero->getMana() * 0.9);
			hero->setDame(hero->getDame() * 0.9);
		}
		else if (team == 'D') {		//khác team
			this->Amor *= 0.7;
		}
	}
}