#include<iostream>
using namespace std;

class BankAccount{
	private:
		int AccountNumber;
		string AccountHolderName;
		
	protected:
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
		
		void getbalance(){
			cout<<"Current Balance :"<<balance<<endl;
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
			interest= balance*0.05;
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
//			this->amount=amount;
		}
		
		void setCheckingAccountinfo(int a_number,string name,double balance,double overdraft,string gettype)
		{
			BankAccount::setAccountinfo(a_number,name,balance,gettype);
			this->overdraftLimit=overdraft;
//			this->amount=amount;
		}
		double checkOverdraft(){
			
			double limit=balance+overdraftLimit;
			return limit;
		}
		double withdraw(double amount){
			
			double limit=checkOverdraft();
			
			cout<<"Enter withdrawal Amount :";
			cin>>amount;
			
			if(amount<=limit){
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
			interest= balance*0.08*term;
		}
		
		~FixedDepositAccount(){
			
		}
};
int main(){
	
	double a_number,balance,term,overdraft;
	int choice,wd,d_amount,w_amount;
	string a_name,gettype,yes_no;
	int index=0;
	
	BankAccount *bankArr[100];
	
	do{
		cout<<"Press 1 to Create Saving Account"<<endl;
		cout<<"Press 2 to Create Checking Account"<<endl;
		cout<<"Press 3 to Create Fixed Deposite Account"<<endl;
		cout<<"Press 4 to Withdraw"<<endl;
		cout<<"Press 5 to Deposit"<<endl;
//		cout<<"Press 6 to Withdraw form Checking Account"<<endl;
		cout<<"Press 7 to Check Overdraft"<<endl;
		cout<<"Press 8 to See Your Account Info"<<endl;
		cout<<"Press 9 to Exit"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<endl;
		
		cout<<"Enter Your Choice :";
		cin>>choice;
		
		switch(choice){
			case 1 :{

				
				cout<<"Enter Account Number :";
				cin>>a_number;
				cout<<"Enter Account Holder Name :";
				cin>>a_name;
				cout<<"Enter Account Balance :";
				cin>>balance;
				gettype="Saving Account";
//				cout<<"If You Want to Withdraw From Checking Account Enter Yes :";
//				cin>>yes_no;
				
				SavingsAccount *s1=new SavingsAccount();
				s1->setSavingsAccountinfo(a_number,a_name,balance,gettype);
				bankArr[index]=s1;
				index++;
//				if(yes_no=="Yes"||"yes"||"YES"){
//					cout<<"Press 1 to Deposit"<<endl;
//					cout<<"Press 2 to Withdraw"<<endl;
//					cout<<"Enter Your Choice :";
//					cin>>wd;
//					if(wd==1){
//						cout<<"Enter Amount To Deposit :";
//						cin>>d_amount;
//						s1->deposit(d_amount);	
//						cout<<"Deposit successfully......"<<endl;
//					}else if(wd==2){
//						cout<<"Enter Amount To Withdraw :";
//						cin>>w_amount;
//						s1->withdraw(w_amount);
//						cout<<"Withdraw successfully......"<<endl;
//					}else{
//						cout<<"Somthing get wrong...."<<endl;
//					}
//				}else{
//					break;
//				}
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
//				cout<<"Enter withdrawal Amount :";
//				cin>>amount;
				cout<<"If You Want to Withdraw From Checking Account Enter Yes :";
				cin>>yes_no;
				
					
				
				CheckingAccount *c1=new CheckingAccount();
				c1->setCheckingAccountinfo(a_number,a_name,balance,overdraft, gettype);
				bankArr[index]=c1;
				if(yes_no=="Yes"||"yes"||"YES"){
					c1->checkOverdraft();
				}else{
					break;
				}
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
			
			case 4:
				
				cout<<"Enter Account Number :";
				cin>>a_number;
				for(int i=0;i<index;i++){
					if(bankArr[i]->getacc_number()==a_number){
						if(bankArr[i]->displaytype()=="Saving Account"){
							cout<<"Enter Withdraw Amount :";
							cin>>w_amount;
							bankArr[i]->withdraw(w_amount);
//							break;
							return;
						}
//						else if(bankArr[i]->displaytype()=="Checking Account"){
////							cout<<"You Don't have Saving Account....."<<endl;
////							if(bankArr[i]->displaytype()=="Checking Account"){
//							cout<<"Enter Withdraw Amount :";
//							cin>>w_amount;
//							bankArr[i]->withdraw(w_amount);
//						}
					}
					
					cout<<"Account Number not Found....."<<endl;
				}		
//				break;				
			case 8:{
				for(int i=0;i<index;i++){
					if(bankArr[i]->displaytype()=="Saving Account"){
						((SavingsAccount*)bankArr[i])->calculateInterest();
						((SavingsAccount*)bankArr[i])->getSavingsAccountinfo();	
					}else if(bankArr[i]->displaytype()=="Checking Account"){
						((CheckingAccount*)bankArr[i])->getCheckingAccountinfo();		
					}else{
						((FixedDepositAccount*)bankArr[i])->calculateInterest();		
						((FixedDepositAccount*)bankArr[i])->getFixedDepositAccountinfo();		
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