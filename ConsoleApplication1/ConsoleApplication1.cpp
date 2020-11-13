#include <iostream>
#include <stdio.h>
#include <cstdlib>

//MAKE C++(NOT C)///

using namespace std;
int main(){
	short int a = 0, b = 0, c = 0, d = 0, E = 0, f = 0;
	cout << "Insert a" << endl; // cout = printf, endl = \n
	cin >> a;  // cin = scanf 
	cout << "Insert b" << endl;
	cin >> b; 
	cout << "Insert c" << endl;
	cin >> c;
	cout << "Insert d" << endl;
	cin >> d;
	cout << "Insert e" << endl;
	cin >> E; 
	cout << "Insert f" << endl;
	cin >> f; 
	short int res_asm;
	short int answer = b + c + d - (a + 4) - (E + 1) + f;
	E = E + 1;
	_asm {
		//окончание x значит 16 бит
		mov bx, [b]; // mov присвоить
		add bx, [c]; // добавить
		add bx, [d];
		mov ax, [a];
		add ax, 4;
		sub ax, E; // отнять
		sub bx, ax;
		add bx, [f];
		mov res_asm, ax;
		//ещё может быть neg(умножить на -1), imul (умножить) idiv(поделить)
	}
	cout << "Answer from Asembler " << (short int)res_asm << endl;
	cout << "Answer from C++ " << (short int) answer << endl;
	//разность из за того, что асемблер использует беззнаковую модель
}