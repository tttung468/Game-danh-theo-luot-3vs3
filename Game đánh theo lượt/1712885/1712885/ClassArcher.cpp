#include "ClassArcher.h"

ClassArcher::ClassArcher() {

}

ClassArcher::~ClassArcher() {

}

void ClassArcher::inputHero(fstream& inFile) {
	string temp;
	int value;

	ClassHero::inputHero(inFile);
	getline(inFile, temp, '\t');
	inFile >> value;
	getline(inFile, temp, '\t');
	inFile >> value;
	getline(inFile, temp, '\t');			//nhap Amor
	inFile >> this->Amor;
}

void ClassArcher::outputHero() {
	ClassHero::outputHero();
	cout << "Strength\t0" << endl;
	cout << "Intelligent\t0" << endl;
	cout << "Amor\t" << this->Amor << endl;
}

int ClassArcher::getDame() {
	return this->Agility;
}

void ClassArcher::setDame(int dame) {
	this->Agility = dame;
}

void ClassArcher::attack(int& healthPlayerB, int amorPlayerB) {
	ClassHero::attack(healthPlayerB, amorPlayerB);
	healthPlayerB -= this->Agility - amorPlayerB;
}