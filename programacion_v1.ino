//ARNES 6 PIN 5
//ARNES 5 PIN 7
//ARNES 4 PIN 4
//ARNES 3 PIN 3
//ARNES 2 PIN 6
//ARNES 1 PIN 2

//int PIR_1 = 2;
int PIR_2 = 3;
int PIR_3 = 4;
int PIR_4 = 5;
int PIR_5 = 6;
int PIR_6 = 7;

//int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;
int value6 = 0;
int Estado = 0;

int relay1 = 8;
int relay2 = 9;
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  //pinMode(PIR_1, INPUT);  //definir pin como entrada
  pinMode(PIR_2, INPUT);  //definir pin como entrada
  pinMode(PIR_3, INPUT);  //definir pin como entrada
  pinMode(PIR_4, INPUT);  //definir pin como entrada
  pinMode(PIR_5, INPUT);  //definir pin como entrada
  pinMode(PIR_6, INPUT);  //definir pin como entrada
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char option = Serial.read();
    if (option == 'B' )//APAGAR SIRENA
    {
      Serial.println("relevadores apagados");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
    }
    if (option == 'F' )//ACTIVAR ALARMA
    {
      digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    Estado = 0;
    while (Estado == 0) {
      if (Serial.available() > 0) {
        char option = Serial.read();
        if (option == 'L' )//APAGAR ALARMA
        {
          Serial.print("Alarma Apagada");
        break;
      }
    }
    //value1 = digitalRead(PIR_1);
    value2 = digitalRead(PIR_2);
    value3 = digitalRead(PIR_3);
    value4 = digitalRead(PIR_4);
    value5 = digitalRead(PIR_5);
    value6 = digitalRead(PIR_6);
    if ( value2 == HIGH || value3 == HIGH || value4 == HIGH || value5 == HIGH || value6 == HIGH) {
      Serial.println("Encendido");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
      Estado = 1;
    }
    if ( value2 == LOW && value3 == LOW && value4 == LOW && value5 == LOW && value6 == LOW) {
      Serial.println("APAGADO");
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, LOW);
      Estado = 0;
    }
    delay(100);
  }
}
}
}
