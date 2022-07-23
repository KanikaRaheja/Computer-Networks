//Go Back N Protocol
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<unistd.h>
#include<time.h>
#include<iomanip>
using namespace std;
class goback
{
     int ws,nof;
	 public:
	 void input();
	 void senderside();	
	 void receiverside(int);
};
void goback::input()
{
	cout<<"\nEnter the number of frames you want to send:- ";
	cin>>nof;
	cout<<"\nEnter the window size:- ";
	cin>>ws;
}
void goback::senderside()
{
	for(int i=1;i<=nof;i+=ws)
	{
		here:
		 cout<<"\n\n******************Sender Side******************"<<endl;
		 int check=(rand()%3)+1;
		srand(time(NULL));
		for(int j=i;j<=(i-1)+ws;j++)
		{
			if(j<=nof)
		cout<<"\nSending Frame "<<j;
	    }
	    cout<<"\n\n          Timer Started              "<<endl;
	    getch();
		if(check==1)
		{
	    receiverside(i);
	    cout<<"\n\n******************Sender Side******************"<<endl;
	    	for(int k=i;k<=ws+(i-1);k++)
	    	{
	    		if(k<=nof)
	    cout<<"\n\nAcknowledgement received for frame "<<k;
	     }
	    cout<<"\n\nSuccessfully sent the frames:- ";
	     	for(int k=i;k<=ws+(i-1);k++)
	    	{
	    		if(k<=nof)
	    cout<<"  "<<k;
	     }
      	}
      	else if(check==2)
      	{
      		
      		int temp=(rand()%i);
      		while(temp<i)
      		{
      			temp++;
			  }
      			cout<<"\n\n******************Receiver Side******************"<<endl;
      			if(temp<=nof)
				cout<<"\n\nFrame "<<temp<<" lost";
				cout<<"\n\n          Sending the frames again";
				goto here;
				getch();
		  }
		  else
		  {
		  	int temp=(rand()%i);
		  	while(temp<i)
      		{
      			temp++;
			  }
		  	receiverside(i);
		  	cout<<"\n\n******************Sender Side******************"<<endl;
		  	if(temp<=nof)
		  	cout<<"\n Sender does not receive the acknowledgement for frame "<<temp;
		  	cout<<"\n\nSending the frames again "<<endl;
		  	goto here;
		  	getch();
		  }
    }
    cout<<"\n\n!!!!!!!!!!!SUCCESSFULLY SENT  ALL THE FRAMES!!!!!!!!!!!!";
}
void goback::receiverside(int i)
{
	int temp=ws;
	cout<<"\n\n******************Receiver Side******************"<<endl;
	for(int k=i;k<=ws+(i-1);k++)
	{
		if(k<=nof)
	cout<<"\n\n Receiver receive the frame "<<k;
    }
    for(int k=i;k<=ws+(i-1);k++)
    {
    	if(k<=nof)
    cout<<"\n\nSending Acknowledgement for frame "<<k;
	}
}
int main()
{
	goback g;
	g.input();
	g.senderside();
	getch();
	return 0;
}

/*
OUTPUT

Enter the number of frames you want to send:- 6

Enter the window size:- 3


******************Sender Side******************

Sending Frame 1
Sending Frame 2
Sending Frame 3

          Timer Started


******************Receiver Side******************


 Receiver receive the frame 1

 Receiver receive the frame 2

 Receiver receive the frame 3

Sending Acknowledgement for frame 1

Sending Acknowledgement for frame 2

Sending Acknowledgement for frame 3

******************Sender Side******************

 Sender does not receive the acknowledgement for frame 1

Sending the frames again


******************Sender Side******************

Sending Frame 1
Sending Frame 2
Sending Frame 3

          Timer Started


******************Receiver Side******************


Frame 1 lost

          Sending the frames again

******************Sender Side******************

Sending Frame 1
Sending Frame 2
Sending Frame 3

          Timer Started


******************Receiver Side******************


Frame 1 lost

          Sending the frames again

******************Sender Side******************

Sending Frame 1
Sending Frame 2
Sending Frame 3

          Timer Started


******************Receiver Side******************


 Receiver receive the frame 1

 Receiver receive the frame 2

 Receiver receive the frame 3

Sending Acknowledgement for frame 1

Sending Acknowledgement for frame 2

Sending Acknowledgement for frame 3

******************Sender Side******************


Acknowledgement received for frame 1

Acknowledgement received for frame 2

Acknowledgement received for frame 3

Successfully sent the frames:-   1  2  3

******************Sender Side******************

Sending Frame 4
Sending Frame 5
Sending Frame 6

          Timer Started


******************Receiver Side******************


 Receiver receive the frame 4

 Receiver receive the frame 5

 Receiver receive the frame 6

Sending Acknowledgement for frame 4

Sending Acknowledgement for frame 5

Sending Acknowledgement for frame 6

******************Sender Side******************

 Sender does not receive the acknowledgement for frame 4

Sending the frames again


******************Sender Side******************

Sending Frame 4
Sending Frame 5
Sending Frame 6

          Timer Started


******************Receiver Side******************


Frame 4 lost

          Sending the frames again

******************Sender Side******************

Sending Frame 4
Sending Frame 5
Sending Frame 6

          Timer Started


******************Receiver Side******************


 Receiver receive the frame 4

 Receiver receive the frame 5

 Receiver receive the frame 6

Sending Acknowledgement for frame 4

Sending Acknowledgement for frame 5

Sending Acknowledgement for frame 6

******************Sender Side******************


Acknowledgement received for frame 4

Acknowledgement received for frame 5

Acknowledgement received for frame 6

Successfully sent the frames:-   4  5  6

!!!!!!!!!!!SUCCESSFULLY SENT  ALL THE FRAMES!!!!!!!!!!!!

*/
