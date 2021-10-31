// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 *
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#include "iostream"
#include "stdlib.h"
#include "FFI.h"

namespace forge {

	void* library;

	FFI::FFI(char* libraryName) {
		dlerror(); // reset
		library = dlopen(libraryName,RTLD_LAZY);;
		if (NULL == library) {
			const char *dlsym_error = dlerror();
			if (dlsym_error) {
				std::cerr << dlsym_error << std::endl;
			}
		}

	}

	FFI::~FFI() {
		if (NULL == library) dlclose(library);
	}



	char* FFI::call (char* functionName, char* functionParameter) {
		dlerror(); // reset
		char* returnValue;

		typedef char* (*functionDeclaration) (const char*);
		void* functionPointer = dlsym (library, functionName);
		const char *dlsym_error = dlerror();
		if (dlsym_error) {
			char EMPTY[] = "";
			returnValue = EMPTY;
			std::cerr << std::endl << "unknown function name" << std::endl;
		}
		else {
			functionDeclaration function = *(functionDeclaration*) (&functionPointer);
			const char *dlsym_error = dlerror();
			if (dlsym_error) {
				char EMPTY[] = "";
				returnValue = EMPTY;
				std::cerr << std::endl << "error on function call" << std::endl;
			}
			else {
				returnValue = function (functionParameter);
				if (returnValue == NULL) {
					char EMPTY[] = "";
					returnValue = EMPTY;
					std::cerr << std::endl << "result is NULL" << std::endl;
				}
				else {} // Thanks god!

			}
		}
		return returnValue;
	}

} /* namespace forge */
