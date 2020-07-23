#define S1 2
#define S2 3
#define S3 4
#define S4 5
#define S5 6
#define S6 7
#define S0 12
#define S7 13
#define pot A0
#define dirA1 A5
#define dirA2 A4
#define dirB1 A3
#define dirB2 A2
#define pwmA 10
#define pwmB 9

int Position,pot_value=0;
bool s0,s1,s2,s3,s4,s5,s6,s7;

void setup() {
  pinMode(S0,INPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(S4,INPUT);
  pinMode(S5,INPUT);
  pinMode(S6,INPUT);
  pinMode(S7,INPUT);
 
  pinMode(dirA1,OUTPUT);
  pinMode(dirA2,OUTPUT);
  pinMode(dirB1,OUTPUT);
  pinMode(dirB2,OUTPUT);
  pinMode(pwmA,OUTPUT);
  pinMode(pwmB,OUTPUT);
 // Serial.begin(9600);
  }

void loop() {
  pot_value=map(analogRead(pot),0,1023,0,255);
 analogWrite(pwmA,pot_value);
 analogWrite(pwmB,pot_value);
 s0=digitalRead(S0);
 s1=digitalRead(S1);
 s2=digitalRead(S2);
 s3=digitalRead(S3);
 s4=digitalRead(S4);
 s5=digitalRead(S5);
 s6=digitalRead(S6);
 s7=digitalRead(S7);
 if((s0 == HIGH)){Position = 0; 
 Quick_left();}else if((s7 == HIGH)){Position = 0;
 Quick_right();
 }
 else if((s1 == HIGH) && (s2 == HIGH) && (s3 == LOW) && (s4 == LOW) && (s5 == LOW) && (s6 == LOW)){ Position=1;   }
 else if((s1 == HIGH) && (s2 == HIGH) && (s3 == HIGH) && (s4 == LOW) && (s5 == LOW) && (s6 == LOW)){ Position=2;    }
 else if((s1 == LOW) && (s2 == HIGH) && (s3 == HIGH) && (s4 == LOW) && (s5 == LOW) && (s6 == LOW)){Position=3;   }
 else if((s1 == LOW) && (s2 == HIGH) && (s3 == HIGH) && (s4 == HIGH) && (s5 == LOW) && (s6 == LOW)){ Position=4;    }
 else if((s1 == LOW) && (s2 == LOW) && (s3 == HIGH) && (s4 == HIGH) && (s5 == LOW) && (s6 == LOW)){ Position=5;    }
 else if((s1 == LOW) && (s2 == LOW) && (s3 == HIGH) && (s4 == HIGH) && (s5 == HIGH) && (s6 == LOW)){ Position=6;    }
 else if((s1 == LOW) && (s2 == LOW) && (s3 == LOW) && (s4 == HIGH) && (s5 == HIGH) && (s6 == LOW)){ Position=7;    }
 else if((s1 == LOW) && (s2 == LOW) && (s3 == LOW) && (s4 == HIGH) && (s5 == HIGH) && (s6 == HIGH)){ Position=8;    }
 else if((s1 == LOW) && (s2 == LOW) && (s3 == LOW) && (s4 == LOW) && (s5 == HIGH) && (s6 == HIGH)){ Position=9;     }

  switch(Position){

     case 1 :
     quick_left();
     break;
     
     case 2 :
     left();
     break;
     
     case 3 :
     left();
     break;
     
     case 4 :
     forward();
     break;
     
     case 5 :
     forward();
     break;
     
     case 6 :
     forward();
     break;
     
     case 7 :
     right();
     break;
     
     case 8 :
     right();
     break;
     
     case 9 :
     quick_right();
     break;
     
  }
//Serial.println(Position);
}
void left(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,HIGH);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,HIGH);
  analogWrite(pwmA,pot_value-20);
  analogWrite(pwmB,pot_value+10);
  
}
void quick_left(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,LOW);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,HIGH);
  analogWrite(pwmB,pot_value+10);
  
}
void quick_right(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,HIGH);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,LOW);
  analogWrite(pwmA,pot_value+10);
  
}
void right(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,HIGH);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,HIGH);
  analogWrite(pwmA,pot_value+10);
  analogWrite(pwmB,pot_value-20);
}
void Quick_right(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,HIGH);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,LOW);
  analogWrite(pwmA,pot_value+40);
  
}
void Quick_left(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,LOW);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,HIGH);
  analogWrite(pwmB,pot_value+40);
  
}
void forward(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,HIGH);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,HIGH);
  analogWrite(pwmA,pot_value);
  analogWrite(pwmB,pot_value);
  
}
void Stop(){
  digitalWrite(dirA1,LOW);
  digitalWrite(dirA2,LOW);
  digitalWrite(dirB1,LOW);
  digitalWrite(dirB2,LOW);
  }
