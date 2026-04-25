#include<iostream>
using namespace std;

//Q1.STACKARRAY...Implementing stack using array

class Stack{
	public:
		int *ptr;
		int size;
		int elements;
		int top;
		
		Stack(int size){
			this->size=size;
			ptr=new int[size];
			top=-1;
			elements=0;
		}
		
		void Push(){
			if(elements==(size+1)){
				cout<<"\nThe stack is full\n";
				return;
			}
			int ele;
			cout<<"\nEnter the element to store in the stack:\n";
			cin>>ele;
			ptr[++top]=ele;
			++elements;
			
		}
		
		bool isempty(){
			return top==-1;
		}
		void pop(){
			if(isempty()){
				cout<<"\nThe Stack is empty :\n";
				return;
			}
			--top;
			--elements;
		}
		int peek(){
			if(isempty()){
				cout<<"\nThe stack is empty\n";
				return 0;
			}
			
			return ptr[top];
		}
		
		void display(){
			if(isempty()){
				cout<<"\nThe array is empty\n";
				return;
			}
			cout<<"\nThe elements in the stack is : \n";
			for(int i=0;i<top;i++){
				cout<<ptr[i]<<" ";
			}
		}
};

//Q2.STACKTHROUGHLINKLIST...Implementation through the link list

class Node{
	public:
		int data;
		Node* next;
		
		public:
			Node(int data){
				this->data=data;
				next=NULL;
			}
};

class LStack{
	private:
		Node* top;
	
	public:
			LStack(){
			top=NULL;
		}
	
		
		bool isempty(){
			return top==NULL;
		}
		void PUSH(int d=-1){
		if(d==-1){
			    cout<<"\nPlease enter the data for storing it in the stack:\n";
			cin>>d;
		}
			Node* newnode=new Node(d);
			newnode->next=top;
			top=newnode;
			
		}
		
		void POP(){
				if(isempty()){
				cout<<"\nThe stack is empty\n";
				return;
			}
			Node* temp=top;
			top=top->next;
			delete temp;
		}
		
