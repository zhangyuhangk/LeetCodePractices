#include <stdio.h>
#include <Windows.h>
#include <exception>

#include "Q241_Different_Ways_to_Add_Parentheses.h"

void main() {
	srand(::GetTickCount());
	try {
		Q241_Different_Ways_to_Add_Parentheses();
	}
	catch (const std::exception& e) {
		printf_s("exception occrued: %s\n", e.what());
	}
	catch (...) {
		printf_s("unknown exception occured!\n");
	}

	system("pause");
}