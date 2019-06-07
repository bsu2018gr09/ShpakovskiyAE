//Класс треугольник в декартовой прямоугольной с/к
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;
class Triangle {
public:
	Triangle() { cout << "Constructor is working\n"; };// а где инициализация????
	Triangle(float m, float n, float k)// а где инициализация????
	{
		l1 = m; l2 = n; l3 = k;
		if (m + n <= k || m + k <= n || n + k <= m)
		{
			cout << "It's not a triangle"; l1 = 1;l2 = 1;l3 = 1;
		}
	};
	Triangle(float m)// а где инициализация????
	{
		l1 = m;l2 = m;l3 = m;
	}
	~Triangle() { cout << "Destructor is working\n"; };
	void input()
	{
		bool k{ 1 };
		while (k)
		{
			cout << "Enter the lenght of 1st line: ";
			cin >> l1;
			cout << "Enter the lenght of 2nd line: ";
			cin >> l2;
			cout << "Enter the lenght of 3rd line: ";
			cin >> l3;
			k = 0;
			if (l1 + l2 <= l3 || l2 + l3 <= l1 || l1 + l3 <= l2)
			{
				cout << "It's not a triangle"; l1 = 1;l2 = 1;l3 = 1;
			}
		}
	};
	void output()
	{
		cout << "1st side: " << l1 << "\n";
		cout << "2nd side: " << l2 << "\n";
		cout << "3rd side: " << l3 << "\n";
	};
	void setl1(float m)
	{
		if (m + l2 <= l3 || l2 + l3 <= m || m + l3 <= l2) //все время одинаковые проверки по тексту. Может стоит сделать функцию, которая проверяет на существование треугольника????
		{
			cout << "It's not a triangle";
		}
		else
			l1 = m;
	}
	void setl2(float m)
	{
		if (l1 + m <= l3 || m + l3 <= l1 || l1 + l3 <= m)
		{
			cout << "It's not a triangle";
		}
		else
			l2 = m;
	}
	void setl3(float m)
	{
		if (l1 + l2 <= m || l2 + m <= l1 || l1 + m <= l2)
		{
			cout << "It's not a triangle";
		}
		else
			l3 = m;
	}
	float getl1() { return l1; }
	float getl2() { return l2; }
	float getl3() { return l3; }
	float perimeter(float m, float n, float k)
	{
		float p;
		p = m + n + k;
		return p;
	};
	float ploshad(float m, float n, float k)
	{
		float s;
		float p = perimeter(m, n, k) / 2;
		s = sqrt(p*(p - k)*(p - m)*(p - n));
		return s;
	};
	void TriangleType(float m, float n, float k)
	{
		if (m == n && n == k)
		{
			cout << "Ravnostoronniy\n";
			return;
		}
		if (m == sqrt(n*n + k * k) || n == sqrt(m*m + k * k) || k == sqrt(m*m + n * n))
		{
			cout << "Priamougolniy\n";
			return;
		}
		if ((m == n && m != k) || (n == k && n != m) || (k == m && k != n))
		{
			cout << "Ravnobedrenniy\n";
			return;
		}
		cout << "Raznostoronniy";
	}
private:
	float l1, l2, l3;
};

int main()
{
	int N, a, b, c;
	cout << "Number of elements: ";
	cin >> N;
	Triangle abc;
	Triangle* f = new (nothrow) Triangle[N];
	abc.input();
	abc.output();
	cin >> a >> b >> c;
	Triangle mnp(a, b, c);
	cout << "Perimeter: " << mnp.perimeter(a, b, c) << "\nSquare: " << mnp.ploshad(a, b, c) << '\n';
	abc.TriangleType(a, b, c);

	system("pause");
}
