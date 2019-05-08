// Массив чисел размера N проинициализировать случайными числами из промежутка от - N до N.Написать функцию циклического сдвига элементов массива вправо на k элементов.
#include <iostream>
#include<time.h>
using namespace std;

void randInitArr(int *A, int N);
void printArray(int*A, int N);
void ShiftArrk(int*A, int N, int k);

int main() 
{
	setlocale(LC_ALL, "Rus");
	int N,k;
	cout << "Введите длину массива: ";
	cin >> N;
	int *A = new int[N];
	if (!A)
	{
		cout << "Ошибка!\n";
		system("pause");
		return 0;
	}
	cout << "Введите кол-во элементов, на которое производится сдвиг: ";
	while (1) {

		cin >> k;
		if (k < 0)
			cout << "Введите положительное число!\n";
		else break;
	}
	randInitArr(A, N);
	printArray(A, N);
	ShiftArrk(A,N,k);
	printArray(A, N);
	delete[] A;
	A = nullptr;
	system("pause");
}
void randInitArr(int *A, int N)
{
	srand(time(0));
	for (int i = 0; i < N; ++i) 
	{
		*(A + i)= rand() % (2 * N) - N;
	}
}
void printArray(int*A, int N) {
	for (int i = 0; i < N; i++)
		cout << *(A + i) << ' ';
	cout << '\n';
}
void reverseArr(int *A, int beg, int end) {
	while (beg < end)
		swap(*(A + beg++), *(A + end--));
}
void ShiftArrk(int*A, int N, int k)
{
	reverseArr(A, N - k, N - 1);
	reverseArr(A, 0, N - 1 - k);
	reverseArr(A, 0, N - 1);
}