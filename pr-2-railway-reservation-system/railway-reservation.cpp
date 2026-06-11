#include<iostream>
using namespace std;
class Train{
	private:
		int trainNumber;
		string trainName;
		string source;
		string destination;
		string trainTime;
		
	public:
		
		// Defult Constructor
		
		Train(){
		}
		
		// Parameterized Constructor
		
		Train(int number,string name,string source,string destination,string time){
			trainNumber=number;
			trainName=name;
			this->source=source;
			this->destination=destination;
			trainTime=time;
		}
		
		// Static variable
		
		static int trainCount;
		
		// Setter Function
		
		void inputTrainDetail(int number,string name,string source,string destination,string time){
			trainNumber=number;
			trainName=name;
			this->source=source;
			this->destination=destination;
			trainTime=time;
		}
		
		//Getter Function
		
		void displayTrainDetail(){
			cout<<"TRAIN NUMBER :"<<trainNumber<<endl<<"TRAIN NAME :"<<trainName<<endl<<"SOURCE :"
			<<source<<endl<<"DESTINATION :"<<destination<<endl<<"TRAIN TIME :"<<trainTime<<endl;
			getTrainCount();
			cout<<"----------------------------"<<endl;
		}
		
		static void getTrainCount(){
			trainCount++;
			cout<<"Train count :"<<trainCount<<endl;
		}
		
		// Destructor
		
		~Train(){
			trainCount--;	
		}
		
		

};
int Train::trainCount = 0;	

int main(){
	

	int n,number;
	cout<<endl<<"Enter Train record number :";
	cin>>n;
	string name,source,destination,time;
	Train trains[n];
	for(int i=0;i<n;i++){
		cout<<endl<<"Train "<<i+1<<" Detail"<<endl;
		cout<<endl<<"Enter Train Number:";
		cin>>number;
		cout<<endl<<"Enter Train Name:";
		cin>>name;
		cout<<endl<<"Enter Source:";
		cin>>source;
		cout<<endl<<"Enter Destination:";
		cin>>destination;
		cout<<endl<<"Enter Train Time:";
		cin>>time;
		cout<<endl;
		trains[i].inputTrainDetail(number,name,source,destination,time);
	}
	for(int i=0;i<n;i++){
		trains[i].displayTrainDetail();
	}
	return 0;
	
}