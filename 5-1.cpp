#include "pch.h"
#include<iostream> //где условие задачи? Какой градиент ты делаешь??? Совпадает код с Жилко
#include<fstream> 
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream fff("d:\\1.bmp", ios::binary);
	ofstream ggg("d:\\rez.bmp", ios::binary);

	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << " file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	unsigned char r, g, b;
	color c;
	unsigned int w, h;

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18);

	w = 128;
	ggg.write((char *)&w, 4);
	h = 256;
	ggg.write((char *)&h, 4);
	fff.read((char *)&buf, 28);
	ggg.write((char *)&buf, 28);

	c.r = 128; c.g = 16; c.b = 77;
	double dr = (255 - 128) / 80;
	double dg = (49 - 16) / 80;
	double db = (99 - 77) / 80;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			ggg.write((char *)&c, 3);
			c.b = c.b + db;
			c.g = c.g + dg;
			c.r = c.r + dr;
		}
		c.r = 128; c.g = 16; c.b = 77;
	}
	fff.close();
	ggg.close();
	return 1;
}
