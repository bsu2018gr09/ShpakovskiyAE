/*В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.*/
#include<iostream>
#include<time.h>
using namespace std;
void randInitArrFrom0To10(int *A, int N);
int findingRepeatingElements(int *A, int N);
void printArray(int*A, int N);
int main()
{
	setlocale(LC_ALL, "Rus");
	int N;
	cout << "Введите длину массива: ";
	cin >> N;
	int *A = new int[N];
	if (!A)
	{
		cout << "Ошибка!\n";
		system("pause");
		return 0;
	}
	randInitArrFrom0To10(A, N);
	printArray(A, N);
	cout<<'\n'<<"Максимальная длина последовательности равных элементов: "<<findingRepeatingElements(A, N);
	delete[] A;
	A = nullptr;
	system("pause");
}
void randInitArrFrom0To10(int *A, int N)
{
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		*(A + i) = rand() % 10;
	}
}
void printArray(int*A, int N) {
	for (int i = 0; i < N; i++)
		cout << *(A + i) << ' ';
}
int findingRepeatingElements(int *A, int N)
{
	int k = 0, kmax = 0;
	for (int i = 1; i < N; i++)
	{
		if (*(A + i) == *(A + i - 1))
			++k;
		else
		{
			if (k >= kmax)
			{
				kmax = k;
			}
			k = 0;
		}

	}
	if (k >= kmax)
	{
		kmax = k;
	}
	return kmax+1;

}
