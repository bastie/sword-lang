// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 *
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#include <string>
#include <iostream>


#include <sstream>
#include <fstream>
#include <codecvt>



void syserr3 (wchar_t const &wc) {
	std::wclog  << wc << " ";
	if (10 == wc) {
		std::wclog << std::endl;
	}
}
void syserrs (std::wstring const &s) {
	std::wclog  << s;
}
void syserrs2 (std::wstring const &s) {
	for (uint i = 0; i < s.length(); i++) {
		std::wcout << s.at(i);
	}
}



std::wstring readFile(const char* filename)
{
	std::wifstream wif(filename);
	wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}
