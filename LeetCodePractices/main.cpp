#include <stdio.h>
#include <Windows.h>
#include <exception>

#include "Q436_Find_Right_Interval.h"
#include "Q473_Matchsticks_to_Square.h"
#include "Q235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.h"

void main() {
	srand(::GetTickCount());
	try {
		Q235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree();
	}
	catch (const std::exception& e) {
		printf_s("exception occrued: %s\n", e.what());
	}
	catch (...) {
		printf_s("unknown exception occured!\n");
	}

	system("pause");
}