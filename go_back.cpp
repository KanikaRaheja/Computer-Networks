#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<unistd.h>
using namespace std;

class go_back
{
   int nof,check,ws;
   int*arr[100];
   public:
   	void input();
   	void senderside();
   	void receiverside(int);
};



void go_back::input()
{	cout<<"enter window size"<<endl;
	cin>>ws;
	cout<<"\nEnter the number of frames:- ";
	cin>>nof;
	senderside();
}


void go_back::senderside()
{
	
/*	for(int i=0;i<nof;i++)
	{
		*arr[i] =i;
		cout<<*arr[i];
	}
	//cout<<arr[0];
*/	
	for(int i=0;i<nof;i++)
	{
			cout<<"\n\n****************************SENDER SIDE****************************"<<endl;
		//cout<<arr[i];
		for(int j=i+1;j<=ws;j++)
		{
			*arr[j] = j;
			
			cout<<"\n sending frame"<<j;
			
		}
		ws++;
		receiverside(i);
	}
}

void go_back::receiverside(int i)
{
	cout<<"\n\n****************************RECEIVER SIDE ****************************"<<endl;
	cout<<"sending acknowledgement for fram:"<<i<<endl;
}

int main()
{
	go_back g;
	g.input();
	g.senderside();
	getch();
	return 0;
}





