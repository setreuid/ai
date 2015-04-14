#ifndef PREHEADER_H
#define PREHEADER_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T>
T StringToNumber(const string& numberAsString) {
	T valor;

	stringstream stream(numberAsString);
	stream >> valor;

	if (stream.fail()) {
		cout << "StringToNumber Fail!" << endl;
	}

	return valor;
};

template < typename T > std::string to_string( const T& n ) {
	std::ostringstream stm ;
	stm << n ;

	return stm.str();
};


#endif
