#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<unistd.h>
using namespace std;

class ARQ
{
   int nof,check;
   public:
   	void input();
   	void senderside();
   	void receiverside(int);
};
void ARQ::input()
{
	cout<<"\nEnter the number of frames:- ";
	cin>>nof;
	senderside();
}
void ARQ::senderside()
{
	for(int i=1;i<=nof;i++)
	{
		 here:
      	cout<<"\n----------------------Sender Side---------------------------"<<endl;
      	cout<<"\nSender sending frame"<<" "<<i<<" from network layer to data link layer";
      	cout<<"\nSender side TIMER started ";
      	cout<<"\n****************************************************"<<endl;
      	srand(time(NULL));
      	check=(rand()%3)+1;
      	getch();
      	
      	if(check==1)
      	{
      	   receiverside(i);
		   cout<<"\nAcknowledgement received at sender side";
		   cout<<"\nSUCCESS in sending frame "<<i<<endl;	
		}
		else if(check==2)
		{
			getch();
			cout<<"\n----------------------Receiver Side---------------------------"<<endl;
			cout<<"\nFrame "<<i<<" lost before reaching receiver";
			cout<<"\nSending frame "<<i<<" again"<<endl;
			goto here;
		}
		else
		{
			receiverside(i);
			cout<<"\nSender does not receive the acknowledgement";
			cout<<"\nSending Frame "<<i<<" again"<<endl;
			goto here;
		}
    }
    cout<<"\n\n!!!!!!!Successfully all Frames received!!!!!!!!!!";
}
void ARQ::receiverside(int i)
{
	cout<<"\n----------------------Receiver Side---------------------------"<<endl;
	cout<<"\nReceiver received the frame "<<i;
	cout<<"\nSending Acknowledgement "<<(i-1)%2;
	getch();
}
int main()
{
	ARQ a;
	a.input();
	getch();
	return 0;
	
}
/*
OUTPUT

Enter the number of frames:- 5

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 1 lost before reaching receiver
Sending frame 1 again

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 1 lost before reaching receiver
Sending frame 1 again

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 1 lost before reaching receiver
Sending frame 1 again

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 1
Sending Acknowledgement 0
Sender does not receive the acknowledgement
Sending Frame 1 again

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 1 lost before reaching receiver
Sending frame 1 again

----------------------Sender Side---------------------------

Sender sending frame 1 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 1
Sending Acknowledgement 0
Acknowledgement received at sender side
SUCCESS in sending frame 1

----------------------Sender Side---------------------------

Sender sending frame 2 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 2
Sending Acknowledgement 1
Acknowledgement received at sender side
SUCCESS in sending frame 2

----------------------Sender Side---------------------------

Sender sending frame 3 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 3
Sending Acknowledgement 0
Acknowledgement received at sender side
SUCCESS in sending frame 3

----------------------Sender Side---------------------------

Sender sending frame 4 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 4
Sending Acknowledgement 1
Sender does not receive the acknowledgement
Sending Frame 4 again

----------------------Sender Side---------------------------

Sender sending frame 4 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 4
Sending Acknowledgement 1
Sender does not receive the acknowledgement
Sending Frame 4 again

----------------------Sender Side---------------------------

Sender sending frame 4 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 4
Sending Acknowledgement 1
Sender does not receive the acknowledgement
Sending Frame 4 again

----------------------Sender Side---------------------------

Sender sending frame 4 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 4
Sending Acknowledgement 1
Acknowledgement received at sender side
SUCCESS in sending frame 4

----------------------Sender Side---------------------------

Sender sending frame 5 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 5 lost before reaching receiver
Sending frame 5 again

----------------------Sender Side---------------------------

Sender sending frame 5 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Frame 5 lost before reaching receiver
Sending frame 5 again

----------------------Sender Side---------------------------

Sender sending frame 5 from network layer to data link layer
Sender side TIMER started
****************************************************

----------------------Receiver Side---------------------------

Receiver received the frame 5
Sending Acknowledgement 0
Acknowledgement received at sender side
SUCCESS in sending frame 5


!!!!!!!Successfully all Frames received!!!!!!!!!!


*/
