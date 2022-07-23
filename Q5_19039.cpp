#include<iostream>
#include<conio.h>
using namespace std;

class Q5{
		int** cost, **dist;
		char *router,**path;
	    int number_of_nodes;
    public :
    	Q5(){
    		cout << "Enter the number of router :";
    		cin>>number_of_nodes;
    		router = new char[number_of_nodes];
		    //Dynamically allocating row space
		    cost = new int*[number_of_nodes];					    
			dist = new int*[number_of_nodes];
			path = new char*[number_of_nodes];
		    //Dynamically allocating column space
		    for(int i=0; i<number_of_nodes; i++){
		        cost[i] = new int[number_of_nodes];
		        dist[i] = new int[number_of_nodes];
		        path[i] = new char[number_of_nodes];
		        router[i]=i+65;
		    }		
		}
		
		void input();
		void routing_table();
		void output();
		void display();
};

void Q5::input(){
	cout<<"\nEnter the cost between gives nodes :\n";
	for(int i=0;i<number_of_nodes;i++){
		for(int j=0;j<number_of_nodes;j++){
			int d;
			if(i>=j){
					if(i==j){
					cost[i][j]=0;
					dist[i][j]=0;
					path[i][j]=router[j];
				}
				else{
					cout<<router[i]<<"---"<<router[j]<<" :";
					cin>>d;
					cost[i][j]=d;
					cost[j][i]=d;	
					dist[i][j]=cost[i][j];
					dist[j][i]=cost[i][j];
					path[i][j]=router[j];	
				}
			}
			else
				path[i][j]=router[j];	
			}
		}
	}


void Q5::output(){
	cout<<"\n\n\n\nCost Matrix\n\n   ";
	for(int k=0;k<number_of_nodes;k++)
		cout<<router[k]<<"  ";
	cout<<endl;	
	for(int i=0;i<number_of_nodes;i++){
		cout<<router[i]<<"  ";	
		for(int j=0;j<number_of_nodes;j++){
				cout<<cost[i][j]<<"  ";
		}
		cout<<endl;
	}
}


void Q5::routing_table(){
	for(int i = 0; i < number_of_nodes; i++) 
		for(int j = i+1; j < number_of_nodes; j++)
            	for(int k = 0; k < number_of_nodes; k++){
					if(dist[i][j] > cost[i][k] + dist[k][j]  && (cost[i][k]>0 && cost[k][j]>0)||(dist[i][j]==0))
	                { 
						dist[i][j] = dist[i][k] + dist[k][j];
	                    dist[j][i] = dist[i][j];
	                    path[i][j] = router[k];
	                    path[j][i] = router[k];
	                }
				}
	                      
}

void Q5::display(){
		char src,dest;
		cout<<"\n\t~~~~~~~~~ROUTING TABLE~~~~~~~~~~~~";
		cout<<"\n\t==============================================\n\n";	

		for(int i = 0; i < number_of_nodes; i++)
        {
            cout<<"\n For router: "<<router[i];
            cout<<"\n===============================================";
            cout<<"\n| Dest  |  Intermediate Node  |  Min. Distance |";
            cout<<"\n===============================================";
            for(int j = 0; j < number_of_nodes; j++){
        		cout<<"\n|   "<<router[j]<<"   |         "<<path[i][j]<<"           |       "<<dist[i][j]<<"        |";
                cout<<"\n-----------------------------------------------";    	
			}
        }
        
        cout<<"\n\nEnter source router (in upper case) : ";
        cin>>src;
        cout<<"Enter Destination router (in upper case) : ";
        cin>>dest;
        int m=src-65;
        int n=dest-65;
        cout<<"Minimum Distace :"<<dist[m][n];
}

int main(){
	Q5 obj;
	obj.input();
	obj.output();
	obj.routing_table();
	obj.display();
	getch();
	return 0;
}
