#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <unistd.h>
/*buat operasi penugasan dimana 
nilai dari suatu variabel pointer dapat disalin
ke variabel pointer lainnya*/

//prototype
void input_value(int id_value[], int size);
void print_value(int array_list[], int size);
void print_memory_addres(int* ptr,int array_list[], int size);
void print_all();

int
main(int argc, char const *argv[])
{
	print_all();
	return 0;
}

//semua program berjalan
void print_all(){
	int size;
	std::cout << "input size value : ";
	std::cin >> size;
	system("cls");

	int Data_1[size];
	input_value(Data_1, size);
	int* ptr;
	int* ptr2;
	int Data_2[size] = {0};

	std::cout << "Data 1 : \n";
	print_memory_addres(ptr, Data_1, size);
	std::cout << "\n";

	std::cout << "Data 2 : \n";
	print_value(Data_2, size);

	int copy, paste;
	std::cout << "Copy Data 1 from index (index 0 to " << size << ") : ";
	std::cin >> copy;
	std::cout << "Paste Data 2 from index (index 0 to " << size << ") : ";
	std::cin >> paste;

	if(copy && paste > size ){
		std::cerr << "invalid input!";
		sleep(2);
		system("cls"); 
		print_all();
	}

	for(size_t i = 0; i < size; i++){
		ptr2 = ptr = &Data_1[copy];
		Data_2[paste] = *ptr2;
	}
	std::cout << "\nData 2 Update : \n";
	print_memory_addres(ptr2, Data_2, size);
}

//fungsi memasukan nilai ke variabel array
void input_value(int id_value[], int size){
	for(size_t i = 0; i < size; i++){
		std::cout << "input value " << i+1 << " : ";
		std::cin >> id_value[i];
	}
}

//fungsi menampilkan list nilai elemen array
void print_value(int array_list[],int size){
	for(size_t i = 0; i < size; i++){	
		std::cout << i+1 << ". " << array_list[i] << std::endl; 
	}
}

//fungsi menampilkan alamat memori dari elemen array
void print_memory_addres(int* ptr,int array_list[], int size){
	for(size_t i = 0; i < size; ++i){
		ptr = &array_list[i];
		std::cout << i+1 << ".  " << ptr << " = " << *ptr << "\n";
	}
}