#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);//rs=13,en=12,d4=11,d5=10,d6=9,d7=8

double pulse, frequency, capacitance, inductance;
void setup(){
  lcd.begin(16,2);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  
}
void loop(){
  digitalWrite(5, HIGH);//5 number pin use for charge the circuit
  delay(5);
  digitalWrite(5,LOW);
  delayMicroseconds(100); 
  pulse = pulseIn(3,HIGH,5000);//3 number pin connect with opamp output
  if(pulse > 0.1){ 
    
    
  
  capacitance = 2.2E-6; // insert value here  //my capacitor is 2.2 uf
  
  
  frequency = 2.2E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);
  inductance *= 1E6; 


  //LCD print
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Inductance:");
  lcd.setCursor(0,1); 
  lcd.print(inductance);
  lcd.setCursor(14,1); 
  lcd.print("uH");          
  delay(10);
  }
}
