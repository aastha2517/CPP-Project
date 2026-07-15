#include<iostream>
using namespace std;

class LibraryItem{
	
	private:
		
		string title;
		string author;
		string dueDate;
		
	public:
		
		void setTitle(string newTitle){
			this->title=newTitle;
		}
		
		void setAuthor(string newAuthor){
			this->author=newAuthor;
		}
		
		void setDueDate(string newDueDate){
			this->dueDate=newDueDate;
		}
		
		string getTitle(){
			return title;
		}
		
		string getAuthor(){
			return author;
		}
		
		string getDueDate(){
			return dueDate;
		}
		
		virtual void setPages(int a){
			
		}
	
		virtual void setISBN(string n){
		}
		
		virtual void setDuration(int duration){
			
		}
		
		virtual void setIssueNumber(int num){
			
		}
		
		virtual void checkOut() = 0;
		virtual void returnItem() = 0;
		virtual void displayDetails() = 0;
		
};

class Book : public LibraryItem{
	
	private:
		int pages;
		string isbn;
	public:
		
		void setPages(int page){
			this->pages=page;
		}
		
		void setISBN(string isbn){
			this->isbn=isbn;
		}
		
		int getPages(){
			return pages;
		}
		
		string getISBN(){
			return isbn;
		}
		
		void checkOut(){
			cout<<"Book Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"Book Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"Book Title is : "<<LibraryItem::getTitle()<<endl; 
			cout<<"Book Due Date is : "<<LibraryItem::getDueDate()<<endl;
			cout<<"Book Author is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"Book Pages are : "<<getPages()<<endl;
			cout<<"Book ISBN is : "<<getISBN()<<endl;
		}
			
	
};

class DVDs : public LibraryItem{
	
	private:
		int duration;
		
	public:
		
		void setDuration(int duration){
			this->duration=duration;
		}
		
		int getDuration(){
			return duration;
		}
		
		void checkOut(){
			cout<<"DVD Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"DVD Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"Book Title is : "<<LibraryItem::getTitle()<<endl; 
			cout<<"Book Due Date is : "<<LibraryItem::getDueDate()<<endl;
			cout<<"Book Author is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"DVD Duration is : "<<getDuration()<<endl;
		}
			

	
};

class Magazines : public LibraryItem{
	
	private:
		int issueNumber;
		
	public:
		
		void setIssueNumber(int issueNum){
			this->issueNumber=issueNum;
		}
		
		int getIssueNumber(){
			return issueNumber;
		}
		
		void checkOut(){
			cout<<"Magazines Issued Successfully...."<<endl;
		}
		
		void returnItem(){
			cout<<"Magazines Returned Successfully...."<<endl;
		} 
		
		void displayDetails(){
			cout<<"Book Title is : "<<LibraryItem::getTitle()<<endl; 
			cout<<"Book Due Date is : "<<LibraryItem::getDueDate()<<endl;
			cout<<"Book Author is : "<<LibraryItem::getAuthor()<<endl;
			cout<<"Magazines Issue Number is : "<<getIssueNumber()<<endl;
		}
			

};


