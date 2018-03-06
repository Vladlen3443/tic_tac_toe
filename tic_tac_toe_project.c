#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define Row 7
#define Column 5

char matrix[Row][Column];
bool result;
void matrix_inputing();
void print_map();
void player_move1();
void player_move2();
void check_winner(int x, int y);
void menu();
void rules();



int main()
{
	int rule;
	printf("Do you want to see the rules?\n");
	printf("Please, input digit 1-yes or digit 2-no:   ");
	scanf_s("%i", &rule);

	if (rule == 1)
	{
		rules();
	}




	//system("cls");
	result = false;

	matrix_inputing();

	printf("\n\t\t\t\t\t***_TIC_TAC_TOE_***\n\n");

	do
	{
		player_move1();
		if (result == true)
		{
			system("cls");
			print_map();
			printf("\n\n\t\tPlayer1 won!\n");
			break;
		}
		player_move2();
		if (result == true)
		{
			system("cls");
			print_map();
			printf("\n\n\t\tPlayer2 won!\n");
			break;
		}

		system("cls");
	} while (1);

	menu();

	return 0;
}

void matrix_inputing()  //filling the array
{
	int i, j;
	for (i = 0; i<Row; i++)
	{
		for (j = 0; j<Column; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

void print_map()
{
	int i;

	for (i = 0; i<Row; i++)
	{
		printf("%c | %c | %c | %c | %c ",
			matrix[i][0], matrix[i][1], matrix[i][2], matrix[i][3], matrix[i][4]);
		if (i == 6) break;
		printf("\n --------------- \n");
	}

	printf("\n");
}

void player_move1()     //player1 make a choise
{
	int x, y;

	print_map();
	printf("\tPlayer1:\nPlease, input coordinates x,y: \n");
	scanf_s("%i %i", &x, &y);
	x--; y--;

	if (matrix[x][y] != ' ' || x>Row || y>Column)
	{
		printf("Wrong inputing, try again!\n\n");
		player_move1();
	}
	else
	{
		matrix[x][y] = 'X';
	}

	check_winner(x, y);
}

void player_move2()          //player2 make a choise
{
	int x, y;

	print_map();
	printf("\tPlayer2:\nPlease, input coordinates x,y: \n");
	scanf_s("%i %i", &x, &y);
	x--; y--;

	if (matrix[x][y] != ' ' || x>Row || y>Column)
	{
		printf("Wrong inputing, try again!\n\n");
		player_move2();
	}
	else
	{
		matrix[x][y] = 'O';
	}
	check_winner(x, y);

}


void check_winner(int x, int y)
{
	int horizontal = 0;
	int vertical = 0;
	int main_diagonal = 0;
	int counter = 4;

	int i;




	for (i = 0; i<Column; i++)
	{

		if (matrix[x][i] == 'X')
		{
			horizontal++;
			if (horizontal == counter)
			{
				result = true;
			}
		}
		else
		{
			horizontal = 0;
		}

	}


	for (i = 0; i<Row; i++)
	{
		if (matrix[i][y] == 'X')
		{
			vertical++;
			if (vertical == counter)
			{
				result = true;
			}
		}
		else
		{
			vertical = 0;
		}
	}

	for (i = 0; i<Column; i++)
	{

		if (matrix[x][i] == 'O')
		{
			horizontal++;
			if (horizontal == counter)
			{
				result = true;
			}
		}
		else
		{
			horizontal = 0;
		}

	}

	for (i = 0; i<Row; i++)
	{
		if (matrix[i][y] == 'O')
		{
			vertical++;
			if (vertical == counter)
			{
				result = true;
			}
		}
		else
		{
			vertical = 0;
		}
	}


	for (i = y; i >= 0; i--)
	{
		if (x == 0 || i == 0)
			break;
		x--;
	}
	for (i = 0; i<Column; i++)
	{
		if (matrix[x][i] == 'X')
		{
			main_diagonal++;
			if (main_diagonal == counter)
			{
				result = true;
			}
		}
		else
		{
			main_diagonal = 0;
		}
		x++;
	}

	//    for(i=y; i>=0; i--)
	//    {
	//        if(x == 0 || i == 0)
	//            break;
	//        x--;
	//    }
	//    for(i=0; i<Column; i++)
	//    {
	//        if(matrix[x][i] == 'O')
	//        {
	//            main_diagonal++;
	//            if(main_diagonal == counter)
	//            {
	//                result = true;
	//            }
	//        }
	//        else
	//        {
	//            main_diagonal = 0;
	//        }
	//        x++;
	//    }


	if (matrix[0][3] == 'X' && matrix[1][2] == 'X' && matrix[2][1] == 'X' && matrix[3][0] == 'X')
	{
		result = true;
	}
	if (matrix[0][4] == 'X' && matrix[1][3] == 'X' && matrix[2][2] == 'X' && matrix[3][1] == 'X')
	{
		result = true;
	}
	if (matrix[1][3] == 'X' && matrix[2][2] == 'X' && matrix[3][1] == 'X' && matrix[4][0] == 'X')
	{
		result = true;
	}
	if (matrix[1][4] == 'X' && matrix[2][3] == 'X' && matrix[3][2] == 'X' && matrix[4][1] == 'X')
	{
		result = true;
	}
	if (matrix[2][3] == 'X' && matrix[3][2] == 'X' && matrix[4][1] == 'X' && matrix[5][0] == 'X')
	{
		result = true;
	}
	if (matrix[2][4] == 'X' && matrix[3][3] == 'X' && matrix[4][2] == 'X' && matrix[5][1] == 'X')
	{
		result = true;
	}
	if (matrix[3][3] == 'X' && matrix[4][2] == 'X' && matrix[5][1] == 'X' && matrix[6][0] == 'X')
	{
		result = true;
	}
	if (matrix[3][4] == 'X' && matrix[4][3] == 'X' && matrix[5][2] == 'X' && matrix[6][1] == 'X')
	{
		result = true;
	}


	if (matrix[0][3] == 'O' && matrix[1][2] == 'O' && matrix[2][1] == 'O' && matrix[3][0] == 'O')
	{
		result = true;
	}
	if (matrix[0][4] == 'O' && matrix[1][3] == 'O' && matrix[2][2] == 'O' && matrix[3][1] == 'O')
	{
		result = true;
	}
	if (matrix[1][3] == 'O' && matrix[2][2] == 'O' && matrix[3][1] == 'O' && matrix[4][0] == 'O')
	{
		result = true;
	}
	if (matrix[1][4] == 'O' && matrix[2][3] == 'O' && matrix[3][2] == 'O' && matrix[4][1] == 'O')
	{
		result = true;
	}
	if (matrix[2][3] == 'O' && matrix[3][2] == 'O' && matrix[4][1] == 'O' && matrix[5][0] == 'O')
	{
		result = true;
	}
	if (matrix[2][4] == 'O' && matrix[3][3] == 'O' && matrix[4][2] == 'O' && matrix[5][1] == 'O')
	{
		result = true;
	}
	if (matrix[3][3] == 'O' && matrix[4][2] == 'O' && matrix[5][1] == 'O' && matrix[6][0] == 'O')
	{
		result = true;
	}
	if (matrix[3][4] == 'O' && matrix[4][3] == 'O' && matrix[5][2] == 'O' && matrix[6][1] == 'O')
	{
		result = true;
	}
}



void menu()
{
	int your_choise;

	printf("\n\t\t***********Tic_Tac_toe***********\n");
	printf("\tIf you want play again input numeric - 1\n");
	printf("\tIf you want exit the game input numeric - 2 and press Enter\n");

	printf("\nMake your choise - ");
	scanf_s("%i", &your_choise);

	switch (your_choise)
	{
	case 1: main(); break;
	case 2: CloseWindow(0);
	}
}

void rules()
{
	printf("\nIn this game involves two players. \n");
	printf("How to make a move: \n");
	printf("You should input coordinates of a cell\n");
	printf("(1;1) | (1;2) | (1;3) | (1;4) | (1;5)\n"
		"-------------------------------------\n"
		"(2;1) | (2;2) | (2;3) | (2;4) | (2;5)\n"
		"-------------------------------------\n"
		"(3;1) | (3;2) | (3;3) | (3;4) | (3;5)\n"
		"-------------------------------------\n"
		"(4;1) | (4;2) | (4;3) | (4;4) | (4;5)\n"
		"-------------------------------------\n"
		"(5;1) | (5;2) | (5;4) | (5;4) | (5;5)\n"
		"-------------------------------------\n"
		"(6;1) | (6;1) | (6;3) | (6;4) | (6;5)\n"
		"-------------------------------------\n"
		"(7;1) | (7;2) | (7;3) | (7;4) | (7;5)\n");
}
