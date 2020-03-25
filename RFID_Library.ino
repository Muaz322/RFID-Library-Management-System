#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10 //RX slave select
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

byte card_ID[4]; //card UID size 4byte
byte IssuedBy[4]={0x3D,0x87,0x25,0xD9};//first UID card
byte Book1[4]={0xA2,0x3C,0xEE,0x29};//second UID card
byte Book[4]={0x43,0x96,0xEF,0x29};//second UID card

int NumbCard[3];//the number of cards. in my case i have just two cards.
int card=0;
bool appear=0;  
int statu[3];//the number of cards. in my case i have just two cards.
int s=0;   
int count=0;
int i=0;// user number     

int const RedLed=6;
int const GreenLed=5;
int const Buzzer=8;

String Log;
String Name;//user name
int Price;//user number
int n ;//The number of card you want to detect (optional)  

void setup() {

  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();  // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  
  Serial.println("Library Systm");                 // clears starting at row 1
  //Serial.println("Item No,   Issued By  ,  Book ,Total ");// make four columns (Date,Time,[Name:"user name"]line 48 & 52,[Number:"user number"]line 49 & 53)

  pinMode(RedLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  
  delay(200);
   }
   
void loop() {
  
  //look for new card
   if ( ! mfrc522.PICC_IsNewCardPresent()) {
  return;//got to start of loop if there is no card present
 }
 // Select one of the cards
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  return;//if read card serial(0) returns 1, the uid struct contians the ID of the read card.
 }
 
 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];

       if(card_ID[i]==IssuedBy[i]){
       Name="Muaz Ata Ur Rehman";//Issuer Name
       card=0;
       i=0; // User number
       s=0; //status
       
      }
      else if(card_ID[i]==Book[i]){
       Name="Rasberry Pie in 24h";//Book Name
       
       card=1;

       
       s=0; // status

       
      }
      else if(card_ID[i]==Book1[i]){
       Name="Gone with the Wind";//Book Name
       
       card=2;
       s=0; // status

       
      }
      else{
          digitalWrite(GreenLed,LOW);
          digitalWrite(RedLed,HIGH);
          goto cont;//go directly to line 71
     }
}
     
  count++;
      
      
    if(card == 1 && statu[s] == 0){
       

       
       if(appear==1){      
       statu[s]=1;      
      Serial.print(Name); 
      Serial.println(" Issues  ");
     
      }

      else{
        Serial.println("Scan USER first");
      }
    }
      
      else if(card == 1 && statu[s] == 1){
       

       if(appear==1){
       statu[s]=0; 
      Serial.print(Name);
      Serial.println(" Returns ");
      
      }
      else{
        Serial.println("Scan USER first");
      }
      }
      
      else if(card == 2 && statu[s]==0){
     if(appear==1)
     {
            statu[s]=1;
            Serial.print(Name);
            Serial.println(" Issues ");
      }

    else{
        Serial.print("Scan USER first");
      }
      
      }
      

       else if(card == 2 && statu[s]==1){
      if(appear==1)
      {
            
            statu[s]=0;
            Serial.print(Name);//send the Name to excel
            Serial.println(" Returns ");
      }
    
    
    else{
        Serial.println("Scan USER first");
      }

      
       }
      
      else if(card == i ){
     // statu[s]=1;
      if(appear==0){
      appear=1;
      Serial.println( Name);//send the Name to excel
      
      }
      else
      {
        appear=0;
        Serial.println( "GOOD BYE");
      }
      
      }
      
//      else if(j == 0 && statu[s]==1){
//      statu[s]=0;
//      z=0;
//      
//      //Serial.println( Name);//send the Name to excel
//      Serial.println( "GOOD BYE");
//      
//      }
//      
      digitalWrite(GreenLed,HIGH);
      digitalWrite(RedLed,LOW);
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
     // }
     // else if(statu[s] == 1){
     //Turn Red LED when the employee Already Left
    // digitalWrite(RedLed,HIGH);
     // }
     // delay(1000);
cont:
delay(2000);
digitalWrite(GreenLed,LOW);
digitalWrite(RedLed,LOW);

//if you want to close the Excel when all card had detected and save Excel file in Names Folder. in my case i have just 2 card (optional)
/*if(n==2){
    Serial.println("SAVEWORKBOOKAS,Names/WorkNames");
    Serial.println("FORCEEXCELQUIT");
    }*/
}
    
