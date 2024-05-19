#include <iostream>
struct Node{
	std::string name;
	Node *next = nullptr;	
};

Node *head = nullptr;
Node *tail = nullptr;

void first_insert(std::string data){
	Node *newdata = new Node;
	newdata->name = data;

	if(head == nullptr){
		head = tail = newdata;
	}else{
		newdata->next = head;
		head = newdata; 
	}
}

void last_insert(std::string data){
	Node *newdata = new Node;
	newdata->name = data;

	if(head == nullptr){
		head = tail = newdata;
	}else{
		head = head->next;
		head->next = newdata;
		newdata = tail;
	}
}

void print(){
	Node *print = head;
	while(print != nullptr){
		std::cout << print->name << " ";
		print = print->next;
	}
}

int main(){
	
	first_insert("hello");
	first_insert("world");
	last_insert("buddy");
	print();
}