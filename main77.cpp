#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h> 
int button = 0;
int button1 = 0;
int button2=0;
static int n = 0 ;
 static int count1;
 static int count2=0;
 static int count3=0;
 static int count4=0;


#define SegA (1<<PD1)
#define SegB (1<<PD2)
#define SegC (1<<PD3)
#define SegD (1<<PD4)
#define SegE (1<<PD5)
#define SegF (1<<PD6)
#define SegG (1<<PD7)
#define SegP (1<<PD0)

void rensa(){    //break for button
    PORTB=PORTB &~ 1 <<PB5;
    PORTB=PORTB &~ 1 <<PB0;
    PORTB=PORTB &~1 <<PB3;
    PORTB=PORTB &~ 1 << PB4;
}

//numbers
void Zero(){
PORTD |= SegA;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegE;
PORTD |= SegF;
PORTD |= SegG;
PORTD |= SegP;
}
void One(){

PORTD |= SegC;
PORTD |= SegD;

PORTD |= SegP;
}
void Two(){
PORTD |= SegB;
PORTD |= SegC;
PORTD |=SegE;
PORTD |=SegF;
PORTD |= SegG;
PORTD |= SegP;
}
void Three(){

PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |=SegE;

PORTD |= SegG;
PORTD |= SegP;
}

void Four(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegP;
}
 void Five(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegD;
PORTD |=SegE;
PORTD |= SegG;
PORTD |= SegP;
 }
 void Six(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegD;
PORTD |=SegE;
PORTD |=SegF;
PORTD |=SegG;
PORTD |= SegP;
 }

 void Seven(){

PORTD |= SegC;
PORTD |= SegD;
PORTD |=SegG;
PORTD |= SegP;
 }

 void Eight(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegE;
PORTD |= SegF;
PORTD |= SegG;
PORTD |= SegP;
 }

 void Nine(){
PORTD |= SegA;
PORTD |= SegB;
PORTD |= SegC;
PORTD |= SegD;
PORTD |= SegG;
PORTD |= SegP;
}

// take a number
void Take(int x){
switch (x)
{
case 1: One();
break;
case 2: Two();
break;
case 3:
Three();
break;
case 4: 
Four();
break;
case 5: 
Five();
break;
case 6: 
Six();
break;
case 7 :
Seven();
break;
case 8:
Eight();
break;
case 9:
Nine();
break;
default:
Zero();
  break;
}
}
void TakeDigit(int x, int y){

switch (x)
{

case 1:
PORTB=PORTB &~ 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB3;
PORTB=PORTB | 1 <<PB4;
  break;
case 2:
PORTB=PORTB &~ 1 <<PB0;
PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB3;
PORTB=PORTB | 1 <<PB4;
  break;
case 3:
  PORTB=PORTB &~ 1 <<PB3;
   PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB4;
  break;
case 4:
  PORTB=PORTB &~ 1 <<PB4;
   PORTB=PORTB | 1 <<PB5;
PORTB=PORTB | 1 <<PB0;
PORTB=PORTB | 1 <<PB3;
  break;

default:
  break;
 
}
 Take(y);
}

void TurnOffAll(){
  PORTB=0;
  PORTD=0;
}

void start(int x, int y){      // Start Time
  if(x==1){
  TurnOffAll();
  TakeDigit(1,y);
  _delay_ms(2);
  
  }
  if(x==2){
  TurnOffAll();
  TakeDigit(2,y);
  _delay_ms(2);
  }
   if(x==3){
  TurnOffAll();
  TakeDigit(3,y);
  _delay_ms(2);
  }
   if(x==4){
  TurnOffAll();
  TakeDigit(4,y);
  _delay_ms(2);
  }
  _delay_ms(1);
  
}
void StartHour(){  //HH-MM
  TurnOffAll();
  start(4,count4);
  TurnOffAll();
  start(3,count3);
  TurnOffAll();
  
}

void StartMinute(){ //HH-MM  

  TurnOffAll();
  start(1,count1);
  _delay_ms(2);
  TurnOffAll();
  start(2,count2);
  _delay_ms(2);
}


void Tuta(){  //PeeeeeB ^_^
  while(1){
  PORTB |= 1 << PB1;
  _delay_ms(200);
  PORTB &=~ 1 << PB1;
  break;
  }
}

void TwinkLeft(){
  Tuta();
while (1)
{
StartHour();
if(PINC & ( 1 << PC2)){
  _delay_ms(400);
if(button2 < 1 ){
if(count4<2 || count3 < 10){
count3++;
}
if(count3 == 10){
count4++;
count3=0;
}
if(count4 == 2 && count3 == 4){
count4=0;
count3=0;
}

}
}
else{
button2=0;
}

if(PINC & 1 << PC3){
break;
}
}

}

 void TwinkRight(){   //MINUTES
 while (1)
{
  
StartMinute();
if(PINC & ( 1 << PC2)){
_delay_ms(400);
if(button1 < 1 ){
if(count1<9 && count2 < 6){  
count1++;
}
else if(count1 == 9){ //XX-X9
count2++;
count1=0;
}
else if(count1 == 0 && count2 == 6){   //XX-60
count1=0; 
count2=0;
}
}

}
else{
button1=0;
}
if((PINC & 1 << PC3) && (PINC & 1 << PC2) ){
  break;
}

}
 }
void InMinute(){
  for(int i=0; i<60; i++){
    _delay_ms(1000);
}
}

int main(){
    DDRB=255; 
    DDRD=255;
    DDRC=0;
    int count=0;
    n=0;
    
while (1)
{
  
start(4,count4);
_delay_ms(2); 
start(3,count3); 
_delay_ms(2);
start(2,count2 = n/1000);
_delay_ms(2); 
start(1,count1 = ((n % 1000) / 100)); 
_delay_ms(2);
n++;
if (PINC & 1 << PC2 && PINC & 1 << PC3){
if(button < 1 ){
if(count<9){
  TwinkLeft();
  TwinkRight();
  
count++;
}
else{
count = 0;
}
button=1;
}
}
else{
button=0;
}
}



  return 0;
}