// Tasks week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//struct Image {
//	double quality;
//	double freshness;
//	double rating;
//
//};
//
//struct Params {
//	double a;
//	double b;
//	double c;
//};
//
//class FunctionPart {
//public:
//	FunctionPart(char new_operation, double new_value) :
//		operation(new_operation), value(new_value){
//	}
//	double Apply(double source_value) const {
//		if (operation == '+') {
//			return source_value + value;
//		}
//		else {
//			return source_value - value;
//		}
//	}
//	void Invert() {
//		if (operation == '+') {
//			operation = '-';
//		}
//		else {
//			operation = '+';
//		}
//	}
//private:
//	char operation;
//	double value;
//};
//
//class Function {
//public: 
//	void AddPart(char operation, double value) {
//		parts.push_back({ operation, value });
//	};
//
//	double Apply(double value) const {
//		for (const FunctionPart& part : parts) {
//			value = part.Apply(value);
//		}
//		return value;
//	};
//
//	void Invert() {
//		for (FunctionPart& part : parts) {
//			part.Invert();
//		}
//		reverse(begin(parts), end(parts));
//	};
//private:
//	vector<FunctionPart> parts;
//};
//
//Function MakeWeightFunction(const Params& params, const Image& image) {
//	Function function;
//	function.AddPart('-', image.freshness * params.a + params.b);
//	function.AddPart('+', image.rating * params.c);
//	return function;
//}
//
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//	Function function = MakeWeightFunction(params, image);
//	return function.Apply(image.quality);
//
//}
//
//double ComputeQualityByWeight(const Params& params, const Image& image, double weight) {
//	Function function = MakeWeightFunction(params, image);
//	function.Invert();
//	return function.Apply(weight);
//}
//
//
//TEST(CLASS_FUNCTION, Task_1) {
//	Image image = { 10, 2, 6 };
//	Params params = { 4, 2, 6 };
//	cout << ComputeImageWeight(params, image) << endl;
//	cout << ComputeQualityByWeight(params, image, 46) << endl;
//}


void ReadAll(const string& path){
	ifstream input(path);
	if (input) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
}

TEST(FSTREAM, Task_1) {
	const string path = "output.txt";
	ofstream output(path, ios::app);
	output << "world!" << endl;
	ReadAll(path);
	
	
}

void Print(const vector <string>& names, const vector <double>&  values, const int width) {
	for (const auto& n : names) {
		cout << setw(width) << n << " ";
	}
	cout << endl;
	cout << fixed << setprecision(7);
	for (const auto& v : values) {
		cout << setw(width) << v << " ";
	}
}

TEST(FSTREAM, Task_2) {
	vector <string> names = { "a", "b", "c" };
	vector <double> values = { 5, 0.1, 0.00005 };
	cout << setfill('.');
	cout << left;
	Print(names, values, 10);
}


struct Duration {
	int hour;
	int min;
	Duration(int h = 0, int m = 0) : hour(h), min(m) {
	}
};

istream& operator>> (istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}


ostream& operator<< (ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour << ':'
		<< setw(2) << duration.min;
	return stream;
}

TEST(FSTREAM, Task_3) {
	stringstream dur_ss("02:50");
	Duration dur1;
	dur_ss >> dur1;
	cout << dur1 << endl;
}

/*
Структура LectureTitle
Дана структура LectureTitle:

struct LectureTitle {
  string specialization;
  string course;
  string week;
};
Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект LectureTitle можно было создать с помощью кода

LectureTitle title(
	Specialization("C++"),
	Course("White belt"),
	Week("4th")
);
но нельзя было с помощью следующих фрагментов кода:

LectureTitle title("C++", "White belt", "4th");

LectureTitle title(string("C++"), string("White belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
	Course("White belt"),
	Specialization("C++"),
	Week("4th")
);

LectureTitle title(
	Specialization("C++"),
	Week("4th"),
	Course("White belt")
);
*/
struct Specialization {
	string specialization;
	explicit Specialization(string new_specialization) : specialization(new_specialization){
	}
};
struct Course {
	string course;
	Course(string new_course) : course(new_course){
	}
};
struct Week {
	string week;
	explicit Week(string new_week) :week(new_week){
	}
};
struct LectureTitle {
	Specialization specialization;
	Course course;
	Week week;
	explicit LectureTitle(Specialization new_specialization, Course new_course, Week new_week) :
		specialization(new_specialization), course(new_course), week(new_week){
	}
};

