#include <iostream>
#include "Array.h"
#include "Functor.h"
#include <time.h>
#include <Windows.h>

template<typename T>
Array returnDynamicArray(T arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = -10 + rand() % int(10 - (-10) + 1);
	}

	Array dynamicArray = Array(size);

	for (int i = 0; i < size; i++)
		dynamicArray[i] = arr[i];
	return dynamicArray;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	const int size = 5;
	
	double a[size], b[size], c[size], d[size], e[size], f[size], g[size];

	Array DynamicA = returnDynamicArray(a, size);
	Array DynamicB = returnDynamicArray(b, size);
	Array DynamicC = returnDynamicArray(c, size);
	Array DynamicD = returnDynamicArray(d, size);
	Array DynamicE = returnDynamicArray(e, size);
	Array DynamicF = returnDynamicArray(f, size);
	Array DynamicG = returnDynamicArray(g, size);

	cout << "Початкові послідовності:" << endl;
	cout << "A: "; DynamicA.print();
	cout << "B: "; DynamicB.print();
	cout << "C: "; DynamicC.print();
	cout << "D: "; DynamicD.print();
	cout << "E: "; DynamicE.print();
	cout << "F: "; DynamicF.print();
	cout << "G: "; DynamicG.print();

	Predicate<double>* zero = new Zero<double>();
	Predicate<double>* positive = new Positive<double>();
	Predicate<double>* negative = new Negative<double>();
	Predicate<double>* even = new Even<double>();
	Predicate<double>* odd = new Odd<double>();

	cout << "Замінимо послідовність A на B" << endl;
	cout << "A: "; DynamicA.print();
	cout << "B: "; DynamicB.print();
	replace_copy(DynamicB.begin(), DynamicB.end(), &DynamicA[0]);
	cout << "Готово:" << endl;
	cout << "A: "; DynamicA.print();

	cout << "Замінимо тільки нульві елементи послідовності B на C" << endl;
	cout << "B: "; DynamicB.print();
	cout << "С: "; DynamicC.print();
	replace_copy_if(DynamicC.begin(), DynamicC.end(), &DynamicB[0], *zero);
	cout << "Готово:" << endl;
	cout << "B: "; DynamicB.print();

	cout << "Замінимо тільки додатні елементи послідовності С на D" << endl;
	cout << "C: "; DynamicC.print();
	cout << "D: "; DynamicD.print();
	replace_copy_if(DynamicD.begin(), DynamicD.end(), &DynamicC[0], *positive);
	cout << "Готово:" << endl;
	cout << "C: "; DynamicC.print();

	cout << "Замінимо тільки від'ємні елементи послідовності D на E" << endl;
	cout << "D: "; DynamicD.print();
	cout << "E: "; DynamicE.print();
	replace_copy_if(DynamicE.begin(), DynamicE.end(), &DynamicD[0], *negative);
	cout << "Готово:" << endl;
	cout << "D: "; DynamicD.print();

	cout << "Замінимо тільки парні елементи послідовності E на F" << endl;
	cout << "E: "; DynamicE.print();
	cout << "F: "; DynamicF.print();
	replace_copy_if(DynamicF.begin(), DynamicF.end(), &DynamicE[0], *even);
	cout << "Готово:" << endl;
	cout << "E: "; DynamicE.print();

	cout << "Замінимо тільки непарні елементи послідовності F на G" << endl;
	cout << "F: "; DynamicF.print();
	cout << "G: "; DynamicG.print();
	replace_copy_if(DynamicG.begin(), DynamicG.end(), &DynamicF[0], *odd);
	cout << "Готово:" << endl;
	cout << "F: "; DynamicF.print();

	system("pause");
	return 0;
}