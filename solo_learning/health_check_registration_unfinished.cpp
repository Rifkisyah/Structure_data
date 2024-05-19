#include <iostream>
#include <string>

template<typename T>
struct Element {
    T value;
    int level;
    Element(T v, int l) : value(v), level(l) {}
};

template<typename T>
class Queue_Patient {

    struct Node {
        T data;
        Node *next = nullptr;
        Node(T d) : data(d) {}
    };

public:
    Node *head = nullptr;
    Node *tail = nullptr;

    bool isEmpty() {
        return (head == nullptr);
    }

    void EnQueue(T value) {
        Node *push = new Node(value);
        if (head == nullptr) {
            head = tail = push;
        } else if (value.level < head->data.level) {
            push->next = head;
            head = push;
        } else {
            Node *temp = head;
            while (temp->next != nullptr && temp->next->data.level <= value.level) {
                temp = temp->next;
            }
            push->next = temp->next;
            temp->next = push;
            if (push->next == nullptr) {
                tail = push;
            }
        }
    }

    void DeQueue() {
        if (isEmpty()) {
            std::cout << "Data pasien tidak ada\n";
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        std::cout << "Data Antrian Pasien\n";
        Node *temp = head;
        int i = 0;
        while (temp != nullptr) {
            std::cout << "[" << i << "] " << temp->data.value << " (Level: " << temp->data.level << ")\n";
            temp = temp->next;
            i++;
        }
    }
};

int main() {
    Queue_Patient<Element<std::string>> init;

    init.EnQueue(Element<std::string>("udin", 3));
    init.EnQueue(Element<std::string>("andi", 1));
    init.EnQueue(Element<std::string>("budi", 2));

    init.print();

    init.DeQueue();
    std::cout << "\nSetelah DeQueue:\n";
    init.print();

    return 0;
}
