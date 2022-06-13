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

	cout << "�������� �����������:" << endl;
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

	cout << "������� ����������� A �� B" << endl;
	cout << "A: "; DynamicA.print();
	cout << "B: "; DynamicB.print();
	replace_copy(DynamicB.begin(), DynamicB.end(), &DynamicA[0]);
	cout << "������:" << endl;
	cout << "A: "; DynamicA.print();

	cout << "������� ����� ����� �������� ����������� B �� C" << endl;
	cout << "B: "; DynamicB.print();
	cout << "�: "; DynamicC.print();
	replace_copy_if(DynamicC.begin(), DynamicC.end(), &DynamicB[0], *zero);
	cout << "������:" << endl;
	cout << "B: "; DynamicB.print();

	cout << "������� ����� ������ �������� ����������� � �� D" << endl;
	cout << "C: "; DynamicC.print();
	cout << "D: "; DynamicD.print();
	replace_copy_if(DynamicD.begin(), DynamicD.end(), &DynamicC[0], *positive);
	cout << "������:" << endl;
	cout << "C: "; DynamicC.print();

	cout << "������� ����� ��'��� �������� ����������� D �� E" << endl;
	cout << "D: "; DynamicD.print();
	cout << "E: "; DynamicE.print();
	replace_copy_if(DynamicE.begin(), DynamicE.end(), &DynamicD[0], *negative);
	cout << "������:" << endl;
	cout << "D: "; DynamicD.print();

	cout << "������� ����� ���� �������� ����������� E �� F" << endl;
	cout << "E: "; DynamicE.print();
	cout << "F: "; DynamicF.print();
	replace_copy_if(DynamicF.begin(), DynamicF.end(), &DynamicE[0], *even);
	cout << "������:" << endl;
	cout << "E: "; DynamicE.print();

	cout << "������� ����� ������ �������� ����������� F �� G" << endl;
	cout << "F: "; DynamicF.print();
	cout << "G: "; DynamicG.print();
	replace_copy_if(DynamicG.begin(), DynamicG.end(), &DynamicF[0], *odd);
	cout << "������:" << endl;
	cout << "F: "; DynamicF.print();

	system("pause");
	return 0;
}