#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <Windows.h>


using namespace std;

struct SoccerPlayer
{
	string surname;
	string role;
	int birthday;
	int NumberOfGames;
	int NumberOfGoals;
};

void Input(SoccerPlayer* arr, const int number)//вручную введем данные 
{
	for (int i = 0; i < number; i++)
	{
		cout << "Введите Фамилию: ";
		cin >> arr[i].surname;
		cout << "Введите амплау игрока: ";
		cin >> arr[i].role;
		cout << "Введите год рожденния: ";
		cin >> arr[i].birthday; cin.ignore();
		cout << "Введите количество игр, проведенных игроком: ";
		cin >> arr[i].NumberOfGames; cin.ignore();
		cout << "Введите количество голов, забитых игроком: ";
		cin >> arr[i].NumberOfGoals; cin.ignore();
	}
}

void Print(SoccerPlayer* arr, const int number)//выведем данные на экран
{
	for (int i = 0; i < number; i++)
	{
		cout << "\nФамилия игрока: " << arr[i].surname << "\nAмплау игрока: " << arr[i].role << "\nГод рожденния игрока: " << arr[i].birthday << "\nКоличество игр, проведенных игроком: " << arr[i].NumberOfGames << "\nКоличество голов, забитых игроком: " << arr[i].NumberOfGoals << endl;
	}
}

void Write(SoccerPlayer* arr, const int number)//запишем данные в файл
{
	time_t now = time(0); //привязал время с компютера для корректной работы программы через некоторое время
	struct tm nowLocal;
	nowLocal = *localtime(&now);

	ofstream file("C:\\Users\\Public\\Desktop\\SoccerPlayer.txt", ios::binary | ios::out);//Открываем файл в двоичном режиме для записи
	for (int i = 0; i < number; i++)
	{
		if (arr[i].birthday >= nowLocal.tm_year + 1880 && arr[i].NumberOfGoals >= 5)
		{
			file.write((char*)&arr[i].surname, sizeof arr[i].surname);//запись данных в файл
			file.write((char*)&arr[i].role, sizeof arr[i].role);//запись данных в файл
			file.write((char*)&arr[i].birthday, sizeof arr[i].birthday);//запись данных в файл
			file.write((char*)&arr[i].NumberOfGames, sizeof arr[i].NumberOfGames);//запись данных в файл
			file.write((char*)&arr[i].NumberOfGoals, sizeof arr[i].NumberOfGoals);//запись данных в файл
		}
	}
	file.close();//закрытие файла
}

void lvl1()
{
	int number;
	cout << "Введить количество игроков: ";
	cin >> number;
	SoccerPlayer* arr = new SoccerPlayer[number];
	Input(arr, number);
	Print(arr, number);
	Write(arr, number);

}

void lvl2()
{
	int number[6];
	int number2[6];
	ofstream file("C:\\Users\\Public\\Desktop\\number.txt", ios::binary | ios::out);//Открываем файл в двоичном режиме для записи
	for (int i = 0; i <= 5; i++)
	{
		number[i] = -5 + rand() % 10;//рандомно заполняем массив
		cout << number[i] << " ";
		file.write((char*)&number[i], sizeof number[i]);//записываем в файл массив чисел number[i]
	}
	file.close();//закрытие файла

	cout << "\n";
	ifstream  file2("C:\\Users\\Public\\Desktop\\number.txt", ios::binary | ios::in); //Открываем файл в двоичном режиме только для чтения
	for (int i = 0; i <= 5; i++)
	{
		file2.read((char*)&number2[i], sizeof number2[i]);//читаем информацию с файла и запоминаем её в number2[i]
		if (number2[i] > 0) // меняем знак на противоположный
		{
			number2[i] = -number2[i];
		}
		else if (number2[i] < 0)
		{
			number2[i] = -number2[i];
		}
		cout << number2[i] << " "; //выводим изменненые данные
	}
	file2.close();//закрытие файла

	ofstream file3("C:\\Users\\Public\\Desktop\\number2.txt", ios::binary | ios::out);//Открываем файл в двоичном режиме для записи
	for (int i = 0; i <= 5; i++)
	{
		file3.write((char*)&number2[i], sizeof number2[i]);//запись новых изменненых данных в файл
	}
	file3.close();//закрытие файла
}

struct lesson
{
	string NameDiscipline;
	int semester;
	int course;
};

void Input(lesson* arra, const int numbe)//вручную введем данные 
{
	for (int i = 0; i < numbe; i++)
	{
		cout << "Введите название дисциплины: ";
		cin >> arra[i].NameDiscipline;
		cout << "Введите семестр, в котором читается данная дисциплина: ";
		cin >> arra[i].semester; cin.ignore();
		cout << "Введите курс, на котором читается данная дисциплина: ";
		cin >> arra[i].course; cin.ignore();
	}
}

void Print(lesson* arra, const int numbe)//выведем данные на экран
{
	for (int i = 0; i < numbe; i++)
	{
		cout << "\nНазвание дисциплины: " << arra[i].NameDiscipline << "\nСеместр, в котором читается данная дисциплина: " << arra[i].semester << "\nКурс, на котором читается данная дисциплина: " << arra[i].course << endl;
	}
}

void Write(lesson* arra, const int number)//запишем данные в файл
{
	ofstream file("C:\\Users\\Public\\Desktop\\lesson.txt", ios::binary | ios::out);//Открываем файл в двоичном режиме для записи
	for (int i = 0; i < number; i++)
	{
		if (arra[i].NameDiscipline == "Технологияпрограммирования")
		{
			arra[i].semester = 1;
			arra[i].course = 3;
		}
		file.write((char*)&arra[i].NameDiscipline, sizeof arra[i].NameDiscipline);//запись данных в файл
		file.write((char*)&arra[i].semester, sizeof arra[i].semester);//запись данных в файл
		file.write((char*)&arra[i].course, sizeof arra[i].course);//запись данных в файл
	}
	file.close();//закрытие файла
}

void lvl3()
{
	int numbe;
	cout << "Введить количество пар: ";
	cin >> numbe;
	lesson* arra = new lesson[numbe];
	Input(arra, numbe);
	Print(arra, numbe);
	Write(arra, numbe);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	SetConsoleCP(1251); SetConsoleOutputCP(1251);//для ввода русских символов

	int n;
	cout << "Введите номер задания (1-Легкий уровень, 2-Средний уровень, 3-Сложный уровень), или введить 0 если хотите выйти : ";
	cin >> n;
	if (n == 1)
	{
		lvl1();
	}
	else if (n == 2)
	{
		lvl2();
	}
	else if (n == 3)
	{
		lvl3();
	}
	else
	{
		fclose;
	}
}