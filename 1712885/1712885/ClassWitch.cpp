#include "ClassWitch.h"

ClassWitch::ClassWitch() {
	this->Intelligent = 0;
}

ClassWitch::~ClassWitch() {

}

void ClassWitch::inputHero(fstream& inFile) {
	string temp;
	int value;

	ClassHero::inputHero(inFile);
	getline(inFile, temp, '\t');
	inFile >> value;
	getline(inFile, temp, '\t');			//nhap Intelligent
	inFile >> this->Intelligent;
	getline(inFile, temp, '\t');			//nhap Amor
	inFile >> this->Amor;
}

void ClassWitch::outputHero() {
	ClassHero::outputHero();
	cout << "Strength\t0" << endl;
	cout << "Intelligent\t" << this->Intelligent << endl;
	cout << "Amor\t" << this->Amor << endl;
}

int ClassWitch::getDame() {
	return this->Intelligent;
}

void ClassWitch::setDame(int dame) {
	this->Intelligent = dame;
}

void ClassWitch::attack(int& healthPlayerB, int amorPlayerB) {
	ClassHero::attack(healthPlayerB, amorPlayerB);
	healthPlayerB -= this->Intelligent - amorPlayerB;
}
