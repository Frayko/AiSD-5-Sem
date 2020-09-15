#pragma once
#include <iostream>
#include "DinArray.h"
#include <vector>

using namespace std;

class Menu {
public:
	static void printMenu() {}
	static void startMenu(DinArray<>& DA) {}
	static void iteratorMenu(DinArray<>* DA, DinArray<>::Iterator* it) {}
	static void riteratorMenu(DinArray<>* DA, DinArray<>::rIterator* it) {}
};