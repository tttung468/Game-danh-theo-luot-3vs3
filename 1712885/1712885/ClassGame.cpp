#include "ClassGame.h"

ClassGame::ClassGame() {

}

ClassGame::~ClassGame() {
	heroList.clear();
	heroListA.clear();
	heroListB.clear();
}

void ClassGame::inputHeroList() {
	ClassHero* hero;
	string temp;		//lưu chuỗi không cần thiết
	string element;		//lưu nguyên tố của hero (5 nguyên tố)
	string typeHero;	//lưu loại tộc của hero	(Horseman, Witch, Archer)

	fstream inFile("ListHero.txt");

	while (1) {
		getline(inFile, temp, '\t');
		getline(inFile, element, '\n');
		getline(inFile, temp, '\t');
		getline(inFile, typeHero, '\n');

		if (inFile.eof())
			break;

		if (element == "Earth" && typeHero == "Horseman") {
			hero = new ClassEarthHorseman();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
		else if (element == "Earth" && typeHero == "Witch") {
			hero = new ClassEarthWitch();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
		else if (element == "Fire" && typeHero == "Witch") {
			hero = new ClassFireWitch();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
		else if (element == "Fire" && typeHero == "Archer") {
			hero = new ClassFireArcher();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
		else if (element == "Metal" && typeHero == "Horseman") {
			hero = new ClassMetalHorseman();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
		else if (element == "Metal" && typeHero == "Archer") {
			hero = new ClassMetalArcher();
			hero->inputHero(inFile);
			heroList.push_back(hero);
		}
	}

	inFile.close();
}

void ClassGame::outputHeroListSide(char team) {
	if (team == 'A') {
		for (int i = 0; i < heroListA.size(); ++i) {
			heroListA[i]->outputHero();
			cout << endl;
		}
	}
	else if (team == 'B') {
		for (int i = 0; i < heroListB.size(); ++i) {
			heroListB[i]->outputHero();
			cout << endl;
		}
	}
}

void ClassGame::outputHeroesName() {

	for (int i = 0; i < heroList.size(); ++i) {
		cout << i + 1 << ") " << heroList[i]->getName() << endl;
	}
}

void ClassGame::attackHeroAHeroB(ClassHero*& heroA, ClassHero*& heroB) {
	int agiPlayerA = heroA->getAgility();
	int healthPlayerA = heroA->getHealth();
	int amorPlayerA = heroA->getAmor();

	int agiPlayerB = heroB->getAgility();
	int healthPlayerB = heroB->getHealth();
	int amorPlayerB = heroB->getAmor();

	if (agiPlayerA > agiPlayerB)			//A có agility cao -> A đánh trước	
	{
		if (heroA->checkMana() == true) {					//A có đủ mana thì mới được đánh
			heroA->attack(healthPlayerB, amorPlayerB);		//A tấn công B
			heroB->setHealth(healthPlayerB);				//cập nhật lại máu của B

			if (heroB->checkHealth() == false) {			//kiểm tra máu của B sau khi đánh
				return;
			}
		}

		if (heroB->checkMana() == true) {					//B có đủ mana thì mới được đánh
			heroB->attack(healthPlayerA, amorPlayerA);		//B tấn công A
			heroA->setHealth(healthPlayerA);				//cập nhật lại máu của A
		}
	}
	else if (agiPlayerA < agiPlayerB)		//B có agility cao -> B đánh trước
	{
		if (heroB->checkMana() == true) {					//B có đủ mana thì mới được đánh
			heroB->attack(healthPlayerA, amorPlayerA);		//B tấn công A
			heroA->setHealth(healthPlayerA);				//cập nhật lại máu của A
			if (heroA->checkHealth() == false) {			//kiểm tra máu của A sau khi đánh
				return;
			}
		}

		if (heroA->checkMana() == true) {
			heroA->attack(healthPlayerB, amorPlayerB);		//A tấn công B
			heroB->setHealth(healthPlayerB);				//cập nhật lại máu của B
		}
	}
	else		//A và B có chỉ số agility bằng nhau
	{
		if (heroA->checkMana() == true) {
			heroA->attack(healthPlayerB, amorPlayerB);		//A tấn công B
			heroB->setHealth(healthPlayerB);				//cập nhật lại máu của B
		}

		if (heroB->checkMana() == true) {
			heroB->attack(healthPlayerA, amorPlayerA);		//B tấn công A
			heroA->setHealth(healthPlayerA);				//cập nhật lại máu của A
		}
	}
}

void ClassGame::attackListAListB() {
	int i = 0;
	int j = 0;


	while (1) {
		//tìm cặp tướng thích hợp để đánh
		while (heroListA[i]->checkHealth() == false) {
			if (i == (heroListA.size() - 1)) {
				i = 0;
			}
			else {
				++i;
			}
		}

		while (heroListB[j]->checkHealth() == false) {
			if (j == (heroListB.size() - 1)) {
				j = 0;
			}
			else {
				++j;
			}
		}

		//tính tương sinh
		ClassGame::tinhTuongSinhCungTeam(i, 'A');
		ClassGame::tinhTuongSinhCungTeam(j, 'B');

		//tính tương khắc cùng team
		ClassGame::tinhTuongKhacCungTeam(i, 'A');
		ClassGame::tinhTuongKhacCungTeam(j, 'B');

		//tính tương khắc khác team
		ClassGame::tinhTuongKhacKhacTeam(i, j);

		//tấn công giữa 2 tướng
		ClassGame::attackHeroAHeroB(heroListA[i], heroListB[j]);

		//kiểm tra team nào có toàn bộ hero chết hết
		if (ClassGame::countHeroesRemainHealth('A') == 0)
			break;
		if (ClassGame::countHeroesRemainHealth('B') == 0)
			break;

		//tìm cặp hero tiếp theo tấn công với nhau, tướng tiếp theo phải còn máu thì mới đc chọn
		++i;
		++j;

		int flagFinish = false;
		for (int temp = i; temp < heroListA.size(); ++temp) {
			if (heroListA[temp]->checkHealth() == true) {
				flagFinish = true;
				break;
			}
		}
		for (int temp = j; temp < heroListB.size(); ++temp) {
			if (heroListB[temp]->checkHealth() == true) {
				flagFinish = true;
				break;
			}
		}

		if (flagFinish == false) {
			break;		//dừng đánh nếu các tướng đều được đánh
		}

		//kiểm tra tất cả tướng của 2 team đều được đánh hay chưa
		if ((i >= heroListA.size()) || (j >= heroListB.size())) {
			break;
		}
	}
}

bool ClassGame::checkHeroInList(string name) {
	for (int i = 0; i < heroList.size(); ++i) {
		if (name == heroList[i]->getName()) {
			return true;
		}
	}
	return false;
}

int ClassGame::countHeroesRemainHealth(char team) {
	int count = 0;

	if (team == 'A') {
		for (int i = 0; i < heroListA.size(); ++i) {
			if (heroListA[i]->checkHealth() == true) {
				++count;
			}
		}
	}
	else if (team == 'B') {
		for (int i = 0; i < heroListB.size(); ++i) {
			if (heroListB[i]->checkHealth() == true) {
				++count;
			}
		}
	}
	return count;
}

int ClassGame::countHeroesRemainMana(char team) {
	int count = 0;

	if (team == 'A') {
		for (int i = 0; i < heroListA.size(); ++i) {
			if ((heroListA[i]->checkMana() == true) && (heroListA[i]->checkHealth() == true)) {
				++count;
			}
		}
	}
	else if (team == 'B') {
		for (int i = 0; i < heroListB.size(); ++i) {
			if ((heroListB[i]->checkMana() == true) && (heroListB[i]->checkHealth() == true)) {
				++count;
			}
		}
	}
	return count;
}

ClassHero* ClassGame::initHero(string name) {
	string ID;			//xác định ID từ name cho trước
	ClassHero* hero = NULL;

	//xem tướng được chọn thuộc tộc và loại hero nào
	for (int i = 0; i < heroList.size(); ++i) {
		if (name == heroList[i]->getName()) {
			ID = heroList[i]->getID();		//lấy ID để xác định tộc và loại

			//khởi tạo hero theo tộc và loại tương ứng
			if (ID[3] == 'E' && ID[4] == 'H') {
				hero = new ClassEarthHorseman();
			}
			else if (ID[3] == 'E' && ID[4] == 'W') {
				hero = new ClassEarthWitch();
			}
			else if (ID[3] == 'F' && ID[4] == 'W') {
				hero = new ClassFireWitch();
			}
			else if (ID[3] == 'F' && ID[4] == 'A') {
				hero = new ClassFireArcher();
			}
			else if (ID[3] == 'M' && ID[4] == 'H') {
				hero = new ClassMetalHorseman();
			}
			else if (ID[3] == 'M' && ID[4] == 'A') {
				hero = new ClassMetalArcher();
			}

			//sao chép lại các thuộc tính
			hero->setID(heroList[i]->getID());
			hero->setName(heroList[i]->getName());
			hero->setHealth(heroList[i]->getHealth());
			hero->setMana(heroList[i]->getMana());
			hero->setAgility(heroList[i]->getAgility());
			hero->setAmor(heroList[i]->getAmor());
			hero->setDame(heroList[i]->getDame());
			break;
		}
	}

	return hero;
}

void ClassGame::chooseHeroForList(char team) {
	string name;		//biến để lấy tên Hero muốn thêm vào team
	ClassHero* hero;	//biến để khởi tạo 1 hero và gán vào HeroList
	vector<ClassHero*> HeroListTemp;	//List hình nộm tùy thuộc vào lựa chọn side, 'A': HeroListA, 'B': HeroListB

	for (int i = 1; i <= 3; ++i) {
		cout << i << ") ";
		cin >> name;

		if (ClassGame::checkHeroInList(name) == true) {
			hero = ClassGame::initHero(name);
			HeroListTemp.push_back(hero);
		}
		else {
			cout << "Hero khong co trong danh sach duoc su dung. Moi ban nhap lai !!!" << endl;
			--i;
		}
	}

	if (team == 'A') {
		heroListA = HeroListTemp;
	}
	else if (team == 'B') {
		heroListB = HeroListTemp;
	}

	HeroListTemp.clear();
}

void ClassGame::tinhTuongSinhCungTeam(int i, char team) {
	if (team == 'A') {
		if (i == 0) {
			if (heroListA[i + 1]->checkHealth() == true) {
				heroListA[i]->tuongSinh(heroListA[i + 1]);
			}
		}
		else if (i == 1) {
			if (heroListA[i - 1]->checkHealth() == true) {
				heroListA[i]->tuongSinh(heroListA[i - 1]);
			}
			if (heroListA[i + 1]->checkHealth() == true) {
				heroListA[i]->tuongSinh(heroListA[i + 1]);
			}
		}
		else if (i == 2) {
			if (heroListA[i - 1]->checkHealth() == true) {
				heroListA[i]->tuongSinh(heroListA[i - 1]);
			}
		}
	}
	else if (team == 'B') {
		if (i == 0) {
			if (heroListB[i + 1]->checkHealth() == true) {
				heroListB[i]->tuongSinh(heroListB[i + 1]);
			}
		}
		else if (i == 1) {
			if (heroListB[i - 1]->checkHealth() == true) {
				heroListB[i]->tuongSinh(heroListB[i - 1]);
			}
			if (heroListB[i + 1]->checkHealth() == true) {
				heroListB[i]->tuongSinh(heroListB[i + 1]);
			}
		}
		else if (i == 2) {
			if (heroListB[i - 1]->checkHealth() == true) {
				heroListB[i]->tuongSinh(heroListB[i - 1]);
			}
		}
	}
}

void ClassGame::tinhTuongKhacCungTeam(int i, char team) {
	if (team == 'A') {
		if (i == 0) {
			if (heroListA[i + 1]->checkHealth() == true) {
				heroListA[i]->tuongKhac(heroListA[i + 1], 'S');
			}
		}
		else if (i == 1) {
			if (heroListA[i - 1]->checkHealth() == true) {
				heroListA[i]->tuongKhac(heroListA[i - 1], 'S');
			}
			if (heroListA[i + 1]->checkHealth() == true) {
				heroListA[i]->tuongKhac(heroListA[i + 1], 'S');
			}
		}
		else if (i == 2) {
			if (heroListA[i - 1]->checkHealth() == true) {
				heroListA[i]->tuongKhac(heroListA[i - 1], 'S');
			}
		}
	}
	else if (team == 'B') {
		if (i == 0) {
			if (heroListB[i + 1]->checkHealth() == true) {
				heroListB[i]->tuongKhac(heroListB[i + 1], 'S');
			}
		}
		else if (i == 1) {
			if (heroListB[i - 1]->checkHealth() == true) {
				heroListB[i]->tuongKhac(heroListB[i - 1], 'S');
			}
			if (heroListB[i + 1]->checkHealth() == true) {
				heroListB[i]->tuongKhac(heroListB[i + 1], 'S');
			}
		}
		else if (i == 2) {
			if (heroListB[i - 1]->checkHealth() == true) {
				heroListB[i]->tuongKhac(heroListB[i - 1], 'S');
			}
		}
	}
}

void ClassGame::tinhTuongKhacKhacTeam(int i, int j) {
	heroListA[i]->tuongKhac(heroListB[j], 'D');
	heroListB[i]->tuongKhac(heroListA[j], 'D');
}

void ClassGame::resultMatch() {
	int countHeroListA = 0;		//đếm số lượng hero còn máu trong team A
	int countHeroListB = 0;		//đếm số lượng hero còn máu trong team B

	for (int i = 0; i < heroListA.size(); ++i) {
		if (heroListA[i]->checkHealth() == true) {
			++countHeroListA;
		}
	}
	for (int i = 0; i < heroListB.size(); ++i) {
		if (heroListB[i]->checkHealth() == true) {
			++countHeroListB;
		}
	}

	//so sánh số lượng hero giữa 2 team và đưa ra kết quả
	if (countHeroListA == countHeroListB) {
		cout << "\nKet qua tran dau :Hoa (" << countHeroListA << ":" << countHeroListB << ")" << endl;
	}
	else if (countHeroListA > countHeroListB) {
		cout << "\nKet qua tran dau :Team A thang (" << countHeroListA << ":" << countHeroListB << ")" << endl;
		ClassGame::outputHeroListSide('A');
	}
	else if (countHeroListA < countHeroListB) {
		cout << "\nKet qua tran dau :Team B thang (" << countHeroListA << ":" << countHeroListB << ")" << endl;
		ClassGame::outputHeroListSide('B');
	}

}

void ClassGame::match() {
	ClassGame::inputHeroList();		//nhập danh sách các hero được sử dụng

	cout << "Danh sach cac hero duoc su dung trong tran dau:" << endl;
	ClassGame::outputHeroesName();

	cout << "\n\nChon 3 hero cho team ben phai san dau, moi nhap ten:" << endl;
	ClassGame::chooseHeroForList('A');	//chọn hero cho sân đấu bên trái 
	cout << "\n\nChon 3 hero cho team ben trai san dau, moi nhap ten:" << endl;
	ClassGame::chooseHeroForList('B');	//chọn hero cho sân đấu bên phải

	//điều khiển cho 2 team đánh nhau
	int countHealthListA = 0;
	int countHealthListB = 0;
	int countManaListA = 0;
	int countManaListB = 0;

	while (1) {
		//kiểm tra điều kiện trận đấu bắt đầu, 2 team đều có hero còn máu và cả 2 team đều có hero còn mana
		countHealthListA = ClassGame::countHeroesRemainHealth('A');
		countHealthListB = ClassGame::countHeroesRemainHealth('B');
		countManaListA = ClassGame::countHeroesRemainMana('A');
		countManaListB = ClassGame::countHeroesRemainMana('B');

		if ((countHealthListA == 0) || (countHealthListB == 0) || (countManaListA == 0 && countManaListB == 0)) {
			break;
		}

		//tấn công giữa 2 team
		ClassGame::attackListAListB();
	}

	ClassGame::resultMatch();
}
