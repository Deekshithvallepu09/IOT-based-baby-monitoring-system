#include <LiquidCrystal.h>  
#include <Servo.h>  
int buzz = 10; 
int led = 9; 
int c_crit = 40;  
String temp_status = "Normal "; 
const int TMP36 = A0; 
const int soilMoisturePin = A2; 
const int gasSensorPin = A1;  
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  
Servo myServo; 
float temp;  
  
void setup() {   
    pinMode(TMP36, INPUT); 
    pinMode(soilMoisturePin, INPUT); 
    pinMode(gasSensorPin, INPUT); 
    pinMode(buzz, OUTPUT); 
    pinMode(led, OUTPUT);  
    myServo.attach(6); // Servo connected to D6  
    lcd.begin(16, 2); 
    lcd.display();  
}  
  
void loop() {   
 // Read temperature 
temp = analogRead(TMP36); 
temp = ((float)temp * 5 / 1023) - 0.5;  
temp = temp * 100;  
  
  // Read soil moisture and convert to percentage (Reversed) 
int soilMoistureRaw = analogRead(soilMoisturePin);  
int soilMoisturePercent = map(soilMoistureRaw, 300, 1023, 0, 100); 
 // Reversed Mapping 
soilMoisturePercent = constrain(soilMoisturePercent, 0, 100);  
  
  // Read gas sensor and convert to percentage 
int gasValueRaw = analogRead(gasSensorPin); 
int gasValuePercent = map(gasValueRaw, 0, 1023, 0, 100); 
gasValuePercent = constrain(gasValuePercent, 0, 100);  
  
  // Display values on LCD  
  lcd.clear();  
 lcd.setCursor(0, 0); 
 lcd.print("Temp: "); 
 lcd.print(temp);  
 lcd.print("C");  
 lcd.setCursor(0, 1); 
 lcd.print("Soil:"); 
 lcd.print(soilMoisturePercent); 
 lcd.print("% Gas:"); 
 lcd.print(gasValuePercent); 
 lcd.print("%");  
  
 delay(2000);  
  
  // High temperature actions 
if (temp >= c_crit) {     
temp_status = "Not Normal!";      
digitalWrite(led, HIGH);      
playHappySleepSound(); 
 // Play happy sleep melody  
 moveServoFor10Sec(); // Move servo for 10 sec  
  } else {      
 temp_status = "Normal ";      
 digitalWrite(led, LOW);  
  }  
  
  // Soil moisture alert  
  if (soilMoisturePercent > 40) { // Adjust threshold as needed      
  beepBuzzer(3); // Beep buzzer for 3 sec  
  }  
  
  // Gas detection alert  
  if (gasValuePercent > 30) { // Adjust threshold as needed      
  beepBuzzer(2); // Beep buzzer     twice  
  }  
}  
  
// Function to move servo for 10 seconds  
void moveServoFor10Sec() {    
unsigned long startTime = millis();    
while (millis() - startTime < 10000) {      
myServo.write(180);      
delay(500);      
myServo.write(0);      
delay(500);  
  }  
} 
// Function to beep buzzer  
void beepBuzzer(int seconds) {    
unsigned long startTime = millis();    
while (millis() - startTime < (seconds * 1000)) {      
tone(buzz, 1000, 200); // Small beep      
delay(400);  
  }  
}  
  
// Function to play happy sleep sound  
void playHappySleepSound() {  
int melody[] = {262, 294, 330, 349, 392}; // Example melody notes    
int noteDurations[] = {300, 300, 300, 300, 300};  
    
  for (int i = 0; i < 5; i++) {  
  tone(buzz, melody[i], noteDurations[i]);     
 delay(noteDurations[i] + 50);  
  }  
  noTone(buzz);  
}  