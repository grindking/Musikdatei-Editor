# Musikdateikonverter und -editor 
Mit diesem Programm lassen sich mp3-Dateien in HEX/BIN/CHAR-Dateien umwandeln und die resultierenden
Dateien anschließend bearbeiten.

## Spezifikationen
- Entwicklungsumgebung: Visual Studio 2019
- C++ 14 Compiler (MSVC 142)
- Architektur: x86

## Erläuterungen zum selber Testen des Programms
Im Programmverzeichnis befindet sich eine Musiktestdatei 'sample.mp3' welche beim Aufrufen
des Programms zum Konvertieren benutzt werden kann. Die drei formatierten heißen dann dementsprechend
'sample.bin', 'sample.hex' und 'sample.char'. Diese können dann zum Testen der Bearbeitung aufgerufen werden.
Da diese Dateien (zum Anzeigen) sehr groß sind, besteht im Programm die Option sich einen bestimmten Ausschnitt aus den 
Dateien anzeigen zu lassen.
**Wichtig**: Falls die Boosttests ausgeführt werden sollen, muss die Boost.test-Library auf dem eigenen Computer installiert sein
und die Hinweise im Modul 'Testmodul.cpp' müssen beachtet werden
