int r_mtr_n = 2; // assign motor pins to arduino
int r_mtr_p = 4;    
int l_mtr_p = 5;
int l_mtr_n = 7;
int pwm1 = 9;
int pwm2 = 11;
int incomingByte = 0; // assign pin for bluetooth module

void setup(){
Serial.begin(9600);
pinMode(r_mtr_n, OUTPUT);
pinMode(r_mtr_p, OUTPUT);
pinMode(l_mtr_p, OUTPUT);
pinMode(l_mtr_n, OUTPUT);
digitalWrite(r_mtr_n, LOW);
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
Serial.println("start");
Serial.begin(9600);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
}

void loop(){

if (Serial.available() > 0) {
incomingByte = Serial.read();
}

switch(incomingByte)
{

case 'z' :
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
Serial.println("Increasing speed\n");
incomingByte='*';
break;

case 'x':
analogWrite(pwm1, 255/3);
analogWrite(pwm2, 255/3);
Serial.println("Decreasing speed\n");
incomingByte='*';
break;

case 'u':
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
incomingByte='*';
break;

case 'a':
digitalWrite(r_mtr_n, HIGH); // control for right
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
Serial.println("right\n");
delay(30);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'd':
digitalWrite(r_mtr_n, LOW); // control for left
digitalWrite(r_mtr_p, HIGH);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
Serial.println("left\n");
delay(30);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'w':
digitalWrite(r_mtr_n, HIGH); // control for forward
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
Serial.println("forward\n");
delay(30);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 's':
digitalWrite(r_mtr_n, LOW); // control for backward
digitalWrite(r_mtr_p, HIGH);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
Serial.println("backwards\n");
delay(30);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'h':
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
Serial.println("TURNING 45 DEGREE\n");
digitalWrite(r_mtr_n, LOW); // control for left
digitalWrite(r_mtr_p, HIGH);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(125);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
incomingByte='*';
break;

case 'g':
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
Serial.println("TURNING 45 DEGREE RIGHT\n");
digitalWrite(r_mtr_n, HIGH); // control for right
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
delay(125);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
incomingByte='*';
break;

case 't':
Serial.println("tackle\n");
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
digitalWrite(r_mtr_n, HIGH); // control for forward
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(250);
digitalWrite(r_mtr_n, LOW); // control for backward
digitalWrite(r_mtr_p, HIGH);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
delay(250);
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
incomingByte='*';
break;

case 'p':
Serial.println("DRAWING PENTAGON\n");
for(int i=0;i<5;i++){
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
digitalWrite(r_mtr_n, HIGH); // control for forward
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(1000);
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
digitalWrite(r_mtr_n, HIGH); // control for right
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
delay(263);}
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'o':
Serial.println("DRAWING SQUARE\n");
for(int i=0;i<4;i++){
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
digitalWrite(r_mtr_n, HIGH); // control for forward
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(1000);
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
digitalWrite(r_mtr_n, HIGH); // control for right
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, HIGH);
digitalWrite(l_mtr_n, LOW);
delay(343);}
digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'l':
Serial.println("WE LOVE XLR8!\n");
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
delay(50);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(1300);
analogWrite(pwm1, 255);
analogWrite(pwm2, 255/12);
delay(50);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(2350);
analogWrite(pwm1, 255);
analogWrite(pwm2, 255);
delay(50);
digitalWrite(r_mtr_n, LOW); // 
digitalWrite(r_mtr_p, HIGH);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(670);
analogWrite(pwm1, 255);
analogWrite(pwm2, 255/12);
delay(50);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(2350);
analogWrite(pwm1, 255/2);
analogWrite(pwm2, 255/2);
delay(50);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(1800);
digitalWrite(r_mtr_n, LOW); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

case 'e':
Serial.println("\t8!\n");
analogWrite(pwm1, 255);
analogWrite(pwm2, 255/12);
delay(10);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(2400);
digitalWrite(r_mtr_n, LOW); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
analogWrite(pwm1, 255/10);
analogWrite(pwm2, 255);
delay(10);
digitalWrite(r_mtr_n, HIGH); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, HIGH);
delay(3800);
digitalWrite(r_mtr_n, LOW); // 
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
incomingByte='*';
break;

digitalWrite(r_mtr_n, LOW); // control for stop
digitalWrite(r_mtr_p, LOW);
digitalWrite(l_mtr_p, LOW);
digitalWrite(l_mtr_n, LOW);
}
}