		void DISPLAY(){
			if(isempty()){
				cout<<"\nThe Stack is empty\n";
				return;
			}
			Node* temp=top;
			while(temp){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		int PEEK(){
			if(isempty()){
				cout<<"\nThe stack is empty\n";
				return 0;
			}
			return top->data;
		}
};

//Q3.Reversing the stack through recurson using the helper function ..... Now pushing the st.push(topele) in the backtracking for 
//reversing

void insertatbottom(LStack &st,int ele){
	if(st.isempty()){
		st.PUSH(ele);
		return ;
	}
	
	int topele=st.PEEK();
	st.POP();
	
	insertatbottom(st,ele);
	st.PUSH(topele);
	
}

void ReverseStack(LStack &s){
	if(s.isempty()){
		return;
	}
	int element=s.PEEK();
	s.POP();
	
	ReverseStack(s);
	insertatbottom(s,element);
	
}

//Q4.Sort2 the helper method ...... for making it into the ascending order add this to the condition.. st.isempty() || ele<=st.PEEK()
//it would convert it into the sorted order

void SORT2(LStack &st,int ele){
	if(st.isempty() || ele<=st.PEEK()){
		st.PUSH(ele);
		return ;
	}
	int topele=st.PEEK();
	st.POP();
	
	SORT2(st,ele);
	st.PUSH(topele);
	
}

void SortStack(LStack &s){
	if(s.isempty()){
		return;
	}
	
	int element=s.PEEK();
	s.POP();
	
	SortStack(s);
	SORT2(s,element);
	
}

void deletemid(LStack &st,int count,int mid){
	if(st.isempty()){
		return;
	}
	int ele=st.PEEK();
	st.POP();
	
	if(count==mid){
		return;
	}
	
	deletemid(st,count+1,mid);
	st.PUSH(ele);
}

void removemid(LStack &st,int n){
	deletemid(st,0,n/2);
}

//Q6.For checking the balanced parenthisis push the each index string to the stack if equals the opening parenthesis if not return false
//

bool matchPair(char open,char close){
    if(open=='(' && close==')'){
    	return true;
	}
    if(open=='{' && close=='}'){
    	return true;
	}
    if(open=='[' && close==']'){
    	return true;
	}
	
    return false;
}

bool checkBalanced(string exp){
    LStack st;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        if(ch=='('||ch=='{'||ch=='['){
            st.PUSH(ch);
        }
        
        else if(ch==')'||ch=='}'||ch==']'){
            if(st.isempty()){
            	return false;
			}
            char topChar=(char)st.PEEK();
            st.POP();
            if(!matchPair(topChar,ch)){
            	return false;
			}
        }
    }
    return st.isempty();
}

//Q7.Next Greater element 

void nextGreater(int arr[],int n){
    LStack st;
    int res[n];
    
    for(int i=n-1;i>=0;i--){
    	
        while(!st.isempty() && st.PEEK()<=arr[i]){
        	 st.POP();
		}
        if(st.isempty()){
        	 res[i]=-1;
		}
        else{
        	 res[i]=st.PEEK();
		}
        st.PUSH(arr[i]);
    }
    for(int i=0;i<n;i++){
    	 cout<<res[i]<<" ";
	}
    cout<<endl;
}



int main(){
    int ch,siz;
    do{
        cout<<"\n------MENU DISPLAY------\n";	
        cout<<"\n1.Array Stack\n";
        cout<<"2.LinkedList Stack\n";
        cout<<"3.Reverse Stack\n";
        cout<<"4.Sorted Stack\n";
        cout<<"5.Delete Mid\n";
        cout<<"6.Balanced Parentheses\n";
        cout<<"7.Next Greater Element\n";
        cout<<"8.Exit\n";
        cout<<"Enter choice:\n";

        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"Enter size:\n";
                cin>>siz;
                
                Stack s(siz);
                int n;
                
                cout<<"How many elements to push:\n";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    s.Push();
                }
                cout<<"\nPop?1/0:\n";
                int x;
                cin>>x;
                
                if(x){
                    s.pop();
                }
                
                s.display();
                break;
            }
            case 2:{
                LStack p;
                int n;
                cout<<"How many elements you want to push:\n";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    p.PUSH();
                }
                p.DISPLAY();
                cout<<"\nPop::1/0:\n";
                int x;
                cin>>x;
                
                if(x){
                    p.POP();
                }
                p.DISPLAY();
                break;
            }
            case 3:{
                LStack s;
                int n;
                cout<<"Enter number of elements:\n";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    s.PUSH();
                }
                cout<<"Original:";
                s.DISPLAY();
                ReverseStack(s);
                cout<<"\nReversed:";
                s.DISPLAY();
                break;
            }
            case 4:{
                LStack s;
                int n;
                cout<<"Enter number of elements:\n";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    s.PUSH();
                }
                
                cout<<"Original:";
                s.DISPLAY();
                SortStack(s);
                
                cout<<"\nSorted:";
                s.DISPLAY();
                break;
            }
            case 5:{
                LStack s;
                int n;
                cout<<"Enter number of elements:\n";
                cin>>n;
                
                for(int i=0;i<n;i++){
                    s.PUSH();
                }
                cout<<"Original:";
                s.DISPLAY();
                
                removemid(s,n);
                
                cout<<"\nDeleted:";
                s.DISPLAY();
                break;
            }
            case 6:{
                string exp;
                cout<<"Enter expression:\n";
                cin>>exp;
                
                if(checkBalanced(exp)){
                    cout<<"Balanced\n";
                }
                else{
                    cout<<"Not Balanced\n";
                }
                break;
            }
            case 7:{
                int n;
                cout<<"Enter size of array:\n";
                cin>>n;
                int arr[n];
                cout<<"Enter elements:\n";
                
                for(int i=0;i<n;i++){
                    cin>>arr[i];
                }
                
                cout<<"Next Greater Elements:";
                nextGreater(arr,n);
                break;
            }
            case 8:
                cout<<"Exit\n";
                break;
            default:
                cout<<"Invalid\n";
        }
    }while(ch!=8);
}

