/*1- In this project, you can drive an electric or hydraulic car
  for a specific purpose by manual control
  without the need for steering.
  2- The project also has the ability to navigate wirelessly.
  3- Items needed:
  1- DC 500-1000 (W) 2- Power supply 12-24(V) & 15-25(A) 
  3- Motor Shield ( L298P ) 4- Relay (3) (20V)
  5- arduino UNO 6- JoyStick 7- Jumper wire
 */
int x,y,E1 = 10 ,M1 = 12, E2=11 ,M2=13 ,R1=8 ,R2=9,h=2,n=0,z=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(h,INPUT);
}

void loop() {
 z=digitalRead(h);
 x=analogRead(A0);
 y=analogRead(A1);
  if(z==HIGH)
  {
    n=n++;
  }
  if(n%2==0)
  {

  if(y<=400 && y>=0)
  {
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);
  }
  else if(y<=1023 && y>=600)
  {
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
  else 
  {
   digitalWrite(R1,LOW);
   digitalWrite(R2,LOW);
    
  }
  if(x<=250 && x>=0)
  {
    delay(800);
    analogWrite(E1,255);
    delay(50);
    analogWrite(E1,0);
    analogWrite(E2,255);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    
  }
  else if(x<=1023 && x>=750)
  {
    delay(800);
    analogWrite(E1,255);
    delay(50);
    analogWrite(E1,0);   
    analogWrite(E2,255);
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);  
  }
  else
  {
    analogWrite(E1,0);
    analogWrite(E2,0);    
  }
  }
  else
  {
    if(y<=400 && y>=0)
  {
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);
  }
    else if(y<=1023 && y>=600)
  {
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
    else
  {
   digitalWrite(R1,LOW);
   digitalWrite(R2,LOW);  
  }
  if(x<=250 && x>=0)
  {
    analogWrite(E1,255);    
    analogWrite(E2,255);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH); 
  }
  else if(x<=1023 && x>=750)
  {
    analogWrite(E1,255);  
    analogWrite(E2,255);   
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);  
  }
  else
  {
    analogWrite(E1,0);
    analogWrite(E2,0);   
  }
  }
}