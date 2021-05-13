#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define button1 7
#define button2 6
#define LED 10

boolean currentStateB1 = LOW;
boolean currentStateB2 = LOW;

int outputState;
int outputState2;
int counter = 0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.display();
  lcd.print("Pantalla de");
  lcd.setCursor(0, 1);
  lcd.print("Inicio");
  delay(2000);
  menu();
}

void loop() {
 currentStateB1 = digitalRead(button1);
 currentStateB2 = digitalRead(button2);

  delay(15);
  if (currentStateB1 == HIGH){
    outputState = 1;
  }


  if(outputState == 1 && currentStateB1 == LOW){
    counter++;
    if (counter >= 2)
    {
      counter = 2;
    }
    Serial.println(counter);
    menu();
    outputState = 0;
  }

  if (currentStateB2 == HIGH)
  {
    outputState2 = 1;
  }
  
  if (outputState2 == 1 && currentStateB2 == LOW)
  {
    counter--;
    if (counter<=0)
    {
      counter = 0;
    }
     Serial.println(counter);
     menu();
     outputState2 = 0;
  }
  
}

void menu(){
  switch (counter){
    case 0:{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("INFORMATICA");
      lcd.setCursor(0, 1);
      lcd.print("INDUSTRIAL");
      delay(100);
      digitalWrite(LED,LOW);
      delay(100);
      digitalWrite(LED,HIGH);
      
      break;
    }
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("LUIS");
      lcd.setCursor(0, 1);
      lcd.print("RODRIGUEZ");
      delay(50);
      digitalWrite(LED,LOW);
      delay(50);
      digitalWrite(LED,HIGH);
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(":)");
      lcd.setCursor(0, 1);
      lcd.print("...");
      delay(200);
      digitalWrite(LED,LOW);
      delay(200);
      digitalWrite(LED,HIGH);
      break;
  }}