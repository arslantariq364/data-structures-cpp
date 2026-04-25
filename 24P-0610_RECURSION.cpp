#include<iostream>
using namespace std;

int count;

// 1.Print All Subsets of a String:n is storing the number of the elements in the string and matching with the index number for hitting
//the base condition.....here the recursive calls generate the subsets by adding or removing the elements from the string to print

void subsets(string st,int index=0,string cur=""){
	
	
	int n=st.length();
	
	if(index==n){
		cout<<"{"<<cur<<"} ,";
		return;
	}
	
	
	subsets(st,index+1,cur+st[index]);
	subsets(st,index+1,cur);
}

// 2.Generate All Permutations of a String:so fo generating the permutation the formula is 3!=3.2.1    where 3 is the number of elements 
//in the string the base condition hit when index would equals n as it would always generate the three elemetns but by swapping 
//so i used the logic of bubble sorting in it to change of n! combinations 

void permutations(string st,int ind=0){
	
	
	if(ind==st.length()){
		cout<<st<<", ";
		return;
	}
	
	
	for(int i=ind;i<st.length();i++){
		
		char temp=st[ind];
		st[ind]=st[i];
		st[i]=temp;

		permutations(st,ind+1);

		temp=st[ind];
		st[ind]=st[i];
		st[i]=temp;
	}
}

// 3.Subset Sum Problem:The idea is to get the numbers that form or equals to the target value then return the true .... so we get the
//in sum form and the start the last array element where we would see each element whether it would result into 0 by adding up or not from
//the sum target

bool subsetSum(int arr[],int n,int sum){
	
	if(sum==0){
		return true;
	}
	
	if(n==0){
		return false;
	}
	
	//if any value from the lasr not equals the sum and is greater so exclude that
	
	if(arr[n-1]>sum){
		return subsetSum(arr,n-1,sum);
	}
	
	//if first condition fails means that now one of the condition has to be accept .... include or mov to next so checking this 
	//recursively to conditions i f by-passed again and again then it would finally be caught in 0 making it true .
	else{
		return subsetSum(arr,n-1,sum) || subsetSum(arr,n-1,sum-arr[n-1]);
	}
}

// 4.Fibonacci Sequence: The base condition would hit when it would see the total number s are completed so it return ...otherwise print
//number in recursive call the a's value changed by b and b value by a+b after printing 

void Fibonacci(int a=0,int b=1,int count=0,int n=0){
	
	if(count==n){
		return;
	}
	
	cout<<a<<" ";
	
	Fibonacci(b,a+b,count+1,n);
}

// 5.Reverse a String: Taking the string by reference would make it change permanently so i would take two indexes one from beginning and
//one from the last and then swapping them together upto the middle would reverse it completely 

void reverse(string &st,int count,int i=0,int ind=0){
	
	if(count==st.length()/2){
		return;
	}
	
	char ch=st[i];
	st[i]=st[ind];
	st[ind]=ch;
	
	
	reverse(st,count+1,i+1,ind-1);
}

// 6.Find Power x raised to y there are two possibilities one is the y is positive so we would multiply with x by each subtracting the 
//the y but in y is negative then making y positive an dagainf calling power recursively and dividing by 1 for result

double powerofn(int x,int y){
	
	if(y==0){
		return 1;
	}
	
	if(y>0){
		return x*powerofn(x,y-1);
	}
	
	else{
		return 1/powerofn(x,-y);
	}
	
}

// 7.Count Digits of a Number: Just keep dividing the number by the 10 and counting the reminders that time so at last when x =0 so base 
//would equal the number of the digits 

void countingdigits(int x,int &base){
	
	if(x==0){
		return;
	}
	
	countingdigits(x/10,++base);
	
}

// 8.Count Occurrences of a Number in Array: Index starting from the last and comparing each index array number with the target if found 
//count ++ otherwise moving to the next one this would count total number of the occurrences in an array

void countoccurrences(int *arr,int target,int index){
	
	if(index<0){
		return;
	}
	
	if(arr[index]==target){
		count++;
	}
	
	countoccurrences(arr,target,index-1);
}

// 9.Reverse an Array: the same logic the swapping from the starting with the end one upto the middle would reverse the elements in 
//the array 

void reversearr(int arr[],int ind,int ind2,int total){
	
	if(ind==total/2){
		return;
	}
	
	int temp=arr[ind];
	arr[ind]=arr[ind2];
	arr[ind2]=temp;
	
	reversearr(arr,ind+1,ind2-1,total);
}

// 10.Find Maximum Element in Array:Using max function would find the max upto all the elements recursively with base condition when become
//one it would return the first value in the index 

int findMax(int arr[],int n){
	
	if(n==1){
		return arr[0];
	}
	
	else{
		return max(arr[n-1],findMax(arr,n-1));
	}
}

