#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void selection_sort();
void print_value_pointer_array();

int main()
{
	cout << "||program print array menggunakan pointer||\n\n";
	print_value_pointer_array();
	cout << endl << endl;
	system("pause");
	system("cls");
	cout << "|program pengurutan data input secara descending||\n\n";
	selection_sort();
	return 0;
}

void selection_sort(){
	srand((unsigned) time(NULL));
	int random_size = 1 + rand() % 11;
	int arr[random_size] = {0};

	for (int i = 0; i < random_size; i++){
		cout << "Masukan data ke " << i << " : ";
		cin >> arr[i];
	}
	cout << "\n";

	cout << "Data diurutkan secara descending : \n";
	for (int i = 0; i < random_size; i++){
		for (int j = i+1; j < random_size; j++)
		{
			if(arr[j] > arr[i]){
				swap(arr[j], arr[i]);
			}
			
		}
		cout << arr[i] << " ";
	}
}

void print_value_pointer_array(){
	int arr[5] = {10,20,30,40,50};
	int size = sizeof(arr)/sizeof(arr[0]);
	int* ptr1;

	for (int i = 0; i < size; i++)
	{
		ptr1 = &arr[i];
		cout << *ptr1 << " ";
	}
}