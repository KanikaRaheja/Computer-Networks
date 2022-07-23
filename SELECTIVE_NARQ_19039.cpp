//Go Back Selective Repeat ARQ Protocol

#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

class selectiveARQ{
	int *frame;
	int num;	//number of frames
	int m;		//number of bits to represent frames
	int wsize;	//window size
	public :
		selectiveARQ(){
			num=0;
			wsize=0;
		}
		
		void getdata();
		void check();
		
};

void selectiveARQ::getdata(){
	cout<<"Enter the total number of Frames:";
	cin>>num;
	cout<<"Enter the value of m:";
	cin>>m;
	
	wsize=pow(2,m-1);
	cout<<"Window Size:"<<wsize;
	
	frame = new int[num];
	for(int i=0;i<num;i++){
		frame[i]=i;
	}
}

void selectiveARQ::check(){
	int count=0;	//to count number of sent frames
   	int i=0;
	while(i<num)
	{
	    int x=0;	//to count acknowledgements
	    cout<<"\n--------------------------"<<endl;
	    for(int j=i;j<i+wsize && j<num;j++)
	    {
	        cout<<"Frame "<<frame[j]<<" SENT"<<endl;
	        count++;
	    }
	    cout<<"--------------------------"<<endl;
	    for(int j=i;j<i+wsize && j<num;j++)
	    {	here:
	        int flag = rand()%4;
	        cout<<endl;
	        if(flag==0){
	        		getch();
	                cout<<endl<<"Received Positive Acknowledgment for Frame "<<frame[j]<<endl;
	                x++;
	                continue;
	            }
	        else if(flag==1){
	        		getch();
	                cout<<endl<<"Acknowledgment for Frame "<<frame[j]<<" is lost"<<endl;
	                cout<<"Retransmitting Frame "<<frame[j]<<endl;
	                count++;
	                goto here;
	        }
	        else if(flag==2){
	        		getch();
					cout<<endl<<"Frame "<<frame[j]<<" Not Received"<<endl;
	                cout<<"Retransmitting Frame "<<frame[j]<<endl;
	                count++;
	                goto here;
	        }
	        else if(flag==3){
		        	getch();
		        	cout<<endl<<"Received Negative Acknowledgement for Frame "<<frame[j]<<endl;
		        	cout<<"Retransmitting Frame "<<frame[j]<<endl;
		        	count++;
		        	goto here;
	        }
	    }
	    cout<<endl;
	    i+=x;
	    getch();
	}
	getch();
	cout<<endl;
//	cout<<"Total frames sent: "<<count<<endl<<endl;
	cout<<"TRANSMISSION SUCCESSFULL!";
}

int main(){
	cout<<"**SELECTIVE REPEAT ARQ PROTOCOL**\n\n";
	selectiveARQ ob;
	ob.getdata();
	ob.check();
	getch();
	return 0;
}