TEST(STRUCTS_and_CLASSES, Task_1) {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
}

/*
* Обратимая функция
Реализуйте рассказанный на лекции класс Function, позволяющий создавать, вычислять и инвертировать функцию, состоящую из следующих элементарных операций:

прибавить вещественное число x;
вычесть вещественное число x.
При этом необходимо объявить константными все методы, которые по сути такими являются.

Замечание
Более детальное описание задачи с подробным разбором реализации вышеуказанного класса приводится в двух предшествующих видеолекциях.
На проверку пришлите файл, содержащий реализацию вышеуказанного класса Function.
Пример
*/

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

class PartFunction {
public:
	PartFunction(char new_operation, double new_value) : 
		operation(new_operation), source_value(new_value){}

	double Apply(double value) {
		if (operation == '+') {
			return  value + source_value;
		}
		else {
			return value - source_value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation == '-';
		}
		else {
			operation == '+';
		}
	}


	 
private:
	char operation;
	double source_value;
};

class Function {
public:
	void AddPart(char operation, double value){
		parts.push_back({ operation, value });
	}

	double Apply(double value) {
		for (PartFunction& part : parts) {
			value = part.Apply(value);
		}
		return value;
	};

	void Invert() {
		for (PartFunction& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	};

private:
	vector <PartFunction> parts;
};

Function MakeWeightFunction(const Params& params,
	const Image& image) {
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

TEST(STRUCTS_and_CLASSES, Task_2) {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 46) << endl;
}





/*
Обратимая функция с умножением и делением
Добавьте в класс Function из задачи «Обратимая функция» обработку умножения ('*') и деления ('/'). Гарантируется отсутствие элементарных операций умножения и деления на 0.
*/
struct Quality {
	double quality;
	explicit Quality(double new_quality) : quality(new_quality) {};
};
struct Freshness {
	double freshness;
	explicit Freshness(double new_freshness) : freshness(new_freshness) {};
};
struct Rating {
	double rating;
	explicit Rating(double new_rating) : rating(new_rating) {};
};

struct Image3 {
	double quality;
	double freshness;
	double rating;
	Image3(Quality new_quality, Freshness new_freshness, Rating new_rating) :
		quality(new_quality.quality), freshness(new_freshness.freshness), rating(new_rating.rating){
	}
};

struct A {
	double a;
	explicit A(double new_a) : a(new_a) {};
};
struct B {
	double b;
	explicit B(double new_b) : b(new_b) {};
};
struct C {
	double c;
	explicit C(double new_c) : c(new_c) {};
};

struct Params3 {
	double a;
	double b;
	double c;
	Params3(A(new_a), B(new_b), C(new_c)) : 
	a(new_a.a), b(new_b.b), c(new_c.c) {
	};
};

class PartFunction3 {
public:
	PartFunction3(const char& new_operation, const double& new_value) :
		operation(new_operation), value(new_value){
	}
	double Apply(const double source_value) const {
		if (operation == '+') {
			return source_value + value;
		}
		else if (operation == '-'){
			return source_value- value;
		}
		else if (operation == '*') {
			return source_value * value;
		}
		else {
			return source_value / value;
		}
	};

	void Invert() {
		if (operation == '+') {
			operation = '-';
		}
		else if (operation == '-') {
			operation = '+';
		}
		else if (operation == '*') {
			operation = '/';
		}
		else  {
			operation = '*';
		}
	};

private:
	char operation;
	double value;
};

class Function3 {
public:
	double Apply(double value) const{
		for (const auto& part : parts) {
			value = part.Apply(value);
		}
		return value;
	};

	void AddPart(const char& new_operation, const double new_value){
		parts.push_back({ new_operation , new_value });
	};

