// Tasks week3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <locale.h>
#include<stdio.h>
#include<windows.h>

using namespace std;

/*
Условие
В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.

Отсортируйте массив А по модулю и выведите его в стандартный поток. Ограничения

0 <= N <= 1000
-1000000 <= A[i] <= 1000000
Примеры
stdin	stdout
2 -4 3	3 -4
3 1 -3 2	1 2 -3
Подсказка
Функция sort дополнительно принимает третий аргумент. Изучите его подробнее по ссылке.
*/

void PrintA(const vector<int>& A) {
	for (const auto& a : A) {
		cout << a << " ";
	}
	cout << "\n";
}
void PrintA(const vector<string>& A) {
	for (const auto& a : A) {
		cout << a << " ";
	}
	cout << "\n";
}

bool comp(const int& a, const int& b) {
	return abs(a) < abs(b);
}
TEST(ALGORITHMS, Task_1) {
	int N = 0;
	cin >> N;
	vector <int> A(N);
	if (N >= 0 && N <= 1000) {
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end(), comp);
		PrintA(A);
	}
	else {
		cout << "Введите другое число N:" << endl; 
	}
}

/*
Условие
В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. Между собой число и строки разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

Ограничения
0 <= N <= 1000
1 <= |S| <= 15
Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
Примеры
stdin	stdout
2 q A	A q
3 a C b	a b C
Подсказка
Обратите внимание на функцию tolower.
*/


//bool compStrA(const string& str1, const ) {
//	return
//}
TEST(ALGORITHMS, Task_2){
	int N = 0;
	cin >> N;
	vector <string> A(N), listSmallReg, listHighReg, sortList;
	string strSmallReg, strHighReg, strHighToSmallReg;
	if (N >= 0 && N <= 1000) {
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			for (const auto& ch : A[i]) {
				strSmallReg += (char)tolower(ch);
			}
			if (A[i] != strSmallReg) {
				listHighReg.push_back(A[i]);
			}
			listSmallReg.push_back(strSmallReg);
			strSmallReg.clear();
		}
		//sort(begin(listHighReg), end(listHighReg));
		sort(begin(listSmallReg), end(listSmallReg));
		vector <int> check_index(listHighReg.size(), -1);
		for (const auto strHighReg : listHighReg) {
			for (const auto& ch : strHighReg) {
				strHighToSmallReg += (char)tolower(ch);
			}
			for (int i = 0; i < listSmallReg.size(); ++i) {
				for (const auto& index : check_index) {
					if (i != index) {
						if (listSmallReg[i] == strHighToSmallReg) {
							listSmallReg[i] = strHighReg;
							strHighToSmallReg = "";
							if (check_index[0] == -1) {
								check_index.resize(0);
							}
							check_index.push_back(i);
							continue;
						}
					}
					else {
						++i;
					}
				}
			}
		}
		sortList = listSmallReg;
		PrintA(sortList);
	}
}

string translateHighToSmallReg(const string& str) {
	string smallReg = "";
	for (const auto& ch : str) {
		smallReg += char(tolower(ch));
	}
	return smallReg;
}

// Реализация через компаратор функции sort
TEST(ALGORITHMS, Task_2_1) {
	int N = 0;
	cin >> N;
	vector <string> list_str(N);
	for (int i = 0; i < N; i++) {
		cin >> list_str[i];
	}
	sort(begin(list_str), end(list_str), [](string str1, string str2) {
		str1 = translateHighToSmallReg(str1);
		str2 = translateHighToSmallReg(str2);
		return str1 < str2;
		});
	PrintA(list_str);
}

// Реализация через компаратор функции sort и использованием функции lexicographical_compare() 

TEST(ALGORITHMS, Task_2_2) {
	int N = 0;
	cin >> N;
	vector <string> list_str(N);
	for (int i = 0; i < N; i++) {
		cin >> list_str[i];
	}
	sort(begin(list_str), end(list_str), [](string str1, string str2) {
		return lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char a, char b) {
			return (char)tolower(a) < (char)(tolower(b));
			}); 
		}
	);
	PrintA(list_str);

}

/*
Реализуйте класс, поддерживающий набор строк в отсортированном порядке.Класс должен содержать два публичных метода :*/
class SortedStrings {
public:
	void AddString(const string& s) {
		str.push_back(s);
	}
	vector<string> GetSortedStrings() { sort(begin(str), end(str)); return str;}
private:
	vector <string> str;
};

