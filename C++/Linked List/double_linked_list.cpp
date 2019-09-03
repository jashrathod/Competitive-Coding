#include<iostream>
using namespace std;

struct node{
	int data;
	node* prev;
	node* next;
};
class Double{
	node* start;
	node *ptr;
	public :
	Double(){
	start = NULL ;
	}
	void insert(int ele){
		node* p = new node ;	
		p->data = ele;
		p->prev = NULL ;
		p->next = NULL ;
		if(start==NULL){
		start = p ;
		}
		else{
		ptr=start;
		while(ptr->next!=NULL) ptr=ptr->next;
		ptr->next=p;
		p->prev=ptr;		
		}
	}
	void find(int x){
		node* p = start;
		node* q = start;
	while(q->next!= NULL){
		while(p->next!=NULL){
			int temp = q->data + p->data ;
			if(x==temp){
				cout<<"<"<<q->data<<" ,"<<p->data<<">"<<endl;
			}
			p = p->next;
		}
		q = q->next;
		p = q->next;
	}
	}
};
int main(){

	Double d;
	d.insert(1);
	d.insert(3);
	d.insert(5);
	d.insert(7);
	d.insert(9);
	d.insert(11);
	d.insert(13);

	d.find(10);
	return 0;
}

