// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 *
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#include "forge.h"

namespace forge {

	Iron::Iron() {
	}

	Iron::~Iron() {
	}

	std::list<Ore> Iron::getIngredients (std::wstring content) {
		std::list<Ore> result;

		Ore *ore = new Ore();
		ore->lex(content);

		return result;
	}

} /* namespace forge */
