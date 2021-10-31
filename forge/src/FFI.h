// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#ifndef FFI_H_
#define FFI_H_

#include <dlfcn.h>

namespace forge {

class FFI {
public:
	FFI(char*);
	virtual ~FFI();

	virtual char* call (char*, char*);
};

} /* namespace forge */

#endif /* FFI_H_ */
