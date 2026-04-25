#include<iostream>
#include<iomanip>
using namespace std;
int LEAF;
int MIN;

class Node{
	public:
		Node* left,*right;
		Node* next;
		int data;
		Node(int data){
			this->data=data;
			left=right=NULL;
		}
};

class BST{
	Node* root;
	Node* front,*rear;
	
	Node* insertion(Node* root,int key){
		if(root==NULL){
			return new Node(key);
		}
		
		if(key<root->data){
			root->left=insertion(root->left,key);
		}
		if(key>root->data){
			root->right=insertion(root->right,key);
		}
		return root;
	}
	

	void DISPLAY(Node* root,int space){
		const int indent=6;
		if(root==NULL){
			return;
		}
		DISPLAY(root->right,space+indent);
		cout<<setw(space)<<' '<<root->data<<endl;
		DISPLAY(root->left,space+indent);
	}
	

	


	
	
//1.Height of the tree: The height is calculated by movig to the longest path from the root toeanrds its leaf nodes and the comparing 
//each heaight of leaft and right for max which at end is the height


	int height(Node* root){
		
		if(root==NULL){
			return 0;
		}
		
	     	int left=1+height(root->left);
		    int right=1+height(root->right);
		    
		    return (left>right) ? left:right;
	}
	
	//COUNTING NODES METHOD 
	
   int countnodes(Node* root){
   	
	if(root==NULL){
		return 0;
	}
	
	return 1+countnodes(root->left)+countnodes(root->right);
	
  }
  
//2.Counting Leaf and Non Leaf Nodes : First counting each node by passing into the countingnodes method and reducing by one bcz of root
//node if equals 0 that means that node is child node and the counting tham would give us the leaf nodes .....subtracting them from the 
//total nodes would tell us about non leaf also 

	    void countingL(Node* root,int &L,int& NL){
		
		if(root==NULL){
			return ;
		}
		
		countingL(root->left,L,NL);
		countingL(root->right,L,NL);
		
		if(root->left || root->right){
			++NL;
		}
		if(root->left==NULL && root->right==NULL){
			++L;
		}
		
	}
		
//3.LEVEL ORDER TRAVERSAL USING THE QUEUE: First including the Queue front rear pointers with next pointer in the Node class Then making
//level order traversal and passing to the queue one by one until nodes end

	
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
	
		
	//3.2: Display method for showing the values stored in the queue in level order traversal 
	
	
	    void PRINT(){
		
		if(front==NULL){
			return;
		}
		
		Node* temp=front;
		cout<<"\n\nThe data in the level order traversal is:\n";
		
		while(temp!=NULL){
			
			cout<<" "<<temp->data<<" ";
			temp=temp->next;
		}
	}
		
//4.Diameter Of the Binary TRee: The longest pathh in the tree that exists in terms of levels not the nodes ... First calculating the 
//Length of the tree which is the sum of the left and right heaight and comparing that with the right and left longest paths and at last 
//returning the length to the function
		
		int Diameter(Node *root){
			
		if(root==NULL){
			return 0;
		}
		
		int lheight=height(root->left);
		int rightheight=height(root->right);
		
		int length=lheight+rightheight;
		
		
		int Rdiameter=Diameter(root->right);
		int Ldiameter=Diameter(root->left);
		
		if(Rdiameter>length){
			
			length=Rdiameter;
			
		}
		
		else if(Ldiameter>length){
			
			length=Ldiameter;
			
		}
		
		return length;
	}


//5.Checking Binary Tree is BST or Not: Making the bool method to check for BST by checking every nodes data less than its right nodes 
//and greater than its left ones if yes then tree is BST 

	    bool checkNodes(Node* root){
	    	
    if(root==NULL){
    	
    	return true;
	} 
    
    if(root->left!=NULL && root->data<=root->left->data){
    	 return false;
	}
       
    
    if(root->right!=NULL && root->data>=root->right->data){
    	 return false;
	}
       
    
    return checkNodes(root->left)&&checkNodes(root->right);
}
	

//6.Printing the path from Root to the Given Node : First Checking the target whether located on left , right or became equal using three
//Conditions when it would became same then return if not keep printing the path 	
	
	
	    void PathfromRN(Node* root,int key){
	    	
		if(root==NULL){
			return;
		}
		
		cout<<" "<<root->data;
		
		if(key<root->data){
			PathfromRN(root->left,key);
		}
		
		else if(key>root->data){
			PathfromRN(root->right,key);
		}
		
		else{
			return;
		}
		
	}

//8.Sum of ALL leaf Nodes :Receiving the root->left for printing the sum of the left leaf nodes only so by condition 
//when root->left && root->right would null then confirmed it is child node then adding that data into the sum 


     	void sumofleaf(Node* root,int& sum){
     		
		if(root==NULL){
			return;
		}
		
		sumofleaf(root->left,sum);
		sumofleaf(root->right,sum);
		
		if(root->left && root->left->left==NULL && root->left->right==NULL){
			sum+=root->left->data;
		}
	}

//9.Printing the ancestors of the the given node first moving from the root data and checking where the target is included and then 
//moving on that side printing the root->data upto that target when root->data equals target the return

