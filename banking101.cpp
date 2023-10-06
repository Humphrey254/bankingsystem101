#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std; 

//declare gloabal variables
int phoneNo,id,age,accNo,accNo1,option3; 
char name[50],address[60];
int choice,choice3,deposit,withdraw, balance;

//declare a class 
class CustomerService
{
	public : 
	void customer();
	void getCustomer();
	void viewCustomer();
	void acc();
	void createAcc();
	void updateAcc();
	


};	
	//customer main menu 
	
		
	void CustomerService::customer(){
		system("cls");
		cout<<"\t\t\t\t\tcustomer menu \n";
		cout<<"\t\t1.create new customer \n";
		cout<<"\t\t2.view customer \n";
		cout<<"\t\t3.update customer \n";
		cout<<"\t\t4.delete customer \n";
		cout<<"Enter option: ";
		cin>>choice;
		if(choice==1){
			getCustomer();
		}
		else if(choice==2)
		{
			viewCustomer();
		}
		else if(choice==3){
			//update
		}
		else if(choice==4)
		{
			//delete
		}
		else
		{
			cout<<"invalid option!!"; 
		}
		
	}
	//method for creating new customer
	void CustomerService:: getCustomer(){
		//system clear 
		system("cls");
		cout<<"\t\t\t\t\tcreate new customer menu \n";
		cout<<"enter name: ";
		cin>>name;
		cout<<"enter id: ";
		cin>>id;
		cout<<"enter age: ";
		cin>>age;
		cout<<"enter phoneNo: ";
		cin>>phoneNo;
		cout<<"enter address: ";
		cin>>address;
		system("cls");
		cout<<"\t\t\t------------------------------------------------------ \n";
		cout<<"\t\t\t name: "<<name<<"\n \t\t\t id number: "<<id;
		cout<<"\n \t\t\t age: "<<age<<"\n \t\t\t phone number: "<<phoneNo<<"\n \t\t\t address: "<<address;
		cout<<"\n \t\t\t------------------------------------------------------ \n";
		cout<<"enter 1 to go to menu enter any number to Exit : ";
		cin>>choice3;
		if(choice3==1){
			customer();
		}	
	
	}
	//method for viewing customer details 
	void CustomerService:: viewCustomer(){
		int id2;
		system("cls");
		cout<<"enter id to search for customer: ";
		cin>>id2;
		if(id2==id){
				cout<<"\t\t\t------------------------------------------------------ \n";
				cout<<"\t\t\t name: "<<name<<"\n \t\t\t age: "<<age;
				cout<<"\n \t\t\t address: "<<address<<"\n \t\t\t phone number: "<<phoneNo;
				cout<<"\n \t\t\t------------------------------------------------------ \n";
			}
			cout<<"enter 1 to go to menu enter any number to Exit : ";
			cin>>choice3;
			if(choice3==1){
				customer();
			}	
		
	}
	

class account : public CustomerService{
	public:
		void acc(){
			int choice1;
			system("cls");
			cout<<"\t\t\t\t\t\taccout menu \n\n\n ";
				cout<<"1. create account \n ";
				cout<<"2. update account \n";
				cout<<"3. view account \n";
				cout<<"4. delete account \n" ; 
				cout<<"5. exit \n" ; 
				cout<<"enter choice: ";
				cin>>choice1;
				if( choice1==1){
					createAcc();
				} 
				else if ( choice1==2){
					updateAcc();
				}
				else if ( choice1==3){
					viewAcc();
				}
		}

		void createAcc(){
			
			system("cls");
			cout<<"\t\t\t\t\t\tcreate account menu \n\n\n ";
			cout<<"enter id no: ";
			cin>>id;
			cout<<"enter name: ";
			cin>>name;
			cout<<"enter Account number: ";
			cin>>accNo;
			cout<<"enter amount to deposit : ";
			cin>>deposit;
			
			system("cls");
			cout<<"\t\t\t------------------------------------------------------ \n";
			cout<<"\t\t\t\thello "<<name<<" you have successfully created an account!\n";
			cout<<" \t\t\t\tyou new account number is: "<<accNo<<endl;
				cout<<" \t\t\t\tyou new balance is: "<<deposit<<endl;
			cout<<"\t\t\t------------------------------------------------------ \n\n\n";
			cout<<"enter 1 to go to menu enter any number to Exit : ";
			cin>>choice3;
			if(choice3==1){
				acc();
			}	
		 
		}
		void viewAcc(){
			
			int id2;
			system("cls");
			cout<<"enter id to search for account: ";
			cin>>id2;
			if(id2==id){
				cout<<"\t\t\t------------------------------------------------------ \n";
				cout<<"\t\t\t name: "<<name<<"\n \t\t\t account number: "<<accNo;
				cout<<"\n \t\t\t balance: "<<deposit;
				cout<<"\n \t\t\t------------------------------------------------------ \n";
			}
			cout<<"enter 1 to go to menu enter any number to Exit : ";
			cin>>choice3;
			if(choice3==1){
				acc();
			}	
			
		}
		void updateAcc(){
		system("cls");
		cout<<"\t\t\t\t\t\tupdate account menu \n\n\n ";
	    int newId,newAge,newPhoneNo;		
		char newAddress;
		cout<<"enter id: ";
		cin>>id;
		cout<<"enter  new id: ";
		cin>>newId;
		cout<<"enter age: ";
		cin>>age;
		cout<<"enter new age: ";
		cin>>newAge;
		cout<<"enter phoneNo: ";
		cin>>phoneNo;
		cout<<"enter new phoneNo: ";
		cin>>newPhoneNo;
		cout<<"enter address: ";
		cin>>address;
		cout<<"enter new address: ";
		cin>>newAddress;
			
		}

	
};

