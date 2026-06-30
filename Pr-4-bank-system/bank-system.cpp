#include<iostream>
using namespace std;

class BankAccount{
	private:
		int AccountNumber;
		string AccountHolderName;
		
	protected:
		double balance;

	public:
		
		BankAccount(){
			
		}
		
		BankAccount(int a_number,string name,double balance){
			this->AccountNumber=a_number;
			this->AccountHolderName=name;
			this->balance=balance;
		}
		
		void setAccountinfo(int a_number,string name,double balance){
			this->AccountNumber=a_number;
			this->AccountHolderName=name;
			this->balance=balance;
		}
		
		void deposit(int d_amount){
			balance += d_amount;
		}
			
		void withdraw(int w_amount){
			balance -= w_amount;
		}
		
		void getbalance(){
			cout<<"Current Balance :"<<balance<<endl;
		}
		
		void displayAccountInfo(){
			cout<<"Account Number :"<<AccountNumber<<endl<<"Account Holder Name : "<<AccountHolderName<<endl<<"Balance :"<<balance<<endl;
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
		
		SavingsAccount(int a_number,string name,double balance)
		:BankAccount(a_number,name,balance){

		}
		
		void setSavingsAccountinfo(int a_number,string name,double balance)
		{
			BankAccount::setAccountinfo(a_number,name,balance);
		}
		
		void getSavingsAccountinfo(){
			BankAccount::displayAccountInfo();
			cout<<"Interest Rate :"<<interestRate<<endl;
			cout<<"Interest :"<<interest<<endl;
			
		}
		
		void calculateInterest(){
			interest= balance*0.05;
		}
		
		~SavingsAccount(){
			
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
		
		FixedDepositAccount(int a_number,string name,double balance,int term)
		:BankAccount(a_number,name,balance){
			this->term=term;
		}
		
		void setFixedDepositAccountinfo(int a_number,string name,double balance,int term)
		{
			BankAccount::setAccountinfo(a_number,name,balance);

			this->term=term;
		}
		
		void getFixedDepositAccountinfo(){
			BankAccount::displayAccountInfo();
			cout<<"Interest Rate :"<<interestRate<<endl;
			cout<<"Term :"<<term<<endl;
			cout<<"Interest :"<<interest<<endl;
		}
		
		void calculateInterest(){
			interest= balance*0.08*term;
		}
		
		~FixedDepositAccount(){
			
		}
};
int main(){
	
//	BankAccount b1;
//	
//	b1.setAccountinfo(101,"aastha",15000);
//	b1.withdraw(5000);
//	b1.deposit(10000);
//	b1.displayAccountInfo();
//	b1.getbalance();
//	
//	SavingsAccount s1;
//	
//	s1.setSavingsAccountinfo(102,"Jiya",10000);
//	s1.calculateInterest();
//	s1.getSavingsAccountinfo();
//
//	FixedDepositAccount f1;
//	
//	f1.setFixedDepositAccountinfo(103,"prachi",20000,2);
//	f1.calculateInterest();
//	f1.getFixedDepositAccountinfo();

	return 0;
}