// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#ifndef FFI_H_
#define FFI_H_

#include <dlfcn.h>
#include <string>
#include "forge.h"

namespace forge {

class FFI {
public:
	FFI(char*);
	FFI(std::string);
	virtual ~FFI();

	virtual char* call (char*, char*);
	virtual char* call (std::string, std::string);

private:
	void loadLibrary(char*);
};

} /* namespace forge */

#endif /* FFI_H_ */
