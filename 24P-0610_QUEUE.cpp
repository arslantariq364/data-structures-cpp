#include<iostream>
using namespace std;

//QU.1:Queue in Array....implementing all the important methods of the isempty , isfull , enque and deque method for QUEUE operations 

class ArrayQueue{
	private:
		
		int *items,size,front,rear;
	public:
		
		ArrayQueue(int size):size(size),front(-1),rear(-1){
			
			items=new int[size];
		}
		
		bool isEmpty(){
			
			if(front==-1){
			 return true;
			  }
			  
			else{
			 return false;
			  }
		}
		
		
		bool isFull(){
			
			if(rear==size-1){
			 return true; 
			 }
			 
			else{
			 return false;
			  }
		}
		
		
		void enqueue(int value){
			
			if(isFull()){
				cout<<"\nQueue Overflow!\n\n";
				return;
			}
			
			if(isEmpty()){
				front=0;
			}
			
			rear=rear+1;
			items[rear]=value;
		}
		
		void dequeue(){
			
			if(isEmpty()){
				cout<<"\nQueue Underflow!\n\n";
				return;
			}
			
			if(front==rear){
				front=-1;
				rear=-1;
			}
			
			else{
				front=front+1;
			}
			
		}
		
		int peek(){
			
			if(isEmpty()){
				cout<<"\nQueue is empty!\n\n";
				return -1;
			}
			
			else{
				return items[front];
			}
		}
		
		void display(){
			
			if(isEmpty()){
				cout<<"\nQueue is empty!\n\n";
				return;
			}
			
			cout<<"\nQueue elements: ";
			for(int i=front;i<=rear;i++){
				cout<<items[i]<<" ";
			}
			cout<<"\n\n";
		}
};

//QU.2:Implementation of the queue by using the node class and the pointers to store front rear positions and then with help of these 
//operations doing enque and deque would form Link list queue


class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data=data;
			next=NULL;
		}
};

class LinkedListQueue{
	
	private:
		Node* front;
		Node* rear;
		
	public:
		
		LinkedListQueue(){
			front=rear=NULL;
		}
		
		bool isEmpty(){
			if(front==NULL){
			 return true;
			  }
			else{ 
			return false; 
			}
		}
		
		void enqueue(int value){
			
			Node* newnode=new Node(value);
			if(isEmpty()){
				front=rear=newnode;
			}
			
			else{
				rear->next=newnode;
				rear=newnode;
			}
		}
		
		void dequeue(){
			
			if(isEmpty()){
				cout<<"\nQueue Underflow!\n\n";
				return;
			}
			
			Node* temp=front;
			front=front->next;
			delete temp;
			
			if(front==NULL){
			 rear=NULL;
			  }
		}
		
		int peek(){
			
			if(isEmpty()){
				cout<<"\nQueue is empty!\n\n";
				return -1;
			}
			else{
				return front->data;
			}
		}
		void display(){
			if(isEmpty()){
				cout<<"\nQueue is empty!\n\n";
				return;
			}
			
			cout<<"\nQueue elements: ";
			Node* temp=front;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<"\n\n";
		}
};

//QU3:Implementation of the queue with the priority by making the struct i stored the value for keeping the data and priority for 
//the position where it is needed to store

class PriorityQueue{
	private:
		
		struct Item{
			int value;
			int priority;
		};
		
		Item* items;
		int size;
		int count;
		
	public:
		PriorityQueue(int size):size(size),count(0){
			items=new Item[size];
		}
		
		bool isEmpty(){
			if(count==0){ 
			return true;
			 }
			 
			else{ 
			return false;
			 }
		}
		
		bool isFull(){
			
			if(count==size){ 
			return true;
			 }
			else{ 
			return false;
			 }
		}
		
		void enqueue(int value,int priority){
			
			if(isFull()){
				cout<<"\nQueue Overflow!\n\n";
				return;
			}
			
			items[count].value=value;
			items[count].priority=priority;
			count++;
		}
		
		void dequeue(){
			
			if(isEmpty()){
				cout<<"\nQueue Underflow!\n\n";
				return;
			}
			int highest=0;
			
			for(int i=1;i<count;i++){
				if(items[i].priority>items[highest].priority){
					highest=i;
				}
			}
			
			cout<<"\nDequeued Value: "<<items[highest].value<<"\n\n";
			
			for(int i=highest;i<count-1;i++){
				items[i]=items[i+1];
			}
			count--;
		}
		
		void display(){
			
			if(isEmpty()){
				cout<<"\nQueue is empty!\n\n";
				return;
			}
			cout<<"\nQueue elements with priority:\n";
			
			for(int i=0;i<count;i++){
				cout<<"("<<items[i].value<<","<<items[i].priority<<") ";
			}
			cout<<"\n\n";
		}
};


//QU.4: Reversing the first K elemets ... first finding the middle of numbered given by user and then upto that swaping from both 
//the sides would reaturn in reversing the queue of k numbers 

