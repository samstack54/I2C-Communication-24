// I2C Slave : SVR-05_D

 #include <Wire.h>
 #define slave_adress 5
 int TH_data[2] ;
 int count = 0; 
  
 void setup() {
  Wire.begin(slave_adress);
  Wire.onRequest(requestEvent);
  Serial.begin(9600) ;
 }

 void requestEvent() { 
  byte Value;
  
  switch (count) {
    case 0:
      Value = 255;
      break;
    case 1:
      Value = TH_data[0];
      break;
    case 2:
      Value = TH_data[1];
      break;
  }
  Wire.write(Value);
  count = count + 1;
  if (count > 2) count = 0; 
 }

 void readData() {
  float temp = analogRead(A0) ;
  float humid = analogRead(A1) ;
  temp = (temp/1023.*5.)*33.3 ; // 5V, slope=33.3
  humid = (humid/1023.*5.)*33.3 ;

  TH_data[0] = (int)temp ;
  TH_data[1] = (int)humid ;

 Serial.print(temp, 0) ;
 Serial.print("\t") ;
 Serial.println(humid, 0) ;  
  delay(20) ;
 }

 void loop() {
 readData() ;
 delay(500) ;
 }
