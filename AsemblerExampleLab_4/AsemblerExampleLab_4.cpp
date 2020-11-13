#include <iostream>
#include <stdio.h>
#include <cstdlib>

//MAKE C++(NOT C)///

using namespace std;
int main()
{
	unsigned char a=0, b=0, c=0, d=0, e=0, f=0;
	//x=int(x); прямое приведение к типу инт если так не сделать то будем работать с символами,
	// ибо char это символьный тип данных
	cout << "Insert a" << endl; // cout = printf, endl = \n
	cin >> a; a = int(a); // cin = scanf 
	cout << "Insert b" << endl;
	cin >> b; b = int(b);
	cout << "Insert c" << endl;
	cin >> c; c = int(c);
	cout << "Insert d" << endl;
	cin >> d; d = int(d);
	cout << "Insert e" << endl;
	cin >> e; e = int(e);
	cout << "Insert f" << endl;
	cin >> f; f = int(f);
	signed char res_asm;;
	signed char answer=	b + c + d - (a + 4) - (e + 1) + f;

	_asm {
		//окончание l или x значит 8 бит
		
		mov bl, [b]; // mov присвоить
		add bl, [c]; // добавить
		add bl, [d]; 
		mov al, [a]; 
		add al , 4;
		sub al, e+1; // отнять
		sub bl, al;
		add bl, [f];
		mov res_asm, al;
		//ещё может быть neg(умножить на -1), imul (умножить) idiv(поделить)
	}
	cout << "Answer from Asembler " << int(res_asm) << endl;
	cout << "Answer from C++ " << int(answer)<< endl;
	
}