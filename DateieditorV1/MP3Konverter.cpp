/*Mit diesem Modul lässt sich eine Musikdatei in BIN/HEX/CHAR 
formatieren*/

#include "Hilfsfunktionen.h"
#include "MP3Konverter.h"
#include <iostream>
#include <fstream>
#include <iomanip> // für hex, setw, setfill
#include <cctype>  // für isprint

using namespace std;

void konvertiereDatei(const string& mp3Pfad) {
    // Eingabedatei öffnen (Binärmodus)
    ifstream inputFile(mp3Pfad, ios::binary);
    if (!inputFile) {
        cerr << "Fehler beim Öffnen der Datei: " << mp3Pfad << endl;
        return;
    }

    // Zielbasename ohne Extension
    size_t pos = mp3Pfad.find_last_of("/\\");
    size_t start = (pos == string::npos) ? 0 : pos + 1;
    size_t end = mp3Pfad.find_last_of(".");
    string baseName = mp3Pfad.substr(start, end - start);

    // Ausgabedateien öffnen
    ofstream binFile(baseName + ".bin", ios::binary);
    ofstream hexFile(baseName + ".hex");
    ofstream charFile(baseName + ".char");

    if (!binFile || !hexFile || !charFile) {
        cerr << "Fehler beim Erstellen der Ausgabedateien." << endl;
        return;
    }

    // Byte für Byte lesen und verarbeiten
    char byte;
    while (inputFile.read(&byte, 1)) {
        // Binärdatei kopieren
        binFile.write(&byte, 1);

        // Hexdarstellung
        unsigned char ucByte = static_cast<unsigned char>(byte);
        hexFile << hex << setw(2) << setfill('0') << (int)ucByte << " ";

        // Zeichen
        if (isprint(ucByte))
            charFile << byte;
        else
            charFile << '.';
    }

    inputFile.close();
    binFile.close();
    hexFile.close();
    charFile.close();

    cout << "Konvertierung abgeschlossen:\n"
        << " -> " << baseName << ".bin\n"
        << " -> " << baseName << ".hex\n"
        << " -> " << baseName << ".char\n";
}