	void Invert() {
		for (PartFunction3& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	};
private:
	char operation;
	vector <PartFunction3> parts;
};

Function3 MakeWeightFunction3(const Image3& image, const Params3& params){
	Function3 function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
	};

double ComputeImageWeight3(const Image3& image, const Params3& params) {
	Function3 function = MakeWeightFunction3(image, params);
	return function.Apply(image.quality);

};


double ComputeQualityByWeight3(const Image3& image, const Params3& params, const double weight) {
	Function3 function = MakeWeightFunction3(image, params);
	function.Invert();
	return function.Apply(weight);
};

TEST(STRUCTS_and_CLASSES, Task_3) {
	Image3 image(Quality(10), Freshness(2), Rating(6));
	Params3 params(A(4), B(2), C(6));
	cout << ComputeImageWeight3(image, params) << endl;
	cout << ComputeQualityByWeight3(image, params, 52) << endl;
}

/*
Работа с файлами
Часть 1
Ваша программа должна считать содержимое файла input.txt и напечатать его на экран без изменений. Гарантируется, что содержимое файла input.txt заканчивается переводом строки.

Пример
input.txt

Keep calm
and
learn C++
stdout

Keep calm
and
learn C++
Часть 2
Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt . Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки.

Пример
input.txt

Keep calm
and
learn C++
output.txt

Keep calm
and
learn C++
*/
TEST(Working_with_text_files_and_threads, Task_1) {
	ifstream input("Task (1).txt");
	string line;
	vector <string> list_str;
	if (input.is_open()) {
		while (getline(input, line)) {
			list_str.push_back(line);
			cout << line << endl;
		}
		cout << "done!";
	}
	else {
		cout << "error!";
	}

	ofstream output("output.txt");
	for (int i = 0; i < list_str.size(); ++i) {
		output << list_str[i] << "\n";
	}
}


/*
Вывод с точностью
В файле input.txt записаны вещественные числа, по одному на строчку. 
На стандартный вывод напечатайте эти числа в том же порядке, по одному на строке, но сделайте так, 
чтобы у каждого из них было ровно три знака после десятичной точки.

Пример ввода 1
5
0.34567
10.4
Пример вывода 1
5.000
0.346
10.400
Пример ввода 2
3.33353
3.333
3.3
Пример вывода 2
3.334
3.333
3.300
*/

TEST(Working_with_text_files_and_threads, Task_2) {
	ifstream input("D:/Документы/white belt/Week 4/Tasks/Files and streams/Print file 2/Task (1).txt");
	double num;
	if (input.is_open()) {
		while (input >> num) {
			
			cout << fixed << setprecision(3) <<  num << endl;
		}
		cout << "done!" << endl;
	}
	else {
		cout << "error" << endl;
	}
}


/*
Чтение и вывод таблицы
В первой строке файла input.txt записаны два числа N и M. 
Далее в файле находится таблица из N строк и M столбцов, представленная в формате CSV (comma-separated values). 
Такой формат часто используется для текстового представления таблиц с данными: 
в файле несколько строк, значения из разных ячеек внутри строки отделены друг от друга запятыми. 
Ваша задача — вывести данные на экран в виде таблицы. Формат таблицы:

размер ячейки равен 10,
соседние ячейки отделены друг от друга пробелом,
последняя ячейка в строке НЕ оканчивается пробелом,
последняя строка НЕ оканчивается символом перевода строки.
Гарантируется, что в таблице будет ровно N строк и M столбцов, значение каждой из ячеек — целое число.

Пример ввода
2 3
1,2,3
4,5,6
Пример вывода
1	2	3
4	5	6
*/


TEST(Working_with_text_files_and_threads, Task_3) {
	ifstream input("D:/Документы/white belt/Week 4/Tasks/Files and streams/Read csv file/Task (1).txt");
	int N, M;
	int width = 10;
	string str = "";
	input >> N;
	input.ignore(1);
	input >> M;
	vector <vector<int>> array(N, vector<int> (M));
	if (input.is_open()) {
		while (input) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					input >> array[i][j];
					cout << setw(width) << array[i][j];
					if (j != M-1) {
						cout << " ";
					}
					input.ignore(1);
				}
				if (i != N-1) {
					cout << endl;
				}
			}
		}
	}
}


