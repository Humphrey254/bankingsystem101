#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

//functon declaton
int mainmenu();



//declare gloabal variables
int phoneNo,id,age,accNo,accNo1,NewaccNo ,option3; 
char name[50],address[60] , acctyp[20]; 
int choice,choice3,deposit,withdraw, balance;

class CustomerService
{
	public : 
		void Customermenu();
		void getCustomer();
		void write_records();
		void viewCustomer();
		void view_records();
	
		void UpdateCustomer();
		void update_records();
		
	

};

// customer menu
void CustomerService:: Customermenu()
{
	int option2;
	system("cls");
	cout<<"\t\t\t\t\t======customer menu====== \n";
	cout<<"\t\t1.create new customer\n";
	cout<<"\t\t2.view Customer  \n ";
	cout<<"\t\t3.update Customer \n";
	cout<<"\t\t4.go to main menu \n";
	cout<<"enter option: ";	
	cin>>option2;

	if(option2==1){
		write_records();	
	}
	else if(option2==2)
	{
		view_records();
	}
	else if(option2==3){
		UpdateCustomer();
	}
	else if(option2==4){
		mainmenu();
	}
	
	
}

//method for creating new customer
void CustomerService:: getCustomer(){
	//system clear 
	system("cls");
	ofstream c_records;
	c_records.open("records.txt", ios::binary | ios::app);
	cout<<"\t\t\tcustomer menu \n\n" ;
	cout<<"enter name: ";
	cin>>name;
	c_records<<endl<<"name: " <<name<<"\t\t " ;
	cout<<"enter id: ";
	cin>>id;
	c_records<<"id: " <<id<<"\t\t ";
	cout<<"enter age: ";
	cin>>age;
	c_records<<"age: "<<age<<"\t\t ";
	cout<<"enter phoneNo: ";
	cin>>phoneNo;
	c_records<<"phone no: "<<phoneNo<<"\t\t ";
	cout<<"enter address: ";
	cin>>address;
	c_records<<"address: "<<address<<"\t\t ";
	c_records.close();
	//dsplay detals 
	system("cls");
	cout<<"\t\t\t------------------------------------------------------ \n";
	cout<<"\t\t\t name: "<<name<<"\n \t\t\t id number: "<<id;
	cout<<"\n \t\t\t age: "<<age<<"\n \t\t\t phone number: "<<phoneNo<<"\n \t\t\t address: "<<address;
	cout<<"\n \t\t\t------------------------------------------------------ \n";
	cout<<"enter 1 to go to menu enter any number to Exit : ";
	cin>>choice3;
	if(choice3==1){
	  Customermenu();
	}
		
	}	
	//wrt records n fle 
	void CustomerService:: write_records(){
	ofstream c_records;
	c_records.open("records.txt", ios::binary | ios::app);
	CustomerService obj;
	
	if (!c_records)
	 {
		cout << "File not created!";
	 }
	else
	 {
	 	
	   	obj.getCustomer();
	   	c_records.write(reinterpret_cast<char*>(&obj), sizeof(obj));
	   	c_records.close();
		
		}

}
	//vew customer 
	void CustomerService:: viewCustomer(){
	fstream my_file;
	my_file.open("records.txt", ios::in);
	my_file.seekg(0);
	if (!my_file) {
		cout << "No such file";
	}
	else {


		while (1) {
			my_file >> name;
			
			if (my_file.eof())
				break;

			cout <<name;

		}

	}
	my_file.close();
	 
			
		
	}
	//view records n fle 
		void CustomerService:: view_records(){
		
		ifstream c_records;
		c_records.open("records.txt" , ios::binary);
		CustomerService obj;
		while(c_records.read(reinterpret_cast<char*>(&obj) , sizeof(obj))){
			obj.viewCustomer();
			cout<<"\n\n";
		}
		c_records.close();
	}
	//update customer
	
	void CustomerService:: UpdateCustomer(){
		//system clear 
		system("cls");
		int Newage;
		ifstream c_records;
		c_records.open("records.txt" , ios::binary);

		if(!c_records){

			cout<<"unable to open fle...";
		}

		
		
}
// update records
void CustomerService:: update_records(){
	ifstream c_records;
	c_records.open("records.txt" , ios::binary);
		CustomerService obj;
	while(c_records.read(reinterpret_cast<char*>(&obj) , sizeof(obj))){
		
			obj.UpdateCustomer();
			cout<<"\n\n";
		}
	
}

class account : public CustomerService
{
	public: 
	void accountmenu();
	void openAcc();
	void wrtAcc();
	void closeAcc();
	void updateAcc();
	
	
	
	
};

void account:: accountmenu()
{
	int option2;
	system("cls");
	cout<<"\t\t\t\t\t======account menu====== \n";
	cout<<"\t\t1.open new account\n";
	cout<<"\t\t2.close exsting account  \n ";
	cout<<"\t\t3.update account \n";
	cout<<"\t\t4.go to main menu \n";
	cout<<"enter option: ";	
	cin>>option2;

	if(option2==1){
		openAcc();	
	}
	else if(option2==2)
	{
		closeAcc();
	}
	else if(option2==3){
		updateAcc();
	}
	else if(option2==4){
		mainmenu();
	}
	
	
}

