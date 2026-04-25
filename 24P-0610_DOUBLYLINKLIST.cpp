#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* pre;
		Node* next;
		
		//for tree: left and right
		
		Node* left;
		Node* right;
		
		Node(int data){
			this->data=data;
			pre=next=NULL;
			left=right=NULL;
		}
};

class Doubly{
	Node* root;
	
	Node* insertion(Node* root,int key){
		if(root==NULL){
			return new Node(key);
		}
		else if(key<root->data){
			root->left=insertion(root->left,key);
		}
		else if(key>root->data){
			root->right=insertion(root->right,key);
		}
		return root;
	}
	
	//Q6.Converting the binary tree into the doubly link list by sorting them using inorder traversal as guided in assignment
	// instructions
	
	void DoublyT(Node* root){
		if(root==NULL){
			return;
		}
		
		DoublyT(root->left);
		Node* newnode=new Node(root->data);
		if(head==NULL){
				head=tail=newnode;
			}
			else{
                tail->next=newnode;
                newnode->pre=tail;
                tail=newnode;
			}
		DoublyT(root->right);	
	}
	
	
	//Q9.Reverse the doubly link list in the group of the k
	
    Node* reverseK(Node* head,int k){
    	
	if(head==NULL){
		return NULL;
	}

	Node* current=head;
	Node* newHead=NULL;
	int count=0;

	while(current!=NULL && count<k){
		Node* next=current->next;

		current->next=newHead;
		if(newHead!=NULL){
			newHead->pre=current;
		}
		current->pre=NULL;
		newHead=current;

		current=next;
		count++;
	}

	if(current!=NULL){
		head->next=reverseK(current,k);
		if(head->next!=NULL){
			head->next->pre=head;
		}
	}

	return newHead;
}


	public:
		Node* head;
		Node* tail;
		
		Doubly(){
			head=tail=NULL;
			//for tree
			root=NULL;
		}
		
		void InsertionatEnd(){
			int n;
			cout<<"\nEnter the number to insert in Link List at End:\n";
			cin>>n;
			Node* newnode=new Node(n);
			if(head==NULL){
				head=tail=newnode;
			}
			else{
                tail->next=newnode;
                newnode->pre=tail;
                tail=newnode;
				
			}
		}
		
	void deletion(int target){
		if(head==NULL){
			cout<<"\nThe list is Empty\n";
			return;
		}
		
		Node* current=head;
		Node* prev;
		
		while(current){
			if(current->data==target){
				break;
			}
			prev=current;
			current=current->next;
		}
		prev->next=current->next;
		current->next->pre=prev;
		delete current;
		
		
	}
	