/*
Список студентов
Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля. Чтение и запись данных в этой задаче производится с использованием стандартных потоков.

Формат ввода
Первая строка содержит одно целое число N от 0 до 10000 — число студентов.

Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.

Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.

Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, и целое число от 1 до 1000000000 — номер студента (нумерация начинается с 1).

Формат вывода
Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.

Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.

Для остальных запросов выведите bad request.

NB: неверные запросы могут выходить за границы, указанные для данных.

Пример ввода
3
Ivan Ivanov 1 1 1901
Petr Petrox 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5
Пример вывода
Ivan Ivanov
3.3.1903
bad request
*/

struct FirstName {
	string name;
	explicit FirstName(string value) : name(value) {}
};

struct SecondName {
	string secondName;
	explicit SecondName(string value) : secondName (value) {}
};

struct DayBirthday{
	int day;
	explicit DayBirthday(int value) : day(value) {}
};

struct MonthBirthday{
	int month;
	explicit MonthBirthday(int value) : month(value) {}
};

struct YearBirthday{
	int year;
	explicit YearBirthday(int value) : year(value) {}
};

struct Student {
	string firstName, secondName;
	int day, month, year;
	Student(){}
	Student(FirstName newFirstName, SecondName newSecondName, DayBirthday newDay, MonthBirthday newMonth, YearBirthday newYear) :
		firstName(newFirstName.name), secondName(newSecondName.secondName), day(newDay.day), month(newMonth.month), year(newYear.year) {}
};

TEST(Working_with_text_files_and_threads, Task_4) {
	Student	student;
	vector <Student> listStudents;
	int N, M;
	setlocale(LC_ALL, "Russian");
	cout << "Введите число студентов от 0 дo 1000!" << endl;
	cin >> N;
	while (N > 0) {
		if (N > 0 && N <= 1000) {
			cout << "На одной строке введите имя и фамилию, день, месяц и год рождения" << endl;
			cin >> student.firstName >> student.secondName >> student.day >> student.month >> student.year;
			listStudents.push_back(student);
			--N;
		}
		else {
			cout << "Неверно!  Введите число студентов от 0 дo 1000!" << endl;
			cin >> N;
		}
	}
	cout << "Введите одно целое число запросов от 0 дo 1000!" << endl;
	cin >> M;
	bool flagM = true;
	while (flagM) {
		if (M >= 0 && M <= 1000) {
			int numStudent;
			string request;
			while (M > 0) {
				bool flagRequest = true;
				while (flagRequest) {
					cout << "Введите запрос информации о студенте и номер студента" << endl;
					cin >> request >> numStudent;
					if (numStudent <= listStudents.size() && numStudent > 0) {
						if (request == "name") {
							cout << listStudents[numStudent - 1].firstName << listStudents[numStudent - 1].secondName << endl;
							flagRequest = false;
						}
						else if (request == "date") {
							cout << listStudents[numStudent - 1].day << "." << listStudents[numStudent - 1].month << "." << listStudents[numStudent - 1].year << "." << endl;
							flagRequest = false;
						}
						else {
							cout << "bad request" << endl;
							flagRequest = false;
						}
					}
					else {
						cout << "bad request" << endl;
					}
				}
				--M;
			}
			flagM = false;
		}
		else {
			cout << "Неверно!  Введите одно целое число запросов от 0 дo 1000!" << endl;
			cin >> M;
		}
	}
}


