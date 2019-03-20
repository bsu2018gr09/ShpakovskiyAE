/*Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.*/
#include<iostream>
#include <time.h>
using namespace std;
void fillArr(int*A, int N);
void freeMemory(int*A);
int *InitArr(int N) {
	int *A = new int[N];
	return A;
}
void printArr(int*A, int N);
void primeNumSort(int*A, int N);
bool isPrime(int a);
int main() {

	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество элементов в массиве: ";
	cin >> N;
	int*A = InitArr(N);
	cout << "Заполните массив: ";
	fillArr(A, N);
	primeNumSort(A, N);
	cout << '\n';
	printArr(A, N);
	freeMemory(A);
	system("pause");
}
void freeMemory(int*A)
{
	delete[]A;
}
void fillArr(int*A, int N)
{
	for (int i = 0;i < N;i++)
		cin >> *(A + i);
}
void printArr(int*A, int N)
{
	for (int i = 0;i < N;i++)
		cout << *(A + i) << '\n';
}
bool isPrime(int a)
{
	if (a <= 1)
		return false;
	if (a == 2)
		return true;
	for (int i = 2;i <= sqrt(a);i++)
	{
		if (a % i == 0)
			return false;
	}
		return true;
}
void primeNumSort(int*A, int N) 
{
		for (int i = 0; i < N; i++)
		{
				if (isPrime(*(A+i)))
				{
					for (int j = 0; j < N ; j++)
					{if(isPrime(*(A + j))&& *(A + i)< *(A + j))
						swap(*(A + i), *(A + j));
					}
				}
		}
}