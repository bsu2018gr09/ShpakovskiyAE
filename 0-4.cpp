#include<iostream>
#include<time.h>
using namespace std;
void randInitArr(int *A, int N, int left, int right);
void bubbleSort(int*D, int k, int N);
void printArray(int*A, int N);
int main()
{
	setlocale(LC_ALL, "Rus");
	int N, k{ 0 }, left, right;
	cout << "Введите длину массива: ";
	cin >> N;
	cout << "Введите элемент начала сортировки: ";
	cin >> k;
	int *A = new int[N];
	if (!A)
	{
		cout << "Ошибка!\n";
		system("pause");
		return 0;
	}
	cout << "Введите левую и правую границу заполнения: ";
	cin >> left >> right;
	randInitArr(A, N, left, right);
	bubbleSort(A, k, N);
	printArray(A, N);
	delete[] A;
	A = nullptr;
	system("pause");
}
void randInitArr(int *A, int N, int left, int right)
{
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % (right - left) + left;
	}
}
void bubbleSort(int*D, int k, int N)
{
	for (int i = k; i < N; i++)
	{
		for (int j = k; j < N - 1; j++)
		{
			if (*(D + j) > *(D + j + 1))
			{
				swap(*(D + j), *(D + j + 1));
			}
		}
	}

}
void printArray(int*A, int N) {
	for (int i = 0; i < N; i++)
		cout << *(A + i) << ' ';
}