// 11.Binary Search using Recursion:First finding the target is whether on the first halft or the second half and then chacking 
//to that side by recursion 


int binarySearch(int arr[],int l,int r,int target){
	
	if(l>r){
		return -1;
	}
	
	int mid=(l+r)/2;
	
	if(arr[mid]==target){
		return mid;
	}
	
	else if(arr[mid]>target){
		return binarySearch(arr,l,mid-1,target);
	}
	
	else{
		return binarySearch(arr,mid+1,r,target);
	}
}


int main(){
	
	int choice;
	
	do{
		
		cout<<"\n=====RECURSIVE PROBLEMS MENU=====\n";
		
		cout<<"1.Print All Subsets of a String\n";
		cout<<"2.Generate All Permutations of a String\n";
		cout<<"3.Subset Sum Problem\n";
		cout<<"4.Fibonacci Sequence\n";
		cout<<"5.Reverse a String\n";
		cout<<"6.Find the Power\n";
		cout<<"7.Count Digits of a Number\n";
		cout<<"8.Count Occurrences of a Number in Array\n";
		cout<<"9.Reverse an Array\n";
		cout<<"10.Find Maximum Element in Array\n";
		cout<<"11.Binary Search in Array\n";
		cout<<"12.Exit\n";
		
		
		cout<<"Enter choice:\n";
		cin>>choice;

		if(choice==1){
			
			string str;
			cout<<"Enter string:\n";
			cin>>str;
			subsets(str);
			
			cout<<endl;
		}
		else if(choice==2){
			string str;
			cout<<"Enter string:\n";
			cin>>str;
			permutations(str);
			
			cout<<endl;
		}
		else if(choice==3){
			
			int size,sum;
			cout<<"Enter size of array:\n";
			
			cin>>size;
			int arr[size];
			
			cout<<"Enter elements:\n";
			
			for(int i=0;i<size;i++){
				cin>>arr[i];
			}
			
			cout<<"Enter target sum:\n";
			cin>>sum;
			
			if(subsetSum(arr,size,sum)){
				cout<<"Subset exists.\n";
			}
			else{
				cout<<"Subset does not exist.\n";
			}
		}
		else if(choice==4){
			
			int n;
			cout<<"Enter n:\n";
			  cin>>n;
			Fibonacci(0,1,0,n);
			cout<<endl;
		}
		else if(choice==5){
			
			string str;
			cout<<"Enter string:\n";
			cin>>str;
			
			  reverse(str,0,0,str.length()-1);
			 cout<<str<<endl;
		}
		else if(choice==6){
			int x,y;
			
			cout<<"Enter base and exponent:\n";
			cin>>x>>y;
			
			cout<<powerofn(x,y)<<endl;
		}
		else if(choice==7){
			int num,base=0;
			
			cout<<"Enter number:\n";
			cin>>num;
			
			countingdigits(num,base);
			
			cout<<"Digits count: "<<base<<endl;
		}
		else if(choice==8){
			
			int size,target;
			cout<<"Enter size of array:\n";
			cin>>size;
			
			int arr[size];
			cout<<"Enter elements:\n";
			
			for(int i=0;i<size;i++){
				cin>>arr[i];
			}
			
			cout<<"Enter target:\n";
			cin>>target;
			count=0;
			
			countoccurrences(arr,target,size-1);
			cout<<"Occurrences: "<<count<<endl;
		}
		else if(choice==9){
			int size;
			
			cout<<"Enter size of array:\n";
			cin>>size;
			int arr[size];
			cout<<"Enter elements:\n";
			
			for(int i=0;i<size;i++){
				cin>>arr[i];
			}
			
			reversearr(arr,0,size-1,size);
			cout<<"Reversed array: ";
			
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		else if(choice==10){
			int size;
			
			cout<<"Enter size of array:\n";
			cin>>size;
			int arr[size];
			cout<<"Enter elements:\n";
			
			for(int i=0;i<size;i++){
				cin>>arr[i];
			}
			
			cout<<"Maximum element: "<<findMax(arr,size)<<endl;
		}
		else if(choice==11){
			int size,target;
			
			cout<<"Enter size of sorted array:\n";
			cin>>size;
			int arr[size];
			
			cout<<"Enter elements (sorted):\n";
			
			for(int i=0;i<size;i++){
				cin>>arr[i];
			}
			
			cout<<"Enter target:\n";
			cin>>target;
			
			int index=binarySearch(arr,0,size-1,target);
			if(index==-1){
				cout<<"Not found\n";
			}
			else{
				cout<<"Found at index "<<index<<endl;
			}
		}
		else if(choice==12){
			cout<<"Exiting...\n";
		}
		else{
			cout<<"Invalid choice.\n";
		}

	}while(choice!=12);

	return 0;
}