         void ancestor(Node* root,int key){
         	
  	  if(root==NULL){
  		return;
	  }
	  
	  if(root->data==key){
	  	return;
	  }
	  
	  cout<<" "<<root->data;
	  
	  if(key<root->data){
	  	ancestor(root->left,key);
	  	
	  }
	  
	  if(key>root->data){
	  	
	  ancestor(root->right,key);
	  
	  }
	  
  }	

//10.Finding the Smallest element in Binary Tree using the inorder traversal 

    	int smallestKth(Node* root){
		
		if(root==NULL){
			return 0;
		}
		
		smallestKth(root->left);
		
	    if(root->data<MIN){
	    	MIN=root->data;
		}          
		
		smallestKth(root->right);
		
		return MIN;
	}
	





	
	public:
		BST(){
			root=NULL;
			front=rear=NULL;
		}
		
		void insert(){
			int n;
			cout<<"\nEnter the number you want to store in a tree :\n";
			cin>>n;
			root=insertion(root,n);
			
		}
		
	
		void display(){
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			cout<<"\nDisplay OF tree is :\n";
			DISPLAY(root,40);
		}
		void HEIGHT(){
			cout<<"\nThe height of the BST is :\n"<<height(root);
		}
		
		void leafnoleaf(){
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			int L=0;
			int NL=0;
			countingL(root,L,NL);
			
			
			
			cout<<"\n\nThe number of leaf nodes are : "<<L<<" and non leaf nodes are : "<<NL;
		}
		
		void Ancestors(){
			if(root==NULL){
				return;
			}
			int n;
			cout<<"\nEnter the number for the ancestors:\n";
			cin>>n;
			ancestor(root,n);
		}
		void diameter(){
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			cout<<"\nThe diameter of the tree is : \n"<<Diameter(root);
		}
		
		void levelorder(){
		int h=height(root);
		for(int i=1;i<=h;i++){
			storingQueue(root,i);
		}
		PRINT();
	}
		
		void smallestE(){
			if(root==NULL){
				return ;
			}
			MIN=root->data;
			
			cout<<"\nThe smallest number in the tree is : \n"<<smallestKth(root);
			
		}
		
		void checkBST(){
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			bool ax=checkNodes(root);
			if(ax){
				cout<<"\nThe tree is BST \n";
			}
		}
		
		void Pathh(){
			if(root==NULL){
				cout<<"\nEmpty\n";
				return;
			}
			int siz;
			cout<<"\nEnter the number upto which you want to print the path :\n";
			cin>>siz;
			PathfromRN(root,siz);
		}
		
		void sumL(){
			if(root==NULL){
				return;
			}
			int sum=0;
			//Passing the Root->left for the sum of left leaf nodes Only
			
			sumofleaf(root,sum);
			cout<<"\nThe sum of the left child Nodes is:\n"<<sum;
		}
};

int main() {
    int choice;
    BST t;           
    int n;
    bool built=false;   

    do {
        cout<<"\n===== BINARY TREE OPERATIONS =====\n";
        cout<<"1.Insert Nodes\n";
        cout<<"2.Height of Binary Tree\n";
        cout<<"3.Count Leaf and Non-Leaf Nodes\n";
        cout<<"4.Level Order Traversal-QUEUE\n";
        cout<<"5.Diameter of Binary Tree\n";
        cout<<"6.Check if Binary Tree is BST\n";
        cout<<"7.Path from Root to Given Node\n";
        cout<<"8.Sum of All Leaf Nodes\n";
        cout <<"9.Ancestors of a Node\n";
        cout<<"10.Kth Smallest Element in BST\n";
        cout<<"0.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==0){
            cout<<"Exiting...\n";
            break;
        }

        switch(choice){

            case 1: {
                cout<<"Enter number of nodes: ";
                cin>>n;

                cout << "Enter values to insert:\n";
                for(int i=0;i<n;i++){
                    t.insert();
                }
                t.display();
                built=true;
                cout<<"Tree Built Successfully!\n";
                break;
            }

            case 2:
                if(built){
                	t.HEIGHT();
				} 
                else{
                	cout<<"Build tree first!\n";
				}
                break;

            case 3:
                if(built){
                	 t.leafnoleaf();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 4:
                if(built){
                	 t.levelorder();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 5:
                if(built){
                	 t.diameter();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 6:
                if(built){
                	 t.checkBST();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 7:
                if(built){
                	 t.Pathh();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 8:
                if(built){
                	 t.sumL();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 9:
                if(built){
                	 t.Ancestors();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            case 10:
                if(built){
                	 t.smallestE();
				}
                else{
                	 cout<<"Build tree first!\n";
				}
                break;

            default:
                cout<<"Invalid choice\n";
        }

    } while(choice!=0);

    return 0;
}