class transaction  {
	public:
		int choice2;
	
	void transact(){
		system("cls");
		cout<<"\t\t\t\t\t transactions account menu \n\n ";
		cout<<"\t\t\t\t\t\t1.deposit\n ";
		cout<<"\t\t\t\t\t\t2.withdrawn\n";
		cout<<"\t\t\t\t\t\t3.view balance\n";
		cout<<"\t\t\t\t\t\t4.Exit\n ";
		cout<<"Enter choice: ";	
		cin>>choice2;
		if(choice2==1){
			depositAcc();
		}
		else if(choice2==2){
			withdrawAcc();
		}
		else if(choice2==3){
			balanceAcc();
		}
		else if(choice2==4){
			exit(0);
		}
	}
	void depositAcc(){
		system("cls");
		cout<<"Enter name: ";
		cin>>name;
		cout<<"enter Account number: ";
		cin>>accNo;
		cout<<"enter amount to deposit : ";
		cin>>deposit;
		cout<<"\n------------------------------------------------------ \n";
		cout<<"\n your new balance is: "<<deposit;
		cout<<"\n 1.exit: ";
		cout<<"\n 2.Go back to menu: ";
		
		cin>>option3;
		if(option3==1){
			exit(0);
		}
		else if(option3==2){
			transact();
		}
		else
		{
			cout<<"sorry invalid option !! ";
		}	
		
		
	}
	
	void withdrawAcc(){
		system("cls");
		cout<<"enter Account number: ";
		cin>>accNo;
		cout<<"\t\t\t------------------------------------------------------ \n";
		cout<<"\t\t\t name: "<<name<<"\n \t\t\t account number: "<<accNo;
		cout<<"\n \t\t\t balance: "<<deposit;
		cout<<"\n \t\t\t------------------------------------------------------ \n";
		
		cout<<"\n enter Amount to withdraw: ";
		cin>>withdraw;
		balance = deposit-withdraw;
		system("cls");
		cout<<"\n\n\n you have succefully withdrawn ksh  "<<withdraw;
		cout<<"\nyour current balance is: "<<balance;
		cout<<"\n 1.exit: ";
		cout<<"\n 2.Go back to menu: ";
		cin>>option3;
		if(option3==1){
			exit(0);
		}
		else if(option3==2){
			transact();
		}
		else
		{
			cout<<"sorry invalid option !! ";
		}	
		
		
	
	}
	void balanceAcc(){
		system("cls");
		cout<<"enter Account number: ";
		cin>>accNo1;
		if(accNo1==accNo){
				cout<<"\t\t\t------------------------------------------------------ \n";
				cout<<"\t\t\t name: "<<name<<"\n \t\t\t account number: "<<accNo;
				cout<<"\n \t\t\t balance: "<<balance;
				cout<<"\n \t\t\t------------------------------------------------------ \n";
			}
			cout<<"enter 1 to go to menu enter any number to Exit : ";
			cin>>choice3;
			if(choice3==1){
				transact();
			}	

		
	}
	
};


int main() {
	int option1;
	cout<<"\t\t\t\t\thello welcome to bms: \n";
	cout<<"\t\t1.customer main menu \n";
	cout<<"\t\t2.account main menu \n ";
	cout<<"\t\t3.transactions main menu \n";
	cout<<"\t\t4.Exit \n";
	cout<<"enter option: ";	
	cin>>option1;

	if(option1==1){
		CustomerService first;
		first.customer();
	}
	else if(option1==2)
	{
		account sec;
		sec.acc();
	}
	else if(option1==3){
		transaction thi;
		thi.transact();

	}
	
    
    return 0;
}


	
	

