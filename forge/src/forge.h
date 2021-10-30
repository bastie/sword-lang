// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#ifndef FORGE_H_
#define FORGE_H_

#include <string>
#include <list>
#include <iostream>



namespace forge {

struct ingredient {};

class Ore {
public:
	Ore();
	virtual ~Ore();
	virtual std::list<ingredient> lex (std::wstring content);
private:
	std::list<wchar_t> getCharList (std::wstring content);
};

class Iron {
public:
	Iron();
	virtual ~Iron();
	virtual std::list<Ore> getIngredients (std::wstring content);
};

class Blade {
public:
	Blade();
	virtual ~Blade();
};

} /* namespace forge */
#endif /* FORGE_H_ */

