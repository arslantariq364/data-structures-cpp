#include<iostream>
using namespace std;


class Node{
	public:
	int data;
	Node* next;

	Node(int data){
		this->data=data;
		next=NULL;
	}
};


class Singly{
	Node* head;
	Node* tail;

	public:
	
	Singly(){
		head=tail=NULL;
	}
		
	
	void insertion(int n=-1){
		if(n==-1){
			cout<<"\nEnter the data to enter in the node:\n";
			cin>>n;
		}
		Node* newnode=new Node(n);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	}
	
	
	//Get tail pointer
	Node* gettail(){
		return tail;
	}

	//Get head pointer
	Node* gethead(){
		return head;
	}
		
	//Display all nodes
	void display(){
		
		if(head==NULL){
			cout<<"\nEmpty\n";
			return;
		}

		Node* temp=head;
		while(temp){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}

	//Check if the list is empty
	bool isempty(){
		return head==NULL;
	}
		
	//QU.1: Reverse the entire linked list use the three pointers the next , current and the pre one after the loop the pre pointer would
    //become the new head and thus reverse the whole singly list 
    
	
	void reverse(){
		
		  if(head==NULL){
			cout<<"\nEmpty\n";
			return;
			
		}
		
		Node* pre=NULL;
		Node* current=head;
		Node* next=NULL;
		
		  while(current){
		  	
			next=current->next;
			current->next=pre;
			pre=current;
			current=next;
		}
		tail=head;
		head=pre;
	}


		
	//Qu.3:Find the middle node of the link list .... first finding the total number of the nodes in a link list then dividing by the 
	//2 to get the middle node ... and next step is taking another counter from 0 and upto the count mid then printing the middle one 
	
	void middle(){
		
		Node* temp=head;
		int count=0;
		
		 while(temp){
		 	
			++count;
			temp=temp->next;
		}
		count=(count/2);

		int n=0;
		temp=head;
		while(temp){
			
			++n;
			if(n==count){
				
				cout<<"\nThe middle of the node is :\n"<<temp->data;
				
				return;
			}
			temp=temp->next;	
		}
	}
		
	//Qu.4:Remove nth node from the end....first counting total number of nodes amd then asking for number to delete from the end 
	//then subtracting number from that total count would hive exact node to be deleted
	
	void Removingfromend(){
		
		  if(isempty()){
			return;
		}
		
		int number;
		cout<<"\nEnter the number of the node you want to remove from the end:\n";
		cin>>number;
		
		 if(number<=0){
			return;
		}
		int count=0;
		
		
		Node* temp=head;
		
		while(temp){
			++count;
			temp=temp->next;
		}
		
		Node* tem=head;
		Node* pre=NULL; 
		
		   
		int deletion=count-number;
		
		if(deletion<0){
			return;
		}
		
		for(int i=0;i<deletion;i++){
			pre=tem;
			tem=tem->next;
		}
		if(tem==head){
			Node* temp1=head;
			head=head->next;
			delete temp1;
		}
		else if(tem==tail){
			pre->next=NULL;
			tail=pre;
			delete tem;
		}
		else{
			pre->next=tem->next;
			delete tem;
		}



	//Delete a node by key
	void deletion(int key){
		if(isempty()){
			cout<<"Empty";
			return;
		}

		Node* temp=head;
		Node* pre=NULL;
		while(temp && temp->data!=key){
			pre=temp;
			temp=temp->next;
		}

		if(temp==head){
			Node* temp2=temp;
			head=head->next;
			delete temp2;
		}
		else if(temp==tail){
			pre->next=NULL;
			tail=pre;
			delete temp;
		}
		else{
			pre->next=temp->next;
			delete temp;
		}
	}


	}

	//QU.9::Remove duplicates from sorted linked list...As it is in sorted already so just findig the next element if equal delete it 
	
	void removingduplicates(){
		
		if(isempty()){
			cout<<"Empty";
			return;
		}
		
		Node* temp=head;
		
		while(temp!=NULL && temp->next!=NULL){
			
			if(temp->data==temp->next->data){
				Node* del=temp->next;
				temp->next=del->next;
				
				if(del==tail){
					tail=temp;
				}
				delete del;
			}
			else{
				temp=temp->next;
			}
		}
	}

	//Qu.10::Reverse nodes in k-groups
	
	void reversenodes(){
		
		int k;
		cout<<"Enter the number of nodes to be reversed:\n";
		cin>>k;
		if(k<0){
			return;
		}
		Node* temp=head;
		
		for(int i=0;i<k;i++){
			
			while(temp && temp->next){
				
				int n=temp->data;
				temp->data=temp->next->data;
				temp->next->data=n;
				temp=temp->next->next;
			}
		}
	}
};

//Qu.7: Add Two Numbers represented by linked lists::too much time but got learned its idea and build logic::first simply 
//adding two lists numbers into the given variable and then dividing that by with the 10 to get the reminder one by one and storing that
//into the linked list 


void Addingtwolists(){
	
	Singly list;
	int size;
	cout<<"\nEnter the no of insertions in the first list:\n";
	cin>>size;
	
	for(int i=0;i<size;i++){
		list.insertion();
	}

	Singly li2;
	int size1;
	
	cout<<"\nEnter the no of insertions in the second list:\n";
	cin>>size1;
	
	for(int i=0;i<size1;i++){
		
		li2.insertion();
	}

	if(list.isempty()){
		
		cout<<"\nFirst List is empty\n";
		return ;
		
	}
	if(li2.isempty()){
		
		cout<<"\nSecond list is empty\n";
		return ;
	}

	int count=0;
	
	Node* temp=list.gethead();
	Node* temp2=li2.gethead();
	
	while((temp!=NULL) || (temp2!=NULL)){
		++count;
		temp=temp->next;
		temp2=temp2->next;
	}
	
	cout<<" \ncount:\n"<<count<<endl; 

	list.reverse();
	li2.reverse();

	temp=list.gethead();
	temp2=li2.gethead();

	int num=0;
	
	for(int i=0;i<count;i++){
		
		num=(num*10)+temp->data+temp2->data;
		temp=temp->next;
		temp2=temp2->next;
	}

	cout<<"\nThe number is :\n"<<num;

	Singly SS;
	
	for(int i=0;i<count;i++){
		
		int val=num%10;
		SS.insertion(val);
		num=num/10;
	}
	
	cout<<endl;
	cout<<"\nThe sum of the two link lists and result into other is :\n";
	SS.display();
}

//QU.2:: Merging  Two Sorted Linked Lists: merging the two lists into the one and then comparing the each node with next one for swapping 
//to sort into a sorrted list 

Singly mergesorted(){
	
	Singly s;
	int size;
	
	cout<<"\nEnter the no of insertions in the first list:\n";
	cin>>size;
	
	   for(int i=0;i<size;i++){
	   	
		s.insertion();
	}

	Singly l;
	int size1;
	
	cout<<"\nEnter the no of insertions in the second list:\n";
	cin>>size1;
	
	for(int i=0;i<size1;i++){
		
		l.insertion();
	}

	if(s.isempty()){
		cout<<"\nFirst List is empty\n";
		return l;
	}
	if(l.isempty()){
		cout<<"\nSecond list is empty\n";
		return s;
	}

	Node* temp=s.gettail();
	Node* temp2=l.gethead();
	Node* h=s.gethead(); 
	temp->next=temp2;
	temp=l.gettail();

	bool swap;
	
	do{
		
		swap=true;
		Node* sort=h;
		while(sort->next){
			
			if(sort->data>sort->next->data){
				
				int temp=sort->next->data;
				sort->next->data=sort->data;
				sort->data=temp;
				swap=false;
			}
			sort=sort->next;
		}
	}while(!swap);

	return s;
}

int main(){
	int choice;
	do{
		cout<<"\n----Menu Display For Link List Problems----\n";
		cout<<"\n\n1.Reverse Link List\n";
		cout<<"2.Merge Two Sorted lists\n";
		cout<<"3.Middle of Link List\n";
		cout<<"4.Remove Nth Node From End\n";
		cout<<"5.Add Two Numbers And Return As List\n";
		cout<<"6.Remove Duplicates\n";
		cout<<"7.Reverse nodes in groups\n";
		cout<<"8.Exit\n";
		cout<<"Enter your choice:\n";
		cin>>choice;

		if(choice==1){
			Singly s;
			int n;
			cout<<"\nEnter the number of insertions:\n";
			cin>>n;
			
			for(int i=0;i<n;i++){
				s.insertion();
			} 
			
			cout<<"\nOriginal:\n";
			s.display();
			cout<<"\nReversed:\n";
			s.reverse();
			s.display();
		}
		else if(choice==2){
			Singly w;
			w=mergesorted();
			cout<<"\nMerged Sorted:\n";
			w.display();
		}
		else if(choice==3){
			Singly s;
			int n;
			cout<<"\nEnter the number of insertions:\n";
			cin>>n;
			for(int i=0;i<n;i++){
				 s.insertion();
			}
			s.display();
			s.middle();
		}
		else if(choice==4){
			Singly s;
			int n;
			cout<<"\nEnter the number of insertions:\n";
			cin>>n;
			for(int i=0;i<n;i++){
				 s.insertion();
			}
			cout<<"\nBefore:\n";
			s.display();
			
			s.Removingfromend();
			
			cout<<"\nAfter:\n";
			s.display();
		}
		else if(choice==5){
			Addingtwolists();
		}
		else if(choice==6){
			Singly s;
			int n;
			cout<<"\nEnter the number of insertions:\n";
			cin>>n;
			for(int i=0;i<n;i++){
				s.insertion();
			}
			cout<<"\nBefore:\n";
			s.display();
			s.removingduplicates();
			cout<<"\nAfter:\n";
			s.display();
		}
		else if(choice==7){
			Singly s;
			int n;
			cout<<"\nEnter the number of insertions:\n";
			cin>>n;
			for(int i=0;i<n;i++){
				s.insertion();
			}
			cout<<"\nBefore:\n";
			s.display();
			s.reversenodes();
			cout<<"\nAfter:\n";
			s.display();
		}
		else if(choice==8){
			cout<<"\nExiting...\n";
		}
		else{
			cout<<"\nInvalid Choice\n";
		}
	}while(choice!=8);

	return 0;
}
