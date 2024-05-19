#include <iostream>

struct Node{
	std::string nama;
	Node *nama_baru = nullptr;
};

class stack{
public :
	Node *head = nullptr;
	Node *tail = nullptr;
	Node *tumpukan = new Node;

	bool isEmpty(){
		return (head == nullptr && tail == nullptr);
	}

	void push(std::string value){
		tumpukan->nama = value;

		if (head = nullptr){
			head = tail = tumpukan;
		}else{
			Node *temp = head;
			while(temp->nama_baru != nullptr){
				head = head->nama_baru;
			}
			head->nama_baru = tumpukan;
			tumpukan = tail;
		}
	}

	void display_stack(){
		if (isEmpty() == true){
			std::cout << "Tumpukan kosong!";
		}else{
			int i = 0;
			while(head != nullptr){
				std::cout << "[" << i << "] " << head->nama << "\n";
				head = head->nama_baru;
				i++;  
			}
		}
	}
};

int main(){
	stack buku;
	int pilihan;
	std::string nama_buku;
	std::cout << "Menu \n1. Tumpuk Buku \n2. Lihat tumpukan buku \n3. Ambil buku \n4. Kosongkan Buku \n5. Keluar \nMasukan Pilihanmu : ";
	std::cin >> pilihan;
	switch(pilihan){
		case 1: 
			std::cout << "Masukan Nama Buku : ";
			std::cin.ignore(); 
			getline(std::cin, nama_buku);
			buku.push(nama_buku);

			break;
		case 2: 
			buku.display_stack();
			break;
		// case 3: break;
		// case 4: break;
		// case 5: break;
		default: std::cerr << "invalid";
	}

	return 0;
}