TEST(STRUCTS_and_CLASSES, Task_1) {
	SortedStrings s;
	s.AddString("smsmxms");
	s.AddString("aaaaa");
	vector <string> str = s.GetSortedStrings();
	for (const auto& item : str) {
		cout << item << " ";
	}
	cout << "\n";
}


/*
Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

Вывод
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova
*/


class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		map_first_name[year] = first_name;
		list_years.push_back(year);
	}
	void ChangeLastName(int year, const string&last_name) {
		// добавить факт изменения фамилии на last_name в год year
		map_last_name[year] = last_name;
		list_years.push_back(year);
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
		list_years.push_back(year);
		sort(begin(list_years), end(list_years));
		int temp_year;
		for (int i = 0; i < list_years.size(); ++i) {
			if (list_years[i] == year) {
				temp_year = i;
				break;
			}
		}
		for (int i = 0; i <= temp_year; ++i) {
			if(map_first_name.count(list_years[i])){
				index_first_name = i;
			}
			if (map_last_name.count(list_years[i])) {
				index_last_name = i;
			}
		}
		if (index_first_name == -1 && index_last_name == -1) {
			return "Incognito";
		}
		else if (index_last_name == -1) {
			return map_first_name[list_years[index_first_name]] + " with unknown last name";
		}
		else if (index_first_name == -1) {
			return map_last_name[list_years[index_last_name]] + " with unknown first name";
		}
		else {
			return map_first_name[list_years[index_first_name]] + " " + map_last_name[list_years[index_last_name]];
		}
	}
private:
	map <int, string> map_first_name;
	map <int, string> map_last_name;
	vector <int> list_years;
	int index_first_name = -1, index_last_name = -1;
};



TEST(STRUCTS_and_CLASSES, Task_2) {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(2020, "Таня");
	for (int year : {2000, 2024}) {
		cout << person.GetFullName(year) << endl;
	}
	person.ChangeLastName(2020, "я люблю тебя!");
	for (int year : {1968, 2024}) {
		cout << person.GetFullName(year) << (char)3 << (char)3 << (char)3 << endl;
	}
}

class Person2 {
public:
	Person2(const string& first_name, const string& last_name, int year) {
		map_first_name[year] = first_name;
		map_last_name[year] = last_name;
		year_birthday = year;
		list_years.push_back(year_birthday);
		set_years.insert(year_birthday);
	}
	Person2(){}

	void ChangeFirstName(const int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		if (year >= year_birthday) {
			map_first_name[year] = first_name;
			list_years.push_back(year);
			set_years.insert(year);
		}
	}
	void ChangeLastName(const int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		if (year >= year_birthday) {
			map_last_name[year] = last_name;
			list_years.push_back(year);
			set_years.insert(year);
		}
	}
	string GetFullName(const int year){
		// получить имя и фамилию по состоянию на конец года year
		list_years.push_back(year);
		sort(begin(list_years), end(list_years));
		int temp_year;
		for (int i = 0; i < list_years.size(); ++i) {
			if (list_years[i] == year) {
				temp_year = i;
				break;
			}
		}
		for (int i = 0; i <= temp_year; ++i) {
			if (map_first_name.count(list_years[i])) {
				index_first_name = i;
			}
			if (map_last_name.count(list_years[i])) {
				index_last_name = i;
			}
		}
		if (year >= year_birthday) {
			if (index_first_name == -1 && index_last_name == -1) {
				return "Incognito";
			}
			else if (index_last_name == -1) {
				return map_first_name[list_years[index_first_name]] + " with unknown last name";
			}
			else if (index_first_name == -1) {
				return map_last_name[list_years[index_last_name]] + " with unknown first name";
			}
			else {
				return map_first_name[list_years[index_first_name]] + " " + map_last_name[list_years[index_last_name]];
			}
		}
		else {
			return "No person";
		}
		
	}
	string GetFullNameWithHistory(const int year) {
		ChooseSetYearsIName(ChooseSetYears(year));
		if (year >= year_birthday) {
			if (set_index_first_name.size() == 0 && set_index_last_name.size() == 0) {
				return "Incognito";
			}
			else if (set_index_last_name.empty()) {
				return PrintHistoryFullName(set_index_first_name, map_first_name) + " with unknown last name";
			}
			else if (set_index_first_name.empty()) {
				return PrintHistoryFullName(set_index_last_name, map_last_name) + " with unknown first name";
			}
			else {
				return PrintHistoryFullName(set_index_first_name, map_first_name) + " " + PrintHistoryFullName(set_index_last_name, map_last_name);
			}
		}
		else {
			return "No person" ;
		}
 		
	}
private:
	map <int, string> map_first_name, map_last_name;
	set <int, greater<int>> set_years, set_index_first_name, set_index_last_name;;
	vector <int> list_years;
	int index_first_name = -1, index_last_name = -1;
	int year_birthday = 0;

