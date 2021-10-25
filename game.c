# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <windows.h>
# include <conio.h>
# include <stdbool.h>

bool player_x_win(char t[3][3])
{
	int i;
	int cp=0;
	int x=0;
	
	bool test=false;
	
	// check rows
	
	do {
		x=0;
			
		for(i=0;i<3;i++)
		{
			if(t[cp][i] !='X')
			{
				x=1;	
				break;
			}
		}
		
		if(x == 0)
		{
			return true;
		}
		cp++;
	}while(!(  cp == 3  ));
	
	
	x=0;
	cp=0;
	
	// check columns
	
	do{
		x=0;
		
		for(i=0;i<3;i++)
		{
			if(t[i][cp] !='X')
			{
				x=1;
				break;
			}
		}
		
		if(x == 0)
		{
			return true;
		}
		cp++;
	}while(!( cp == 3 ));
	
	
	x=0;
	
	// check first diagonal	
	
	for(i=0;i<3;i++)
	{
		if(t[i][i] !='X')
		{
			x=1;
			break;
		}
	}
	
	if(x == 0)
	{
		return true;
	}
	
	
	x=0;
	
	// check second diagonal
	
	for(i=0;i<3;i++)
	{
		if(t[i][2-i] !='X')
		{
			x=1;
			break;
		}
	}
	
	if(x == 0)
	{
		return true;
	}
	
	return false;
}



bool player_y_win(char t[3][3])
{
	int i;
	int cp=0;
	int x=0;
	
	
	bool test=false;
	
	// check rows
	
	do{
		x=0;
			
		for(i=0;i<3;i++)
		{
			if(t[cp][i] !='O')
			{
				x=1;	
				break;
			}
		}
		
		if(x == 0)
		{
			return true;
		}
		cp++;
	}while(!(  cp == 3  ));
	
	x=0;
	cp=0;
	
	// check columns
	
	do{
		x=0;
		
		for(i=0;i<3;i++)
		{
			if(t[i][cp] !='O')
			{
				x=1;
				break;
			}
		}
		
		if(x == 0)
		{
			return true;
		}
		cp++;
	}while(!( cp == 3 ));
	
	x=0;
		
	// check first diagonal	
		
	for(i=0;i<3;i++)
	{
		if(t[i][i] !='O')
		{
			x=1;
			break;
		}
	}
	
	if(x == 0)
	{
		return true;
	}
	
	x=0;
	
	// check second diagonal 
	
	for(i=0;i<3;i++)
	{
		if(t[i][2-i] !='O')
		{
			x=1;
			break;
		}
	}
	
	if(x == 0)
	{
		return true;
	}
	
	return false;
}


int main()
{
	char t[3][3]={  {' ',' ',' '}    ,   {' ',' ',' '}    ,    {' ',' ',' '}   };
	char aux[3][3]={  {' ',' ',' '}    ,   {' ',' ',' '}    ,    {' ',' ',' '}   };
	
	int x1;
	int y1;
	
	int x2;
	int y2;
	
	int i;
	int j;
	
	int x=0;
	
	
	do{
		
		printf("\n\nx turn !\n\n");
		
		do{
			scanf("%d",&x1);
			scanf("%d",&y1);
		}while(!(  aux[x1-1][y1-1] != '-'  &&  x1<=3 && x1>0  && y1<=3 && y1>0 ));
		
		aux[x1-1][y1-1]='-';
		t[x1-1][y1-1]='X';
		
		for(i=0;i<3;i++)
		{
			printf("\n\n");
			for(j=0;j<3;j++)
			{
				printf("%c  ",t[i][j]);
			}
		}
		
		if(player_x_win(t) == true)
		{
			break;
		}
		else
		{
			if(x >= 8)
			break;
		}
		
		printf("\n\no turn !\n\n");
		
		do{
			scanf("%d",&x2);
			scanf("%d",&y2);
		}while(!( aux[x2-1][y2-1] != '-' && x2<=3  && x2>0 && y2<=3 && y2>0));	
		
		aux[x2-1][y2-1]='-';
		t[x2-1][y2-1]='O';
		
		x++;
		
		system("cls");
		
		for(i=0;i<3;i++)
		{
			printf("\n\n");
			for(j=0;j<3;j++)
			{
				printf("%c  ",t[i][j]);
			}
		}
		
		if(player_y_win(t))
		{
			break;
		}
		else
		{
			if(x >=8)
			break;
		}
			
		printf("\n\n");
		
		x++;
	}while(!( player_x_win(t) == true   ||  player_y_win(t) == true ));
	
	
	if(player_x_win(t) == true)
	{
		printf("\n\n\nx won the game !");
	}
	else if(player_y_win(t) == true)
	{
		printf("\n\no won the game !");
	}
	else
	{
		printf("the game was a draw !");
	}
	
	while(!kbhit())
	{
		system("color 1");
		system("color 2");
		system("color 4");
		system("color 6");
	}
	
}