/*
  YР“С”n HTTP Client

 This example for the Arduino YР“С”n shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>
#include "LedControl.h"


LedControl lc=LedControl(12,11,10,2);

// set up a constant for the tilt switchPin
const int switchPin = 6;

// variable to hold the value of the switchPin
int switchState = 0;

// variable to hold previous value of the switchpin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

int col=0;


void setup() {
  
   pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
 // while(!Serial);
  
 int devices=lc.getDeviceCount();
  //we have to init all devices in a loop
  for(int address=0;address<devices;address++) {
    /*The MAX72XX is in power-saving mode on startup*/
    lc.shutdown(address,false);
    /* Set the brightness to a medium values */
    lc.setIntensity(address,15);
    /* and clear the display */
    lc.clearDisplay(address);
  }

}

char c;
int k=0;
int cikle=10;

void loop() {
  
  HttpClient client;
  digitalWrite(13, HIGH);
  if (cikle==10) 
  {
  
   
  // Make a HTTP request:
  np(0,1);
  client.get("https://start.humanconnection.org/cube.php");

  // if there are incoming bytes available
  // from the server, read them and print them:
  long d[20];
  int p=0;
  while (client.available())
   {
    char c = client.read();
    d[p]=(int)c-48;
    p++;
    }
 long d2=0;
 for(int i=0;i<p;i++)
 {
   int g=p-i;
   long h=1;
   for(int j=1;j<g;j++){h=h*10;}
   
   if(g!=1){d2=d2+d[i]*h;}
   else{d2=d2+d[i];}
   //Serial.print(d2);       
   //Serial.print('-');       

  // Serial.flush();
 }
  

long d1=0;
if(d2>9999)
{
  d1=d2/10000;
  d2=d2-(d1*10000);
}
 //Serial.print(d2);       
 print_n(1,d1); 
 print_n(0,d2); 
 np1(0,1);
 
  cikle=0;
  }
  cikle++;
   if(k==0){np(0,0);k=1;}
   else{np1(0,0);k=0;}
  digitalWrite(13, LOW);
  
  delay(500);
   
}


void print_n(int j,int n)
{
int i=0; 


String b =  String(n); 
if(n<1){b="----";}
else if(n<10){b="---"+b;}
else if(n<100){b="--"+b;}
else if(n<1000){b="-"+b;}
else if(n<10000){b=b;}
else{b="-999";}


if(j==0){i=0;}  
else if(j==1){j=4;}  
else if(j==2){j=0;i=1;}  
else if(j==3){j=4;i=1;}  
int q=0;

for(int y=j+3;y>=j;y--)
  {
   if(b[q]=='9'){n9(i,y);}
   if(b[q]=='8'){n8(i,y);}
   if(b[q]=='7'){n7(i,y);}
   if(b[q]=='6'){n6(i,y);}
   if(b[q]=='5'){n5(i,y);}
   if(b[q]=='4'){n4(i,y);}
   if(b[q]=='3'){n3(i,y);}
   if(b[q]=='2'){n2(i,y);}
   if(b[q]=='1'){n1(i,y);}   
   if(b[q]=='0'){n0(i,y);}
   if(b[q]=='-'){nq(i,y);}   
   q++;
  }
  
}  

void np(int i,int j) {  lc.setLed(i,j,0,true);  }
void np1(int i,int j) {  lc.setLed(i,j,0,false);  }

 void nq(int i,int j) {for(int y=0;y<8;y++) {lc.setLed(i,j,y,false);      }}
 void n1(int i,int j) {  lc.setLed(i,j,2,true);     lc.setLed(i,j,3,true);   lc.setLed(i,j,1,false); lc.setLed(i,j,4,false);lc.setLed(i,j,5,false);lc.setLed(i,j,6,false);lc.setLed(i,j,7,false);}
 void n2(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,7,true); lc.setLed(i,j,5,true); lc.setLed(i,j,4,true); lc.setLed(i,j,3,false);lc.setLed(i,j,6,false);}
 void n3(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,3,true); lc.setLed(i,j,4,true); lc.setLed(i,j,7,true); lc.setLed(i,j,5,false);lc.setLed(i,j,6,false);}
 void n4(int i,int j) {  lc.setLed(i,j,2,true);     lc.setLed(i,j,3,true);   lc.setLed(i,j,6,true); lc.setLed(i,j,7,true);  lc.setLed(i,j,1,false);lc.setLed(i,j,5,false);lc.setLed(i,j,4,false);}
 void n5(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,6,true);   lc.setLed(i,j,7,true); lc.setLed(i,j,3,true); lc.setLed(i,j,4,true); lc.setLed(i,j,2,false);lc.setLed(i,j,5,false);}
 void n6(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,6,true);   lc.setLed(i,j,5,true); lc.setLed(i,j,4,true); lc.setLed(i,j,3,true);  lc.setLed(i,j,7,true);lc.setLed(i,j,2,false);}
 void n7(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,3,true); lc.setLed(i,j,6,false);lc.setLed(i,j,7,false);lc.setLed(i,j,4,false);lc.setLed(i,j,5,false);}
 void n8(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,3,true); lc.setLed(i,j,4,true); lc.setLed(i,j,5,true); lc.setLed(i,j,6,true); lc.setLed(i,j,7,true);}
 void n9(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,3,true); lc.setLed(i,j,4,true); lc.setLed(i,j,6,true); lc.setLed(i,j,7,true);lc.setLed(i,j,5,false);}
 void n0(int i,int j) {  lc.setLed(i,j,1,true);     lc.setLed(i,j,2,true);   lc.setLed(i,j,3,true);     lc.setLed(i,j,4,true);   lc.setLed(i,j,5,true);     lc.setLed(i,j,6,true);   lc.setLed(i,j,7,false);}
 




