#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;
const int n = 4;
int gun = 0;
char Game[n][n];
int ships = 0;

int** create(int hard) {
	int **A;
	A = new int *[n]; //создание массива указателей
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			A[i][j] = rand() % 2;
			if (A[i][j] == 1) {
				gun++;
			}
		}
	}
	ships = gun;
	switch (hard) {
	case 1:   // сложность легко
		gun += 4;
		break;
	case 2:   // сложность средне
		gun += 2;
		break;
	}
	

	return A;
}

void fire(int** A) {
	int x, y;
	cout << "Введите координаты выстрела (по горизонтали-х; по горизонтали-у)" << endl;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;
	cout << endl;

	if (A[x-1][y-1] == 0){
		cout << "Промах ";
		Game[x-1][y-1] = '0';
	}
	else {
		cout << "Убит ";
		Game[x - 1][y - 1] = 'X';
		ships --;
	}
	
	gun--;
	cout << "осталось " << ships << " кораблей" << endl;
	cout << "у вас осталось " << gun << " выстрелов" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Game[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Game[i][j] = '—';
		}
	}
	int sloj;
	cout << "Введите уровень сложности (1-легко; 2-средне; 3-сложно)" << endl;
	cin >> sloj;
	cout << endl;
	int** Matrix = create(sloj);

	while (gun != 0) {
		fire(Matrix);
	}
	if (ships == 0) {
		cout << "You win!!!" << endl;
	}
	else {
		cout << "Game Over" << endl;
	}

}

