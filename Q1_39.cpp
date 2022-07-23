#include<iostream>
#include<conio.h>
using namespace std;

int xor_func(int b1, int b2)
{
	int xoredBit = (b1 & b2) ? 0 : (b1 | b2);
	return xoredBit;
	
}

int decimal_to_binary(int n)
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
}    
 

void input(int x, int y)
{
	cout<<"enter the first number\n";
	
	cin>>x;
	
	cout<<"enter the second number\n";
	
	cin>>y;
	
}


int main() 
{ 
int x;
cin>>x;
int y;
cin>>y;
decimal_to_binary(x);
decimal_To_binary(y);

   getch();
   return 0;  
} 
