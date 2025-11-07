#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool datenAnStelleVeraendern(const string& dateiPfad, size_t position,
    const string neueDaten, bool append = false);