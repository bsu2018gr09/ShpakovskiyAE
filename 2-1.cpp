#include <iostream>
#include <iomanip>
using namespace std;
int** giveMemory(int N, int M);
void initArr(int **p, int N, int M);
int mainFunc(int **p, int N, int M);
void printArr(int **p, int N, int M);
void freeMemory(int **p, int N);

int main()
{/*В массиве А(N,М) часть строк состоит из нулей. удалить нулевые строки.*/
	setlocale(LC_ALL, "rus");
	int N, M;
	cout << "Введите количество строк и столбцов: ";
	cin >> N >> M;
	int **A = giveMemory(N, M);
	cout << "Заполните массив: " << '\n';
	initArr(A, N, M);
	N = mainFunc(A, N, M);
	printArr(A, N, M);
	freeMemory(A, N);
	system("pause");
}
int** giveMemory(int N, int M) {
	int** p = new(nothrow) int*[N];
	for (int i = 0; i < N; ++i) {
		int* p1 = new(nothrow) int[M];
		p[i] = p1;
	}
	return p;
}
void initArr(int** p, int N, int M) {
	for (int i = 0; i < N; i++) {
		int* p1 = p[i];
		for (int j = 0; j < M; j++) {
			cin >> p1[j];
		}
	}
}
void printArr(int** p, int N, int M) {
	for (int i = 0; i < N; i++) {
		int* p1 = p[i];
		for (int g = 0; g < M; g++) {
			cout << setw(5) << p1[g];
		}
		cout << '\n';
	}
	cout << '\n';
}
void freeMemory(int** p, int N) {
	for (int i = 0; i < N; i++) {
		p[i] = nullptr;
	}
	delete[]p;
}
int mainFunc(int **p, int N, int M)
{
	bool flag(1);
	for (int j = 0; j< N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			if (p[j][i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			for (int k = j; k < N - 1; k++)
			{
				for (int l = 0; l < M; l++)
				{
					p[k][l] = p[k + 1][l];
				}
			}
			--N;
		}
		flag = 1;
	}
	return N;
}