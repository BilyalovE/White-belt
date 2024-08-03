// Tasks week1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "gtest/gtest.h"
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/*
 *В стандартном потоке даны три строки, разделённые пробелом. 
 *Каждая строка состоит из строчных латинских букв и имеет длину не более 30 символов. 
 *Выведите в стандартный вывод лексикографически минимальную из них.
 */
TEST(White_Belt_Week_1, Task_1) {
	string a, b, c;
	cin >> a >> b >> c;
	if (a <= b && a <= c) {
		cout << a;
	}
	else if (b <= a && b <= c) {
		cout << b;
	}
	else 
		cout << c;
	
}

/*
 *На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. 
 *Выведите все его различные действительные корни в поток вывода в любом порядке, при этом разделяя корни пробелами. 
 *Гарантируется, что хотя бы один из коэффициентов уравнения не равен нулю.
 */

TEST(White_Belt_Week_1, Task_2) {
	double A, B, C, D, x1,x2;
	cin >> A >> B >> C;
	// ур-ие линейное
	if (A == 0) {
		if (B != 0){
			cout << -C / B;
		}
	}
	
	else if ( (D = B * B - 4 * A * C) >= 0){
		x1 = (-B - sqrt(D)) / (2 * A);
		x2 = (-B + sqrt(D)) / (2 * A);
		if (x1 != x2) {
			cout << x1 << " " << x2 << "\n";
		}
		else {
			cout << x1 << "\n";
		}
	}
	else {
		cout << "Иррациональные корни";
	}
}

/*
 *Дано два целых числа A и B в диапазоне от 0 до 1 000 000 включительно. 
 *Напишите программу, которая вычисляет целую часть частного от деления A на B.
 *Если B = 0, выведите "Impossible". 
 */
TEST(White_Belt_Week_1, Task_3) {
	int A, B;
	cin >> A >> B;
	if (A >= 0 && A <= 1000000 && B >= 0 && B <= 1000000) {
		if (B != 0) {
			cout << A / B;
		}
		else {
			cout << "Impossible";
		}
	}
	else {
		cout << "Введите числа A и B в диапазоне от 0 до 1 000 000 включительно";
	}
}


/*
 * Написать программу вычисления стоимости покупки товара с учётом скидки. 
 *Если исходная стоимость товара больше A рублей, то на неё устанавливается скидка в X процентов.
 *Если исходная стоимость товара больше B рублей, то на неё устанавливается скидка в Y процентов.

 *На вход программе даны пять вещественных чисел: N, A, B, X, Y (A < B) - где N - исходная стоимость товара. 
 *Выведите стоимость покупки товара с учётом скидки.
 */
TEST(White_Belt_Week_1, Task_4) {
	double costWithSale, N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	if (A < B) {
		double n, a, b, x, y;
		cin >> n >> a >> b >> x >> y;
		if (n > b) {
			n *= (1 - y / 100);
		}
		else if (n > a) {
			n *= (1 - x / 100);
		}
		cout << n;
	}
	else {
		cout << "Введите A < B";
	}
}


/*
Дано два целых числа A и B (A <= B, A >= 1, B <= 30000). 
Выведите через пробел все чётные числа от A до B (включительно).

Для проверки целого числа x на чётность используется операция взятия остатка от деления на 2, которая в C++ оформляется с помощью символа "%". 
*/

TEST(White_Belt_Week_1, Task_5) {
	int A, B;
	cin >> A >> B;
	if (A <= B, A >= 1, B <= 30000) {
		for (A; A <= B; A++) {
			if (A % 2 == 0) {
				cout << A << " ";
			}
		}
	}
}


/*
* Дана строка. Найдите в этой строке второе вхождение буквы f и выведите индекс этого вхождения. 
Если буква f в данной строке встречается только один раз, выведите число -1, а если не встречается ни разу, выведите число -2. 
Индексы нумеруются с нуля.
*/
TEST(White_Belt_Week_1, Task_6) {
	string str;
	cin >> str;
	int count = 0;
	int index = -1;
	for (char f : str) {
		index++;
		if (f == 'f') {
			count++;
			if (count == 2) {
				cout << index;
				break;
			}
		}
	}
	if (count == 0) {
		cout << -2;
	}
	else if (count == 1) {
		cout << -1;
	}
}

TEST(White_Belt_Week_1, Task_6_1) {
	string str;
	cin >> str;
	int count = 0;
	int index = -1;
	for (int i = 0; i < size(str); i++) {
		if (str[i] == 'f') {
			count++;
			if (count == 2) {
				cout << i;
				break;
			}
		}
	}
	if (count == 0) {
		cout << -2;
	}
	else if (count == 1) {
		cout << -1;
	}
}

TEST(White_Belt_Week_1, Task_6_2) {
	string str;
	cin >> str;
	int results = -2;
	for (int i = 0; i < size(str); i++) {
		if (str[i] == 'f') {
			if (results == -2) {
				results = -1;
			}
			else if (results == -1) {
				results = i;
				break;
			}
		}
	}
	cout << results;
}


/*
В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
*/
TEST(White_Belt_Week_1, Task_7) {
	int x, y, max_devider;
	cin >> x >> y;
	if (x >= 0 && y >= 0) {
		if (x % y == 0) {
			max_devider = y;
		}
		else if (y % x == 0) {
			max_devider = x;
		}
		else if (x < y){
			for (int i = 1; i < x / 2; i++) {
				if (x % i == 0 && y % i == 0) {
					max_devider = i;
				}
			}
		}
		else {
			for (int i = 1; i < y / 2; i++) {
				if (x % i == 0 && y % i == 0) {
					max_devider = i;
				}
			}
		}
		cout << max_devider;
	}
	else {
		cout << "Введите натуральные числа";
	}
}

TEST(White_Belt_Week_1, Task_7_1) {
	int a, b;
	cin >> a >> b;

	// пока оба числа положительны, будем их уменьшать, не меняя их НОД
	while (a > 0 && b > 0) {
		// возьмём большее из чисел и заменим его остатком от деления на второе
		// действительно, если a и b делятся на x, то a - b и b делятся на x
		// тогда и a % b и b делятся на x, так что можно a заменить на a % b
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	// если одно из чисел оказалось равно нулю, значит, на последней итерации
	// большее число разделилось на меньшее
	cout << a + b;
}

/*
* На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
*/
TEST(White_Belt_Week_1, Task_8) {
	int N, remainder, whole_part;
	cin >> N;
	vector <int> mod2;
	if (N > 0) {
		if (N == 1) {
			cout << N;
		}
		whole_part = N;
		while (whole_part != 0 && whole_part != 1) {
			remainder = whole_part % 2;
			whole_part /= 2;
			mod2.push_back(remainder);
			if (whole_part == 0 || whole_part == 1) {
				mod2.push_back(whole_part);
			}
		}
		for (int i = size(mod2)-1; i >=0; i--){
			cout << mod2[i];
		}
	}
	else
		cout << "Введите  целое положительное число N";
}

TEST(White_Belt_Week_1, Task_8_1) {
	int n;
	vector<int> bits;

	cin >> n;
	while (n > 0) {
		bits.push_back(n % 2);
		n /= 2;
	}

	for (int i = bits.size() - 1; i >= 0; --i) {
		cout << bits[i];
	}
}