//open acc
void account::openAcc(){
	int no1;
	system("cls");
	fstream c_records;
	//open records
	c_records.open("records.txt",  ios:: in | ios::binary | ios::ate);
	cout<<"enter id no: ";
	cin>>no1;
	// //read from customer fle
	c_records.read(reinterpret_cast<char*>(&c_records) , sizeof(c_records));
	c_records>>id;
	if(no1==id){
		c_records.open("records.txt", ios:: out | ios::app);
		accNo = rand();
		cout<<"hello "<<name;
		//wrte data to  record
		c_records.write(reinterpret_cast<char*>(&c_records) , sizeof(c_records));
		cout<<"your account number: "<<accNo;
		c_records<<endl<<"Account number: "<<accNo<<"\t\t ";
		cout<<"enter amount to deposit : ";
	   	cin>>deposit;
	   	c_records<<"Account number: "<<accNo<<"\t\t ";
		   	
		
	}
	
	c_records.close();
	system("cls");
	cout<<"\t\t\t------------------------------------------------------ \n";
	cout<<"\t\t\t\thello "<<name<<" you have successfully created an account!\n";
	cout<<" \t\t\t\tyou new account number is: "<<accNo<<endl;
		cout<<" \t\t\t\tyou new balance is: "<<deposit<<endl;
	cout<<"\t\t\t------------------------------------------------------ \n\n\n";
	cout<<"enter 1 to go to menu enter any number to Exit : ";
	cin>>choice3;
	if(choice3==1){
		accountmenu();
	}
}

//fle handlng for aopen account
void account::wrtAcc(){
	fstream acc1;
	account obj;
	CustomerService obj2;
	
	//read from customer fle
	acc1.open("records.txt", ios::binary | ios::in);
	// wrt to account 
	acc1.open("records.txt", ios:: out | ios::app);
	acc1.seekg(0);
	while(!acc1.eof()){
		acc1.read(reinterpret_cast<char*>(&obj), sizeof(obj));
		obj2.getCustomer();
		acc1.write(reinterpret_cast<char*>(&obj), sizeof(obj));
		obj.openAcc();
		
	}
	acc1.close();
}

//close account
void account::closeAcc(){
	
	cout<<"enter Account number: ";
	cin>>accNo;
	cout<<"closed succesful.... ";
	
}
// update account 	
void account::updateAcc(){
	cout<<"enter Account number: ";
	cin>>accNo;
	cout<<"account updated successful....";
}
// transact class
class transact : public account{
	public: 
		void transactionmenu();
		void depo();
		void draw();
		void history();
};
//transact menu 
void transact::transactionmenu(){
	int option2;
	system("cls");
	cout<<"\t\t\t\t\t======transaction menu====== \n";
	cout<<"\t\t1.deposit\n";
	cout<<"\t\t2.withdraw  \n ";
	cout<<"\t\t3.go to History \n";
	cout<<"\t\t4.go to main menu \n";
	cout<<"enter option: ";	
	cin>>option2;

	if(option2==1){
		depo();	
	}
	else if(option2==2)
	{
		draw();
	}
	else if(option2==3){
		history();
	}
	else if(option2==4){
		mainmenu();
	}
	
}
//depo  method
void transact::depo(){
		
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
			transactionmenu();
		}
	
}
//wthdraw method
void transact::draw(){
		system("cls");
		cout<<"enter Account number: ";
		cin>>accNo;
		cout<<"enter amount you wish to withdraw: ";
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
			transactionmenu();
		}	
		
}
// hstory method
void transact::history(){
		system("cls");
		cout<<"enter Account number: ";
		cin>>accNo;
		cout<<"\t\t\t------------------------------------------------------ \n";
		cout<<"\t\t\t name: "<<name<<"\n \t\t\t account number: "<<accNo;
		cout<<"\n \t\t\t balance: "<<deposit;
		cout<<"\n \t\t\t------------------------------------------------------ \n";
	
}

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
		first.Customermenu();
	}
	else if(option1==2)
	{
		account sec;
		sec.accountmenu();
	}
	else if(option1==3){
		transact thi;
		thi.transactionmenu();

	}
	else{
			exit(0);
		}
	
    
    return 0;
}

//functon 
int mainmenu(){

	system("cls");
	cout<<"\t\t\t\t\t\tMain menu \n\n\n ";
	cout<<"1. customer menu \n ";
	cout<<"2. account menu \n";
	cout<<"3. transaction menu \n";
	cout<<"4. exit \n" ; 
	cout<<"enter choice: ";
	int option1;
	cin>>option1;
	if(option1==1){
		CustomerService first;
		first.Customermenu();
	}
	else if(option1==2)
	{
		account sec;
		sec.accountmenu();
	}
	else if(option1==3){
		transact thi;
		thi.transactionmenu();

	}
	else{
			exit(0);
		}
}


	
	

