/*Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа).
	Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.*/
#include <iostream> 
#include <time.h> 
#include <iomanip>
using namespace std;
void randomArr(int*A, int N, int left, int right);
void freeMemory(int*A);
void pointAndLineDistCalc(int*X, int*Y, int*D, int N, int a, int b, int c);
void bubbleSort(int*X, int*Y, int*D, int N);
void printArrays(int*A, int*B,int*D, int N);
int *InitArr(int N) {
	int *A = new int[N];
	if (!A)
	{
		cout << "Ошибка!\n";
		system("pause");
		return 0;
	}
	return A;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int N, a, b, c;
	cin >> N;
	cout << "Введите коэффициенты а, b, c в уравнении прямой ax+by+c=0" << '\n';
	cin >> a>>b>>c;
	int *X= InitArr(N);
	int *Y = InitArr(N);
	randomArr(X, N, -N / 2, N / 2);	
	randomArr(Y, N, -N / 2, N / 2);
	int *D = InitArr(N);
	pointAndLineDistCalc(X, Y, D, N, a, b, c);
	bubbleSort(X,Y,D, N);
	printArrays(X, Y,D, N);
	freeMemory(X);
	freeMemory(Y);
	freeMemory(D);
	system("pause");
}
void randomArr(int*A, int N, int left, int right) {
	if (!A) {
		cout << "error";
		system("pause");
	}
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % (left - right) + left;
	}
}
void freeMemory(int*A)
{
	delete[]A;
	A=nullptr;
}
void pointAndLineDistCalc(int*X, int*Y,int*D, int N,int a,int b,int c)
{
	int m = sqrt(a*a + b * b);
	for (int i = 0;i < N;i++)
	{
		*(D + i) = abs(a**(X + i)+b**(Y + i)+c)/m;
	}
}
void bubbleSort(int*X, int*Y, int*D,int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++) 
		{
			if (*(D+j) > *(D+j+1))
			{
				swap(*(X + j), *(X + j + 1));
				swap(*(Y + j), *(Y + j + 1));
				swap(*(D + j), *(D + j + 1));
			}
		}
	}
	
}
void printArrays(int*A,int*B,int*D, int N) {
	for (int i = 0;i < N;i++)
		cout <<'('<< *(A + i)<<',' <<*(B+i)<<')' << setw(5) <<*(D+i) << '\n';
}
