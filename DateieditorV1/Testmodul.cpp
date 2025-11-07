

/*In diesem Modul sind alle Tests für die einzelnen Module aufgelistet
WICHTIG!!! : Bei Gebrauch MUSS die int main()-Funktion in DateieditorV1.cpp MUSS 
auskommentiert werden, ansonsten kommt es zu einem Linkerfehler wegen mehrerer
Main-Funktionen
Gebrauchsanweisung:
1. Zunächst die (wie bereits erwähnt)
   main-Funktion im Modul Dateieditor.cpp in ein Kommentar einbauen
2. Die include und define Anweisungen aus dem Kommentar nehmen
3. Den gewünschten Test auswählen und dort auch die 
   Kommentarzeichen entfernen
4. Das Programm kann daraufhin normal über den Debugger ausgeführt werden*/



/*#define BOOST_TEST_MODULE KonvertiereDateiTest
#include <boost/test/included/unit_test.hpp>
#include <fstream>
#include <string>
#include <cstdio> // für remove
#include "MP3Konverter.h"
#include "DateiBearbeiten.h"
#include "Hilfsfunktionen.h"

using namespace std;*/




/*############################################################
 TEST FUER DATEIEN KONVERTIEREN
 #############################################################*/
 // Hilfsfunktion: liest die Datei vollständig als string
/*string liesDatei(const string& pfad) {
    ifstream f(pfad, ios::binary);
    return string((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
}

// Boost-Test
BOOST_AUTO_TEST_CASE(TestKonvertierung) {
    string mp3Datei = "test.mp3";

    // Testdatei erstellen mit Beispielinhalt
    {
        ofstream f(mp3Datei, ios::binary);
        string inhalt = "abc123!?§";
        f.write(inhalt.c_str(), inhalt.size());
    }

    // Funktion aufrufen
    konvertiereDatei(mp3Datei);

    // Basisname extrahieren
    size_t pos = mp3Datei.find_last_of("/\\");
    size_t start = (pos == string::npos) ? 0 : pos + 1;
    size_t end = mp3Datei.find_last_of(".");
    string baseName = mp3Datei.substr(start, end - start);

    // Überprüfe die binäre Datei
    string binInhalt = liesDatei(baseName + ".bin");
    BOOST_CHECK_EQUAL(binInhalt, "abc123!?§"); //§ ist nicht druckbar (isprint()), daher wird bei der .char-Datei ein Punkt angezeigt

    // Überprüfe die hex-Datei
    string hexInhalt = liesDatei(baseName + ".hex");
    // Das Beispiel: "61 62 63 31 32 33 3f a7 "
    // Konvertiere hex in String
    string expectedHex = "61 62 63 31 32 33 21 3f a7 ";
    BOOST_CHECK_EQUAL(hexInhalt, expectedHex);

    // Überprüfe die char-Datei
    string charInhalt = liesDatei(baseName + ".char");
    // Nicht druckbare Zeichen in Hex, aber hier nur Beispiel
    
    BOOST_CHECK_EQUAL(charInhalt, "abc123!?.");

    // Aufräumen
    remove((baseName + ".bin").c_str());
    remove((baseName + ".hex").c_str());
    remove((baseName + ".char").c_str());
    remove(mp3Datei.c_str());
}*/



/*############################################################
 TEST FUER DATEIEN BEARBEITEN
 #############################################################*/

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

/*############################################################
 TEST FUER EINE MUSIKDATEI IN DAS PROGRAMMVERZEICHNIS ZU KOPIEREN
 #############################################################*/

 /*BOOST_AUTO_TEST_CASE(test_musikdateiKopieren) {
     // Testdaten vorbereiten
     string sourcedateiname = "test_source.mp3";
     string targetdateiname = "./test_source.mp3";

     // Erstelle eine Testdatei mit Testdaten
     {
         ofstream out(sourcedateiname, ios::binary);
         out << "Dies ist ein Testinhalt der MP3 Datei.";
     }

     // Funktion aufrufen
     musikdateiKopieren(sourcedateiname);

     // Überprüfung: Datei existiert im aktuellen Verzeichnis
     ifstream original(sourcedateiname, ios::binary);
     ifstream kopiert(targetdateiname, ios::binary);
     BOOST_REQUIRE_MESSAGE(original.is_open(), "Originaldatei konnte nicht geöffnet werden");
     BOOST_REQUIRE_MESSAGE(kopiert.is_open(), "Kopierte Datei konnte nicht geöffnet werden");

     // Inhalte vergleichen
     ostringstream bufOriginal, bufKopiert;
     bufOriginal << original.rdbuf();
     bufKopiert << kopiert.rdbuf();
     BOOST_CHECK_EQUAL(bufOriginal.str(), bufKopiert.str());

     // Aufräumen: Testdateien löschen
     remove(sourcedateiname.c_str());
     remove(targetdateiname.c_str());
 }*/