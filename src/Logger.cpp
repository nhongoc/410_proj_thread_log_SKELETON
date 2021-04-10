/*
 * Logger.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: keith
 */
#include <iostream>
#include "../includes/Logger.h"
#include "../includes/constants.h"
using namespace std;

Logger::Logger(LOG_TYPE lt, string fn) : lt(lt), fn(fn), fs(ofstream(fn, ofstream::out)) {
}

void Logger::Log(string info) {
	if (lt == LOG_FILE) {
		lock_guard<mutex> lck (mtx);
		fs << info << '\n';
	}
	else {
		lock_guard<mutex> lck (mtx);
		cout << info << '\n';
	}
}

Logger::~Logger() {
	fs.close();
}
