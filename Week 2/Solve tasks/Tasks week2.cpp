// Week 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

/*
Напишите функцию, которая

называется Factorial
возвращает int
принимает int и возвращает факториал своего аргумента.

Гарантируется, что аргумент функции по модулю не превышает 10.
Для отрицательных аргументов функция должна возвращать 1.
*/
int Factorial(int x) {
	int factorial = 1;
	if (x > 0) {
		for (int i = 1; i <= x; ++i) {
			factorial *= i;
		}
		return factorial;
	}
	else {
		return 1;
	}
}
// Второй вариант
int Factorial_1(int x) {
	if (x <= 1) {
		return 1;
	}
	else {
		return x * Factorial_1(x - 1);  // вычисляем факториал от x-1 и умножаем на x
	}
}

TEST(Functions, Task_1) {
	int x;
	cin >> x;
	if (x <= 10) {
		cout << Factorial(x);
	}
	else {
		cout << "Введите значение x по модулю не превышающее 10";
	}
}


/*
Напишите функцию, которая

называется IsPalindrom
возвращает bool
принимает параметр типа string и возвращает, является ли переданная строка палиндромом
Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.
Пустая строка является палиндромом.
*/


bool IsPalindrom(const string& str) {
	bool flag = false;
	string reverse_str;
	for (int i = str.size() - 1; i >= 0; i--) {
		reverse_str += str[i];
	}
	if (reverse_str == str) {
		flag = true;
	}
	return flag;
}
// Второй вариант
bool IsPalindrom_1(string s) {
	// Замечание: более правильным было бы использовать здесь тип size_t вместо
	// int О причинах Вы узнаете на Жёлтом поясе
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

TEST(Functions, Task_2) {
	string str;
	map <int, string>  int_to_bool{ {1, "true"}, {0, "false"} };
	cin >> str;
	cout << "Принято!" << endl;
	cout << int_to_bool[IsPalindrom(str)] << endl;
}


/*
Отбор палиндромов
Напишите функцию, которая

называется PalindromFilter
возвращает vector
принимает vector words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.*/

vector <string> PalindromFilter(const vector <string>& vector_words, int minLength) {
	vector <string> result;
	bool flag = 1;
	for (const auto& word : vector_words) {
		for (int i = 0; i < word.size() / 2; ++i) {
			if (word.size() < minLength || word[i] != word[word.size() - i - 1]) {
				flag = 0;
			}
		}
		if (flag) {
			result.push_back(word);
		}
	}
	return result;
}

void PrintFilterWords(const vector <string>& result) {
	for (const auto& word : result) {
		cout << word << endl;
	}
}

/// Второй способ

// определяет, является ли строка s палиндромом
bool IsPalindrom_f(string s) {
	// переберём все символы s[i] из первой половины строки
	for (size_t i = 0; i < s.size() / 2; ++i) {
		// s[s.size() - i - 1] — символ, симметричный символу s[i]
		if (s[i] != s[s.size() - i - 1]) {
			return false;  // если они не совпадают, строка точно не палиндром
		}
	}

	// если все пары символов совпадают, строка — палиндром
	return true;
}

vector<string> PalindromFilter_f(vector<string> words, int min_length) {
	vector<string> result;
	// перебираем все элементы вектора words
	for (auto s : words) {
		// если требуеые условия выполняются, добавляем s к ответу
		if (s.size() >= min_length && IsPalindrom(s)) {
			result.push_back(s);
		}
	}
	return result;
}

TEST(Functions, Task_3) {
	setlocale(LC_ALL, "Russian");
	vector <string> words;
	cout << "Введеите minLength" << endl;
	char ch;
	string word;
	int minLength;
	cin >> minLength;
	cout << "Введите строку" << endl;
	while ((cin >> word) && word != "9999") {
		words.push_back(word);
	}
	cout << "Заданный вектор" << endl;
	PrintFilterWords(words);
	cout << "Отфильтрованный вектор" << endl;
	PrintFilterWords(PalindromFilter_f(words, minLength));
}


/*
Максимизатор
Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second.
Если first оказался больше second, Ваша функция должна записывать в second значение параметра first.
При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть видно на вызывающей стороне.

Пример
3 4

Замечание
В данной задаче вам нужно самостоятельно выбрать типы для параметров функции UpdateIfGreater.
 Подумайте, какой из них обязан быть ссылкой, а какой может быть просто int. При этом учтите разные варианты вызова функции:

UpdateIfGreater(x, y);
UpdateIfGreater(5, y)
*/

void UpdateIfGreater(int first, int& second) {
	if (first > second) {
		second = first;
	}
}

TEST(Functions, Task_4) {
	int first, second;
	setlocale(LC_ALL, "Russian");
	cout << "Введите первое число" << endl;
	cin >> first;
	cout << "Введите второе число" << endl;
	cin >> second;
	UpdateIfGreater(first, second);
	cout << "Первое число : " << first << endl;
	cout << "Второe число : " << second << endl;
}



/*
Перемещение строк
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination,
и дописывает все строки из первого вектора в конец второго.
После выполнения функции вектор source должен оказаться пустым.

Чтобы очистить содержимое вектора, надо вызвать у него метод clear:

vector<string> words = {"hey", "hi"};
words.clear();
// Теперь вектор words пуст*/

void MoveStrings(vector <string>& source, vector <string>& destination) {
	destination.insert(destination.end(), source.begin(), source.end());
	source.clear();
}

void MoveStrings_1(vector<string>& source, vector<string>& destination) {
	for (auto w : source) {
		destination.push_back(w);
	}
	source.clear();
}

TEST(Functions, Task_5) {
	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	for (const auto& str : destination) {
		cout << str << endl;
	}
}

/*
Разворот последовательности
Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.

Пример
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
*/

void Reverse(vector <int>& vec) {
	int tmp;
	for (int i = 0; i < vec.size() / 2; i++) {
		tmp = vec[i];
		vec[i] = vec[vec.size() - 1 - i];
		vec[vec.size() - 1 - i] = tmp;
	}
}

TEST(Functions, Task_6) {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	for (const auto x : numbers) {
		cout << x << endl;
	}
}

/*
Разворот последовательности 2
Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

Пример
Вектор v	    Результат функции
1, 5, 3, 4, 2	2, 4, 3, 5, 1
*/


vector<int> Reversed(const vector<int>& input)
{
	vector<int> result;
	for (int i = input.size() - 1; i >= 0; --i) {
		result.push_back(input[i]);
	}
	return result;
}

TEST(Functions, Task_7) {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	;
	for (const auto x : Reversed(numbers)) {
		cout << x << endl;
	}
	cout << "/////" << endl;
	for (const auto x : numbers) {
		cout << x << endl;
	}
}

/*
Средняя температура
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.

Формат ввода
Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.

Формат вывода
Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.

Пример
Ввод	    Вывод
5	          3
7 6 3 0 9	0 1 4
*/

TEST(Vector, Task_1) {
	int N;
	int arithmetic_mean = 0;
	int sum = 0;
	cin >> N;
	vector <int> tempeature_to_days(N), num_days;

	for (int i = 0; i < N; i++) {
		cin >> tempeature_to_days[i];
		sum += tempeature_to_days[i];
	}
	arithmetic_mean = sum / N;
	int i = 0;
	for (const auto temp_to_day : tempeature_to_days) {
		if (temp_to_day > arithmetic_mean) {
			num_days.push_back(i);
		}
		i++;
	}
	for (const auto x : num_days) {
		cout << x << endl;
	}

}


/*
* Очередь
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.

Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.

Реализуйте обработку следующих операций над очередью:

WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.

Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.

Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.

Пример
Ввод	    Вывод
8	          1
COME 5	      2
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT

Указание
Для дописывания всех элементов вектора v2 в конец вектора v1 удобно использовать метод insert:

v1.insert(end(v1), begin(v2), end(v2));
Кроме того, элементом вектора может быть любой тип, в том числе и другой вектор.
Например, ```vector<vector> — это вектор, элементами которого являются вектора целых чисел (то есть двумерный массив). Пример использования:

vector<vector<int>> m(10); // Создаём вектор из десяти векторов целых чисел
m[0].push_back(5);  // Добавляем элементы в первый вектор
m[0].push_back(15);
cout << m[0][1]; // Выведет 15 — второй элемент первого вектора

m[1].push_back(3);
for (int x : m[1]) {
	// Перебираем все элементы второго
}
*/



TEST(Vector, Task_2) {
	int Q;
	cin >> Q;
	string command;
	vector <int> people;
	for (int j = 0; j < Q; ++j) {
		cin >> command;
		// COME k: добавить k спокойных человек в конец очереди;
		int k;
		if (command == "COME") {
			cin >> k;
			/*if (k > 0) {
				people.insert(people.end(), k, 1);
			}
			else if (k < 0) {

				people.erase(end(people)+k, end(people));
			}*/
			people.resize(people.size() + k, 1);

		}
		// WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
		// QUIET i: пометить i-го человека как успокоившегося;
		else if (command == "WORRY" || command == "QUIET") {
			int j;
			cin >> j;
			people[j] = (command != "WORRY");
		}
		else if (command == "WORRY_COUNT") {
			cout << count(begin(people), end(people), 0);
		}
		else {
			cout << "Введите команду из списка" << endl;
			--j;
		}
	}

}


/*
Ежемесячные дела
У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца:
оплата счетов за электричество, абонентская плата за связь и пр.
Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:

ADD i s
Назначить дело с названием s на день i текущего месяца.

DUMP i
Вывести все дела, запланированные на день i текущего месяца.

NEXT
Перейти к списку дел на новый месяц.
При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся
и становится активным (новый) список дел на следующий месяц: все дела со старого списка дел копируются в новый список.
После выполнения данной команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается.
При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:

если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.

Замечания
Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца.
Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
Формат ввода
Сначала число операций Q, затем описания операций.

Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания.
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца. Формат вывода

Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом.
Порядок вывода дел в рамках каждой операции значения не имеет.

Пример
Ввод	                     Вывод
12	                       1 Salary
ADD 5 Salary	       2 WalkPreparations Walk
ADD 31 Walk	                  0
ADD 30 WalkPreparations	      0
NEXT	               2 WalkPreparations Walk
DUMP 5	               3 WalkPreparations Walk Payment
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
*/




TEST(Vector, Task_3) {
	setlocale(LC_ALL, "Russian");
	bool flag = true;
	int q = 0;
	while (flag) {
		cout << "Введите число операций Q > 0" << endl;
		cin >> q;
		if (q > 0) {
			flag = false;
			string command;
			const vector <int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			vector <vector <string>> month_list(days_in_month[0] + 1);
			// счетчик задач по дням (от 1 до 31 дня в месяце - размер начального массива 32)
			vector <int> counter_task_on_days(days_in_month[0] + 1);
			int count_month = 0;
			int day = 0;
			for (int i = 0; i < q; ++i) {
				cout << "Введите команду из списка" << endl;
				cin >> command;
				if (command == "ADD") {
					string task;
					cout << "Введите день" << endl;
					cin >> day;
					if (day <= days_in_month[count_month]) {
						cout << "Введите задачу" << endl;
						cin >> task;
						counter_task_on_days[day] += 1;
						month_list[day].push_back(task);
					}
					else {
						cout << "В текущем месяце нет такого дня" << endl;
						--i;
					}
				}
				else if (command == "DUMP") {
					cout << "Введите день для показа запланированных дел" << endl;
					cin >> day;
					if (day <= days_in_month[count_month]) {
						cout << counter_task_on_days[day] << " ";
						for (const auto& item : month_list[day]) {
							if (item != "") {
								cout << item << " ";
							}
						}
						cout << "\n";
					}
					else {
						cout << "В текущем месяце нет такого дня" << endl;
						--i;
					}
				}
				else if (command == "NEXT") {
					++count_month;
					if (count_month > 11) {
						count_month = 0;
					}
					if (days_in_month[count_month - 1] == days_in_month[count_month]) {
						continue;
					}
					else if (days_in_month[count_month - 1] > days_in_month[count_month]) {
						vector <string> temp_list;
						int temp_counter = 0;
						int num = days_in_month[count_month];
						int num_diff_days = days_in_month[count_month - 1] - num;
						for (int i = num + 1; i < num + num_diff_days + 1; ++i) {
							temp_list.insert(end(temp_list), begin(month_list[i]), end(month_list[i]));
							temp_counter += counter_task_on_days[i];
						}
						month_list.resize(num + 1);
						counter_task_on_days.resize(num + 1);
						month_list[num].insert(end(month_list[num]), begin(temp_list), end(temp_list));
						counter_task_on_days[num] += temp_counter;
					}
					else {
						int num = days_in_month[count_month];
						month_list.resize(num + 1);
						counter_task_on_days.resize(num + 1);
					}
				}
				else {
					--i;
				}
			}
		}
		else {
			flag = true;
		}
	}
}


/*
Анаграммы
Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом. Например, слово «eat» можно получить перестановкой букв слова «tea», поэтому эти слова являются анаграммами друг друга. Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга. Указание

Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем. Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква. Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==), то слова являются анаграммами друг друга, в противном случае не являются.

При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.

Формат ввода
Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить. Гарантируется, что все слова состоят лишь из строчных латинских букв.

Формат вывода
Выведите N строк: для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.

Пример
Ввод 3 eat tea find search master stream

Вывод YES NO YES
*/

string BuildCharCounters(const vector <string>& words) {
	if (words.size() < 2) {
		return "false"; // Если слов меньше двух, то нельзя проверить анаграммы
	}
	vector <map <char, int>> map_word(words.size());
	for (int i = 0; i < words.size(); ++i) {
		for (const auto& ch : words[i]) {
			++map_word[i][ch];
		}
	}
	if (map_word[0] == map_word[1]) {
		return "true";
	}
	else {
		return "false";
	}
}


TEST(MAP, Task_1) {
	int n;
	cin >> n;
	vector <vector <string>> words(n, vector<string>(2));
	vector <string>  result;
	for (int i = 0; i < n; ++i) {
		cin >> words[i][0] >> words[i][1];
		result.push_back(BuildCharCounters(words[i]));
	}
	for (const auto& item : result) {
		cout << item << endl;
	}
}

// второй способ

map<char, int> BuildCharCounters(const string& word) {
	map<char, int> ans;
	for (auto c : word) {
		ans[c] += 1;
	}
	return ans;
}


TEST(MAP, Task_1_1) {
	int n;
	cin >> n;
	string word1, word2;
	for (int i = 0; i < n; ++i) {
		cin >> word1 >> word2;
		if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

TEST(MAP, Task_2) {
	setlocale(LC_ALL, "Russian");
	int q;
	string command, country, new_capital, old_country_name, new_country_name;
	map <string, string> capital_directory;
	capital_directory;
	cout << "Введите число команд :" << endl;
	cin >> q;
	while (q > 0) {
		cout << "Введите команду из списка: CHANGE_CAPITAL, RENAME, ABOUT, DUMP :" << endl;
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cout << "Введите название страны и новую столицу :" << endl;
			cin >> country >> new_capital;
			if (capital_directory.count(country) && capital_directory[country] == new_capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
			else if (capital_directory.count(country) && capital_directory[country] != new_capital) {
				cout << "Country " << country << " has changed its capital from " << capital_directory[country];
				capital_directory[country] = new_capital;
				cout << " to " << capital_directory[country] << endl;
			}
			else {
				capital_directory[country] = new_capital;
				cout << "Introduce new country " << country << " with capital " << capital_directory[country] << endl;
			}
		}
		else if (command == "RENAME") {
			cout << "Введите старое название страны и новое название страны :" << endl;
			cin >> old_country_name >> new_country_name;
			if (capital_directory.count(new_country_name) || !capital_directory.count(old_country_name)) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				string temp_capital = capital_directory[old_country_name];
				capital_directory.erase(old_country_name);
				capital_directory[new_country_name] = temp_capital;
				cout << "Country " << old_country_name << " with capital " << capital_directory[new_country_name] << " has been renamed to " << new_country_name << endl;
			}
		}
		else if (command == "ABOUT") {
			cout << "Введите название страны :" << endl;
			cin >> country;
			if (!capital_directory.count(country)) {
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else {
				cout << "Country " << country << " has capital " << capital_directory[country] << endl;
			}

		}
		else if (command == "DUMP") {
			if (capital_directory.empty()) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& item : capital_directory) {
					cout << item.first << "/" << item.second << " ";
				}
			}
			cout << "\n";
		}
		else {
			++q;
			cout << "Неверная команда" << endl;
		}
		--q;
	}
}


/*
Автобусные остановки - 1
Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
ALL_BUSES — вывести список всех маршрутов с остановками.
Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.

Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.
На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.
На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.
Предупреждение
*/


// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <gtest/gtest.h>

using namespace std;

void PrintStopList(const string ongoing_bus, const string stop, const vector<string>& list_bus) {
	cout << stop << ": ";
	if (list_bus.size() == 1) {
		cout << "no interchange" << endl;
	}
	else {
		for (const auto& bus : list_bus) {
			if (ongoing_bus != bus) {
				cout << bus << " ";
			}
		}
		cout << "\n";
	}
}

TEST(MAP, Task_3) {
	setlocale(LC_ALL, "Russian");
	int q = 0;
	string command = "";
	cout << "Введите число команд :" << endl;
	cin >> q;
	map <string, vector<string>> bus_route;
	map <string, vector<string>> map_stop;
	while (q > 0) {
		cout << "Введите команду из списка: NEW_BUS, BUSES_FOR_STOP, STOPS_FOR_BUS, ALL_BUSES:" << endl;
		cin >> command;
		if (command == "NEW_BUS") {
			string bus = "";
			string stop = "";
			int stop_count = 0;
			cout << "Добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ..." << endl;
			cin >> bus >> stop_count;
			if (stop_count > 0) {
				for (int i = 0; i < stop_count; ++i) {
					cin >> stop;
					map_stop[bus].push_back(stop);
					bus_route[stop].push_back(bus);
				}
			}
			else {
				cout << "Количество остановок должно быть больше 0" << endl;
			}
		}
		else if (command == "BUSES_FOR_STOP") {
			cout << "Введите названия остановки, в ответ выведется названия всех маршрутов автобуса, проходящих через эту остановку" << endl;
			string stop = "";
			cin >> stop;
			bool flag_bus = 0;
			for (const auto& item : bus_route) {
				if (item.first == stop) {
					flag_bus = 1;
					for (const auto& bus : item.second) {
						cout << bus << " ";
					}
					cout << "\n";
				}
			}
			if (!flag_bus) {
				cout << "No stop" << endl;
			}
		}
		else if (command == "STOPS_FOR_BUS") {
			cout << "Введите названия маршрута, в ответ выведется названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок" << endl;
			string bus = "";
			cin >> bus;
			vector <string> list_stop_for_bus;

			for (const auto& [stop, list_bus] : bus_route) {
				for (const auto& item : list_bus) {
					if (bus == item) {
						list_stop_for_bus.push_back(stop);
					}
				}
			}
			if (list_stop_for_bus.size() == 0) {
				cout << "No bus" << endl;
			}
			else {
				for (const auto& stop : list_stop_for_bus) {
					PrintStopList(bus, stop, bus_route[stop]);
				}
			}
		}
		else if (command == "ALL_BUSES") {
			if (map_stop.empty()) {
				cout << "No buses" << endl;
			}
			else {
				for (const auto& [bus, stop_list] : map_stop) {
					cout << "Bus " << bus << ": ";
					for (const auto& stop : stop_list) {
						cout << stop << " ";
					}
					cout << "\n";
				}

			}
		}
		else {
			++q;
			cout << "Неверная команда" << endl;
		}
		--q;
	}
}


/*
Автобусные остановки - 2
В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.

Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример). Указание

В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N различных названий остановок соответствующего маршрута. Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

Пример
Ввод
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
Вывод
New bus 1
New bus 2
Already exists for 1
New bus 3
*/

TEST(MAP, Task_4) {
	setlocale(LC_ALL, "Russian");
	cout << "Введите число команд : " << endl;
	int q = 0;
	cin >> q;
	int i = 0;
	string stop = "";
	map <vector<string>, int> map_route;
	vector <string> stop_list;
	while (q > 0) {
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> stop;
			stop_list.push_back(stop);
		}
		if (map_route.count(stop_list) == 0) {
			++i;
			map_route[stop_list] = i;
			cout << "New bus " << map_route[stop_list] << endl;
		}
		else {
			cout << "Already exists for " << map_route[stop_list] << endl;
		}
		stop_list.clear();
		--q;
	}
}


