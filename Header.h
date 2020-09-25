#pragma once
#include <iomanip>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
double Function(double x) {
	double a = cos(x);
	double b = log10(x);
	return (a + b);
}
double PointFinding(int a, int b, int k, int N) {
	double temp = b - a;
	return (((temp / (N + 1)) * k) + a);
}
double CalcLenght(int a, int b, int N) {
	double temp = (2 * (b - a));
	return (temp / (N - 1));
}
double CalcPrecision(int a, int b, int N) {
	double temp = b - a;
	return (temp / (N + 1));
}
void PassiveSearch(int a, int b, double epsilon) {
	bool flag = true;
	int N = 1;
	std::cout << std::string(29, '-') << std::endl;
	std::cout << "| " << "Amount of " << "| " << std::setw(14) << std::left << " Value in x "
		<< "|" << std::right << std::endl;
	std::cout << "| " << std::setw(10) << "points (N)" << "| " << std::setw(15) << "|" << std::endl;
	std::cout << std::string(29, '-') << std::endl;
	while (flag) {
		std::map<double, std::set<double>> values;
		for (int k = 1; k <= N; ++k) {
			double x = PointFinding(a, b, k, N);
			double y = Function(x);
			values[y].insert(x);
		}
		double L = 0.5;
		if (N != 1) {
			L = CalcLenght(a, b, N);
		}
		double precision = CalcPrecision(a, b, N);
		std::cout << std::left << "| " << std::setw(10) << N << "| "
			<< std::setw(4) << *values.begin()->second.begin() << " +- "
			<< std::setw(5) << std::setprecision(3) << L << " |" << std::endl;
		if (L > epsilon) {
			++N;
		}
		else {
			flag = false;
		}

	}
	std::string str(29, '-');
	std::cout << str;
}
bool CompareValues(double x1, double x2) {
	return (Function(x1) < Function(x2));
}
void GoldenRatio(int a, int b, double epsilon) {
	bool flag = true;
	double tau = 1.618034;
	double _a = a;
	double _b = b;
	double len = b - a;
	double len_k = len / tau;
	double left = b - len_k;
	double right = a + len_k;
	std::cout << std::string(58, '-') << std::endl;
	std::cout << "| " << std::setw(8) << "Interval"  << " | " << std::setw(8) << "End of" << " | "
	<< std::setw(9) << "Lenght of" << " | " << std::setw(11)  << " | " << std::setw(11)
	 << " |" << std::endl;

	std::cout << "| " << std::setw(8) << "start"<< " | " << std::setw(6) << "intelval" << " | "
	<< std::setw(9) << "interval" << " | "  << std::setw(8) << "f(ak) " << " | " << std::setw(9)
	<< "f(bk)  " << " |" << std::endl;

	std::cout << "| " << std::setw(8) << "(ak)" << " | " << std::setw(8) << "(bk)" << " | " <<
	std::setw(9) << "(l)" << " | " << std::setw(11) << " | " << std::setw(11) << " |" << std::endl;

	std::cout << std::string(58, '-') << std::endl;
	double L = _b - _a;
	std::cout << "| " << std::setprecision(4) << std::setw(8)
		<< 7 << " | " << std::setw(8) << 10
		<< " | " << std::setw(9) << L << " | ";
	std::cout << std::setw(8) << std::setprecision(4) << Function(left) << " | "
		<< std::setw(9) << Function(right) << " |" << std::endl;
	while (flag) {
		if (CompareValues(left, right)) {
			_b = right;
			right = left;
			left = _a + _b - right;
		}
		else {
			_a = left;
			left = right;
			right = _a + _b - left;
		}
		double L = _b - _a;
		std::cout << "| " << std::setprecision(4) << std::setw(8)
			<< left << " | " << std::setw(8) << right
			<< " | " << std::setw(9) << L << " | ";
		if (L < epsilon) {
			std::cout << std::setw(15) << " l < epsilon" <<std::setw(7)<< " |" << std::endl;
			flag = false;
		}
		else {
			std::cout << std::setw(8) << std::setprecision(4) << Function(left) << " | "
				 << std::setw(9) << Function(right) << " |" << std::endl;
		}
	}
	double x_min = (_a + _b) / 2;
	std::cout << std::string(58, '-') << std::endl;
	std::cout << "the min of function in " << x_min <<" +- " << (_b - _a)/2. <<  std::endl;
}

