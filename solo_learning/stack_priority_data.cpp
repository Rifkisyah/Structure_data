#include <iostream>

struct TypeInput{
	int level;
	int value;
	TypeInput(int v = 0, int l = 0) : level(l), value(v) {}
};

template <typename T>
class Stack_Linkedlist{
	struct Stack{
		T name;
		Stack *next = nullptr;
	};

public :
	Stack *head = nullptr;
	Stack *tail = nullptr;
	int i = 1;

	bool isEmpty(){
		return (head == nullptr);
	}
	void push(T value) {
        Stack *stack = new Stack;
        stack->name = value;

        if (head == nullptr){
            head = tail = stack;
        } else if (value.level > head->name.level) {
            stack->next = head;
            head = stack;
        } else {
            Stack *current = head;
            while (current->next != nullptr && current->next->name.level >= value.level) {
                current = current->next;
            }
            stack->next = current->next;
            current->next = stack;
            if (stack->next == nullptr) {
                tail = stack;
            }
            i++;
        }
    }
	void pop(){
		Stack *temp = head;
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
		while(head != nullptr){
			std::cout << "[ " << i-- << " ] " << head->name.value << " ( level : " << head->name.level << " )" << "\n";
			head = head->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	Stack_Linkedlist<TypeInput> baru;
	baru.push(TypeInput(100, 1));
	baru.push(TypeInput(300, 3));
	baru.push(TypeInput(200, 2));
	baru.push(TypeInput(10, 1));
	baru.push(TypeInput(30, 3));
	baru.pop();

	baru.print();
	return 0;
}
