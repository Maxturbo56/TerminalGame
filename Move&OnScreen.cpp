#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Screen{
	
public:
	int x = 0;
	int y = 0;
	
public:
	void Init_Screen(int one, int two)
	{
		x = one;
		y = two;
	}
};

class Entity{

public:
	int x;
	int y;
	string tag;	

public :
	void Set_Tag(string a)
	{
		tag = a;
	}
};

class Player : public Entity{
	
public:
	string image = "&/";
	int hp = 10;
	
public:
	void Handle_Movement(Screen screen)
	{
		bool isPressed;
		
		if(GetKeyState('W') & 0x8000)
		{
			if(y > 1)
			{
				y--;
			}
		}	
		else if(GetKeyState('S') & 0x8000)
		{
			if(y < screen.y - 1)
			{
				y++;
			}
		}
		else if(GetKeyState('D') & 0x8000)
		{
			if(x < screen.x - 1)
			{
				x++;
			}
		}
		else if(GetKeyState('A') & 0x8000)
		{
			if(x > 1)
			{
				x--;
			}
		}		
	}

public:	
	void Collision_Detection(Entity other, string tag)
	{
		if(other.x == x && other.y == y)
		{
			if(tag == "enemy")
			{
				x -= 1;
				hp--;
			}
		}
	}
};

class Patroling_Enemy : public Entity{
	
public:
	string image = "*";
	
	int l_or_r = 0;
	
	//left is 1
	//right is 0
	
public:
	void Patrol()
	{	
		if(x == 6)
		{
			l_or_r = 1;
		}
		else if(x == 3)
		{
			l_or_r = 0;
		}
	
		if(l_or_r == 0)
		{
			x++;
		}
		else if(l_or_r == 1)
		{
			x--;
		}
	}
};

int main()
{
	//Screen Intitialization
	
	Screen screen;
	screen.Init_Screen(10, 10);
	
	//Entity Initialization
	
	Player player;
	player.x = 1;
	player.y = 1;
	
	Patroling_Enemy patroling_Enemy;
	patroling_Enemy.x = 3;
	patroling_Enemy.y = 5;
	
	player.Set_Tag("player");
	patroling_Enemy.Set_Tag("enemy");
	
	//Values
	
	
	// ------------------------------------------------------------------------- //
	
	do{
		// ------------------------ HANDLE UI HERE ------------------------------ //
		
		cout<<"\tHP : "<<player.hp<<endl<<endl;
				
		// --------------------------------------------------------------------- //
		
		cout<<".............................................................."<<endl<<endl;
		
		for(int i = 0; i < screen.y; i++)
		{
			for(int j = 0; j < screen.x; j++)
			{
				if(player.x == j && player.y == i)
				{
					cout<<player.image;
				}
				else if(patroling_Enemy.x == j && patroling_Enemy.y == i)
				{
					cout<<patroling_Enemy.image;
				}
						
				cout<<"   ";
			}	
		
			cout<<"\n";
		}
		
		cout<<endl<<endl<<".............................................................."<<endl<<endl;
		
		// ---------------- UPDATE LOOP IS HERE --------------------------- // 
		
		player.Handle_Movement(screen);
		patroling_Enemy.Patrol();
		
		// ------------------------------------------- COLLISION LAYER ---------------------------------- //
		
		player.Collision_Detection(patroling_Enemy,"enemy");
		
		//DEBUG
		
		cout<<endl<<endl<<endl<<"Player position : \n x : "<<player.x<<endl<<" y : "<<player.y<<endl<<endl<<"Enemy position : \n x : "<<patroling_Enemy.x<<endl;
	
		Sleep(90);
		system("CLS");
	}while(player.hp > 1);
	
	if(player.hp <= 1)
	{
		system("CLS");
		cout<<"\t\t\tGAME OVER! GIT GUD SCRUB!"<<endl<<endl<<endl<<"\t\t\tPress any key to continue!";
		cin.ignore();
	}

	
	return 0;	
}
