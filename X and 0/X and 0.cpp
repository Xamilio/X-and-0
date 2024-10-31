#include <iostream>
using namespace std;

void field(char mas[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mas[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << "----------";
			cout << endl;
		}
	}
}
int examinationX(char mas[3][3], int k)
{
	if ((mas[0][0] == mas[1][1] && mas[0][0] == mas[2][2] && mas[0][0] == 'X') ||
		(mas[0][2] == mas[1][1] && mas[0][2] == mas[2][0] && mas[0][2] == 'X') ||
		(mas[0][0] == mas[0][1] && mas[0][0] == mas[0][2] && mas[0][0] == 'X') ||
		(mas[1][0] == mas[1][1] && mas[1][0] == mas[1][2] && mas[1][0] == 'X') ||
		(mas[2][0] == mas[2][1] && mas[2][0] == mas[2][2] && mas[2][0] == 'X') ||
		(mas[0][0] == mas[1][0] && mas[0][0] == mas[2][0] && mas[0][0] == 'X') ||
		(mas[0][1] == mas[1][1] && mas[0][1] == mas[2][1] && mas[0][1] == 'X') ||
		(mas[0][2] == mas[1][2] && mas[0][2] == mas[2][2] && mas[0][2] == 'X'))
	{
		cout << "Выйграли креcтики" << endl;
		return 0;
	}
}
int examination0(char mas[3][3], int k)
{
	if((mas[0][0] == mas[1][1] && mas[0][0] == mas[2][2] && mas[0][0] == '0') ||
	  (mas[0][2] == mas[1][1] && mas[0][2] == mas[2][0] && mas[0][2] == '0') ||
	  (mas[0][0] == mas[0][1] && mas[0][0] == mas[0][2] && mas[0][0] == '0') ||
	  (mas[1][0] == mas[1][1] && mas[1][0] == mas[1][2] && mas[1][0] == '0') ||
	  (mas[2][0] == mas[2][1] && mas[2][0] == mas[2][2] && mas[2][0] == '0') ||
	  (mas[0][0] == mas[1][0] && mas[0][0] == mas[2][0] && mas[0][0] == '0') ||
	  (mas[0][1] == mas[1][1] && mas[0][1] == mas[2][1] && mas[0][1] == '0') ||
	  (mas[0][2] == mas[1][2] && mas[0][2] == mas[2][2] && mas[0][2] == '0')) 
	{
		cout << "Выйграли нолики" << endl;
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	char mas[3][3] {{' ',' ',' '}, 
					{' ', ' ', ' '},
					{' ', ' ', ' '}};
	int size1;
	int size2;
	int k = 0;
	while (k < 9)
	{	
		field(mas);
		while (true)
		{
			cout << "Что бы поставить 'X' напишите номер рядка: ";
			cin >> size1;
			cout << "Туперь напите номер столбца: ";
			cin >> size2;
			size1--;
			size2--;
			if (mas[size1][size2] == 'X')
			{
				cout << "На этом месте уже стоит 'X'" << endl;
				continue;
			}
			else if (mas[size1][size2] == '0')
			{
				cout << "На этом месте уже стоит '0'" << endl;
				continue;
			}
			else
			{
				mas[size1][size2] = 'X';
			}
			break;
		}
		field(mas);
		if (examinationX(mas, k) == 0) break;
		while(true)
		{
			cout << "Что бы поставить '0' напишите номер рядка: ";
			cin >> size1;
			cout << "Теперь напите номер столбца: ";
			cin >> size2;
			size1--;
			size2--;
			if (mas[size1][size2] == 'X')
			{
				cout << "На этом месте уже стоит 'X'" << endl;

				continue;
			}
			else if (mas[size1][size2] == '0')
			{
				cout << "На этом месте уже стоит '0'" << endl;
				continue;
			}
			else
			{
				mas[size1][size2] = '0';
			}
			break;
		}
		if(examination0(mas, k) == 0) break;
		cout << endl;
		k++;
	}
}