	set <int, greater<int>> ChooseSetYears(const int& year) {
		//set_years.insert(year);
		set <int, greater<int>> new_set_years;
		for (const auto& item : set_years) {
			if (item <= year) {
				new_set_years.insert(item);
			}
		}
		return new_set_years;
	}

	void ChooseSetYearsIName(const set <int, greater<int>>&  new_set_years) {
		for (const auto& year : new_set_years) {
			if (map_first_name.count(year)) {
				set_index_first_name.insert(year);
			}
			if (map_last_name.count(year)) {
				set_index_last_name.insert(year);
			}
		}
	}

	string PrintHistoryFullName(set <int, greater<int>>& set_index_i_name, map <int, string>& map_i_name) {
		string result = "";
		int  i = 0;
		string temp_i_name = "";
		for (const auto& year : set_index_i_name) {
			if (temp_i_name != map_i_name[year]) {
				if (i == 0) {
					result = map_i_name[year];
					++i;
				}
				else if (set_index_i_name.size() == 2) {
					result += " (" + map_i_name[year] + ")";
				}
				else if (i == 1 && set_index_i_name.size() > 2) {
					result += " (" + map_i_name[year] + ",";
					++i;
				}
				else if (i >= 2 && i < set_index_i_name.size() - 1) {
					result += " " + map_i_name[year] + ",";
					++i;
				}
				else if (i == set_index_i_name.size() - 1) {
					result += " " + map_i_name[year] + ")";
				}
				temp_i_name = map_i_name[year];
			}
		}
		return result;
	}
};


/*
* История имени 2
Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом GetFullNameWithHistory:

В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

Для лучшего понимания формата см. примеры.
*/
TEST(STRUCTS_and_CLASSES, Task_3_1) {
	Person2 person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;
	cout << person.GetFullName(1920) << endl;
	
}


TEST(STRUCTS_and_CLASSES, Task_3_2) {
	Person2 person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;
}

TEST(STRUCTS_and_CLASSES, Task_3_3) {
	Person2 person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeFirstName(1965, "Appolinaria");

	person.ChangeLastName(1965, "Sergeeva");
	person.ChangeLastName(1965, "Volkova");
	person.ChangeLastName(1965, "Volkova-Sergeeva");

	for (int year : {1964, 1965, 1966}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
}

class ReversibleString {
public:
	ReversibleString(const string& s) : str(s) {
	}
	ReversibleString() :  str(""){
	}
	void Reverse() {
		reverse(begin(str), end(str));
	}
	string ToString() const {
		return str;
	}

private:
	string str; 
};

/*
* ReversibleStirng
Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы Reverse для переворота строки и ToString для получения строки.

Пример
Вывод
evil
live
""
*/
TEST(CONSTRUCTORS, Task_1) {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;
}


/*
Имена и фамилии - 3
Дополните класс Person из задачи «Имена и фамилии — 2» конструктором, позволяющим задать имя и фамилию человека при рождении, а также сам год рождения. Класс не должен иметь конструктора по умолчанию.

При получении на вход года, который меньше года рождения:

методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
Кроме того, необходимо объявить константными все методы, которые по сути ими являются.

Пример
Вывод
No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva)
*/

TEST(CONSTRUCTORS, Task_2) {
	Person2 person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}
}

/*
Способы инициализации
Определите тип Incognizable, для которого следующий код будет корректен:*/
struct Incognizable {
	int a = 0;
	int b = 0;
};

TEST(CONSTRUCTORS, Task_3) {

	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
}