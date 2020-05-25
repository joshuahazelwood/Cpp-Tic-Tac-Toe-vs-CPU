/* Levi Hazelwood
10/24/2019
The purpose of this lab is too create a game of tic tac toe vs a CPU */ 

#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<time.h>
using namespace std;

class Player
{
	public:
	
	char choice;
	char move;
	char playshape;
	
	
};

class DECIDE
{
	public: 

	char spot[10] = "123456789";
	
	
	int checkwin() 
	{
		int index; 
		int win;
		int counter;
		
		for (index=0; index < 7; index+=3)
		{
			if(spot[index]==spot[index+1] && spot[index+1]==spot[index+2])
			{
				return win = 1;
			}
		}
		for (index=0; index < 3; index++)
		{
			if(spot[index]==spot[index+3] && spot[index+3]==spot[index+6])
			{
				return win = 1;
			}
		}
		if (spot[0]==spot[4] && spot[4]== spot[8])
		{
			return win = 1;
		}
		else if (spot[2]==spot[4] && spot[4]== spot[6])
		{
			return win = 1;
		}
		for (index= 0; index < 9; index++ )
		{
			if (spot[index] == 'x' || spot[index] == 'o')
			{
				counter += 1;
				
				if(counter == 9)
				{
					return win = 2;
				}
			}
		}
		if(win != 1 || win != 2)
		{
			return win = -1;
		}
	}	
	
	void Board()
	{
		cout << "\t\t__" << spot[0] << "__|__" << spot[1] << "__|__" << spot[2] <<"__\n\t\t__" << spot[3] << "__|__" << spot[4] << "__|__" << spot[5] << "__\n\t\t  " << spot[6] << "  |  " <<  spot[7] << "  |  " <<  spot[8] << "  \n " << endl;
	}
};

int main()
{
	Player P1;
	Player CP;
	
	DECIDE decide;
	
	srand(time(NULL));
	int radnum = rand()%9+1;
	int i;
	int j;
	int choice; 
	int win = -1;
	int radstart = rand()%2;
	cout << radstart,'\n';
	
	cout << "Welcome to Tic Tac Toe, below is a board. Each number corresponds to a designated position." << endl;
	cout << "First you will play, then the CPU prepare for the match...\n" << endl;
	cout << "\t\t__1__|__2__|__3__\n\t\t__4__|__5__|__6__\n\t\t  7  |  8  |  9  \n " << endl;
	

	while(win == -1)
	{
		while (radstart == 1)
		{
			cout << "\n" << "Please choose a placement: ";
			cin >> P1.choice;
			
			if (P1.choice > '0' && P1.choice <= '9')
			{
				i = P1.choice - '0';
				
				if (P1.choice == decide.spot[i-1] )
				{
					P1.playshape = 'x';
					P1.move = P1.playshape; 
					decide.spot[i-1] = P1.move; 
				}
			}
			else
			{
				while (P1.choice < '0' || P1.choice > '9' || P1.choice != decide.spot[i-1])
				{
					cout << "\n" << "Please choose a placement: ";
					cin >> P1.choice;
					i = P1.choice - '0';
					P1.playshape = 'x';
					P1.move = P1.playshape; 
					decide.spot[i-1] = P1.move; 
					
				}
			}
			
			decide.Board();
			win = decide.checkwin();
			if (win == 1)
			{
				cout << "\nPlayer Winner!";
				radstart = 9;
			}
			else if (win == 2)
			{
				cout << "\nTie!";
				radstart = 9;
			}
			else if(win == -1)
			{
				radstart = 0;
			}
		
			
			
		
		}

		while (radstart == 0)
		{
			cout << "\nCPU Play\n";
			CP.choice = radnum;
				
			while(decide.spot[CP.choice-1] == 'x' || decide.spot[CP.choice-1] == 'o')
			{
				radnum = rand()%9+1;
				CP.choice = radnum;
			}
			
			CP.playshape = 'o';
			CP.move = CP.playshape; 
			decide.spot[CP.choice-1] = CP.move;
			
			decide.Board();
			win = decide.checkwin();
			if (win == 1)
			{
				cout << "\nCPU Winner!";
				radstart = 9;
			}
			else if (win == 2)
			{
				cout << "\nTie!";
				radstart = 9;
			}
			else if(win == -1)
			{
				radstart = 1;
			}
		}
		if (radstart == 9)
			return 0;
	}
return 0;
}