void reverseK(int arr[],int start,int k){
	
	if(start>=k/2){
		return;
	}
	
	int temp=arr[start];
	arr[start]=arr[k-1-start];
	arr[k-1-start]=temp;
	
	
	reverseK(arr,start+1,k);
}

//QU.5: Checking the PALINDROME ... first find the middle one of the queue and then checking the first and the last element is that same 
//as same going on if not return false for palindrome 

bool checkPalindrome(int arr[],int n){
	
	for(int i=0;i<n/2;i++){
		
		if(arr[i]!=arr[n-1-i]){
			
			return false;
		}
	}
	return true;
}

//Display Menu

void displayMenu(){
	cout<<"01 Array Queue Operations\n"
		<<"02 Linked List Queue Operations\n"
		<<"03 Priority Queue Operations\n"
		<<"04 Reverse First K Elements of a Queue\n"
		<<"05 Check if Queue is Palindrome\n"
		<<"06 Exit Program\n";
}


int main(){
	int choice=0;
	
	ArrayQueue aq(10);
	LinkedListQueue lq;
	
	PriorityQueue pq(10);
	int arr[100],arrCount=0; 
	
	while(choice!=6){
		
		displayMenu();
		cout<<"\nEnter your choice:\n";
		cin>>choice;
		
		if(choice==1){
			
			int subChoice=0;
			
			while(subChoice!=5){
				cout<<"\nArray Queue Menu:\n"
					<<"1.Enqueue\n"
					<<"2.Dequeue\n"
					<<"3.Front\n"
					<<"4.Display\n"
					<<"5.Back to Main Menu\n";
				cout<<"\nEnter your choice:\n";
				cin>>subChoice;
				
				if(subChoice==1){
					int value;
					cout<<"\nEnter value to enqueue:\n";
					cin>>value;
					aq.enqueue(value);
				}
				else if(subChoice==2){
					aq.dequeue();
				}
				
				else if(subChoice==3){
					int val=aq.peek();
					if(val!=-1){
						cout<<"\nFront Element: "<<val<<"\n\n";
					}
				}
				
				else if(subChoice==4){
					aq.display();
				}
				else if(subChoice==5){
					break;
				}
				else{
					cout<<"\nInvalid choice!\n";
				}
			}
		}
		else if(choice==2){
			int subChoice=0;
			
			while(subChoice!=5){
				cout<<"\nLinked List Queue Menu:\n"
					<<"1.Enqueue\n"
					<<"2.Dequeue\n"
					<<"3.Front (Peek)\n"
					<<"4.Display\n"
					<<"5.Back to Main Menu\n";
				cout<<"\nEnter your choice:\n";
				cin>>subChoice;
				
				if(subChoice==1){
					int value;
					cout<<"\nEnter value to enqueue:\n";
					cin>>value;
					lq.enqueue(value);
				}
				else if(subChoice==2){
					lq.dequeue();
				}
				else if(subChoice==3){
					int val=lq.peek();
					if(val!=-1){
						cout<<"\nFront Element: "<<val<<"\n\n";
					}
				}
				else if(subChoice==4){
					lq.display();
				}
				else if(subChoice==5){
					break;
				}
				else{
					cout<<"\nInvalid choice!\n";
				}
			}
		}
		else if(choice==3){
			int subChoice=0;
			while(subChoice!=5){
				cout<<"\nPriority Queue Menu:\n"
					<<"1.Enqueue\n"
					<<"2.Dequeue\n"
					<<"3.Display\n"
					<<"4.Back to Main Menu\n";
				cout<<"\nEnter your choice:\n";
				cin>>subChoice;
				
				if(subChoice==1){
					int value,priority;
					cout<<"\nEnter value and priority:\n";
					cin>>value>>priority;
					pq.enqueue(value,priority);
				}
				else if(subChoice==2){
					pq.dequeue();
				}
				else if(subChoice==3){
					pq.display();
				}
				else if(subChoice==4){
					break;
				}
				else{
					cout<<"\nInvalid choice!\n";
				}
			}
		}
		else if(choice==4){
			int n,k;
			
			cout<<"\nEnter number of elements in queue:\n";
			cin>>n;
			cout<<"\nEnter elements:\n";
			
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			
			cout<<"\nEnter k to reverse first k elements:\n";
			cin>>k;
			
			if(k>n){
			 k=n;
			  }
			  
			reverseK(arr,0,k);
			cout<<"\nQueue after reversing first k elements: ";
			
			for(int i=0;i<n;i++){
				cout<<arr[i]<<" ";
			}
			cout<<"\n\n";
		}
		else if(choice==5){
			int n;
			cout<<"\nEnter number of elements in queue:\n";
			cin>>n;
			cout<<"\nEnter elements:\n";
			
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			
			if(checkPalindrome(arr,n)){
				cout<<"\nQueue is a palindrome\n\n";
			}
			else{
				cout<<"\nQueue is not a palindrome\n\n";
			}
		}
		else if(choice==6){
			cout<<"\nExiting Program.Goodbye!\n";
		}
		else{
			cout<<"\nInvalid choice!\n";
		}
	}
	return 0;
}
