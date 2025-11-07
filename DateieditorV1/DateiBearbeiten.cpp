#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
//#define BOOST_TEST_MODULE DateiFunktionTest
//#include <boost/test/included/unit_test.hpp>

using namespace std;

/*
 * Datei an einer Stelle verändern:
 * - wenn append = false: Daten überschreiben (ersetzen)
 * - wenn append = true: Daten einfügen (hinzufügen), Verschiebung des Inhalts
 */

bool datenAnStelleVeraendern(const string& dateiPfad, size_t position,
    const string neueDaten, bool append = false) {
    // Ablauf, um bei 'append' die ganze Datei neu zu schreiben
    fstream datei(dateiPfad, ios::in | ios::out | ios::binary);
    if (!datei) {
        cerr << "Fehler beim Öffnen der Datei: " << dateiPfad << endl;
        return false;
    }

    if (append) {
        // Datei komplett lesen
        datei.seekg(0, ios::end);
        size_t dateiGroesse = datei.tellg();
        datei.seekg(0, ios::beg);

        vector<unsigned char> datenInhalt(dateiGroesse);
        datei.read(reinterpret_cast<char*>(datenInhalt.data()), dateiGroesse);

        if (!datei) {
            cerr << "Fehler beim Lesen der Datei." << endl;
            return false;
        }

        // Verschieben auf die Position, an die eingefügt werden soll
        datenInhalt.insert(datenInhalt.begin() + position, neueDaten.begin(), neueDaten.end());

        // Datei schließen und neu im Truncate-Modus öffnen
        datei.close();
        // Datei im Ausgabe- und Truncate-Modus öffnen, um alles zu löschen
        ofstream dateiNeu(dateiPfad, ios::out | ios::binary | ios::trunc);
        if (!dateiNeu) {
            cerr << "Fehler beim Neueröffnen der Datei im Trunc-Modus." << endl;
            return false;
        }
        // komplette Daten neu schreiben
        dateiNeu.write(reinterpret_cast<const char*>(datenInhalt.data()), datenInhalt.size());
        dateiNeu.close();
    }
    else {
        // Überschreiben an der Stelle
        datei.seekp(position);
        if (!datei) {
            cerr << "Fehler beim Setzen der Position." << endl;
            return false;
        }
        datei.write(reinterpret_cast<const char*>(neueDaten.data()), neueDaten.size());
        if (!datei) {
            cerr << "Fehler beim Schreiben." << endl;
            return false;
        }
    }
    cout << "Daten erfolgreich geändert" << endl;
    return true;
}




 

/*BOOST_AUTO_TEST_CASE(TestEinfügen) {
    const string testfile = "test.bin";

    // Erstelle eine Testdatei
    ofstream f(testfile, ios::binary);
    f << "ABCDEFGH";
    f.close();

    // Neue Daten einfügen
    BOOST_CHECK(datenAnStelleVeraendern(testfile, 3, "XYZ", true));

    // Inhalt prüfen
    ifstream fin(testfile, ios::binary);
    string inhalt((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    BOOST_CHECK_EQUAL(inhalt, "ABCXYZDEFGH");

    // Datei cleanup
    remove(testfile.c_str());
}

BOOST_AUTO_TEST_CASE(TestÜberschreiben) {
    const string testfile = "test2.bin";

    ofstream f(testfile, ios::binary); 
    f << "1234567890";
    f.close();

    BOOST_CHECK(datenAnStelleVeraendern(testfile, 4, "ABCD", false));

    ifstream fin(testfile, ios::binary);
    string inhalt((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();

    BOOST_CHECK_EQUAL(inhalt, "1234ABCD90");

    remove(testfile.c_str());
}*/