int main(){
	
	int choice,itemChoice,issueNum,duration,page;
	string title,author,dueDate,isbn;
	int index=0;
	
	LibraryItem *libraryArr[100]; 
	
	do{
		cout<<endl;
		cout<<"Press 1 to Library Item"<<endl;
		cout<<"Press 2 to Search"<<endl;
		cout<<"Press 3 to Checkout"<<endl;
		cout<<"Press 4 to Return"<<endl;
		cout<<"Press 5 to Display"<<endl;
		cout<<"Press 6 to Exit"<<endl;
		cout<<"-------------------------------------------"<<endl<<endl;
		
		cout<<"Enter your Choice : ";
		cin>>choice;
		
		switch(choice){
			
			case 1:
				
				cout<<endl;
				cout<<"Press 1 to Add Book"<<endl;
				cout<<"Press 2 to Add DVD"<<endl;
				cout<<"Press 3 to Add Magazine"<<endl;
				cout<<"Press 4 to Exit"<<endl;
				cout<<"-------------------------------------------"<<endl<<endl;
				
				cout<<"Enter Your Choice : ";
				cin>>itemChoice;
				
				switch(itemChoice){
					
					case 1:
						
						cout<<"Enter Book Title : ";
						cin>>title;
						
						cout<<"Enter Book Author Name : ";
						cin>>author;
						
						cout<<"Enter Book Due Date : ";
						cin>>dueDate;
						
						cout<<"Enter Book Pages : ";
						cin>>page;
						
						
						try{
							
							cout<<"Enter Book ISBN Code : ";
							cin>>isbn;
							
							if(isbn.length()!=13){
								throw 123;
							}
					
						}catch(int a){
							cout<<"ISBN Code is not 13 Digits so Rewrite it...";
							cout<<endl;
							cout<<"Enter Book ISBN Code : ";
							cin>>isbn;
						}
						
						libraryArr[index] = new Book();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setPages(page);
						libraryArr[index]->setISBN(isbn);
						
						index++;
						
						
						break;
						
					case 2:
						
						cout<<"Enter DVDs Title : ";
						cin>>title;
						
						cout<<"Enter DVDs Author Name : ";
						cin>>author;
						
						cout<<"Enter DVDs Due Date : ";
						cin>>dueDate;
						
						cout<<"Enter DVDs Duration :";
						cin>>duration;
						
						
						libraryArr[index] = new DVDs();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setDuration(duration);
						
						index++;
						
						break;
						
					case 3:
						
						cout<<"Enter Magazines Title : ";
						cin>>title;
						
						cout<<"Enter Magazines Author Name : ";
						cin>>author;
						
						cout<<"Enter Magazines Due Date : ";
						cin>>dueDate;
						
						cout<<"Enter Magazines Issue Number :";
						cin>>issueNum;
						
						libraryArr[index] = new Magazines();
						
						libraryArr[index]->setTitle(title);
						libraryArr[index]->setAuthor(author);
						libraryArr[index]->setDueDate(dueDate);
						libraryArr[index]->setIssueNumber(issueNum);
						
						index++;
						break;
						
					case 4:
						cout<<"Exited....."<<endl;
						break;
						
					default:
						cout<<"Invalid Choice...."<<endl;
						break;
				}
				
				break;
				
			case 2:{
				
				cout<<"Enter Title to Search (Book / DVDs / Magazines) :";
				cin>>title;
				
				bool flag = false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==title){
						flag = true;
						cout<<endl;
						libraryArr[i]->displayDetails();
						break;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Found...."<<endl;
					break;
				}
				break;
			}
			case 3:{

				cout<<"Enter Title to Search (Book / DVDs / Magazines) :";
				cin>>title;
				
				bool flag = false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==title){
						flag = true;
						libraryArr[i]->checkOut();
						break;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Found...."<<endl;
					break;
				}
				
				break;
			}
			
			case 4:{
				
				cout<<"Enter Title to Search (Book / DVDs / Magazines) :";
				cin>>title;
				
				bool flag = false;
				
				for(int i=0;i<index;i++){
					if(libraryArr[i]->getTitle()==title){
						flag = true;
						libraryArr[i]->returnItem();
						break;
					}
				}
				
				if(flag==false){
					cout<<"Library Item Not Found...."<<endl;
					break;
				}
				
				break;
			}
				
			case 5:
				
				for(int i=0;i<index;i++){
					cout<<endl;
					libraryArr[i]->displayDetails();
				}
			
				break;
				
			case 6:
				cout<<"Exiting The System...";
				break;
				
			default:
				cout<<"Invalid Choice..."<<endl;
				break;
			
		}
	}while(choice!=6);
	
	return 0;
}