/*
* Класс Rational
Общее описание
В этой задаче вам надо разработать класс для представления рациональных чисел и внедрить его в систему типов языка С++ так, чтобы им можно было пользоваться естественным образом. Задание состоит из нескольких частей. К каждой части приложен файл с заготовкой программы, который имеет следующую структуру

#include <iostream>
using namespace std;

// Комментарии, которые говорят, что именно нужно реализовать в этой программе

int main() {
    // Набор юнит-тестов для вашей реализации
    cout << "OK" << endl;
    return 0;
}
Вам нужно, не меняя тело функции main, реализовать то, что предложено в комментариях, так, чтобы ваша программа выводила на экран сообщение OK. Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK программа выведет подсказку о том, что именно работает неправильно.

Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку. Ваша реализация будет тестироваться на другом, более полном наборе тестов. То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша реализация будет принята тестирующей системой. В случае неудачной посылки тестирующая система также выдаст вам подсказку о том, какая именно часть реализации работает неправильно.

Внимательно изучите набор юнит-тестов для каждой заготовки решения. Тесты описывают требования, предъявляемые к вашей реализации, которые могут быть не указаны в условии задач

На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять из него не нужно.

Часть 1
В первой части Вам надо реализовать класс Rational, который представляет собой рациональное число вида p/q, где p — целое, а q — натуральное и диапазоны возможных значений p, q таковы, что могут быть представлены типом int. При этом, класс Rational должен иметь следующий интерфейс:

class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
Класс Rational должен гарантировать, что p/q — это несократимая дробь. Например, код

Rational r(4, 6);
cout << r.Numerator() << '/' << r.Denominator();
должен выводить «2/3» — именно поэтому мы делаем Rational классом, а не структурой. Структура позволила бы нарушить этот инвариант:

struct Rational {
    int numerator, denominator;
};

Rational r{2, 3};
r.numerator = 6; // Нарушен инвариант несократимости
Список требований, предъявляемых к реализации интерфейса класса Rational:

Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1.
При конструировании объека класса Rational с параметрами p и q должно выполняться сокращение дроби p/q (здесь вам может пригодиться решение задачи «Наибольший общий делитель»).
Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь отрицательный числитель и положительный знаменатель.
Если дробь p/q положительная, то объект Rational(p, q) должен иметь положительные числитель и знаменатель (обратите внимание на случай Rational(-2, -3)).
Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
Гарантируется, что ни в одном из тестов, на которых будет тестироваться ваша реализация, не будет знаменателя, равного нулю.

Замечание:
В стандарте языка C++17 для вычисления НОД имеется стандартная функция gcd. Допустимо использовать данную функцию для сокращения дробей. Подробнее с данной функцией и её ограничениями можно ознакомиться по ссылке: https://en.cppreference.com/w/cpp/numeric/gcd
*/

class Rational {
public:
	Rational() : p(0), q(1) {};
	Rational(int numerator, int denominator) : p(numerator), q(denominator) {
		if (q == 0 || q < 0) {
			string error_str = "invalid_argument";
			throw runtime_error(error_str);
		}
	};

