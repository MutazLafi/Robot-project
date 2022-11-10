#include <Servo.h>

#include <SoftwareSerial.h>

#include <NewPing.h>



int Max_Distance = 250;

String Command = "";

int Hand_Angle = 0 ;

int zero_Angle = 0 ;

#define motorInput1 22        
#define motorInput2 24
#define motorInput3 26
#define motorInput4 28



#define Trig_Pin 9            
#define Echo_Pin 8





NewPing sonar (Trig_Pin, Echo_Pin, Max_Distance);

Servo servo;

 // TX,RX

void setup() {
  // put your setup code here, to run once:




  pinMode(A0, OUTPUT);
  pinMode(A14, OUTPUT);


  analogWrite(A0, 255); 

  servo.attach(A14);

  Serial.begin(9600);

  Bluetooth.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:


  int distance = ReadPing();

  if (distance < 10 && distance > 3) {

    Touch_Eyes();

  }


  if (distance < 10 && distance > 6) {
    Move('B', 255);
    delay(500);
    servo.write(Hand_Angle);

  }

  while (Bluetooth.available() > 0) {
    delay(10);
    char c = Bluetooth.read();
    Command += c;

  }




  if (Command == "dance") {
    // Bluetooth Command

    Dance();
  }

  if (Command == "f") {
    Move('F', 255);

  }

  if (Command == "b") {
    Move('B', 255);

  }


  if (Command == "R") {
    Move('L', 255);

  }



  if (Command == "l") {
    Move('L', 255);

  }



  if (Command == "forward") {
    Move('F', 255);
    delay(1000);
    Move('S', 0);

  }


  if (Command == "back") {
    Move('B', 255);
    delay(1000);
    Move('S', 0);

  }


  if (Command == "left") {
    Move('L', 255);
    delay(1000);
    Move('S', 0);

  }


  if (Command == "right") {
    Move('R', 255);
    delay(1000);
    Move('S', 0);

  }




  Command = "";



}


void Touch_Eyes() {
  Move('B', 255);
  delay(500);
  Move('S', 255);
  delay(500);

}


void Dance () {
  Move('B', 255);
  delay(700);
  Move('R', 255);
  delay(700);
  Move('F', 255);
  delay(700);
  Move('L', 255);
  delay(700);
  Move('B', 255);
  delay(700);
  Move('F', 255);
}

void Long_Dance() {

  Move('B', 255);
  delay(700);
  Move('R', 255);
  delay(700);
  Move('F', 255);
  delay(700);
  Move('L', 255);
  delay(700);
  Move('B', 255);
  delay(700);
  Move('F', 255);
  delay(700);
  Move('B', 255);
  delay(700);
  Move('R', 255);
  delay(700);
  Move('F', 255);
  delay(700);
  Move('L', 255);
  delay(700);
  Move('B', 255);
  delay(700);
  Move('F', 255);
}

int ReadPing() {
  int cm = sonar.ping_cm();


  return cm;


}






void Move(char Go_For, int Speed) {
  analogWrite(50, Speed);
  analogWrite(51, Speed);

  switch (Go_For) {
    case 'F':
      digitalWrite(motorInput1, LOW);
      digitalWrite(motorInput2, HIGH);
      digitalWrite(motorInput3, HIGH);
      digitalWrite(motorInput4, LOW);


      break;



    case 'B':
      digitalWrite(motorInput1, HIGH);
      digitalWrite(motorInput2, LOW);
      digitalWrite(motorInput3, LOW);
      digitalWrite(motorInput4, HIGH);

      break;




    case 'R':
      digitalWrite(motorInput1, LOW);
      digitalWrite(motorInput2, HIGH);
      digitalWrite(motorInput3, LOW);
      digitalWrite(motorInput4, LOW);
      break;




    case 'L':
      digitalWrite(motorInput1, LOW);
      digitalWrite(motorInput2, LOW);
      digitalWrite(motorInput3, LOW);
      digitalWrite(motorInput4, HIGH);
      break;


    case 'S':
      digitalWrite(motorInput1, LOW);
      digitalWrite(motorInput2, LOW);
      digitalWrite(motorInput3, LOW);
      digitalWrite(motorInput4, LOW);
      break;


  }
}
