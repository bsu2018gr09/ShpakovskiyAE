/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
 Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
#include<iostream>
using namespace std;
void fillArr(int*A, int N);
void freeMemory(int*A);
int *InitArr(int N) {
	int *A = new int[N];
	if (!A)
		cout << "error";
	return A;
}
void posNegSort(int*A, int N);
void printArr(int*A, int N);
int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите кол-во элементов в массиве: ";
	cin >> N;
	int *A = InitArr(N);
	cout << '\n' << "Заполните массив" << '\n';
	fillArr(A, N);
	posNegSort(A, N);
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
void posNegSort(int*A, int N)
{
	int flag{ 0 };
	int k{ 0 };
	for (int i = N-1;i >=0;i--)
	{
		if (*(A + i) >= 0)
			swap(*(A + i), *(A + N - 1 - k++));
	} 
	for (int i = 0; i < N; ++i) {
		flag = 0;
		for (int j = 0; j < N; ++j) {
			if (*(A + j) < *(A + j + 1)) {
				if (*(A + j + 1) <= 0) {
					swap(*(A + j), *(A + j + 1));
					flag = 1;
				}
			}
		}
		if (!flag)
			break;
	}
}
void printArr(int*A, int N)
{
	for (int i = 0;i < N;i++)
		cout << *(A + i) << '\n';
}