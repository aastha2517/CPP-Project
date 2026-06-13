#include<iostream>
using namespace std;
class Train{
	private:
		
		// Member Variable
		string trainName;
		string source;
		string destination;
		string trainTime;
		
	public:
				
		// Static variable
		static int trainCount;
		
		int trainNumber;
		
		// Defult Constructor
		Train(){
		}
		
		// Parameterized Constructor
		Train(int number,string name,string source,string destination,string time){
			this->trainNumber=number;
			this->trainName=name;
			this->source=source;
			this->destination=destination;
			this->trainTime=time;
			trainCount++;
		}

		// Setter Function
		void inputTrainDetail(int number,string name,string source,string destination,string time){
			trainNumber=number;
			trainName=name;
			this->source=source;
			this->destination=destination;
			trainTime=time;
			trainCount++;
		}
		
		//Getter Function
		void displayTrainDetail(){
			cout<<"TRAIN NUMBER :"<<trainNumber<<endl<<"TRAIN NAME :"<<trainName<<endl<<"SOURCE :"
			<<source<<endl<<"DESTINATION :"<<destination<<endl<<"TRAIN TIME :"<<trainTime<<endl;
			getTrainCount();
			cout<<"----------------------------"<<endl;
		}
		
		// Static Function
		static int getTrainCount(){
			return trainCount;
		}
		
		// Destructor
		~Train(){
			trainCount--;	
		}
		
};

class RailwaySystem{

	private:
		
		Train trains[100];
		int totaltrains=0;
		
	public:
		
		// 1.Add Train Function
		void addTrain(int number,string name,string source,string destination,string time){
			trains[totaltrains].inputTrainDetail(number,name,source,destination,time);
			totaltrains++;
			cout<<"Train Create Successfully......"<<endl;
		}
		
		// Display Train Records Function
		void displayAllTrains(){
			for(int i=0;i<totaltrains;i++){
				trains[i].displayTrainDetail();
			}
		}
		
		// Search Train by Number Function
		void searchTrainByNumber(int number){
		    for(int i=0;i<totaltrains;i++){
		        if(trains[i].trainNumber==number){
		            trains[i].displayTrainDetail();
		            return;
		        }
		    }
		
		    cout<<"Train Number is Not Found....."<<endl;
		}
};

int Train::trainCount = 0;	

int main(){

	RailwaySystem irctc;
	int choice;
	
	do{
		cout<<endl;
		cout<<"--- Railway Reservation System Menu ---"<<endl;
		cout<<"Press 1 for Add New Train Record "<<endl;
		cout<<"Press 2 for Display All Train Records "<<endl;
		cout<<"Press 3 for Search Train by Number "<<endl;
		cout<<"Press 4 for Exit"<<endl;
		cout<<endl;
		
		cout<<"Enter Your Choice :";
		cin>>choice;
		
		int number;
		string name,source,destination,time;
		
		switch(choice){
			
			case 1 :
				cout<<"Enter Train Number:" ;
				cin>>number;
				cout<<"Enter Train Name:";
				cin>>name;
				cout<<"Enter Source:";
				cin>>source;
				cout<<"Enter Destination:";
				cin>>destination;
				cout<<"Enter Train Time:";
				cin>>time;
				irctc.addTrain(number,name,source,destination,time);
				break;
				
			case 2:
				irctc.displayAllTrains();
				break;
				
			case 3:
				int num;
				cout<<"Enter Train Number to search :";
				cin>>num;
				irctc.searchTrainByNumber(num);
				break;
				
			default:
				cout<<"Exiting The system Thank You ....."<<endl;
		}	
	
	}while(choice!=4);
	
	return 0;
	
}