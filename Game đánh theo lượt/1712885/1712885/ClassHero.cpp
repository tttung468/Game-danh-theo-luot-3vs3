#include "ClassHero.h"

ClassHero::ClassHero() {
	this->Agility = this->Amor = this->Health = this->Mana = 0;
}

ClassHero::~ClassHero() {
	this->Name.clear();
	this->ID.clear();
}

void ClassHero::inputHero(fstream& inFile) {
	string temp;

	getline(inFile, temp, '\t');		//nhap ID
	inFile >> this->ID;
	getline(inFile, temp, '\t'); 		//nhap Name
	inFile >> this->Name;
	getline(inFile, temp, '\t');		//nhap Health
	inFile >> this->Health;
	getline(inFile, temp, '\t');		//nhap Mana
	inFile >> this->Mana;
	getline(inFile, temp, '\t');		//nhap Agility
	inFile >> this->Agility;
}

void ClassHero::outputHero() {
	cout << "ID\t" << this->ID << endl;
	cout << "Name\t" << this->Name << endl;
	cout << "Health\t" << this->Health << endl;
	cout << "Mana\t" << this->Mana << endl;
	cout << "Agility\t" << this->Agility << endl;
}

bool ClassHero::checkMana() {
	if (this->Mana > 0) return true;
	return false;
}

bool ClassHero::checkHealth() {
	if (this->Health > 0) return true;
	return false;
}

string ClassHero::getID() {
	return this->ID;
}

string ClassHero::getName() {
	return this->Name;
}

int ClassHero::getHealth() {
	return this->Health;
}

int ClassHero::getMana() {
	return this->Mana;
}

int ClassHero::getAgility() {
	return this->Agility;
}

int ClassHero::getAmor() {
	return this->Amor;
}

int ClassHero::getDame() {
	return 0;
}

void ClassHero::setID(string ID) {
	this->ID = ID;
}

void ClassHero::setName(string Name) {
	this->Name = Name;
}

void ClassHero::setHealth(int health) {
	this->Health = health;
}

void ClassHero::setMana(int mana) {
	this->Mana = mana;
}

void ClassHero::setAgility(int agi) {
	this->Agility = agi;
}

void ClassHero::setAmor(int amor) {
	this->Amor = amor;
}

void ClassHero::setDame(int dame) {

}

void ClassHero::attack(int& healthPlayerB, int amorPlayerB) {
	this->Mana *= 0.9;
}

void ClassHero::tuongSinh(ClassHero* &hero) {

}

void ClassHero::tuongKhac(ClassHero* &hero) {

}