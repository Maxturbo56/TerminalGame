#include <iostream>
#include <cmath>
using namespace std;

int f_x(int x)
{
    // F(X) is equal to THIS! 
    int y = sin(x);
    return y;
}

int f_g(int g)
{
    int y = 0;
    return y;
}


int main()
{    
  
    for(int y = 30; y >= -30; y--)
    {    
        for(int x = 0; x < 30; x++)
        {            
            if(y == f_x(x))
            {
            	cout<<"*"<<"\t";
                //cout<<"x"<<"( "<<x<<" , "<<y<<" )"<<"\t";
            }
            else if(y == f_g(x))
            {
            	cout<<"*"<<"\t";
                //cout<<"g"<<"( "<<x<<" , "<<y<<" )"<<"\t";
            }
            else
            {
                cout<<"\t\t";
            }    
        }
        
        cout<<"\n";
    }
    
    bool found_Intersect = false;
    
    for(int y = 10; y >= 0; y--)
    {    
        for(int x = 0; x < 10; x++)
        {        
            if(y == f_g(x) && y == f_x(x))
            {
                cout<<endl<<endl<<"----------------------------"<<endl<<"Intersection at : "<<x<<" , "<<y<<endl;
                found_Intersect = true;
            }
        }
    }
    
    if(found_Intersect == false)
    {
        cout<<endl<<endl<<"----------------------------"<<endl<<"No Intersection found."<<endl;
    }
    
    
    return 0;
}