/*
Kличество уникальных строк
Дан набор строк. Найдите количество уникальных строк в этом наборе.

Формат ввода
Сначала вводится количество строк N, затем — сами N строк, разделённые символом перевода строки. Все строки состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Выведите единственное целое число — количество уникальных строк в данном наборе.

Пример
Ввод
6
first
second
first
third
second
second

Вывод
3
*/
TEST(SET, Task_1) {
	int N = 0;
	cin >> N;
	vector <string> list_str(N);
	for (int i = 0; i < N; ++i) {
		cin >> list_str[i];
	}
	set <string>  set_str(begin(list_str), end(list_str));
	cout << set_str.size() << endl;
}

/*
Множество значений словаря
Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string> и возвращающую множество значений этого словаря:

set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}
*/
set <string> BuildMapValuesSet(const map<int, string>& my_map) {
	set <string> my_set;
	for (const auto& [key, str] : my_map) {
		my_set.insert(str);
	}
	return my_set;
}

TEST(SET, Task_2) {
	set<string> values = BuildMapValuesSet({ {1,"one"}, {2, "two"}, {3, "three"} });
	for (const string& value : values) {
		cout << value << endl;
	}
}


/*
Синонимы
Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции над словарём синонимов:

ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
COUNT word — узнать количество синонимов слова word.
CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
Замечание
Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B, а B - синоним C, то из этого НЕ следует, что A - синоним C.

Формат ввода
Сначала вводится количество запросов Q, затем Q строк с описаниями запросов. Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны. Все слова состоят лишь из латинских букв, цифр и символов подчёркивания. Формат вывода

Для каждого запроса в соответствующей строке выведите ответ на него:

В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.
Пример
Ввод
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java
Вывод
0
2
1
YES
NO
NO
*/   
TEST(SET, Task_3) {
	int num_command = 0;
	cout << "Введите число запросов" << endl;
	cin >> num_command;
	map <string, set<string>> dictionary_synonyms;
	while (num_command > 0 ) {
		string command = "";
		cout << "Введите команду из списка (ADD, COUNT, CHECK):" << endl;
		cin >> command;
		if (command == "ADD") {
			string word_1 = "", word_2 = "";
			cin >> word_1 >> word_2;
			dictionary_synonyms[word_1].insert(word_2);
			dictionary_synonyms[word_2].insert(word_1);
		}
		else if (command == "COUNT") {
			//cout << "Введите слово, для которого нужно узнать количество синонимов:" << endl;
			string word = "";
			cin >> word;
			cout << dictionary_synonyms[word].size() - 1 << endl;
		}
		else if (command == "CHECK") {  
			//cout << "Введите 2 слова, которые нужно проверить на синонимичность" << endl;
			string word_1 = "", word_2 = "";
			cin >> word_1 >> word_2;
			bool flag = false;
			for (const auto& item : dictionary_synonyms[word_1]) {
				if (item == word_2) {
					flag = true;
				}
			}
			if (flag) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "Введена неправильная команда!" << endl;
			++num_command;
		}
		--num_command;
	}
}


/*
Автобусные остановки - 3
В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить друг из друга перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных). Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

Пример
Ввод
5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino
Вывод
New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2
*/
TEST(SET, Task_4) {
	int q = 0;
	cout << "Введите число команд: " << endl;
	cin >> q;
	int  temp = q;
	map <set<string>, int> map_set_stop;
	set<string> set_stop;
	int i = 0;
	while (q > 0) {
		cout << "Введите количество остановок и их описания:" << endl;
		int N = 0;
		cin >> N;
		string stop = "";
		for (int i = 0; i < N; ++i) {
			cin >> stop;
			set_stop.insert(stop);
		}
		if (!map_set_stop.count(set_stop)) {
			++i;
			map_set_stop[set_stop] = i;
			cout << "New bus " << i << endl;
		}
		else {
			cout << "Already exists for " << map_set_stop[set_stop] << endl;
		}
		set_stop.clear();
		--q;
	}
}
