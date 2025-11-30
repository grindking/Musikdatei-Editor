/*####Hauptmodul des Programms####
Hier findet sich das realisierte Menu und die 
Benutzereingaben für das Programm*/


#include <iostream>
#include <string>
#include "Hilfsfunktionen.h"
#include "MP3Konverter.h"
#include "DateiBearbeiten.h"

using namespace std;

int main()
{

    
    int auswahl, start, ende; //Variablen um die Dateipositionen zum Bearbeiten festzulegen
    bool anhaengen; // Falls True, wird beim Datei Bearbeiten nur angehängt anstatt zu ersetzen
    string eingabe; // Strings, um die Benutzereingaben zu puffern
    string neueDaten;
    string dateiname;

    //Eine kurze Erklärung zum Programmstart wird ausgegeben
    cout << "Hallo!\n";
    cout << "Dieses Programm konvertiert MP3-Dateien zu Hex/Bin oder Char\n";
    cout << "und ermöglicht die Bearbeitung der Dateien\n";

    // Hauptschleife des Programms
    // Das generelle Prinzip:
    //Der Benutzer gibt seine gewünschte Auswahl an, danach werden
    //die Parameter vom Benutzer abgefragt und die korrekte Funktion
    //aufgerufen
    while (true) {
        MenuAnzeigen();
        getline(cin, eingabe);
        //Eingaben, die ein bestimmtes Format erwarten, werden mit einem
        // try...catch-Block abgefangen um Programmabstürze zu vermeiden
        try {
            auswahl = stoi(eingabe); //Die Eingabe wird zu Integer konvertiert und abgespeicher in 'auswahl'
        }
        catch (...) {
            cerr << "Ungültige Zahl!\n";
            continue;
        }

        switch (auswahl) {
        // Bei '0' wird das Programm beendet
        case 0:
            cout << "Bis dann!\n";
            return 0;

        // Bei 1 wird eine Musikdatei konvertiert
        case 1:
            
            cout << "Bitte gebe den Namen der zu konvertierenden Musikdatei an:";
            getline(cin, dateiname);
            konvertiereDatei(dateiname);
            break;
        // Bei 2 wird ein Ausschnitt aus einer Datei angezeigt
        case 2:
            
            cout << "Bitte gebe den Namen der anzuzeigenden Datei an (mit Dateiendung .bin/.char/.hex):";
            getline(cin, dateiname);
            
            cout << "Bitte gebe die Startposition zum Anzeigen der Datei an:";
            getline(cin, eingabe);
            //Eingaben, die ein bestimmtes Format erwarten, werden mit einem
            // try...catch-Block abgefangen um Programmabstürze zu vermeiden
            try {
                start = stoi(eingabe);
            }
            catch (...) {
                cerr << "Ungültige Zahl!\n";
                break;
            }
            
            cout << "Bitte gebe die Endposition zum Anzeigen der Datei an:";
            getline(cin, eingabe);
            //Eingaben, die ein bestimmtes Format erwarten, werden mit einem
            // try...catch-Block abgefangen um Programmabstürze zu vermeiden
            try {
                ende = stoi(eingabe);
            }
            catch (...) {
                cerr << "Ungültige Zahl!\n";
                break;
            }
            dateiAnzeigen(dateiname, start, ende);
            break;
        //Bei '3' wird die angegebene Datei bearbeitet
        case 3:
            
            cout << "Bitte gebe den Namen der zu bearbeitenden Datei an (mit Dateiendung .bin/.char/.hex):";
            getline(cin, dateiname);

            cout << "Bitte gebe die Position zum Bearbeiten der Datei an:";
            getline(cin, eingabe);
            //Eingaben, die ein bestimmtes Format erwarten, werden mit einem
           // try...catch-Block abgefangen um Programmabstürze zu vermeiden
            try {
                start = stoi(eingabe);
            }
            catch (...) {
                cerr << "Ungültige Zahl!\n";
                break;
            }
            
            cout << "Bitte gebe die neuen Daten an:";
            getline(cin, neueDaten);
            
            cout << "Bitte gebe eine '1' ein, falls du die Daten anhängen möchtest, ansonsten eine '0' falls du sie ersetzen möchtest:";
            getline(cin, eingabe);
            //Eingaben, die ein bestimmtes Format erwarten, werden mit einem
            // try...catch-Block abgefangen um Programmabstürze zu vermeiden
            try {
                anhaengen = stoi(eingabe);

                if (anhaengen > 1 || anhaengen < 0 ) {
                    cout << "Bitte eine korrekte Eingabe tätigen";
                }
            }
            catch (...) {
                cerr << "Ungültige Zahl!\n";
                break;
            }
            datenAnStelleVeraendern(dateiname, start, neueDaten, anhaengen);
            break;
        //Bei '4' wird eine Musikdatei ins aktuelle Verzeichnis kopiert
        case 4:
            
            cout << "Bitte gebe den Dateipfad zur neuen Datei an:";
            getline(cin, dateiname);
            musikdateiKopieren(dateiname);
            break;
        }
    }
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
