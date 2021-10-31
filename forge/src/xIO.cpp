// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 *
 * Author: Sͬeͥbͭaͭsͤtͬian
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



// https://cppcodetips.wordpress.com/2014/10/09/reading-and-writing-a-utf-8-file-in-c/
std::wstring readFile(const char* filename) // https://www.it-swarm.com.de/de/c%2B%2B/lesen-sie-die-unicode-utf-8-datei-wstring/972052129/
{
	std::wifstream wif(filename);
	wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>)); // https://code-flow.club/253408/i-have-error-empty-is-not-a-member-of-std-locale
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}

/*
 * https://www.heise.de/developer/artikel/volatile-und-andere-kleine-Verbesserungen-in-C-20-4874333.html
 */
