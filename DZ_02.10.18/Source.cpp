#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <cstring>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream in_file("in.txt", ios::in);
	ofstream out_file("out.txt");
	int n;
	cout << "Введите номер задания: ";
	cin >> n;
	if (n == 1)
	{
		cout << "В конец существующего текстового файла записать строку с текстом «До свиданья люди!»" << endl;
		char str[100];
		in_file.getline(str, 100);
		in_file.close();
		in_file.open("in.txt", ios::app);
		in_file << "До свиданья люди!" << endl;

	}
	else if (n == 2)
	{
		cout << "Дан текстовый файл. Подсчитать количество символов в нём." << endl;
		int s = 0;
		char c;
		while (!in_file.eof())
		{
			in_file.get(c);
			s++;
		}
		cout << s << endl;
	}
	else if (n == 3)
	{
		cout << "Дан текстовый файл. Подсчитать количество строк в нём." << endl;
		int t = 1;
		while (!in_file.eof())
		{
			char c;
			in_file.get(c);
			if (c == '\n') t++;
		}
		cout << t << endl;
	}
	else if (n == 4)
	{
		cout << "Дан текстовый файл. Удалить из него последнюю строку. Результат записать в другой файл." << endl;
		const int len = 30, strings = 3;
		char str[len][strings];
		for (int i = 0; i < strings - 1; i++)
		{
			in_file.getline(str[i], len - 1);
			out_file << str[i] << endl;
		}
	}
	else if (n == 5)
	{
		cout << "Дан текстовый файл. Найти длину самой длинной строки. " << endl;
		int k = 0;
		int max = 0;
		char str[100];
		while (!in_file.eof())
		{
			k = 0;
			in_file.getline(str, 100);

			for (int i = 0; str[i] != '\0'; i++)
			{
				k++;
			}
			if (max < k) max = k;
		}
		cout << max << endl;
	}
	else if (n == 6)
	{
		cout << "Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задаёт пользователь" << endl;
		char name[100];
		char * p, *context;
		int k = 0;
		char choice;
		cout << "Введите начальную букву: ";
		cin >> choice;
		while (!in_file.eof())
		{
			in_file.getline(name, 100);
			p = strtok_s(name, " ", &context);
			while (p)
			{
				out_file << p << endl;
				if (p[0] == choice) k++;
				p = strtok_s(context, " ", &context);
			}
		}
		cout << "Количество слов начинающихся с буквы " << choice << " равно " << k << endl;
	}
	else if (n == 7)
	{
		cout << "Дан текстовый файл. Переписать в другой файл все его строки с заменой в них символа 0 на символ 1 и наоборот." << endl;
		char c;

		while (!in_file.eof())
		{
			in_file.get(c);
			if (in_file.eof()) return;
			else
			{
				if (c == '0')
					c = '1';
				else if (c == '1')
					c = '0';
				cout << c;
			}			
		}
		cout << endl;		
	}
	
	system("pause");
}