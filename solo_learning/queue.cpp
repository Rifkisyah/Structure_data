#include <iostream>

class QueueArray{
public:
	#define SIZE 5
	struct Queue{
		std::string data[SIZE];
		int index;
	};

	Queue *queue = new Queue;

	void init(){
		for (int i = 0; i < SIZE; i++){
			queue->data[i] = "Kosong";
		}
		queue->index = -1;
	}

	bool isEmpty(){
		return (queue->index == -1);
	}

	bool isFull(){
		return (queue->index == SIZE-1);
	}
	
	void EnQueue(std::string value){
		if (isFull()){
			print();
		}else{
			queue->index++;
			queue->data[queue->index] = value;
		}
	}

	void DeQueue(){
		if (isEmpty()){
			print();
		}else{
			for (int i = 1; i < SIZE; i++){
				queue->data[i-1] = queue->data[i];
			}
			queue->data[queue->index] = "kosong";
			queue->index--;
		}
	}

	void print(){
		if (isFull()){
			std::cout << "Data Penuh!";
		}else if(isEmpty()){
			std::cout << "Data Kosong!";
		}else{
			for (int i = SIZE-1; i >= 0; i--){
				std::cout << "[ " << i << " ] " << queue->data[i] << "\n";
			}
		}
	}
};

class QueueLinkedlist{
public:
	struct Node{
		std::string data;
		Node *next = nullptr;
	};

	Node *head = nullptr;
	Node *tail = nullptr;
	int i = -1;

	bool isEmpty(){
		return (head == nullptr && tail == nullptr);
	}

	void EnQueue(std::string value){
		Node *queue = new Node;
		queue->data = value;

		if (head == nullptr){
			head = tail = queue;
		}else{
			Node *temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = queue;
			tail = queue;
			i++;
		}
	}

	void DeQueue(){
		Node *temp = head;
		if (isEmpty()){
			print();
		}else{
			head = temp->next;
			delete temp;
		}
	}

	void print(){
		if (!isEmpty()){
			while(head != nullptr){
				std::cout << "[ " << i-- << " ] " << head->data << "\n";
				head = head->next;
			}
		}else{
			std::cout << "Data Kosong!";
		}
	}
};

int main(int argc, char const *argv[])
{
	

	return 0;
}