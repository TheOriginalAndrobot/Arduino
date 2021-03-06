
// Example sketch showing how to request time from controller

#include <SPI.h>
#include <MySensor.h>  
#include <Time.h>  

MySensor gw;
boolean timeReceived = false;

void setup()  
{  
  gw.begin();

  // Send the sketch version information to the gateway and Controller
  gw.sendSketchInfo("Clock", "1.0");

  // Request time from controller. 
  gw.requestTime(receiveTime);  
}

// This is called when a new time value was received
void receiveTime(unsigned long time) {
  // Ok, set incoming time 
  setTime(time);
  timeReceived = true;
}
 
void loop()     
{     
  gw.process();
  // Print time
  if (timeReceived) {
    Serial.print(hour());
    printDigits(minute());
    printDigits(second());
    Serial.print(" ");
    Serial.print(day());
    Serial.print(" ");
    Serial.print(month());
    Serial.print(" ");
    Serial.print(year()); 
    Serial.println(); 
  }
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}


