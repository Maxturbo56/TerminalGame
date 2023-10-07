#include<iostream>
#include<windows.h>
using namespace std;

struct Vector2
{
	int x; 
	int y;
};

class Entity
{
public:
	Vector2 position;
	char image;
public:
	void Set_Image(char a)
	{
		image = a;
	}
};

class Player : public Entity
{
public:
	char k, h;
	int score;

public:
	void Handle_Movement()
	{
		if(GetKeyState(k) & 0x8000)
		{
			{
				position.y--;
			}
		}	
		else if(GetKeyState(h) & 0x8000)
		{
			if(position.y < 20 - 1)
			{
				position.y++;
			}
		}
	}
	
	void Set_Up(char a)
	{
		k = a;	
	}
	
	void Set_Down(char j)
	{
		h = j;	
	}
};

class Ball : public Entity
{
	int speed = 1;
	
	// 0 = right ; 1 = left
	int l_or_r = 1;

public:
	void Handle_Ball(Player one, Player two)
	{
		if(position.x == one.position.x && position.y == one.position.y)
		{
			l_or_r = 0;
		}
		else if(position.x == two.position.x && position.y == two.position.y)
		{
			l_or_r = 1;	
		}	
		
		switch(l_or_r)
		{
			case 0:
				position.x++;
				break;
			case 1: 
				position.x--;
				break;
		}
	}	
};

int main()
{
	//Player Initialization ------------------------ //
	
	Player player_One, player_Two;
	
	player_One.Set_Image('|');
	player_Two.Set_Image('|');
	
	player_One.Set_Up('W');
	player_One.Set_Down('S');
	
	player_Two.Set_Up('I');
	player_Two.Set_Down('K');
	
	player_One.position.x = 1;
	player_One.position.y = 10;
	
	player_Two.position.x = 19;
	player_Two.position.y = 10;
	
	// Ball Init --------------------------------- //
	
	Ball ball;
	ball.position.x = 10;
	ball.position.y = 10;
	ball.Set_Image('o');
	
	// ----------- Update Loop ----------------- //
	
	do{
		
		player_One.Handle_Movement();
		player_Two.Handle_Movement();
		ball.Handle_Ball(player_One, player_Two);
		
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				if(player_One.position.x == j && player_One.position.y == i)
				cout<<player_One.image;
				
				if(player_Two.position.x == j && player_Two.position.y == i)
				cout<<player_Two.image;
				
				if(ball.position.x == j && ball.position.y == i)
				cout<<ball.image;
				
				cout<<"  ";
			}
			
			cout<<"\n";
		}
		
		Sleep(90);
		system("CLS");
	}while(1);
	
	// End -------------------- //
	
	return 0;
}