	void Display(){
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
		
	bool searchbyvalue(int k){
		if(head==NULL){
			cout<<"\nEmpty\n";
			return false;
		}
        Node* temp;
		while(temp && temp->data!=k){
			temp=temp->next;
		}
		
		return (temp==NULL)?false:true;
	}
	
	//Q1.Insertion in sorted manner :: using two pointers the previous for locaton the previous locations and one is current for 
	//moving ahead from head to tail and it would stop when current->data would be greater means prev->next is where newnode be inserted	
	
	void insertioninsorted(){
		int target;
		cout<<"\nEnter the value in sorted Link list:\n";
		cin>>target;
		Node* current=head;
		Node* prev=NULL;
		
		while(current){
			
			if(current->data>target){
				break;
			}
			prev=current;
			current=current->next;
			
		}
		
		Node* newnode=new Node(target);
		if(current==head){
			newnode->next=head;
			head->pre=newnode;
			head=newnode;
		}
		else if(current==NULL){
			prev->next=newnode;
			newnode->pre=prev;
			tail=newnode;
		}
		else{
			newnode->next=prev->next;
			newnode->pre=prev;
			prev->next=newnode;
			current->pre=newnode;
		}
	}
	
	//Q2.Deleting All the occurrences of the Data:: first making a loop and finding the target when found removing that node until 
	//the occurrences has been removed from the link list
	
	void Deleteoccu(){
		if(head==NULL){
			cout<<"\nEmpty\n";
			return;
		}
		
		int key;
		cout<<"\nEnter the occurrence you want to delete:\n";
		cin>>key;
		while(true){
		Node* temp=head;
		Node* prev=NULL;
		while(temp && temp->data!=key){
			prev=temp;
			temp=temp->next;
		}
		
		if(temp==NULL){
			cout<<"\nNo Occurrence Found-Deleted\n";
			return;
		}
		if(temp==head){
			head=head->next;
			delete temp;
		}
		else if(temp==tail){
			tail=temp->pre;
			tail->next=NULL;
			delete temp;
		}
		
		else{
			prev->next=temp->next;
			temp->next->pre=prev;
			delete temp;
		}
		}

	}
	
	
	//Q3.Finding the sumpairs by looping twice to find the two numbers in link list that equals target so printing that numbers thrpugh 
	//cout
	
	void sumpairs(){
		if(head==NULL){
			cout<<"\nEmpty\n";
			return;
		}
		int sum;
		cout<<"\nEnter the number for which you want to print the sum pair:\n";
		cin>>sum;
		Node* temp=head;
		while(temp){
			Node* temp2=temp->next;
			
			while(temp2){
				if(temp->data+temp2->data==sum){
					cout<<"("<<temp->data<<","<<temp2->data<<") ";
				}
				
				temp2=temp2->next;
			}
			temp=temp->next;
		}
		
	}
	
	//Q4.Rotating the link list in anti clock wise by dealing with head and tail pointers to make it efficient which rotate k times
	
	void rotatedou(){
		if(head==NULL){
			cout<<"\nEmpty\n";
			return;
		}
		int cycle;
		cout<<"\nEnter the number of the cycles to rotate the Link List:\n";
		cin>>cycle;
		for(int i=0;i<cycle;i++){
			
			
			Node* temp=head;
			head=head->next;
			temp->next=NULL;
			
			tail->next=temp;
			temp->pre=tail;
			tail=temp;
			
			
			}
		
		
	}
	
	
	//Q7.Finding the triplets would print the triple numbers making the sum equal to target entered by the user
	
	void triplepairs(){
			
		if(head==NULL){
			cout<<"\nEmpty\n";
			return;
		}
		int sum;
		
		cout<<"\nEnter the number for which you want to print the sum Triplet:\n";
		cin>>sum;
		Node* temp=head;
		
		while(temp){
			Node* temp2=temp->next;
			
			while(temp2){
				Node* temp3=temp2->next;
				
				while(temp3){
					if(temp->data+temp2->data+temp3->data==sum){
					cout<<"("<<temp->data<<","<<temp2->data<<","<<temp3->data<<") ";
				}
				
				temp3=temp3->next;
				}
			
				
				temp2=temp2->next;
			}
			temp=temp->next;
		}
		
	}
	
	bool isempty(){
		return head==NULL;
	}
	

	
    void reversegroupK(){
	int k;
	cout<<"\nEnter K value:\n";
	cin>>k;

	head=reverseK(head,k);
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	tail=temp;
   }
	Node* gethead(){
		return head;
	}
		
	Node* gettail(){
		return tail;
	}	
	
	void InsertionTree(){
		int key;
		cout<<"\nEnter the data to enter in the tree:\n";
		cin>>key;
		root=insertion(root,key);
	}
	
	void todoubly(){
		if(root==NULL){
			cout<<"\nThe Tree is Empty\n";
			return;
		}
		
		DoublyT(root);
		
	}

		
		
};

//Q5.Merging two link list by attaching them together and then sorting them in a sorted way and return to a merge sorted list 

Doubly merge(Doubly l1,Doubly l2){
	if(l1.isempty()){
		cout<<"\nThe list 1 is empty\n";
		return l2;
	}
	if(l2.isempty()){
		cout<<"\nThe list 2 is empty\n";
		return l1;
	}
	Node* h1=l1.gethead();
	Node* h2=l2.gethead();
	Node* t1=l1.gettail();
	Node* t2=l2.gettail();
	
  t1->next=h2;
  h2->pre=t1;
  t1=t2;
  Node* temp=h1;
  
  while(temp){
  	Node* temp2=temp->next;
  	while(temp2){
  		if(temp->data>temp2->data){
  			int tem=temp->data;
  			temp->data=temp2->data;
  			temp2->data=tem;
		  }
		  temp2=temp2->next;
	  }
  	temp=temp->next;
  }
  return l1;
	
}


int main(){
    Doubly list1,list2,list3,tree;
    int choice;

    do{
        cout<<"\n===== DOUBLY LINKED LIST MENU =====\n";
        cout<<"First insert by 1 for List1 functions\n";
        cout<<"1. Insert at End (List1)\n";
        cout<<"2. Insert in Sorted Manner (List1)\n";
        cout<<"3. Delete All Occurrences (List1)\n";
        cout<<"4. Find Pairs with Given Sum (List1)\n";
        cout<<"5. Rotate List1 by N Nodes\n";
        cout<<"6. Merge List1 and List2\n";
        cout<<"7. Convert Tree to Doubly List\n";
        cout<<"8. Find Triplets with Given Sum (List1)\n";
        cout<<"9. Merge K Sorted Lists\n";
        cout<<"10. Reverse List1 in Groups of K\n";
        cout<<"11. Display List1\n";
        cout<<"12. Display List2\n";
        cout<<"13. Exit\n";
        cout<<"Enter Choice:\n";
        cin>>choice;

        switch(choice){

            case 1:
                cout<<"\nEnter number of nodes to insert:\n";
                {
                    int n;
                    cin>>n;
                    for(int i=0;i<n;i++){
                        list1.InsertionatEnd();
                    }
                }
                list1.Display();
                break;

            case 2:
                list1.insertioninsorted();
                list1.Display();
                break;

            case 3:
                list1.Deleteoccu();
                list1.Display();
                break;

            case 4:
                list1.sumpairs();
                break;

            case 5:
                list1.rotatedou();
                list1.Display();
                break;

            case 6:
                cout<<"\nInsert elements for List1:\n";
                for(int i=0;i<4;i++){
                    list1.InsertionatEnd();
                }

                cout<<"\nInsert elements for List2:\n";
                for(int i=0;i<4;i++){
                    list2.InsertionatEnd();
                }

                list3 = merge(list1,list2);
                cout<<"\nMerged List:\n";
                list3.Display();
                break;

            case 7:
                cout<<"\nInsert 4 nodes into tree:\n";
                for(int i=0;i<4;i++){
                    tree.InsertionTree();
                }
                tree.todoubly();
                cout<<"\nDoubly List from Tree:\n";
                tree.Display();
                break;

            case 8:
                list1.triplepairs();
                break;

            case 9:{
                    int k;
                    cout<<"\nEnter number of lists:\n";
                    cin>>k;

                    Doubly* arr=new Doubly[k];

                    for(int i=0;i<k;i++){
                        cout<<"\nInsert elements for List "<<i+1<<":\n";
                        for(int j=0;j<4;j++){
                            arr[i].InsertionatEnd();
                        }
                    }

                    list3 = arr[0];
                    for(int i=1;i<k;i++){
                        list3 = merge(list3, arr[i]);
                    }

                    cout<<"\nMerged K Sorted Lists:\n";
                    list3.Display();

                    delete[] arr;
                }
                break;

            case 10:
                list1.reversegroupK();
                list1.Display();
                break;

            case 11:
                cout<<"\nList1:\n";
                list1.Display();
                break;

            case 12:
                cout<<"\nList2:\n";
                list2.Display();
                break;

            case 13:
                cout<<"\nExiting...\n";
                break;

            default:
                cout<<"\nInvalid Choice\n";
        }

    }while(choice!=13);

    return 0;
}
