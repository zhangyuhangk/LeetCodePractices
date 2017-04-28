#include <stdio.h>
#include <Windows.h>
#include <exception>

#include "Q436_Find_Right_Interval.h"
#include "Q473_Matchsticks_to_Square.h"

void main() {
	srand(::GetTickCount());
	try {
		//Q436_Find_Right_Interval();
		Q473_Matchsticks_to_Square();
	}
	catch (const std::exception& e) {
		printf_s("exception occrued: %s\n", e.what());
	}
	catch (...) {
		printf_s("unknown exception occured!\n");
	}

	system("pause");
}