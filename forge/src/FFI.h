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

/**
 * Foreign function interface to call external methods.
 *
 * Example:
 * <code>
 * 	FFI *ffi = new FFI("/usr/lib/libSystem.B.dylib");
 *	char* result = ffi->call("getenv","PATH");
 *	std::cout << "PATH: " << result <<std::endl;
 * </code>
 *
 * @brief foreign function interface
 * @version 0.1.0
 * @author Sͬeͥbͭaͭsͤtͬian
 */
class FFI {
public:
	/**
	 * Construct new instance and load library
	 * @param libraryName qualified library name
	 */
	FFI(char* libraryName);
	/**
	 * Construct new instance and load library
	 * @param libraryName qualified library name
	 */
	FFI(std::string libraryName);
	/**
	 * Destruct the instance and free the library
	 */
	virtual ~FFI();

	/**
	 * Call the function in the library
	 * @param functionName name of function
	 * @param functionParameter char* parameter
	 * @return non-nullable char*
	 */
	virtual char* call (char* functionName, char* functionParameter);
	/**
	 * Adapter for char* call(char*,char*)
	 * @param functionName name of function
	 * @param functionParameter char* parameter
	 * @return non-nullable char*
	 */
	virtual char* call (std::string functionName, std::string functionParameter);

private: // internal methods
	void loadLibrary(char*);
};

} /* namespace forge */

#endif /* FFI_H_ */
