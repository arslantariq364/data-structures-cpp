#include<iostream>
#include<iomanip>
using namespace std;

class Node{
	public:
		
		int data;
		Node* next;
		Node* left,*right;
		int height;
		
		Node(int data){
			
			this->data=data;
			left=right=NULL;
			height=1;
			next=NULL;
			
		}
};

class AVL{
	
	Node* root;
	Node* front;
	Node* rear;
	
	//THE METHOD FOR RETURNING HEIGHT OF RESPECTIVE NODE
	
	int height(Node* root){
		if(root==NULL){
			return 0;
		}
		return root->height;
	}
	
	//THE METHOD FOR RETURNING BALANCE FACTOR OF RESPECTIVE NODE
	
	int getbalance(Node* root){
		if(root==NULL){
			return 0;
		}
		return height(root->left)-height(root->right);
	}
	
	//METHOD OF RR ROTATION : RR IMBALANCE 
	
   Node* RR(Node* root){
   	
   	 Node* UN=root->right;
   	 Node* ST=UN->left;
   	 
   	 UN->left=root;
   	 root->right=ST;
   	 
   	 root->height=1+max(height(root->left),height(root->right));
   	 UN->height=1+max(height(UN->left),height(UN->right));
   	 
   	 return UN;
   }
   
   //LR IMBALANCE SO CALLED LR ROTATION HERE FIRST MOVE TO LEFT SIDE WOULD PERFORM RIGHT ROTATION AND THEN LEFT ROTATION AND THEN 
   //UPDATE THE HEIGHT
   Node* LR(Node* root){
   	
   	Node* UN=root->left;
   	Node* UNR=UN->right;
   	Node* UNRR=UNR->right;
   	Node* UNRL=UNR->left;
   	
   	UNR->left=UN;
   	UNR->right=root;
   	root->left=UNRR;
   	UN->right=UNRL;
   	
   	root->height=1+max(height(root->right),height(root->left));
   	UN->height=1+max(height(UN->right),height(UN->left));
   	UNR->height=1+max(height(UNR->left),height(UNR->right));
   	
   	return UNR;
   }
   
    //RL IMBALANCE SO CALLED RL ROTATION HERE FIRST MOVE TO RIGHT SIDE WOULD PERFORM LEFT ROTATION AND THEN RIGHT ROTATION AND THEN 
   //UPDATE THE HEIGHT
    Node* RL(Node* root){
    	
   	Node* UN=root->right;
   	Node* UNL=UN->left;
   	Node* UNLR=UNL->right;
   	Node* UNLL=UNL->left;
   	
   	UNL->left=root;
   	UNL->right=UN;
   	root->right=UNLL;
   	UN->left=UNLR;
   	
   	  	root->height=1+max(height(root->right),height(root->left));
   	UN->height=1+max(height(UN->right),height(UN->left));
   	UNL->height=1+max(height(UNL->left),height(UNL->right));
   	
   	return UNL;
   }
   
	//METHOD OF LL ROTATION : LL IMBALANCE
	   
      Node* LL(Node* root){
      	
   	 Node* UN=root->left;
   	 Node* ST=UN->right;
   	 
   	 UN->right=root;
   	 root->left=ST;
   	 
   	 root->height=1+max(height(root->left),height(root->right));
   	 UN->height=1+max(height(UN->left),height(UN->right));
   	 
   	 return UN;
   }
   

//QU:1 INSERTION IN AN AVL IS NOT SIMPLE REQUIRED THE UPDATION OF THE HRIGHT AND ALSO CALCULATION THE BALANCE FACTOR FOR THE NODES 
//AND THEN PERFORMING THE RESPECTIVE ROTATIONS FOR THE IMBALANCES 


