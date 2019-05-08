/*В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.*/
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
	cout << '\n' << "Количество элементов, встречающихся более одного раза: " << findingRepeatingElements(A, N)<<'\n';
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
	int *B = new int[N];
	if (!B)
	{
		cout << "Ошибка!\n";
		system("pause");
		return 0;
	}
	int k = 0,flag=1;
	for (int i = 0; i < N; i++)
	{
		for (int l = 0; l < N; ++l)
		{
			if (*(A + i) == *(B + l))
			{
				flag = 0;
			}
		}
		for (int j = i + 1; j < N; ++j)
		{
			if (!flag)
			{
				flag = 1;
				break;
			}
			if (*(A + i) == *(A + j))
			{
				*(B + k++) = *(A + i);
				break;
			}
		}
	}
		cout << "\nB";
		printArray(B, k);
		delete[] B;
		B = nullptr;
		return k;
}
