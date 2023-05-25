#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	
	float a,b,c,delta;
	
	cin>>a;
	cin>>b;
    cin>>c;
    
	delta=b*b-4*a*c;
	if(delta==0){cout<<"Jedno rozwiazanie";}
	else{if(delta>0){cout<<"Dwa rozwiazania";}
	else{if(delta<0){cout<<"Brak rozwiazan w dziedzinie liczb rzeczywistych";}}
	}
	return 0;
}
