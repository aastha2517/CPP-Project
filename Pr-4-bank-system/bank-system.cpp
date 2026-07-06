#include<iostream>
using namespace std;

class BankAccount{
	private:
		int AccountNumber;
		string AccountHolderName;
		double balance;

	public:
		string gettype;
		BankAccount(){
			
		}
		
		BankAccount(int a_number,string name,double balance,string gettype){
			this->AccountNumber=a_number;
			this->AccountHolderName=name;
			this->balance=balance;
			this->gettype=gettype;
		}
		
		void setAccountinfo(int a_number,string name,double balance,string gettype){
			this->AccountNumber=a_number;
			this->AccountHolderName=name;
			this->balance=balance;
			this->gettype=gettype;
		}
		
		void deposit(int d_amount){
			balance += d_amount;
		}
			
		void withdraw(int w_amount){
			balance -= w_amount;
		}
		
		double getbalance(){
			return balance;
		}
		
		void displayAccountInfo(){
			cout<<"Account Number :"<<AccountNumber<<endl<<"Account Holder Name : "<<AccountHolderName<<endl<<"Balance :"<<balance<<endl;
		}
		
		string displaytype(){
			return gettype;
		}
		
		int getacc_number(){
			return AccountNumber;
		}
		
		~BankAccount(){
			
		}	
};

class SavingsAccount:public BankAccount{
	private:
		float interestRate=5;
		int interest;
	public:
		
		SavingsAccount(){
			
		}
		
		SavingsAccount(int a_number,string name,double balance,string gettype)
		:BankAccount(a_number,name,balance,gettype){

		}
		
		void setSavingsAccountinfo(int a_number,string name,double balance,string gettype)
		{
			BankAccount::setAccountinfo(a_number,name,balance,gettype);
		}
		
		void getSavingsAccountinfo(){
			BankAccount::displayAccountInfo();
			cout<<"Interest Rate :"<<interestRate<<endl;
			cout<<"Interest :"<<interest<<endl;
			
		}
		
		void calculateInterest(){
			interest=(getbalance())*0.05;
		}
		
		~SavingsAccount(){
			
		}
};

class CheckingAccount :public BankAccount{
	
	private:
		double overdraftLimit;
		double amount;
		
		
	public:
		
		CheckingAccount(){
			
		}
		
		CheckingAccount(int a_number,string name,double balance,double overdraft,string gettype)
		:BankAccount(a_number,name,balance,gettype){
			this->overdraftLimit=overdraft;
		}
		
		void setCheckingAccountinfo(int a_number,string name,double balance,double overdraft,string gettype)
		{
			BankAccount::setAccountinfo(a_number,name,balance,gettype);
			this->overdraftLimit=overdraft;
		}
		double checkOverdraft(){
			
			double limit=(getbalance())+overdraftLimit;
			return limit;
		}
		void withdraw(double amount){
			
			double limit=checkOverdraft();
			
			if(amount<=limit){
				BankAccount::withdraw(amount);
				cout<<"Withdrawal Successful......"<<endl;
			}else{
				cout <<"Overdraft Limit Exceeded..."<<endl;
			}	
			
		
		}
		
		void getCheckingAccountinfo(){
			BankAccount::displayAccountInfo();
			cout<<"Overdraft Limit :"<<overdraftLimit<<endl;
		}
		
};
class FixedDepositAccount :public BankAccount{
	private:
		float interestRate=8;
		int term;
		int interest;
		
	public:
		
		FixedDepositAccount(){
			
		}
		
		FixedDepositAccount(int a_number,string name,double balance,int term,string gettype)
		:BankAccount(a_number,name,balance,gettype){
			this->term=term;
		}
		
		void setFixedDepositAccountinfo(int a_number,string name,double balance,int term,string gettype)
		{
			BankAccount::setAccountinfo(a_number,name,balance,gettype);

			this->term=term;
		}
		
		void getFixedDepositAccountinfo(){
			BankAccount::displayAccountInfo();
			cout<<"Interest Rate :"<<interestRate<<endl;
			cout<<"Term :"<<term<<endl;
			cout<<"Interest :"<<interest<<endl;
		}
		
		void calculateInterest(){
			interest=(getbalance())*0.08*term;
		}
		
