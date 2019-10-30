#include "ClassEarthWitch.h"

ClassEarthWitch::ClassEarthWitch() {

}

ClassEarthWitch::~ClassEarthWitch() {

}

void ClassEarthWitch::tuongSinh(ClassHero* hero) {
	string id = hero->getID();

	//Tương sinh với Hỏa, Hỏa sinh Thổ
	if (id[3] == 'F') {
		this->Intelligent *= 1.1;		//Cộng 10 % sức tấn công
		this->Mana *= 1.2;				//Cộng 20 % sức mana
	}
}

void ClassEarthWitch::tuongKhac(ClassHero*& hero, char team) {

}