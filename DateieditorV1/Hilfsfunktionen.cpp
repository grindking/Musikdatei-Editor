#include "Hilfsfunktionen.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>// für isprint
#include <limits>
//#define BOOST_TEST_MODULE DateiFunktionTest
//#include <boost/test/included/unit_test.hpp>
using namespace std;


void MenuAnzeigen() {
    cout << "\n";
    cout << "========================================\n";
    cout << "   Musikdateien konvertieren & editieren\n";
    cout << "========================================\n";
    cout << "1. Musikdatei zu HEX/BIN/CHAR formatieren?\n";
    cout << "2. Eine Datei anzeigen?\n";
    cout << "3. Eine Datei bearbeiten?\n";
    cout << "4. Musikdatei hinzufuegen\n";
    cout << "0. Programm beenden\n";
    cout << "========================================\n";
    cout << "Auswahl: ";
}

/*void DateiAnzeigen(const string& dateiPfad) {
    // Datei im binären Modus öffnen
    ifstream datei(dateiPfad, ios::binary);
    if (!datei) {
        cerr << "Fehler beim Öffnen der Datei: " << dateiPfad << endl;
        return;
    }

    // Dateiendung ermitteln (für Ausgabeart)
    size_t pos = dateiPfad.find_last_of(".");
    string extensio = (pos == string::npos) ? "" : dateiPfad.substr(pos + 1);

    // Byte lesen und ausgeben
    char byte;
    while (datei.read(&byte, 1)) {
        unsigned char uc = static_cast<unsigned char>(byte);

        if (extensio == "bin" || extensio == "BIN") {
            // Ausgabe in Binär (8 Bits)
            for (int i = 7; i >= 0; --i) {
                cout << ((uc >> i) & 1);
            }
            cout << " ";
        }
        else if (extensio == "hex" || extensio == "Hex" || extensio == "HEX") {
            // Hex-Ausgabe
            cout << byte;
        }
        else if (extensio == "char" || extensio == "CHAR" || extensio == "Char") {
                cout << byte;
            
        }
        else {
            // Standard: Hex
            cout << hex << setw(2) << setfill('0') << (int)uc << " ";
        }
    }
    cout << endl;

    datei.close();
}*/

void dateiAnzeigen(const string& dateiPfad, size_t start = 0, size_t ende = 20) {
    ifstream datei(dateiPfad, ios::binary);
    if (!datei) {
        cerr << "Fehler beim Öffnen der Datei: " << dateiPfad << endl;
        return;
    }

    // Dateiendung ermitteln
    size_t pos = dateiPfad.find_last_of(".");
    string extension = (pos == string::npos) ? "" : dateiPfad.substr(pos + 1);


    // Dateigröße ermitteln
    datei.seekg(0, ios::end);
    size_t dateiGroesse = datei.tellg();

    // Überprüfen: Start innerhalb der Datei
    if (start > dateiGroesse) {
        cerr << "Startindex liegt außerhalb der Dateigröße (Datei: " << dateiGroesse << " Byte)." << endl;
        return;
    }

    // Ende auf Dateigröße setzen, wenn nicht angegeben oder größer
    if (ende == 0 || ende > dateiGroesse)
        ende = dateiGroesse;

    // Wenn Ende kleiner oder gleich Start, Fehler
    if (ende <= start) {
        cerr << "Endindex muss größer als Startindex sein." << endl;
        return;
    }

    size_t anzahlBytes = ende - start;

    // Position auf das Start-Byte setzen
    datei.seekg(start, ios::beg);

    // Bytes lesen und ausgeben
    // Dateimodus, je nach Erweiterung
    size_t gelesenBytes = 0;
    size_t limitBytes = anzahlBytes;

    // Bytes lesen und ausgeben
    for (size_t i = 0; i < limitBytes; ++i) {
        char byte;
        if (!datei.read(&byte, 1))
            break;
        unsigned char uc = static_cast<unsigned char>(byte);

        if (extension == "bin" || extension == "BIN") {
            for (int bit = 7; bit >= 0; --bit)
                cout << ((uc >> bit) & 1);
            cout << " ";
        }
        else if (extension == "hex" || extension == "HEX") {
            cout << hex << setw(2) << setfill('0') << (int)uc << " ";
        }
        else if (extension == "char" || extension == "CHAR") {
            if (isprint(uc))
                cout << byte;
            else
                cout << '.';
        }
        else {
            cout << hex << setw(2) << setfill('0') << (int)uc << " ";
        }
    }
    cout << endl;
}












bool copyFile(const string& sourcePath, const string& destPath) {
    ifstream src(sourcePath, ios::binary);
    ofstream dst(destPath, ios::binary);

    if (!src || !dst) {
        cerr << "Fehler beim Öffnen der Datei.\n";
        return false;
    }

    dst << src.rdbuf();

    return src && dst;
}

void musikdateiKopieren(const string& sourcePath) {
    // Hole den Dateinamen aus dem Pfad
    size_t pos = sourcePath.find_last_of("/\\");
    string dateiname = (pos == string::npos) ? sourcePath : sourcePath.substr(pos + 1);

    // Zielpfad im aktuellen Verzeichnis
    string destination = "./" + dateiname;

    if (copyFile(sourcePath, destination)) {
        cout << "Datei wurde erfolgreich kopiert: " << destination << endl;
    }
    else {
        cerr << "Kopieren fehlgeschlagen.\n";
    }
}


// Der Test
/*BOOST_AUTO_TEST_CASE(test_musikdateiKopieren) {
    // Testdaten vorbereiten
    string sourcedateiname = "test_source.mp3";
    string targetdateiname = "./test_source.mp3";

    // Erstelle eine Testdatei mit Testdaten
    {
        std::ofstream out(sourcedateiname, std::ios::binary);
        out << "Dies ist ein Testinhalt der MP3 Datei.";
    }

    // Funktion aufrufen
    musikdateiKopieren(sourcedateiname);

    // Überprüfung: Datei existiert im aktuellen Verzeichnis
    std::ifstream original(sourcedateiname, std::ios::binary);
    std::ifstream kopiert(targetdateiname, std::ios::binary);
    BOOST_REQUIRE_MESSAGE(original.is_open(), "Originaldatei konnte nicht geöffnet werden");
    BOOST_REQUIRE_MESSAGE(kopiert.is_open(), "Kopierte Datei konnte nicht geöffnet werden");

    // Inhalte vergleichen
    std::ostringstream bufOriginal, bufKopiert;
    bufOriginal << original.rdbuf();
    bufKopiert << kopiert.rdbuf();
    BOOST_CHECK_EQUAL(bufOriginal.str(), bufKopiert.str());

    // Aufräumen: Testdateien löschen
    std::remove(sourcedateiname.c_str());
    std::remove(targetdateiname.c_str());
}*/