/*Определить, сколько слов в строке содержат хотя бы одну заданную букву. Вывести такие слова на экран.*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<clocale>
const int MAX{ 255 };
using namespace std;

int wordsCalc(char *str, int size, char chr);
void wordsFind(char*str, int size, char chr);
void deleteMemory(char*&str) {
	delete[] str;
	str = nullptr;
}
void giveMemory(char*&str)
{
	str = new(nothrow) char[MAX];
	if (!str)
	{
		cout << "error" << "\n";
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	
	char*str = nullptr;
	giveMemory(str);
	cout << "Введите строку: ";
	cin.getline(str, MAX);
	char chr;
	cout << "Введите символ для поиска:";
	cin >> chr;
	cout<<wordsCalc(str, MAX, chr)<<" слов содержат символ \""<<chr<<"\""<<'\n';
	wordsFind(str, MAX, chr);
	deleteMemory(str);
	system("pause");
}
int wordsCalc(char *str, int size, char chr)
{
	int k{ 0 }, flag{ 0 };
	for (int i = 0;i<size;++i)
	{
		if (str[i] == chr && !flag)
		{
			++k;
			flag = 1;
		}
		if (str[i] == ' ')
			flag = 0;
	}
	return k;
}
void wordsFind(char*str, int size, char chr)
{
	int k{ 0 };
	for (int i = 0;i < size;++i)
	{
		if (str[i] == chr)
		{
			while ((str[k] != ' ') && (k < strlen(str)))
				cout << str[k++];
			cout << " ";
			i = k;
		}
		if (str[i] == ' ')
		{
			k = i + 1;
		}
	}
		
}