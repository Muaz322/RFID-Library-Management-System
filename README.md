# RFID-Library-Management-System


Pre-Requisite:

•	Before doing this project I prefer you to first do RFID attendance based system because using that same this Smart basket system can be made by making some small alteration in it.

Description:

•	In this project we will be using RFID CAT 1 type cards to mark user and book.

•	Then if the user have been scanned then the book will be “ISSUED” otherwise it would ask to “SCAN THE USER FIRST” after issuing the book if the book card is scanned again then the book status will change to return.

•	We don’t need a big database for now otherwise we can create a database in MYSQL or ORACLE.

•	For real time use use a CAT 4 tag

Software:

•	Arduino IDE

Components Required:

•	RFID CAT1 card (1 or 2)

•	RFID- RC522 (RFID card reader)

•	Arduino UNO


Wiring Schematics:

Arduino UNO                                   RFID-RC522

•	Pin10					SDA

•	Pin13                                  		SCK

•	Pin11					MOSI

•	Pin12					MISO

•	---					IRQ

•	GND					GND

•	Pin9					RST

3.3V					3.3V
