#include<iostream>
#include<conio.h>
#include<fstream>


using namespace std;

class Student{
	public:
    int roll_no;
	string name;
	int marks;
};

class Node: public Student{
	public:
		
		Student data;
		Node *next;
		
		public:
		void insert_at_beg(int rn,string nm,int m);
		void insert_at_end(int rn,string nm,int m);
		void insert_at_pos(int rn,string nm,int m,int pos);
		void del_at_beg();
		void del_at_end();
		void del_at_pos(int pos);
	    void traverse();
	    int store_data_in_file() ;
	    
};
Node *root=NULL;
void Node::insert_at_beg(int rn,string nm,int m) 
{
	        
			Node* new_node=new Node();
			
			new_node->roll_no=rn;
			new_node->name=nm;
			new_node->marks=m;
			
		    if(root==NULL) 
			{
			root=new_node;
				new_node->next=NULL;
		
		}
		else
		{
			new_node->next=root;
			root=new_node;
			}
			cout<<"Student data inserted successfully"<<endl;
	}
	
	void Node::insert_at_end(int rn,string nm,int m) 
{
			Node* new_node=new Node();
			Node  *temp;
				new_node->roll_no=rn;
			new_node->name=nm;
			new_node->marks=m;
		new_node->next=NULL;
			if(root==NULL) 
			{
			root=new_node;
			}
		else
		{
			temp=root;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new_node;
			}
			cout<<"Student data inserted successfully"<<endl;
	}
	
	void Node::insert_at_pos(int rn,string nm,int m,int pos) 
{
		
			Node  *temp,*p;
			temp=root;
			for(int i=1;i<pos-1;i++){
				if(temp==NULL){
					cout<<"Insufficient space"<<endl;
					return;
				}
				temp=temp->next;
			}
				Node* new_node=new Node();
				new_node->roll_no=rn;
			new_node->name=nm;
			new_node->marks=m;
		new_node->next=temp->next;
		temp->next=new_node;
		cout<<"Student data inserted successfully"<<endl;
	}
	
	void Node::del_at_beg()
	{
		Node *temp;
		
		if(root==NULL)
		cout<<"\n Empty list";
		else
		{
		cout<<"The data of student having roll_no "<<root->roll_no<<"is deleted"<<endl;
		temp=root;
		if(root->next==NULL){
			root=NULL;
				delete(temp);
		}	
		else{
			root=root->next;
			delete(temp);
		}
	
		}
	}
	
	void Node::del_at_end()
	{
		Node *temp,*v;
		
		if(root==NULL)
		cout<<"\n Empty list";
		else
		{
			cout<<"The data of student having roll_no "<<root->roll_no<<"is deleted"<<endl;
		temp=root;
		if(root->next==NULL){
			root=NULL;
				delete(temp);
		}	
		else{
		v=root->next;
		while(v->next!=NULL){
			v=v->next;
			temp=temp->next;
		}
		cout<<"The data of student having roll_no "<<v->roll_no<<"is deleted"<<endl;
		temp->next=NULL;
		delete(v);
		}
	
		}
	}
	
	void Node::del_at_pos(int pos)
	{
		Node *temp,*p;
		temp=root;
		for(int i=1;i<pos-1;i++){
			if(temp==NULL){
				cout<<"Insufficient element"<<endl;
				return;
			}
			temp=temp->next;
		}
		p=temp->next;
		cout<<"deleted element is "<<p->roll_no<<endl;
		temp->next=p->next;
		delete(p); 
			}
	
	
	
	void Node::traverse()
	{
	    Node *temp;
		temp=root;
		if(temp==NULL)
		cout<<"\n Empty list";
		else
		{
			while(temp!=NULL) 
		{
			
			cout<<"Roll No : "<<temp->roll_no<<endl;
			cout<<"Name No : "<<temp->name<<endl;
			cout<<" Marks : "<<temp->marks<<endl;
			temp=temp->next;
		}
	}
}
	
	int Node::store_data_in_file() {
		
		if(root==NULL){
			cout<<"Data not initialized";
			return (0);
		}
		else {
		ofstream fout;
		fout.open("student_file.txt",ios::app);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		ifstream ifs;
		ifs.read((char*)this,sizeof(*this));
		ifs.close();
		cout<<"data is saved in file successfully"<<endl;
		return(1);
	}
}

int main() {
int rn,m,pos;
string nm;
int choice;



Node n;

do {
cout<<"Enter 1 to insert student data in beginning of list"<<endl;
cout<<"Enter 2 to insert student data at end of the list"<<endl;
cout<<"Enter 3 to insert student data in any specified position linked list"<<endl;
cout<<"Enter 4 to delete student data from beginning of list"<<endl;
cout<<"Enter 5 to delete student data from the end of list"<<endl;
cout<<"Enter 6 to delete student data from any specified position in list"<<endl;
cout<<"Enter 7 to traverse the data from list"<<endl;
cout<<"Enter 8 to exit"<<endl;
cout<<"Enter your choice"<<endl;
cin>>choice;
switch(choice){
	case 1:
	
		cout<<"Enter roll no of student"<<endl;
		cin>>rn;
		cout<<"Enter name of student"<<endl;
		cin>>nm;
		cout<<"Enter marks of student"<<endl;
		cin>>m;
	    n.insert_at_beg(rn,nm,m);
	    n.store_data_in_file();
		break;
		
		case 2:
		cout<<"Enter roll no of student"<<endl;
		cin>>rn;
		cout<<"Enter name of student"<<endl;
		cin>>nm;
		cout<<"Enter marks of student"<<endl;
		cin>>m;
	    n.insert_at_end(rn,nm,m);
	     n.store_data_in_file();
		break;
		
		case 3:
		
		cout<<"Enter position where u want to insert the data"<<endl;
		cin>>pos;
     	cout<<"Enter roll no of student"<<endl;
		cin>>rn;
		cout<<"Enter name of student"<<endl;
		cin>>nm;
		cout<<"Enter marks of student"<<endl;
		cin>>m;
	
	    n.insert_at_pos(rn,nm,m,pos);
	    n.store_data_in_file();
		break;
		
		case 4:
			n.del_at_beg();
			break;
			
		case 5:
			n.del_at_end();
			break;	
			
			case 6:
				cout<<"Enter position"<<endl;
				cin>>pos;
				n.del_at_pos(pos);
				break;
		
		case 7:
		n.traverse();
		break;
		
	    case 8: exit(0);
				
		default:
		cout<<"Enter correct choice"<<endl;
}
}while(1);
return 0;	
}

	
