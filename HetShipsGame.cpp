#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

const int rows = 10;
const int elements = 10;
int MaxShips = 10;
int c = 10;

int Ships[rows][elements];

void Clear()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int u = 0; u < elements; u++)
		{
			Ships[i][u] = 0;
		}
	}
}

void Show()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int u = 0; u < elements; u++)
		{
			cout<<Ships[i][u] <<" ";
		}
		cout << endl;
	}
}

void Set()
{
	int s = 0;
	while (s<MaxShips)
	{
		int x = rand() % rows;
		int y = rand() % elements;
		if (Ships[x][y] != 1)
		{
			s++;
			Ships[x][y] = 1;
		}
	}
}

int NumberOfShips()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int u = 0; u < elements; u++)
		{
			if (Ships[i][u] == 1)
			{
				c++;
			}
		}
	}
	return c;
}

bool Check(int x, int y)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int u = 0; u < elements; u++)
		{
			if (Ships[x-1][y-1] == 1)
			{
				Ships[x-1][y-1] = 0;
				c--;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int xo = 0, yo = 0;
	Clear();
	Set();
	cout<<"Number Of Ships = "<<c;
	cout << "\nEnter what i asked for or enter 100 to Exit" << endl;
	Show();
	for (int i = 0; i<4 ; i++)
	{

		cout<<"\n enter Positio : ";
		cin >> xo;cin>>yo;
		if (Check(xo, yo) == true)
		{
			cout  << "OK,Nice Work" << endl;
		}
		else if (xo == 100 && yo == 100)
		{
			system("stop");
		}
		else 
		{
			cout << "Innvalid !" << endl;
		}
	}
	if (c == 10)
	{
		cout << "\nGame Over..!" << endl;
	}
	else
	{
		cout << "\n ------------------------------------------ \nNice Work \n work hard next time"<<
             "\n* Ships You hits correctly : " 
			<< 10 - c <<
			endl << "\n* Ships you missed : " << c << endl;
	}
	_getch();
	return 0;
};