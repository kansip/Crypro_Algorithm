//Пример: Ктосук отько-елр лувбь ю
//Гаие дн а - Гадание
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	string s;
	int a, d, n = 0;
	int flag = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	getline(cin, s);
	//s = "Чтопсь отоо -мл ея н";
	//cout << s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
	}
	while (true)
	{
		n++;
		if ((n * n + n) / 2 == s.length())
		{
			flag = 1;
			break;
		}
		else if ((n * n + n) / 2 + (n * n + n) % 2 > s.length())
		{
			flag = 2;
			break;
		}
	}
	cout << endl;
	int tmp = n;
	int tmpfor = 0;
	int count = 0;
	char ch[100][100];
	int x = 0, y = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			ch[j][i] = ' ';
		}
	}
	if (flag == 1)
	{

		for (int i = 0; i < s.length(); i++)
		{
			if (tmpfor == n)
			{
				n--;
				tmpfor = 0;
				count++;
			}
			if (tmpfor < n)
			{
				ch[tmp - n + tmpfor][count] = s[i];
			}
			tmpfor++;
		}
		cout << ch[x][y];
		while (true)
		{
			if (ch[x + 1][y] != ' ')
			{
				x++;
				while (ch[x][y] != ' ')
				{
					cout << ch[x][y];
					y++;
				}
				x++;
				while (ch[x][y] != ' ')
				{
					cout << ch[x][y];
					y--;
				}
				y++;
			}
			else
			{
				break;
			}
		}
		cout << endl << endl;
		for (int i = 0; i < tmp; i++)
		{
			for (int j = 0; j < tmp; j++)
			{
				cout << ch[j][i];
			}
			cout << endl;
		}
	}
	else
	{
		n--;
		tmp = n; //tmpfor=0;n=3;s.lenght()=7;x=1;count=0
		x = s.length() - ((n * n + n) / 2 + (n * n + n) % 2);  // 7 - 6 + 0 = 1		 //Гаие дн а
		if ((n + 1) % 2 == 0)
		{
			for (int i = 0; i < s.length(); i++)
			{
				//cout << ch[1][1];
				if (tmpfor > n && x > 0)
				{
					ch[tmp - n + tmpfor][count] = s[i];
					x--;
					n--;
					count++;
					cout << endl;
					tmpfor = 0;
				}
				if (tmpfor < n && x == 0)
				{
					ch[tmp - n + tmpfor][count] = s[i];
					cout << " " << ch[tmp - n + tmpfor][count];
					//cout << " x: " << tmp - n + tmpfor << " y: " << count;
				}
				else if (tmpfor == n && x == 0)
				{
					tmpfor = 0;
					count++;
					n--;
					cout << endl;

					//ch[tmp - n + tmpfor][count] = s[i];
					//cout << " " << ch[tmp - n + tmpfor][count];
					//cout << " x: " << tmp - n + tmpfor << " y: " << count;
					tmpfor = 0;
					ch[tmp - n + tmpfor][count] = s[i];
					cout << " " << ch[tmp - n + tmpfor][count];
				}
				else if (tmpfor <= n && x > 0)
				{
					ch[tmp - n + tmpfor][count] = s[i];
					cout << " " << ch[tmp - n + tmpfor][count];
					//cout << " x: " << tmp - n + tmpfor << " y: " << count;
				}
				tmpfor++;
			}
			cout << endl;
			cout << endl;
			cout << ch[x][y];
			while (true)
			{
				if (ch[x + 1][y] != ' ')
				{
					x++;
					while (ch[x][y] != ' ')
					{
						cout << ch[x][y];
						y++;
					}
					x++;
					while (ch[x][y] != ' ')
					{
						cout << ch[x][y];
						y--;
					}
					y++;
				}
				else
				{
					break;
				}
			}
			cout << endl;
		}
		else
		{
			n++;
			tmp = n;
			for (int i = 0; i < s.length(); i++)
			{
				if (tmpfor == n - 1 && n > x)
				{
					count++;
					tmpfor = 0;
					n--;
					cout << endl;
				}
				if (tmpfor < n - 1 && n > x)
				{
					ch[tmp - n + tmpfor][count] = s[i];
					cout << " " << ch[tmp - n + tmpfor][count];
					//cout << " x: " << tmp - n + tmpfor << " y: " << count;
				}
				if (tmpfor == n && n <= x)
				{
					tmpfor = 0;
					n--;
					count++;
					cout << endl;
				}
				if (tmpfor < n && n <= x)
				{
					ch[tmp - n + tmpfor][count] = s[i];
					cout << " " << ch[tmp - n + tmpfor][count];
					//cout << " x: " << tmp - n + tmpfor << " y: " << count;
				}

				tmpfor++;
			}
			x = 0;
			cout << endl;
			cout << endl;
			cout << ch[x][y];
			while (true)
			{
				if (ch[x + 1][y] != ' ')
				{

					x++;
					while (ch[x][y] != ' ')
					{
						cout << ch[x][y];
						y++;
					}
					x++;
					while (ch[x][y] != ' ')
					{
						cout << ch[x][y];
						y--;
					}
					y++;
				}
				else
				{
					break;
				}
			}
			cout << endl;
		}

	}
	system("pause");
}