	Node* insertion(Node* root,int key){
		
		if(root==NULL){
			return new Node(key);
		}
		
		if(key<root->data){
			
			root->left=insertion(root->left,key);
		}
		
		else if(key>root->data){
			root->right=insertion(root->right,key);
		}
		
		else{
			return root;
		}
		
		root->height=1+max(height(root->left),height(root->right));
        int balance=getbalance(root);

       //LL CASE 
       
       if(balance>1 && getbalance(root->left)>=0){
       	
         return LL(root);
        }
        
        //RR CASE
        
        if(balance<-1 && getbalance(root->right)<=0){
        	
        return RR(root);
        }
        
        //LR CASE
        
       if(balance>1 && getbalance(root->left)<0){
       	
      return LR(root);
       }

        //RL CASE 
       if(balance<-1 && getbalance(root->right)>0){
     return RL(root);
        }
      
	  return root;
	}
	
//QU:2 DELETION IN AN AVL IS NOT SIMPLE REQUIRED THE UPDATION OF THE HEIGHT AND ALSO CALCULATION THE BALANCE FACTOR FOR THE NODES 
//AND THEN PERFORMING THE RESPECTIVE ROTATIONS FOR THE IMBALANCES 


	Node* Deletee(Node* root,int data){
		
		if(root==NULL){
			return NULL;
		}
		
		if(data<root->data){
			root->left=Deletee(root->left,data);
		}
		
		else if(data>root->data){
			root->right=Deletee(root->right,data);
		}
		else{
			//IF HAVE ONE CHILD
			
			if(root->right==NULL){
				Node* temp=root->left;
				delete root;
				return temp;
			}
			
			if(root->left==NULL){
				Node* temp=root->right;
				delete root;
				return temp;
			}
			//IF HAVE BOTH CHILD
			
			Node* temp=findmin(root->right);
			root->data=temp->data;
			root->right=Deletee(root->right,temp->data);
			
		}
		if(root==NULL){
			 return root;
		}                    
      //UPDATION OF THE HEIGHT
      
	  root->height=1+max(height(root->left),height(root->right));
      int balance=getbalance(root);
      
      //LL CASE

       if(balance>1 && getbalance(root->left)>=0){
         return LL(root);
        }

      //RR CASE

        if(balance<-1 && getbalance(root->right)<=0){
        	
        return RR(root);
        }

      //LR CASE
        
       if(balance>1 && getbalance(root->left)<0){
       	
      return LR(root);
       }

      //RL CASE

       if(balance<-1 && getbalance(root->right)>0){
       return RL(root);
        }
     
	  return root;
	}
	
//QU.3: FINDING THE BALANCE FACTOR FOR EVERY NODE .... WHILE TRAVERSING EACH NODE CALLING THE GET BALANCE FACTOR FOR BALANCE FACTOR 
//OF EACH NODE AND THEN PRINTING 

		void BalanceFc(Node* root){
			
		if(root==NULL){
			return;
		}
		
		BalanceFc(root->left);
		BalanceFc(root->right);
		
		cout<<"\nThe Balance Factor Of the Node :\n"<<root->data<<" is :\n"<<getbalance(root);
		
	}

//QU.5:FINDING THAT THE TREE IS AVL OR NOT BY CHECKING EACH NODES BALANCE FACTOR BETWEEN 1 AND -1 IF NOT THAN TREE IS NOT BALANCED
//HENCE NOT AVL


       bool checkAVL(Node* root){
	   	
   	   if(root==NULL){
   		return true;
	   }
	   
	   
	   int balance=getbalance(root);
	   
	   if(balance>1 || balance<-1){
	   	return false;
	   }
	   return checkAVL(root->left)&&checkAVL(root->right);
	   
   }


    //DISPLAY METHOD FOR AVL TREE USING THE LIBRARY IOMANIP AND SPACES PLUS INDENTATION ... IT STARTS FROM THE RIGHT MOST BY PRINTING IT
    //FROM THE TOP AND ENDING AT LEFT SUBTREE AT BOTTOM OF THE CONSOLE

	void Display(Node* root,int space){
		
		const int indent=6;
		
		if(root==NULL){
			return;
		}
		
		Display(root->right,space+indent);
		cout<<setw(space)<<' '<<root->data<<endl;
		Display(root->left,space+indent);
	}
	

