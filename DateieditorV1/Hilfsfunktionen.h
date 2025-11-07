#pragma once
#include <string>

using namespace std;

void MenuAnzeigen();
void dateiAnzeigen(const string& dateiPfad, size_t start , size_t ende);
bool copyFile(const string& sourcePath, const string& destPath);
void musikdateiKopieren(const string& sourcePath);