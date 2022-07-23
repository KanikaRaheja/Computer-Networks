#include<iostream>
#include<conio.h>
using namespace std;

class crc
{
	int sizeDataword,sizeGenerator,*data,*generator,*temp,*rem,*cw,*temp1, *chk,*td;
	
	public:
		void input();
		void senderSide();
		void receiverSide();
		void display();
	
	
	
};

void crc::input()
{
	
	cout<<"enter the number of bits for the dataword"<<endl;
	cin>>sizeDataword;
	data = new int[sizeDataword];
	
	cout<<"enter the dataword in binary now"<<endl;
	for(int i=0;i<sizeDataword;i++)
	cin>>data[i];
	
	cout<<"enter the number of bits for generator polynomial"<<endl;
	cin>>sizeGenerator;
	generator = new int[sizeGenerator];
	
	cout<<"enter the generator polynomial in binary now"<<endl;
	for(int i=0;i<sizeGenerator;i++)
	cin>>generator[i];
}


void crc::senderSide()
{
	
	//we need to first add sizeGenerator-1 number of times '0' to the dataword
	int k,j;
	for(int i=sizeDataword;i<sizeDataword+sizeGenerator-1;i++)
	data[i] = 0;
	
	// we need to now transfer data from dataword to another variable temp so that we can make changes in that in order tocheck the msg at receiver side
	temp = new int[sizeDataword+sizeGenerator-1];
	for(int i=0;i<sizeDataword+sizeGenerator-1;i++)
	data[i] = temp[i];
	
	//XOR implementation : 0 xor 0 = 0 ,  1 xor 1 = 0, 1 xor 0 = 1, 0 xor 1 =0
	
	for(int i=0;i<sizeDataword;i++)
	{
		if(temp[0]==generator[i])
		{
			
			for(int j=0,k=i;j<sizeGenerator+1;j++,k++)
			{
			 
             if(!(temp[k]^generator[j]))
                 temp[k]=0;
             else
                 temp[k]=1;
                 
        	}
     	}
			
			
	}
	rem = new int[sizeGenerator-1];
	for(int i=0,j=sizeDataword; i<sizeDataword+sizeGenerator-1;i++,j++)
	rem[i] = temp[j];
	
	cw = new int[sizeDataword+sizeGenerator-1];
	for(int i=0;i<sizeDataword;i++)
	cw[i] = data[i];
	
	for(int i=sizeDataword,j=0;i<sizeDataword+sizeGenerator-1;i++,j++)
	cw[i] = rem[i];
	
	


}

void crc::receiverSide()
{
	
	int k,j;
	temp1 = new int[sizeDataword+sizeGenerator-1];
	td = new int[sizeDataword+sizeGenerator-1];
	
	
	cout<<"enter the codeword the receiver recieved"<<endl;
	for(int i=0;i<sizeDataword+sizeGenerator-1;i++)
	cin>>td[i];
	
	for(int i=0;i<sizeDataword+sizeGenerator-1;i++)
	temp1[i] = td[i];
	
	for(int i=0;i<sizeDataword;i++)
	{
		
		
		if(temp[0]==generator[i])
		{
			
			for(int j=0,k=i;j<sizeGenerator+1;j++,k++)
			{
			 
             if(!(temp[k]^generator[j]))
                 temp[k]=0;
             else
                 temp[k]=1;
                 
        	}
     	}
		
	}
	
	chk = new int[sizeGenerator-1];
	for(int j=0,i=sizeDataword; i<sizeDataword+sizeGenerator-1;i++,j++)
	chk[j] = temp1[i];
	
	cout<<"messege received at receiver side: "<<endl;
	for(int i=0;i<sizeDataword+sizeGenerator-1;i++)
	cout<<" "<<td[i];
	
	cout<<endl<<"remainder is :"<<endl;
	for(int i=0;i<sizeGenerator-1;i++)
	cout<<" "<<chk[i];
	
	int flag =0;
	for(int i=0;i<sizeGenerator-1;i++)
	{
		if(chk[i] ==1)
		{
			flag =1;
			cout<<"\n Sice the remainder is not zero there is  error in the message received";
			break;
			
		}
		
	}
if(flag==0)
	cout<<"\n Sice the remainder is  0 there is no error in the message received";		
}
	

int main()
{
	crc c;
	c.input();
	c.senderSide();
	//c.display();
	c.receiverSide();
	getch();
	return 0;
}