		~FixedDepositAccount(){
			
		}
};
int main(){
	
	double a_number,balance,term,overdraft;
	int choice,wd,d_amount,w_amount,acc_choice;
	string a_name,gettype,yes_no;
	int index=0;
	
	BankAccount *bankArr[100];
	
	do{
		cout<<"--------------------------------------------"<<endl;
		cout<<"Press 1 to Create  Account"<<endl;
		cout<<"Press 2 to Withdraw"<<endl;
		cout<<"Press 3 to Deposit"<<endl;
		cout<<"Press 4 to See Your Account Info"<<endl;
		cout<<"Press 5 to Exit"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<endl;
		
		cout<<"Enter Your Choice :";
		cin>>choice;
		
		switch(choice){
			case 1 :{
				
				cout<<endl;
				cout<<"Press 1 to Add Saving Account"<<endl;
				cout<<"Press 2 to Add Checking Account"<<endl;
				cout<<"Press 3 to Add Fix Deposit Account"<<endl;
				cout<<"--------------------------------------------"<<endl;
				cout<<endl;
				
				cout<<"Enter Your Choice :";
				cin>>acc_choice;
				
				switch(acc_choice){
					case 1 :{
					
						
						cout<<"Enter Account Number :";
						cin>>a_number;
						cout<<"Enter Account Holder Name :";
						cin>>a_name;
						cout<<"Enter Account Balance :";
						cin>>balance;
						gettype="Saving Account";
					
						
						SavingsAccount *s1=new SavingsAccount();
						s1->setSavingsAccountinfo(a_number,a_name,balance,gettype);
						bankArr[index]=s1;
						index++;
						
						break;	
					}
					case 2 :{
						
						cout<<"Enter Account Number :";
						cin>>a_number;
						cout<<"Enter Account Holder Name :";
						cin>>a_name;
						cout<<"Enter Account Balance :";
						cin>>balance;
						cout<<"Enter Overdraft Limit :";
						cin>>overdraft;
						gettype="Checking Account";
							
						
						CheckingAccount *c1=new CheckingAccount();
						c1->setCheckingAccountinfo(a_number,a_name,balance,overdraft, gettype);
						bankArr[index]=c1;
						index++;
						
						break;
					}
						
					case 3 :{
					
						cout<<"Enter Account Number :";
						cin>>a_number;
						cout<<"Enter Account Holder Name :";
						cin>>a_name;
						cout<<"Enter Account Balance :";
						cin>>balance;
						cout<<"Enter Your Term :";
						cin>>term;
						gettype="Fix Deposit Account";
						
						FixedDepositAccount *f1=new FixedDepositAccount();
						f1->setFixedDepositAccountinfo(a_number,a_name,balance,term,gettype);
						bankArr[index]=f1;
						index++;
						
						break;
					}
					default :
						cout<<"Invalid Choice...."<<endl;
						break;
						
				}
				cout<<"Account Successfully Created....."<<endl;
			break;
			}
			
			case 2 :{
				
				cout<<"Enter Account Number :";
				cin>>a_number;
				
				bool flag = false;
				for(int i=0;i<index;i++){
					if(bankArr[i]->getacc_number()==a_number){
						flag = true;
						if(bankArr[i]->displaytype()=="Saving Account"){
							cout<<"Enter Withdraw Amount :";
							cin>>w_amount;
							bankArr[i]->withdraw(w_amount);
							cout<<"Withdrawal Successful......"<<endl;
						}else if(bankArr[i]->displaytype()=="Checking Account"){
							cout<<"Enter Withdraw Amount :";
							cin>>w_amount;
							((CheckingAccount*)bankArr[i])->withdraw(w_amount);
						}else if(bankArr[i]->displaytype()=="Fix Deposit Account"){
							cout<<"Can't Withdraw from Fix Deposit"<<endl;
						}else{
							cout<<"Something get wrong...."<<endl;
							break;
						}
						break;
					} 
						
				}
				if(flag==false){
					cout<<"There is no Account found......"<<endl;
				}
				
				
				break;
			}
			
			case 3 :{
				
				cout<<"Enter Account Number :";
				cin>>a_number;
				
				for(int i=0;i<index;i++){
					if(bankArr[i]->getacc_number()==a_number){
						cout<<"Enter Deposit Amount :";
						cin>>d_amount;
						bankArr[i]->deposit(d_amount);
						cout<<"Deposite Successful......"<<endl;
						break;
					}else{
						cout<<"There is no Account found......"<<endl;
						break;
					}
				}
				
				break;
			}
	
			case 4:{
				for(int i=0;i<index;i++){
					if(bankArr[i]->displaytype()=="Saving Account"){
						((SavingsAccount*)bankArr[i])->calculateInterest();
						((SavingsAccount*)bankArr[i])->getSavingsAccountinfo();	
						cout<<"--------------------------------------------"<<endl;
						cout<<endl;
					}else if(bankArr[i]->displaytype()=="Checking Account"){
						((CheckingAccount*)bankArr[i])->getCheckingAccountinfo();
						cout<<"--------------------------------------------"<<endl;
						cout<<endl;		
					}else{
						((FixedDepositAccount*)bankArr[i])->calculateInterest();		
						((FixedDepositAccount*)bankArr[i])->getFixedDepositAccountinfo();	
						cout<<"--------------------------------------------"<<endl;
						cout<<endl;	
					}
				}
				break;
			}
			default :{
				cout<<"Exiting From System.....";
				break;
			}
		
		}
	}while(choice!=5);
	return 0;
}