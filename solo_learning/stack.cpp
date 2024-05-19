#include <iostream>

class StackArray{
public:
	#define SIZE 3

	struct Stack{
		std::string nama[SIZE];
		int index;
	};

	Stack *stack = new Stack;

	void init(){
		for (int i = 0; i < SIZE; i++){
			stack->nama[i] = "Kosong";
		}
		stack->index = -1;
	}

	bool isEmpty(){
		return (stack->index == -1);
	}

	bool isFull(){
		return (stack->index == SIZE-1);
	}

	void push(std::string value){
		if (isFull()){
			std::cout << "Data Penuh!";
		}else{
			stack->index++;
			for (int i = 0; i < SIZE; i++){
				stack->nama[stack->index] = value;
			}
		}
	}

	void pop(){
		if (isEmpty()){
			std::cout << "Data Kosong!";
		}else{
			stack->nama[stack->index] = "kosong";
			stack->index--;
		}
	}

	void clear(){
		if (!isEmpty()){
			init();
		}else{
			print();
		}
	}

	void push_all(StackArray *all){
		if (isFull()){
			std::cout << "Data Penuh!";
		}else{
			all->index++;
			all->nama[all->index] = value;
		}
	}

	void print(){
		if (isFull()){
			std::cout << "";
		}else if(isEmpty()){
			std::cout << "Data Kosong!";
		}else{
			for (int i = SIZE-1; i >= 0; i--){
				std::cout << "[ " << i << " ] " << stack->nama[i] << "\n";
			}
		}
	}

	void menu(){
		int opt;
		std::string nama;
		std::cout << "Stack Array\n";
		print();
		std::cout << "\n\n";
		std::cout << "Menu\n" << "1. Push  \n2. Pop \n3. clear \n0. exit\n Choose your option : ";
		std::cin >> opt;


		system("cls");
		switch(opt){
		case 1: 
			std::cout << "Masukan Nama : ";
			std::cin.ignore();
			getline(std::cin,nama);
			push(nama);
			system("cls");
			menu();
			break;
		case 2:
			pop();
			system("cls");
			menu();
			break;
		case 3:
			clear();
			system("cls");
			menu();
			break;
		case 0:
			system("exit");
			break;
		default : 
			std::cerr << "invalid input!";
			system("cls");
			menu();
			break;
		}
	}
};

class StackLinkedlist{
public:
	struct Node{
		std::string nama;
		Node *next = nullptr;
		int i = 0;
	};

	Node *head = nullptr;
	Node *tail = nullptr;

	bool isEmpty(){
		return (head == nullptr && tail == nullptr);
	}

	void push(std::string value){
		Node *stack = new Node;
		stack->nama = value;
		if (head == nullptr){
			head = tail = stack;
		}else{
			Node *newdata = head;
			while(newdata->next != nullptr){
				newdata = newdata->next;
			}
			newdata->next = stack;
			tail = stack;
			head->i++;
		}
	}

	void pop(){
		Node *temp = head;
		if (isEmpty()){
			print();
		}else if (temp->next != nullptr){
			while(temp->next != tail){
				temp = temp->next;
			}
			delete temp->next;
			temp->next = nullptr;
			tail = temp;
		}else if (temp->next == nullptr){
			delete temp;
			head = tail = temp = nullptr;
		}
	}

	void print(){
		if (!isEmpty()){
			while(head != nullptr){
				std::cout << "[ " << head->i-- << " ] " << head->nama << "\n";
				head = head->next;
			}
		}else{
			std::cout << "Data Kosong!";
		}
	}
};

void push_all(StackArray *queue){
		if (isFull()){
			print();
		}else{
			queue->index++;
			queue->data[queue->index] = value;
		}
	}

int main(int argc, char const *argv[])
{
	StackArray balita;
	StackArray anak_anak;
	StackArray dewasa;
	StackArray *kondisi_umur;

	balita.push("anna");
	balita.push("edward");


	anak_anak.push("vincent");
	anak_anak.push("ollie");


	dewasa.push("james");
	dewasa.push("john");


	kondisi_umur->push_all(balita);
	kondisi_umur->push_all(anak_anak);
	kondisi_umur->push_all(dewasa);

	kondisi_umur->print();
	return 0;
}