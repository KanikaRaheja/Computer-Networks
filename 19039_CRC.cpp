#include<iostream>
#include<conio.h>
using namespace std;
//crc class
class crc
{
     int *data,*gp,sd,sg,size,*temp,*rem,*td,*chk,*temp1,*cw;
	 public:
	 void input ();	
	 void display();
	 void senderside();
	 void receiverside();
};
//taking the input from the user
void crc::input()
{
	cout<<"\n Enter the number of bits for dataword:-";
	cin>>sd;
	data=new int[sd];
	cout<<"\n Enter the dataword in binary:-";
	for(int i=0;i<sd;i++)
	cin>>data[i];
	cout<<"\nEnter the number of bits for generator polynomial:- ";
	cin>>sg;
	gp=new int[sg];
	cout<<"\nEnter the generator polynomial in binary:-";
	for(int i=0;i<sg;i++)
	cin>>gp[i];
}
//calculating the remainder bits at the sender side
void crc::senderside()
{
	int k,j;
	temp=new int[sd+size];
	size=sg-1;
	for(int i=sd;i<sd+size;i++)
	data[i]=0;
	for(int i=0;i<sd+size;i++)
	temp[i]=data[i];
	for(int i=0;i<sd;i++)
	{
		k=i;
		j=0;
		if(temp[k]>=gp[j])
		{
			for(int j=0,k=i;j<sg;k++,j++)
			{
				if((temp[k]==1 && gp[j]==1) || (temp[k]==0 && gp[j]==0))
				temp[k]=0;
				else
				temp[k]=1;
			}
		}
	}
	rem=new int[size];
	for(int i=0,j=sd;i<sd+size;i++,j++)
	rem[i]=temp[j];
	cw=new int[sd+size];
	for(int i=0;i<sd;i++)
	cw[i]=data[i];
	for(int i=sd,j=0;i<sd+size;i++,j++)
	cw[i]=rem[j];
}
//checking if the received message is correct or not
void crc::receiverside()
{
	int k,j;
	temp1=new int[sd+size];
	td=new int[sd+size];
	cout<<"\n\n    AT RECEIVERS SIDE  "<<endl;
	cout<<"\n Enter the codeword the receiver received:-";
	for(int i=0;i<sd+size;i++)
	cin>>td[i];
	for(int i=0;i<sd+size;i++)
	temp1[i]=td[i];
     for(int i=0;i<sd;i++)
	{
		k=i;
		j=0;
		if(temp1[k]>=gp[j])
		{
			for(int j=0,k=i;j<sg;k++,j++)
			{
				if((temp1[k]==1 && gp[j]==1) || (temp1[k]==0 && gp[j]==0))
				temp1[k]=0;
				else
				temp1[k]=1;
			}
		}
	}
	chk=new int[size];
	for(int i=sd,j=0;i<sd+size;j++,i++)
	{
	chk[j]=temp1[i]; 
	}
	cout<<"\n Message received at receiver side-";
	for(int i=0;i<sd+size;i++)
	cout<<" "<<td[i];
	cout<<"\n Remainder is:-";
	for(int i=0;i<size;i++)
	cout<<" "<<chk[i];
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(chk[i]==1)
		{
			flag=1;
		cout<<"\n Sice the remainder is not zero there is  error in the message received";
		break;	
		}
	}
	if(flag==0)
	cout<<"\n Sice the remainder is  0 there is no error in the message received";
		
}
//displaying the senders side
void crc::display()
{
	cout<<"\n   AT THE SENDER'S SIDE   "<<endl;
	cout<<"\n Dataword is:-";
	for(int i=0;i<sd;i++)
	cout<<" "<<data[i];
	cout<<"\n Generator Polynomial is:-";
	for(int i=0;i<sg;i++)
	cout<<" "<<gp[i];
	cout<<"\n Number of 0's to be appended is:-"<<size;
	cout<<"\n After appending dataword becomes:-";
	for(int i=0;i<sd+size;i++)
	cout<<" "<<data[i];
	cout<<"\n Remainder bits are:-";
	for(int i=0;i<size;i++)
	cout<<" "<<rem[i];
 	cout<<"\n CodeWord generated is:- ";
	for(int i=0;i<sd+size;i++)
	cout<<" "<<cw[i];
}
int main()
{
	crc c;
	c.input();
	c.senderside();
	c.display();
	c.receiverside();
	getch();
	return 0;
}
/*
Enter the number of bits for dataword:-8

 Enter the dataword in binary:-1 0 0 1 1 1 0 1

Enter the number of bits for generator polynomial:- 4

Enter the generator polynomial in binary:-1 0  0 1

   AT THE RECEIVER'S SIDE

 Dataword is:- 1 0 0 1 1 1 0 1
 Generator Polynomial is:- 1 0 0 1
 Number of 0's to be appended is:-3
 After appending dataword becomes:- 1 0 0 1 1 1 0 1 0 0 0
 Remainder bits are:- 1 0 0
 CodeWord generated is:-  1 0 0 1 1 1 0 1 1 0 0

    AT RECEIVERS SIDE

 Enter the codeword the receiver received:-1 0 0 1 1 1 0 1 1 0 0
 Message received at receiver side- 1 0 0 1 1 1 0 1 1 0 0
 Remainder is:- 0 0 0
 Sice the remainder is 0 there is no error in the message received

2nd OUTPUT 
Enter the number of bits for dataword:-6

 Enter the dataword in binary:-1 0 1 1 1 0

Enter the number of bits for generator polynomial:- 4

Enter the generator polynomial in binary:-1 0 0 1

   AT THE SENDER'S SIDE

 Dataword is:- 1 0 1 1 1 0
 Generator Polynomial is:- 1 0 0 1
 Number of 0's to be appended is:-3
 After appending dataword becomes:- 1 0 1 1 1 0 0 0 0
 Remainder bits are:- 0 1 1
 CodeWord generated is:-  1 0 1 1 1 0 0 1 1

    AT RECEIVERS SIDE

 Enter the codeword the receiver received:-1 0 1 1 1 0 0 0 0

 Message received at receiver side- 1 0 1 1 1 0 0 0 0
 Remainder is:- 0 1 1
 Sice the remainder is not zero there is  error in the message received
*/

