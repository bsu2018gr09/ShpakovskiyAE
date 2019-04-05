/*Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.
 Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.*/
#include<iostream>
using namespace std;
void fillArr(int*A, int N);
void freeMemory(int*A);
int *InitArr(int N) {
	int *A = new int[N];//нет проверки
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
	delete[]A;//нет nullptr
}
void fillArr(int*A, int N)
{
	for (int i = 0;i < N;i++)
		cin >> *(A + i);
}
void posNegSort(int*A, int N)
{
	int k{ 0 };
	for (int i = N-1;i >=0;i--)
	{
		if (*(A + i) >= 0)
			swap(*(A + i), *(A + N - 1 - k++));
	} 
	for (int i = 0; i < N - 1-k; i++)
	{
		for (int j = 0; j < N - i - 1-k; j++)
		{
			if (*(A + j) < *(A + j + 1))
				swap(*(A + j), *(A + j + 1));//очень наивная сортировка без малейшей оптимизации  
		}
	}
}
void printArr(int*A, int N)
{
	for (int i = 0;i < N;i++)
		cout << *(A + i) << '\n';
}
