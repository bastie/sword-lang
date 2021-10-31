// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

//============================================================================
// author      : Sͬeͥbͭaͭsͤtͬian
// version     : 0.1.0
// description : The forge!
//============================================================================

#include "forge.h"
#include "xIO.h" // x => eXtension
#include "FFI.h" // FFI => BuildIn base

using namespace forge;
using namespace std;

int main() {
	std::cout << "This sword will cut." << std::endl;

	Iron lexer;

	std::wstring content = readFile("../Makefile");

	Iron *iron = new Iron();
	list<Ore> ores = iron->getIngredients (content);

	/*
	syserrs (content);
	system("sleep 1");
	syserrs2(content);
	system("sleep 1");
	*/

	FFI *ffi = new FFI("/usr/lib/libSystem.B.dylib");
	char* result = ffi->call("getenv","PATH");

	std::cout << "PATH: " << result <<std::endl;

	delete ffi;

	return 0;
}

/*
 * Der Iron Lexer erstellt aus der Ore Quelle die Token für den Blade Parser.
 *
 */
