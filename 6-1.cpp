//Класс треугольник в декартовой прямоугольной с/к
#include "pch.h"
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;
class Triangle {
public:
	Triangle(){ cout << "Constructor is working\n"; };
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
	{ ax=x1, ay=y1, bx=x2, by=y2, cx=x3, cy=y3; 
	if ((ax - cx)*(by - cy) == (bx - cx)*(ay - cy))//Проверка лежат ли точки на 1 прямой
	{
		cout << "It's not a triangle"; ax, ay, bx, cy = 0;by, cx = 1;
	}
	};
	~Triangle() { cout << "Destructor is working\n"; };
	void input()
	{
		bool k{ 1 };
		while (k)
		{
			cout << "Enter the x and y coordinates of first point: ";
			cin >> ax >> ay;
			cout << "Enter the x and y coordinates of second point: ";
			cin >> bx >> by;
			cout << "Enter the x and y coordinates of third point: ";
			cin >> cx >> cy;
			k = 0;
			if ((ax - cx)*(by - cy) == (bx - cx)*(ay - cy))
			{
				cout << "It's not a triangle\n";
				k = 1;
			}
		}
	};
	void output() 
	{
		cout << "A:" << "(" << ax << ";" << ay << ")\n";
		cout << "B:" << "(" << bx << ";" << by << ")\n";
		cout << "C:" << "(" << cx << ";" << cy << ")\n";
	};
	float sideLngth(float x1, float y1, float x2, float y2)
	{
		float length;
		length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		return length;
	};
	float perimeter(float x1, float y1, float x2, float y2, float x3, float y3)
	{
		float p;
		
		p = sideLngth(x1,y1,x2,y2) + sideLngth(x1, y1, x3, y3) + sideLngth(x2, y2, x3, y3);
			return p;
	};
	float square(float x1, float y1, float x2, float y2, float x3, float y3)
	{
		float s;
		float p = perimeter(x1, y1, x2, y2, x3, y3) / 2;
		s = sqrt(p*(p - sideLngth(x1, y1, x2, y2))*(p - sideLngth(x1, y1, x3, y3))*(p - sideLngth(x2, y2, x3, y3)));
			return s;
	};
	void moving(float dx,float dy) 
	{
		ax += dx;bx += dx;cx += dx;
		ay += dy;by += dy;cy += dy;
	};
private:
	float ax, ay, bx, by, cx, cy;
};

int main() 
{
	int N,mx,my,nx,ny,px,py;
	cout << "Number of elements: ";
	cin >> N;
	Triangle abc;
	Triangle* f = new (nothrow) Triangle[N];
	abc.input();
	abc.moving(5, 7);
	abc.output();
	cin >> mx >> my >> nx >> ny >> px >> py;
	Triangle mnp(mx, my, nx, ny, px, py);
	cout << "Perimeter: " << mnp.perimeter(mx, my, nx, ny, px, py) << "\nSquare: " << mnp.square(mx, my, nx, ny, px, py);
	system("pause");
}
