#include<iostream>
using namespace std;
class LibraryItem{
	private:
		string title;
		string author;
		string dueDate;
		
	public:
		
		
		void setTitle(string title){
			this->title=title;
		}
		
		void setAuthor(string author){
			this->author=author;
		}
		
		void setDueDate(string dueDate){
			this->dueDate=dueDate;
		}	
		
		void getTitle(){
			cout<<"Book Title is :"<<title<<endl;
		}
		
		void getAuthor(){
			cout<<"Book Author Name is  :"<<author<<endl;
		}
		
		void getDueDate(){
			cout<<"Book Due Date is :"<<dueDate<<endl;
		}
		
		
		virtual void checkOut() = 0;
		
		virtual void returnItem() = 0;
		
		virtual void displayDetails() = 0;
		
};


class Book:public LibraryItem{
	private :
		int pages;
		string isbn;
	public :
		
		void setpages(int pages){
			this->pages=pages;
		}
		
		void setisbn(string isbn){
			this->isbn=isbn;
		}
		
		void getpages(){
			cout<<"Book Pages are :"<<pages<<endl;
		}
		
		void getisbn(){
			cout<<"Book ISBN is :"<<isbn<<endl;
		}
		
		void checkOut(){
			cout<<"Book Issue Successfully....."<<endl;
		}
		
		void returnItem(){
			cout<<"Book Returned Successfully....."<<endl;
		}
		
		void displayDetails(){
			LibraryItem::getTitle();
			LibraryItem::getAuthor();
			LibraryItem::getDueDate();
			getpages();
			getisbn();
		}
	
};

class DVDs:public LibraryItem{
	
	private :
		int duration;
	
	public :
		
		void setduration(int duration){
		 	this->duration =duration;
		}
		 
		void getduration(){
		 	cout<<"DVDs Duration is :"<<duration<<"Days"<<endl;
		}
		 
		void checkOut(){
			cout<<"DVDs Issue Successfully....."<<endl;
		}
		
		void returnItem(){
			cout<<"DVDs Returned Successfully....."<<endl;
		}
		
		void displayDetails(){
			LibraryItem::getTitle();
			LibraryItem::getAuthor();
			LibraryItem::getDueDate();
			getduration();
		}
		
		
};

class Magazine :public LibraryItem{
	
	private :
		int issueNumber;
	
	public :
		
		void setissueNumber(int number){
		 	this->issueNumber=number;
		}
		 
		void getissueNumber(){
		 	cout<<"Magazine Issue Number is :"<<issueNumber<<endl;
		}
		 
		void checkOut(){
			cout<<"Magazine Issue Successfully....."<<endl;
		}
		
		void returnItem(){
			cout<<"Magazine Returned Successfully....."<<endl;
		}
		
		void displayDetails(){
			LibraryItem::getTitle();
			LibraryItem::getAuthor();
			LibraryItem::getDueDate();
			getissueNumber();
		}
		
};

int main(){
	
	int choice,itemchoice,issueNumber,duration,pages;
	string title,author,dueDate,isdn;
	
	LibraryItem *LibraryArr[100] = new LibraryItem();
	int index=0;
	
	do{
		
		
		
		cout<<"Press 1 To Library Item"<<endl;
		cout<<"Press 2 To Search"<<endl;
		cout<<"Press 3 To CheckOut"<<endl;
		cout<<"Press 4 To Return"<<endl;
		cout<<"Press 5 To Display"<<endl;
		cout<<"Press 6 To Exit"<<endl;
		
		cout<<"Enter Your Choice";
		cin>>choice;
		
		switch(choice){
			case 1:{
			
				cout<<"Press 1 to Add Book"<<endl;
				cout<<"Press 2 to Add DVDs"<<endl;
				cout<<"Press 3 to Add Magazine"<<endl;
				
				cout<<"Enter Your Choice :";
				cin>>itemchoice;
				
				switch(itemchoice){
					case 1:{
						
						cout<<"Enter Book Title :";
						cin>>title;
						
						cout<<"Enter Book Author Name :";
						cin>>author;
						
						cout<<"Enter Book Due Date :";
						cin>>dueDate;
						
						cout<<"Enter Book Pages :";
						cin>>pages;
						
						cout<<"Enter Book ISBN Code :";
						cin>>isdn;
						
						LibraryArr[index]->setTitle(title);
						LibraryArr[index]->setAuthor(author);
						LibraryArr[index]->setDueDate(dueDate);
						LibraryArr[index]->setpages(pages);
						LibraryArr[index]->setisbn(isbn);
						
						index++;
							
						break;
					}
					case 2:{
						break;
					}
					case 3:{
						break;
					}
					default:{
						cout<<"Invalid Choice...."<<endl;
						break;
					}
				}
				break;
			} 
			case 2:{
				break;
			} 
			case 3:{
				break;
			} 
			case 4:{
				break;
			} 
			case 5:{
				break;
			} 
			case 6:{
				cout<<"Exiting The System...."<<endl;
				break;
			}
			default:{
				cout<<"Invalid Choice....."<<endl;
				break;
			} 
		}
		
	}while(choice!=7);
	
	return 0;
}