

/*Dieses Modul ermöglicht die Bearbeitung von den erzeugten Dateien,
dabei wird immer nur eine Datei genommen und an der angegeben verändert.
Man kann auswählen zwischen einfügen bzw. anhängen oder 
bestehende Daten ändern*/


//Eingebundene Bibliotheken
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//Funktion um eine Datei an einer bestimmten Stelle zu verändern
//Funktioniert für HEX/BIN/CHAR Dateien
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
        //Standardabfrage, ob die Datei existiert
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




 


