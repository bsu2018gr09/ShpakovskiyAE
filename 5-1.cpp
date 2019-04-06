//Горизонтальный градиент c выбранным начальным и конечным цветом
#include<iostream>
#include<cmath>
#include<fstream> 		                 
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream fff("d:\\1.bmp", ios::binary);
	ofstream ggg("d:\\rez.bmp", ios::binary);
	if (!fff) { cout << "No file C:\\file.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "No file C:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	unsigned char r, g, b;
	color c;
	unsigned int w, h;

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18);
	fff.read((char *)&w, 4); 
	cout << "w=" << w;
	fff.read((char *)&w, 4);
	cout << ", h=" << w;
	w = 256; ggg.write((char *)&w, 4);
	h = 256; ggg.write((char *)&h, 4);
	fff.read((char *)&buf, 28);
	ggg.write((char *)&buf, 28);

	float step;
	cout << '\n' << "step: ";
	cin >> step;
	unsigned int rStart, gStart, bStart;
	cout << "Введите r, g и b начального цвета: ";
	cin >> rStart;
	cin >> gStart; 
	cin >> bStart;
	c.r = rStart;
	c.g = gStart;
	c.b = bStart;
	float rEnd = 0, gEnd = 0, bEnd = 0;
	cout << "Введите r, g и b конечного цвета: ";
	cin >> rEnd;
	cin >> gEnd;
	cin >> bEnd;
	float stepR = abs(rEnd - rStart) / step;
	float stepG = abs(gEnd - gStart) / step;
	float stepB = abs(bEnd - bStart) / step;
	int k = 0;

	for (int i{ 0 }; i < w; ++i) { 
		for (int j{ 0 }; j < h; ++j) {
			if (k < step) {
				c.b += stepB;
				c.g += stepG;
				c.r += stepR;
				k++;
			}
			ggg.write((char *)&c, 3);
		}
		c.r = rStart;
		c.g = gStart;
		c.b = bStart;
		k = 0;
	}
}