	int Numerator() const {
		if (p == 0) {
			return p;
		}
		else {
			int new_numerator = abs(p / Gcd(p, q));
			return new_numerator * CheckOperation(p, q);
		}
	}
	int Denominator() const {
		if (p == 0) {
			return 1;
		}
		else {
			int new_denominator = abs(q / Gcd(p, q));
			return new_denominator;
		}
	}

private:
	int Gcd(const int p, const int q) const {
		int a = max(abs(p), abs(q));
		int b = min(abs(p), abs(q));
		int temp;
		while (b != 0) {
			temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

	int CheckOperation(const int new_numerator, const int new_denominator) const {
		if (new_numerator < 0 && new_denominator < 0 || new_numerator > 0 && new_denominator > 0) {
			return 1;
		}
		else {
			return -1;
		}
	}

	int p, q;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		Rational temp(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
		Rational r(temp.Numerator(), temp.Denominator());
		return r;
	}
	else {
		Rational temp(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
		Rational r(temp.Numerator(), temp.Denominator());
		return r;
	}
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		Rational temp(lhs.Numerator() - rhs.Numerator(), lhs.Denominator());
		Rational r(temp.Numerator(), temp.Denominator());
		return r;
	}
	else {
		Rational temp(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
		Rational r(temp.Numerator(), temp.Denominator());
		return r;
	}
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational temp(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
	Rational r(temp.Numerator(), temp.Denominator());
	return r;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int numerator = lhs.Numerator() * rhs.Denominator();
	int denominator = rhs.Numerator() * lhs.Denominator();
	if (denominator == 0) {
		string error_str = "Division by zero";
		throw runtime_error(error_str);
	}
	else {
		Rational r(numerator, denominator);
		return r;
	}
}

// Унарный +
Rational operator+(const Rational& rhs) {
	return rhs;
}

Rational operator-(Rational& r) {
	r = { -r.Numerator(), r.Denominator() } ;
	return r;
}



bool operator==(const Rational& lhs, const Rational& rhs) {
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		return lhs.Numerator() < rhs.Numerator();
	}
	else {
		return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
	}
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	if (lhs.Denominator() == rhs.Denominator()) {
		return lhs.Numerator() > rhs.Numerator();
	}
	else {
		return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();
	}
}


istream& operator>>(istream& stream, Rational& r) {
	char operation;
	int p, q;
	stream >> p >> operation >> q;
	r = Rational(p, q);
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << '/' << r.Denominator();
	return stream;
}

TEST(Performing_the_operation_in_a_natural_way, Task_1) {
	setlocale(LC_ALL, "Russian");
	try {
		Rational r1(0, 0);
		cout << r1.Numerator() << '/' << r1.Denominator() << endl;
		const Rational r2 = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
		if (r2 == Rational(7, 12)) {
			cout << "equal" << endl;
		}
		else {
			cout << "not equal" << endl;
		}
		const Rational r3 = Rational(0, 2) * Rational(0, 3) / Rational(0, 4);
		if (r3 == Rational(0, 3)) {
			cout << "equal" << endl;
		}
		else {
			cout << "not equal" << endl;
		}

		Rational r;
		cin >> r;
		cout << r << endl;

		set<Rational> rationals;
		rationals.insert(Rational(1, 2));
		for (const auto& item : rationals) {
			cout << item << endl;
		}
		rationals.insert(Rational(1, 3));
		map<Rational, string> name;
		name[Rational(1, 2)] = "одна вторая";
		name[Rational(2, 5)] = "две пятых";
		cout << name[Rational(2, 5)];
		Rational r4(10, 0);
		cout << r4;

	}
	catch (exception& ex) {
		cout << ex.what();
	}
}



/*
* Функция EnsureEqual
Напишите функцию

void EnsureEqual(const string& left, const string& right);
В случае, если строка left не равна строке right, функция должна выбрасывать исключение runtime_error с содержанием " != ", где и - строки, которые хранятся в переменных left и right соответственно. Обратите внимание, что вокруг знака неравенства в строке, которая помещается в исключение, должно быть ровно по одному пробелу.

Если left == right, функция должна корректно завершаться.

Например, код

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (runtime_error& e) {
    cout << e.what() << endl;
  }
  return 0;
}
должен выводить

C++ White != C++ Yellow

*/
void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		string error_str = left + " != " + right;
		throw runtime_error(error_str);
	}
	else {
		cout << "Equal" << endl;
	}
}

TEST(Exceptions, Task_1) {
	try {
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
}


/*
Исключения в классе Rational
Вспомним класс Rational, который мы реализовали в задачах, посвящённых перегрузке операторов. 
Там специально говорилось, что в тестах объекты класса Rational никогда не создаются с нулевым знаменателем и никогда не выполняется деление на ноль. 
Настало время избавиться от этого ограничения и научиться обрабатывать нулевой знаменатель и деление на ноль. В этой задаче вам предстоит это сделать.

Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал исключение invalid_argument,
если знаменатель равен нулю. Кроме того, переделайте реализацию оператора деления для класса Rational так, 
чтобы он выбрасывал исключение domain_error, если делитель равен нулю.

Напомним, что вам надо реализовать интерфейс

class Rational {
public:
  Rational();
  Rational(int numerator, int denominator);

  int Numerator() const;
  int Denominator() const;
};
и оператор деления для класса Rational

Rational operator / (const Rational& lhs, const Rational& rhs);
Так же, как и в задачах на перегрузку операторов, вам будет предложен файл с заготовкой кода. 
Функция main в этом файле содержит ряд юнит-тестов, которые позволят вам проверить свою реализацию. 
При проверке вашего решения оно будет тестироваться на более полном наборе тестов, так что успешное прохождение всех юнит-тестов не гарантирует, 
что ваша реализация будет зачтена.*/
TEST(Exceptions, Task_2) {
	setlocale(LC_ALL, "Russian");
	try {
		Rational r1(12, 6), r2(0, 5);
		cout << r1 / r2;
	}
	catch (exception& ex){
		cout << ex.what();
	}
}

/*
Калькулятор обыкновенных дробей
Итак, теперь у нас с вами есть полноценный тип для представления обыкновенных дробей: класс Rational интегрирован в язык с помощью перегрузки операторов и не позволяет выполнять некорректные операции за счёт выбрасывания исключений. Давайте на основе класса Rational создадим простой калькулятор для обыкновенных дробей.

Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате ДРОБЬ_1 операция ДРОБЬ_2. ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где X — целое, а Y — целое неотрицательное число. операция — это один из символов '+', '-', '*', '/'.

Если ДРОБЬ_1 или ДРОБЬ_2 является некорректной обыкновенной дробью, ваша программа должна вывести в стандартный вывод сообщение "Invalid argument". Если считанная операция — это деление на ноль, выведите в стандартный вывод сообщение "Division by zero". В противном случае выведите результат операции. Пример

stdin	stdout
1/2 + 1/3	5/6
1/2 + 5/0	Invalid argument
4/5 / 0/8	Division by zero
*/

TEST(Exceptions, Task_3) {
	char operation;
	Rational r1, r2;
	try {
		cin >> r1 >> operation >> r2;
		if (operation == '+') {
			cout << r1 + r2 << endl;
		}
		else if (operation == '-') {
			cout << r1 - r2 << endl;
		}
		else if (operation == '*') {
			cout << r1 * r2;
		}
		else if (operation == '/') {
			cout << r1 / r2 << endl;
		}
		else {
			cout << "no input command" << endl;
		}
	}
	catch (exception& ex) {
		cout << ex.what();
	}
}

/*
Работа с сервером времени
Вам дана функция string AskTimeServer(), про которую известно следующее:

в процессе своей работы она обращается по сети к удалённому серверу, запрашивая текущее время;
если обращение к серверу прошло успешно, функция возвращает текущее время в виде строки;
если в процессе обращения к серверу возникла сетевая проблема, функция выбрасывает исключение system_error;
функция может выбрасывать другие исключения, чтобы сообщить о других проблемах.
Используя функцию AskTimeServer, напишите класс TimeServer со следующим интерфейсом:

class TimeServer {
public:
  string GetCurrentTime();
private:
  string last_fetched_time = "00:00:00";
};
Метод GetCurrentTime должен вести себя так:

он должен вызвать функцию AskTimeServer, записать её результат в поле last_fetched_time и вернуть значение этого поля;
если AskTimeServer выбросила исключение system_error, метод GetCurrentTime должен его поймать и вернуть текущее значение поля last_fetched_time. Таким образом мы скрываем от пользователя сетевые проблемы, возвращая значение, которое было получено при последнем успешном обращении к серверу;
если AskTimeServer выбросила другое исключение, метод GetCurrentTime должен пробросить его дальше, потому что в рамках класса TimeServer мы не знаем, как обрабатывать проблемы, не связанные со сбоями сети.
Как выполнять задание
Вам дан файл, содержащий заготовку класса TimeServer. В нём вам надо реализовать метод GetCurrentTime так, как описано выше. Файл содержит пустую функцию AskTimeServer. Для тестирования своей реализации вы можете пробовать добавлять разные команды в её тело:

возврат строки;
выброс исключения system_error (класс system_error принимает в конструкторе параметр типа error_code, поэтому самый простой способ выбросить это исключение — throw system_error(error_code());, подробнее см. https://en.cppreference.com/w/cpp/error/system_error);
выброс других исключений.
*/



string AskTimeServer(int i) {
	if (i == 1) {
		return "12:50:29";
	}
	else if (i == 2) {
		throw system_error(error_code());
	}
	else {
		string error_str = "Неизвестная ошибка!";
		throw runtime_error(error_str);
	}
}

class TimeServer {
public:
	string GetCurrentTime() {
		try {
			last_fetched_time = AskTimeServer(3);
			return last_fetched_time;
		}
		catch (system_error& er){
			//cout << er.code();
			return last_fetched_time;
		}
	}

private:
	string last_fetched_time = "00:00:00";
};

TEST(Exceptions, Task_4) {
	setlocale(LC_ALL, "Russian");
	TimeServer timeServer;
	try {
		cout << timeServer.GetCurrentTime() << endl;
	}
	catch (exception& ex){
		cout << ex.what() << endl;
	}
}