	//FINDING THE MINIMUM NODE FOR DELETION 
	
	Node* findmin(Node* root){
				
			while( root && root->left!=NULL){
				
				root=root->left;
			}
			return root;
		}
	

//QU.7: PRINTING THE AVL IN THE LEVEL ORDER IN FORM OF THE QUEUE     
	
		void storingQueue(Node* root,int level){
		if(root==NULL){
			return;
		}
		if(level==1){
	    Node* newnode=new Node(root->data);
		
		if(front==NULL){
				front=rear=newnode;
			}
			
		else{
		    rear->next=newnode;
			rear=newnode;
		}
		}
		
		else{
			storingQueue(root->left,level-1);
			storingQueue(root->right,level-1);
		}
	}
		
		//PRINTIN THE LEVEL ORDER FORM OF AVAL STORED IN THE QUEUE
		
      void PRINT(){
	
    if(front==NULL){
    	
        cout<<"\n\nLevel order QUEUE is empty\n";
        return;
    }
    Node* temp=front;
    cout<<"\n\nThe data in the level order traversal is:\n";

    while(temp!=NULL){
    	
        cout<<" "<<temp->data<<" ";
        temp=temp->next;
    }

    front=rear=NULL;
 }



	public:
		AVL(){
			root=NULL;
			front=rear=NULL;
		}
		
		void insert(){
			
			int n;
			cout<<"\nEnter the number to store in the AVL tree:\n";
			cin>>n;
			
			root=insertion(root,n);
		}
		
		void display(){
			
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			
			int space=0;
			
			cout<<"\nThe Display of the AVL tree is :\n";
			
			Display(root,space);
		}
		void deletee(){
			
			if(root==NULL){
				return ;
			}
			
			int n;
			cout<<"\nEnter the value to delete a value from AVL: \n";
			cin>>n;
			root=Deletee(root,n);
		}
		
		void Balance(){
			if(root==NULL){
				return ;
			}
			
			BalanceFc(root);
		}
		
		void isAVL(){
			
			if(root==NULL){
				return;
			}
			
			bool isAVL=true;
			isAVL=checkAVL(root);
			
			if(isAVL){
				cout<<"\nThe tree is AVL tree\n";
			}
		}
		
//QU.6: CONSTRUCTION OF THE AVL TREE FROM THE ARRAY USING THE INSERTION METHON AND BALANCING TECHNIQUE
		
		void constructAVL(int *ptr,int size){
			
			for(int i=0;i<size;i++){
				root=insertion(root,*(ptr+i));
			}
		}
		
		void levelorder(){
		int h=height(root);
		for(int i=1;i<=h;i++){
			storingQueue(root,i);
		}
		PRINT();
	}
};

int main(){
    AVL tree;
    AVL array;
    int choice;
    do{
        cout<<"\n1.Insert"
            <<"\n2.Delete"
            <<"\n3.Show Balance Factors"
            <<"\n4.Check AVL"
            <<"\n5.Construct AVL From Array"
            <<"\n6.Level Order Traversal"
            <<"\n7.Display Tree"
            <<"\n8.Exit"
            <<"\nEnter choice: ";

        cin>>choice;

        if(choice==1){
        	int n;
        	cout<<"\nEnter the number of the insertions to add in the AVL:\n";
        	cin>>n;
        	for(int i=0;i<n;i++){
        		 tree.insert();
			}
           
        }
        else if(choice==2){
            tree.deletee();
        }
        else if(choice==3){
            tree.Balance();
        }
        else if(choice==4){
            tree.isAVL();
        }
        else if(choice==5){
            int size;
            cout<<"Enter size: ";
            cin>>size;
            int arr[size];
            cout<<"\nEnter the number to store in array:\n";
            for(int i=0;i<size;i++){
                cin>>arr[i];
            }
            array.constructAVL(arr,size);
            array.display();
            array.isAVL();
        }
        else if(choice==6){
            tree.levelorder();
        }
        else if(choice==7){
            tree.display();
        }

    }while(choice!=8);
}
