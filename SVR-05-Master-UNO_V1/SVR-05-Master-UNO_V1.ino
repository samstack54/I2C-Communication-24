// I2C Master : Uno (slave is SVR-05) 
 
 #include <Wire.h>
 #define slave_adress 5
 int count;
 byte TH_data[2] ;
 
 void setup() {
  Wire.begin();
  Serial.begin(9600);
 }

 byte readI2C(int address) {
  byte Value ;
  long Past_time = millis();

  Wire.requestFrom(address, 1); //1 byte data
  while (Wire.available() == 0 )      
  { Serial.println("Waiting"); }

  if  (millis() - Past_time < 100 ) { 
   Value = Wire.read(); 
   return Value;
  }
 }

 void loop() {
  while (readI2C(slave_adress) < 255) {
    Serial.print(".........."); 
  }
  for (count = 0; count < 2; count++) {
    TH_data[count] = readI2C(slave_adress);
  }
  for (int i = 0; i < 2; i++) {
    if(i==0) { Serial.print(" Temp = ") ; }  
    else { Serial.print(" Humid = ") ; }       
    Serial.print(TH_data[i]);
    Serial.print("\t"); 
  }
  Serial.println( " Master");
  delay(200);
 }
