#include <Servo.h>

int val;
int angle1, angle2, angle3;
int charsRead;
int chose;
char buffer[10];
Servo servo, servo1, servo2, servo3;

void setup() {
  Serial.begin(9600);
  servo.attach(6);
  
  servo1.attach(9);
  servo1.write(50);
  angle1 = servo1.read();
  
  servo2.attach(10);
  servo2.write(160);
  angle2 = servo2.read();
  
  servo3.attach(11);
  servo3.write(90);
  angle3 = servo3.read();
}

void loop() {
    if (val == 6) {
      servo.write(150);
    }
    else if (val == 5) {
      servo.write(30);
    }
   else if(val == 4021){
       servo1.write(angle1--);
       delay(35);
       }
       else if (val == 4011){
         servo1.write(angle1++);
         delay(35);
         }
      else if(val == 4022 || val == 4012){
        servo1.write(angle1);
        }
        
        else if (val == 3021){
          servo2.write(angle2--);
          delay(35);
          }
          else if (val == 3011){
            servo2.write(angle2++);
            delay(35);
            }
            else if (val == 3022 || val == 3012){
              servo2.write(angle2);
              }
              
              else if (val == 2021){
                servo3.write(angle3--);
                delay(35);
                }
                else if (val == 2011){
                  servo3.write(angle3++);
                  delay(36);
                  }
                  else if(val == 2022 || val == 2012){
                    servo3.write(angle3);
                    }
        
          serialCheck();
}

void serialCheck(){
  while(Serial.available() > 0){
    charsRead = Serial.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    buffer[charsRead] = '\0';
    val = atoi(buffer);
    Serial.println(val);
    }
  }
