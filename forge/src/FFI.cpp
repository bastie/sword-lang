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

	/**
	 * Pointer to the dynamic loaded library
	 */
	void* library;

	/**
	 * Create an instance and load the library over their name
	 * @param libraryName
	 * @throws runtime_error rethrowed from loadLibrary
	 */
	FFI::FFI(char* libraryName) {
		this->loadLibrary (libraryName); // load the library
	}

	/**
	 * Create an instance and load the library over their name
	 * @param libraryName
	 * @throws runtime_error rethrowed from loadLibrary
	 */
	FFI::FFI(std::string libraryName) {
		// convert the std::string to char* ...
		char lName[libraryName.length()+1];
		std::strncpy (lName,libraryName.c_str(),sizeof(lName));
		// ... and use the default method to load the library
		this->loadLibrary(lName);
	}

	/**
	 * Load dynamic C library at runtime
	 *
	 * @param libraryName full qualified name of library
	 * @throws runtime_error throwed in result of not loadable library
	 */
	void FFI::loadLibrary (char* libraryName) {
		dlerror(); // reset the error messages
		library = dlopen(libraryName,RTLD_LAZY); // load library
		if (NULL == library) { // if library not loaded
			const char *dlsym_error = dlerror(); // get the error message
			if (dlsym_error) { // if error message loaded from underlying system
				std::cerr << dlsym_error << std::endl; // output the error message
			}
			std::string errorMessage = "library " + std::string(libraryName) + " not loaded"; // get own error message
			throw std::runtime_error(errorMessage); // throw a runtime error with own message
		}
	}

	/**
	 * Destruct the instance and free the loaded library.
	 */
	FFI::~FFI() {
		if (NULL == library) dlclose(library); // if library pointer exist close library
	}


	/**
	 * Adapter method for <code> char* call(char*,char*) </code>
	 *
	 * @see char* call(char*,char*)
	 *
	 * @param functionName
	 * @param functionParameter
	 * @return
	 */
	char* FFI::call (std::string functionName, std::string functionParameter) {
		// convert the std::string to char* ...
		char fName[functionName.length()+1];
		std::strncpy(fName, functionName.c_str(), sizeof(fName));
		char fParameter[functionParameter.length()+1];
		std::strncpy(fParameter, functionParameter.c_str(), sizeof(fParameter));

		// ... and use the method with char*,char* parameters
		char* result = this->call(fName, fParameter);

		return result;
	}

	/**
	 * Call a function in the dynamic loaded library over dynamic call for
	 * function with <code>char* functionName (char*)</code> declaration.
	 *
	 * @note return empty char* if called function returns <code>NULL</code> or on error
	 *
	 * @param functionName the export entry point (C name)
	 * @param functionParameter char* parameter
	 * @return non-nullable char*
	 */
	char* FFI::call (char* functionName, char* functionParameter) {
		dlerror(); // reset the error message
		char* returnValue; // declare the return value

		typedef char* (*functionDeclaration) (const char*); // typedef the method syntax
		void* functionPointer = dlsym (library, functionName); // get a pointer to method
		const char *dlsym_error = dlerror(); // get error message
		if (dlsym_error) { // if error set the return to empty char array
			char EMPTY[] = "";
			returnValue = EMPTY;
			std::cerr << std::endl << "unknown function name" << std::endl; // print own error message
		}
		else {
			functionDeclaration function = *(functionDeclaration*) (&functionPointer);
			const char *dlsym_error = dlerror(); // get error message
			if (dlsym_error) {// if error set the return to empty char array
				char EMPTY[] = "";
				returnValue = EMPTY;
				std::cerr << std::endl << "error on function call" << std::endl; // print own error message
			}
			else {
				returnValue = function (functionParameter);
				if (returnValue == NULL) { // if get no return value set the return to empty char array
					char EMPTY[] = "";
					returnValue = EMPTY;
					std::cerr << std::endl << "result is NULL" << std::endl; // print own error message
				}
				else {} // Thanks god!

			}
		}
		return returnValue;
	}

} /* namespace forge */
