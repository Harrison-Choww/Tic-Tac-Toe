#include <iostream>

void createGameBoard(char bd[][3]);
bool markSpace(char bd[][3], int row, int col);
void printBoard(char bd[][3]);
bool gameOver(char bd[][3], char &whoWon);

using namespace std;

int main()
{
	char bd[3][3];
	bool finished = false;
	int x, y, count = 0;
	char winner = ' ';
	createGameBoard(bd);
	printBoard(bd);

	while (!finished)
	{
		cout << "Enter column and row to place the next character: " << endl;
		cin >> x >> y;
		if (markSpace(bd, x, y))
		{
			printBoard(bd);
		}
		count++;
		finished = gameOver(bd, winner);
		if (finished && count < 9)
		{
			cout << winner << " Wins!" << endl;
		}
		else if (!finished && count == 9)
		{
			cout << "Tie Game!";
			finished = true;
		}
	}

	return 0;
}

void createGameBoard(char bd[][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			bd[row][col] = '-';
		}
	}
}

void printBoard(char bd[][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << bd[row][col] << "\t";
		}
		cout << endl;
	}
}

bool markSpace(char bd[][3], int row, int col)
{
	static bool xTurn = false;
	xTurn = !xTurn;
	if (bd[row][col] == '-')
	{
		if (xTurn)
		{
			bd[row][col] = 'X';
		}
		else
		{
			bd[row][col] = 'O';
		}
		system("CLS");
		return true;
	}
	else
	{
		return false;
	}
}

bool gameOver(char bd[][3], char &whoWon)
{
	char winner = ' ';
	if (bd[0][0] == bd[1][1] && bd[0][0] == bd[2][2] && bd[0][0] != '-')
	{
		winner = bd[0][0];
	}
	else if (bd[2][0] == bd[1][1] && bd[1][1] == bd[0][2] && bd[2][0] != '-')
	{
		winner = bd[2][0];
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (bd[i][0] == bd[i][1] && bd[i][0] == bd[i][2] && bd[i][0] != '-')
			{
				winner = bd[i][0];
				break;
			}
			else if (bd[0][i] == bd[1][i] && bd[1][i] == bd[2][i] && bd[0][i] != '-')
			{
				winner = bd[0][i];
				break;
			}
		}
	}
	if (winner == ' ')
	{
		return false;
	}
	else
	{
		whoWon = winner;
		return true;
	}
}
