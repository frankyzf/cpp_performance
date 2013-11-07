/*
 * performance_stringprint.cpp
 *
 *  Created on: 7 Nov, 2013
 *      Author: fzhong
 */
#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <boost/progress.hpp>

int m_field;
std::string m_string;
//mutable std::string m_data;
//mutable int m_length;
//mutable int m_total;
//mutable bool m_calculated;
std::string m_data;
int m_length;
int m_total;
bool m_calculated;

template<class T>
inline int number_of_symbols_in(T value) {
	int symbols = value > 0 ? 0 : 1;

	while (value) {
		++symbols;
		value /= 10;
	}

	return symbols;
}

template<class T>
inline char* integer_to_string(char* buf, const size_t len, T t) {
	const bool isNegative = t < 0;
	char* p = buf + len;

	*--p = '\0';

	if (isNegative) {
		if (t == (std::numeric_limits < T > ::min)()) {
			*--p = '0' + (char) ((10 - t % 10) % 10);
			t /= 10;
		}
		t = -t;
		do {
			*--p = '0' + (char) (t % 10);
			t /= 10;
		} while (t > 0);
		*--p = '-';
	} else {
		do {
			*--p = '0' + (char) (t % 10);
			t /= 10;
		} while (t > 0);
	}
	return p;
}

void calculate()  {
	int tagLength = number_of_symbols_in(m_field) + 1;
	m_length = tagLength + m_string.length() + 1;

	m_data.resize(m_length);

	char * buf = (char*) m_data.c_str();
	integer_to_string(buf, tagLength, m_field);

	buf[tagLength - 1] = '=';
	memcpy(buf + tagLength, m_string.data(), m_string.length());
	buf[m_length - 1] = '\001';

	const unsigned char* iter =
			reinterpret_cast<const unsigned char*>(m_data.c_str());
	m_total = std::accumulate(iter, iter + m_length, 0);

	m_calculated = true;
}

void calculate_print()  {
	int tagLength = number_of_symbols_in(m_field) + 1;
	m_length = tagLength + m_string.length() + 1;

	m_data.resize(m_length);

	char * buf = (char*) m_data.c_str();
	snprintf(buf, m_length, "%d=%s", m_field, m_string.c_str());
	buf[m_length - 1] = '\001';

	const unsigned char* iter =
			reinterpret_cast<const unsigned char*>(m_data.c_str());
	m_total = std::accumulate(iter, iter + m_length, 0);

	m_calculated = true;
}

void mycalculate_print()  {
	static char sbuf[128];
	snprintf(sbuf, sizeof(sbuf), "%d", m_field);

	int tagLength = strlen(sbuf) + 1;
	m_length = tagLength + m_string.length() + 1;

	m_data.resize(m_length);

	char * buf = (char*) m_data.c_str();
	snprintf(buf, m_length, "%d=%s", m_field, m_string.c_str());
	buf[m_length - 1] = '\001';

	const unsigned char* iter =
			reinterpret_cast<const unsigned char*>(m_data.c_str());
	m_total = std::accumulate(iter, iter + m_length, 0);

	m_calculated = true;
}

int main() {
	const int num = 10000000;
	m_field = 11;
	m_string = "mystring";
	{
		std::cout << " calculate method:" << std::endl;
		boost::progress_timer t;  // start timing
		for (int i = 0; i < num; ++i)
			calculate();
	}

	{
		std::cout << " calculate_print method:" << std::endl;
		boost::progress_timer t;  // start timing
		for (int i = 0; i < num; ++i)
			calculate_print();
	}

	{
		std::cout << " mycalculate_print method:" << std::endl;
		boost::progress_timer t;  // start timing
		for (int i = 0; i < num; ++i)
			mycalculate_print();
	}

	return 1;
}
