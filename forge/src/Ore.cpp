// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 * Eine Sammlung von Ingredienzien aus 1..n Quellen, üblicherweise Erze und Zusatzstoffe.
 *
 * Author: Sͬeͥbͭaͭsͤtͬian
 */

#include "forge.h"

namespace forge {

	Ore::Ore() {
	}

	Ore::~Ore() {
	}

	std::list<ingredient> Ore::lex (std::wstring content) {
		std::list<ingredient> result;

		std::list<wchar_t> chars = this->getCharList(content);

		return result;
	}

	std::list<wchar_t> Ore::getCharList (std::wstring content) {
		std::list<wchar_t> result;
		for (auto index = 0; index < content.length(); index++) {
			result.push_back(content.at(index));
		}
		return result;
	}



} /* namespace forge */

