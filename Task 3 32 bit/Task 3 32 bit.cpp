#include <iostream>
#include <stdio.h>
#include <cstdlib>

//MAKE C++(NOT C)///

using namespace std;
int main() {
	int a = 0, b = 0, c = 0, d = 0, E = 0, f = 0;
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
	int res_asm;
	int answer = b + c + d - (a + 4) - (E + 1) + f;
	E = E + 1;
	_asm {
		//окончание x значит 16 бит
		mov ebx, [b]; // mov присвоить
		add ebx, [c]; // добавить
		add ebx, [d];
		mov eax, [a];
		add eax, 4;
		sub eax, E; // отнять
		sub ebx, eax;
		add ebx, [f];
		mov res_asm, eax;
		//ещё может быть neg(умножить на -1), imul (умножить) idiv(поделить)
	}
	cout << "Answer from Asembler " << res_asm << endl;
	cout << "Answer from C++ " << answer << endl;
	//разность из за того, что асемблер использует беззнаковую модель
}