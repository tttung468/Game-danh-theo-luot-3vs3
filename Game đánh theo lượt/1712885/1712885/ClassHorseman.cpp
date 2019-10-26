#include "ClassHorseman.h"

ClassHorseman::ClassHorseman() {
	this->Strength = 0;
}

ClassHorseman::~ClassHorseman() {

}

void ClassHorseman::inputHero(fstream& inFile) {
	string temp;
	int value;

	ClassHero::inputHero(inFile);
	getline(inFile, temp, '\t');			//nhap Strength
	inFile >> this->Strength;
	getline(inFile, temp, '\t');
	inFile >> value;
	getline(inFile, temp, '\t');			//nhap Amor
	inFile >> this->Amor;
}

void ClassHorseman::outputHero() {
	ClassHero::outputHero();
	cout << "Strength\t" << this->Strength << endl;
	cout << "Intelligent\t0" << endl;
	cout << "Amor\t" << this->Amor << endl;
}

int ClassHorseman::getDame() {
	return this->Strength;
}

void ClassHorseman::setDame(int dame) {
	this->Strength = dame;
}

void ClassHorseman::attack(int& healthPlayerB, int amorPlayerB) {
	ClassHero::attack(healthPlayerB, amorPlayerB);
	healthPlayerB -= this->Strength - amorPlayerB;
}
