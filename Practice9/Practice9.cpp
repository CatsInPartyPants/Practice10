#include <iostream>

using namespace std;

int horizontal, vertical; // координаты коня


void showRec(int n, int k); // прямоугольник с заданными сторонами
int max_of_two(int a, int b); // максимум из двух
char result_simbol(int a, int b); // выводится символ, < > =
void factorial(int a); // факториал числа
bool is_simple(int n); // простое ли число
int cube(int a); // возводит в куб
bool is_positive(int a); // положительное или нет
void f_arr(int arr[]); // меняет число в массиве
void max_min_arr(int arr[], int a); // максимальное минимальное в массиве
void change_arr(int arr[], int a); // меняет массив reverse
int simple_in_arr(int arr[], int); // сколько простых чисел в массиве
void sortArray(int arr[], int size, bool flag = false); // сортировка по флагу
void sortedASC(int arr[], int size); // сортировка по возрастанию
void sortedDESC(int arr[], int size); // сортировка по убыванию
void show(int arr[], int size); // показывает содержимое массива

// ход коня

// функция для отображения доски

void showBoard(int a = 10, int b = 10);

//функция для проверки хода коня

bool isStepOfHorse(int h, int v);


int main()
{
	setlocale(LC_ALL, "");
	/*
	showRec(5, 20);
	cout << max_of_two(20, 11) << endl;
	cout << result_simbol(10, 2) << endl;
	factorial(10);
	cout << is_simple(4) << endl;
	cout << cube(3) << endl;
	is_positive(-6) ? cout << "true" << endl : cout << "false" << endl;

	int arr[5]{ 1,2,3,4,5 };

	max_min_arr(arr, 4);
	cout << endl << endl;
	change_arr(arr,5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << simple_in_arr(arr, 5) << endl;

	int arr2[5]{ 8,2,7,4,1 };
	sortArray(arr2, 5);
	show(arr2, 5);
	sortArray(arr2, 5, true);
	show(arr2, 5);
	*/
	
	showBoard();
	cout << "Игра: Ход коня\n";
	cout << "Куда поставить коня?\n"
		<< "Число по горизонтали: ";
	cin >> horizontal;
	cout << "Число по вертикали: ";
	cin >> vertical;
	system("CLS");
	showBoard(horizontal, vertical);

	int h, v;
	do {
		cout << "Куда вы хотите переместить коня?\n"
			<< "Число по горизонтали: ";
		cin >> h;
		cout << "Число по вертикали: ";
		cin >> v;
		system("CLS");
		if (isStepOfHorse(h, v) == true) {
			showBoard(horizontal, vertical);
		}
		else {
			showBoard(horizontal, vertical);
		}
	} while (h >0 && v > 0);
		
}

void showRec(int n, int k)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int max_of_two(int a, int b) {
	return (a > b) ? a : b;
}

char result_simbol(int a, int b)
{
	if (a > b) {
		return '>';
	}
	else if (a < b) {
		return '<';
	}
	else {
		return '=';
	}
}

void factorial(int a) {
	long long f = 1;
	for (int i = 1; i <= a; i++) {
		f *= i;
	}
	cout << f << endl;
}

bool is_simple(int a) {
	int count = 0;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0) 
			count++;
	}
	return (count == 2 || a == 1) ? true : false;
}

int cube(int a) {
	return a * a * a;
}

bool is_positive(int a) {
	return a > 0 ? true : false;
}

void f_arr(int arr[]) {
	arr[1] = 15;
}

void max_min_arr(int arr[], int a) {
	int max = arr[0], min = arr[0];
	int index_max = 0, index_min = 0;
	for (int i = 0; i < a; i++) {
		if (max < arr[i]) { max = arr[i]; index_max = i; };
		if (min > arr[i]) { min = arr[i]; index_min = i; };
	}
	cout << "Maximum is " << max << " and index is " << index_max << endl;
	cout << "minimum is " << min << " and index is " << index_min << endl;
}

void change_arr(int arr[], int a) {
	int temp;
	for (int i = 0; i <= a/2; i++, a--) {
		temp = arr[i];
		arr[i] = arr[a-1];
		arr[a-1] = temp;
	}
}

int simple_in_arr(int arr[], int a)
{
	int count = 0;
	for (int i = 0; i < a; i++) {
		if(is_simple(arr[i])) count++;
	}
	return count;
}

//сортировка по возрастанию buble
void sortedASC(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size - 1; j++) {
			if (arr[i] > arr[j+1]) {
				int temp = arr[i];
				arr[i] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

//сортировка по убыванию buble
void sortedDESC(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size - 1; j++) {
			if (arr[i] < arr[j+1]) {
				int temp = arr[i];
				arr[i] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void sortArray(int arr[], int size, bool flag) {
	flag ? sortedASC(arr, size) : sortedDESC(arr, size);
}

void show(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


// ход коня

void showBoard(int a, int b) {
	char c = '_';
	char h = 'K';
	cout << "  ";
	for (int i = 1; i < 9; i++) {
		cout << i << " ";
	}
	cout << endl;

	for (int i = 1; i < 9; i++) {
		cout << i;
		for (int j = 1; j < 9; j++) {
			cout << "|";
			(a == i && b == j) ? cout << h : cout << c;
		}
		cout << "|" << endl;
	}
}

// проверка возможности хода

bool isStepOfHorse(int h, int v) {
	if(abs(horizontal -h) == 2 && abs((vertical - v)) == 1 && h <= 8 && v<= 8){

		horizontal = h;
		vertical = v;
	}
	else if (abs(horizontal - h) == 1 && abs((vertical - v)) == 2 && h <= 8 && v <= 8){
		horizontal = h;
		vertical = v;
	}
	else {
		cout << "Нельзя так ходить!\n" << endl;
		return false;
	}
	return true;
}