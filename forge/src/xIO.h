// SPDX-FileCopyrightText: 2021 - Sebastian Ritter <bastie@users.noreply.github.com>
// SPDX-License-Identifier: MIT

/*
 * author: Sͬeͥbͭaͭsͤtͬian
 */

#ifndef XIO_H_
#define XIO_H_

#include <iostream>
#include <string>

std::wstring readFile(const char* filename);
void syserr3 (wchar_t const &wc);
void syserrs (std::wstring const &s);
void syserrs2 (std::wstring const &s);


#endif /* XIO_H_ */
