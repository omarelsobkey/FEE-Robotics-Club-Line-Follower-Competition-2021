//left motor dirction and speed
#define IN1 5
#define IN2 8
#define EN1 9

//right motor dirction and speed
#define IN3 7
#define IN4 10
#define EN2 6

// sensors' signals' pins
#define signal1 2//right sensor
#define signal2 3//middel sensor
#define signal3 4//left sensor

//signals values
int white = 1;
int black = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  //  pinMode (EN1, OUTPUT);

  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  //  pinMode (EN2, OUTPUT);

  pinMode (signal1, INPUT);
  pinMode (signal2, INPUT);
  pinMode (signal3, INPUT);

//  Serial.begin(9600);
}
void motor ( int LM, int RM)
{
  // control left motor directions and speed
  if ( LM < 0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite (EN1, -LM);

  }
  if (LM > 0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite (EN1, LM);
  }
  if (LM == 0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite (EN1, 0);
  }

  // control right motor directions and speed
  if (RM < 0)
  {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite (EN2, -RM);
  }

  if (RM > 0)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite (EN2, RM);
  }

  if (RM == 0)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite (EN2, 0);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  int s1 = digitalRead (signal1);//right sensor
  int s2 = digitalRead (signal2);//middel sensor
  int s3 = digitalRead (signal3);//left sensor
//
//  Serial.print(s1);
//  Serial.print(s2);
//  Serial.println(s3);
  if (s1 == black && s2 == black && s3 == black)
  {
    delay(100);
    motor(0, 0);
}
if (s1 == white && s2 == black && s3 == black)
  {
    motor(110, -110);
  }
  //middel sensor
  if (s2 == black && s1 == white && s3 == white)
  {
    motor(120, 120);
  }
  // left sensor
  if (s3 == black && s2 == white && s1 == white )
  {
    motor(-130, 130);
  }
  //right sensor
  if (s1 == black && s2 == white && s3 == white)
  {
    motor(130,-130);
  }
}
