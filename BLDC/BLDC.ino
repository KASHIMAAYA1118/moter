#include <SPI.h>
//自動で VSPI となる。SCLK= #18 , MOSI= #23 は自動アサイン。
const uint8_t cs_OLED = 17; //CS (Chip Select)
const uint8_t DCpin =  16; //OLED DC(Data/Command)
const uint8_t RSTpin =  4; //OLED Reset
const uint8_t MODEpin=19;//DISPMode切替ピン Dispが切り替わる
const uint8_t MODEpin2=36;//
const uint8_t MODEpin3=21;//
const uint8_t MODEpin4=3;//
const uint8_t ADpin=15;//ADinputPINアナログ入力ピン


const int CHANNEL_0 = 0;         //PWMのチャンネル　
const int IN1 = 22;             //どのピンから制御ピンをだすか決める
const int PWM_TIMER_BIT = 10;   // PWMの範囲(8bitなら0〜255、10bitなら0〜1023)
const int PWM_BASE_FREQ = 25000; // 周波数(Hz)
const int VALUE_MAX = 1023;      // PWMの最大値


 
void setup() {
   Serial.begin(115200);
  SSD1331_Init(cs_OLED, DCpin, RSTpin);
  pinMode(MODEpin,INPUT);//DISP切替ピン1
  pinMode(MODEpin2,INPUT);//DISP切替ピン2
  pinMode(MODEpin3,INPUT);//DISP切替ピン3
  pinMode(MODEpin4,INPUT);//DISP切替ピン4
  pinMode(ADpin,INPUT);//AD入力ピン(可変抵抗により速度調整を行う)

  pinMode(IN1, OUTPUT); // IN1
  ledcSetup(CHANNEL_0, PWM_BASE_FREQ, PWM_TIMER_BIT);
  ledcAttachPin(IN1, CHANNEL_0);

  Display_Clear(0, 0, 95, 63);
  CommandWrite(0xAE); //Set Display Off
  delay(100);
  CommandWrite(0xA0); //Remap & Color Depth setting　
  CommandWrite(0b00110010); //A[7:6] = 00; 256 color.
  
}

void loop() { 


  if(digitalRead(MODEpin)==LOW)
  {

  if(digitalRead(MODEpin2)==HIGH)
  {
    Wifimode(); //20181214Wifiでのモード利用になります
  }
  else
  {
  dryermode();    //Dryerモードでは、ドライヤーの制御が行えるようにしておく
  }
  
  }
  else if(digitalRead(MODEpin)==HIGH)
  {
    disp();
  }
}



void Wifimode()
{

}

void dryermode()
{

  
  int i, j;
  uint8_t R, G, B, Dot1, Dot2,BLK;
 

  R=2; G=4; B=7; //256 color : R (0-7), G (0-7), B (0-3)
  Dot1 = (R << 5) | (G << 2) | B;
  R=0; G=0; B=0; //256 color : R (0-7), G (0-7), B (0-3)
  BLK = (R << 5) | (G << 2) | B;


int advalue=analogRead(ADpin);
//Serial.print(advalue);

if(advalue>=0&&advalue<=650)
 {

ledcWrite(CHANNEL_0, 512);

  
   for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(j>=41&&j<=64)
      {
       if(i>=9&&i<=14)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }else
      {
      DataWrite(BLK);
      }
                      }
                     }

 
 }
 else if(advalue>=651&&advalue<=767)
 {

ledcWrite(CHANNEL_0, 576);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
     
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      } 
      else
      {
      DataWrite(BLK);
      }
                      }
                     }





  
 }
 else if(advalue>=768&&advalue<=904)
 {
ledcWrite(CHANNEL_0, 640);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }






  
 }
  else if(advalue>=905&&advalue<=1041)
 {

ledcWrite(CHANNEL_0, 704);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }











  
  
 }
  else if(advalue>=1042&&advalue<=1178)
 {
ledcWrite(CHANNEL_0, 768);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=45&&i<=50)
      {
        if(j>=21&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }













  
 }
  else if(advalue>=1179&&advalue<=1907)
 {
ledcWrite(CHANNEL_0, 832);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=45&&i<=50)
      {
        if(j>=21&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
               else if(i>=54&&i<=59)
      {
        if(j>=16&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }




  
  
 }
  else if(advalue>=1908&&advalue<=2637)
 {

ledcWrite(CHANNEL_0, 896);
for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=45&&i<=50)
      {
        if(j>=21&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
               else if(i>=54&&i<=59)
      {
        if(j>=16&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
        else if(i>=63&&i<=68)
      {
        if(j>=11&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }





  
 }
  else if(advalue>=2638&&advalue<=3665)
 {
ledcWrite(CHANNEL_0, 960);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

       if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=45&&i<=50)
      {
        if(j>=21&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
               else if(i>=54&&i<=59)
      {
        if(j>=16&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
        else if(i>=63&&i<=68)
      {
        if(j>=11&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=72&&i<=77)
      {
        if(j>=6&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }

 }
 else if(advalue>=3366&&advalue<=4096)
 {
  ledcWrite(CHANNEL_0, 1024);

for(j=0; j<64; j++){
    for(i=0; i<96; i++){

        if(i>=9&&i<=14)
      {
       if(j>=41&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=18&&i<=23)
      {
        if(j>=36&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
       else if(i>=27&&i<=32)
      {
        if(j>=31&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else if(i>=36&&i<=41)
      {
        if(j>=26&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=45&&i<=50)
      {
        if(j>=21&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
               else if(i>=54&&i<=59)
      {
        if(j>=16&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
        else if(i>=63&&i<=68)
      {
        if(j>=11&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      else if(i>=72&&i<=77)
      {
        if(j>=6&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
           else if(i>=81&&i<=86)
      {
        if(j>=2&&j<=64)
         {DataWrite(Dot1);}
         else
         {DataWrite(BLK);} 
      }
      
      else
      {
      DataWrite(BLK);
      }
                      }
                     }







  
 }


 CommandWrite(0xAF); //Set Display On
  delay(100); //0xAFコマンド後最低100ms必要
  Brightness_FadeIn(0);
 // delay(100);
  //Brightness_FadeOut(4);
 // delay(10);


 /*
  ledcWrite(CHANNEL_0, 500);
  delay(1000);
  ledcWrite(CHANNEL_0,1023);
  delay(1000);
  ledcWrite(CHANNEL_0,0);
  delay(1000);
*/
  

  

}





void disp(){
  int i, j;
  uint8_t R, G, B, Dot1, Dot2,BLK;
  Display_Clear(0, 0, 95, 63);
 
  CommandWrite(0xAE); //Set Display Off
  delay(1000);
 
  CommandWrite(0xA0); //Remap & Color Depth setting　
  CommandWrite(0b00110010); //A[7:6] = 00; 256 color.
 
  R=7; G=0; B=0; //256 color : R (0-7), G (0-7), B (0-3)
  Dot1 = (R << 5) | (G << 2) | B;

  R=7; G=7; B=7; //256 color : R (0-7), G (0-7), B (0-3)
  BLK = (R << 5) | (G << 2) | B;
  
 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
  
 for(j=0; j<64; j++){
    for(i=0; i<96; i++){
    
              if(j>=0&&j<16)
               {
                   DataWrite(BLK);
                }

    if(j>=16&&j<=20)
    {
      if((i>=0&&i<7)||(i>30&&i<36)||(i>59&&i<68)||(i>30&&i<36)||(i>91&&i<96))
    {DataWrite(BLK);}
    else
    {DataWrite(Dot1);} 
    }

   if(j>=21&&j<=26)
    {
      if((i>=15&&i<20)||(i>=36&&i<=40)||(i>=68&&i<=72))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }

     if(j>=27&&j<=33)
    {
      if((i>=15&&i<=19)||(i>=36&&i<=57)||(i>=68&&i<=89))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }


         if(j>=34&&j<=42)
    {
      if((i>=15&&i<=19)||(i>=36&&i<=40)||(i>=85&&i<=89))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }
        if(j>=43&&j<=48)
    {
      if((i>=15&&i<=19)||(i>=36&&i<=57)||(i>=68&&i<=89))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }

    if(j>=49&&j<=63)
    {
      
    DataWrite(BLK);
 
    }

                   }
                    }
                      
CommandWrite(0xAF); //Set Display On
  delay(110); //0xAFコマンド後最低100ms必要
  Brightness_FadeIn(4);
  delay(1000);
  //Brightness_FadeOut(4);
  delay(1000);

 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
 for(j=0; j<64; j++){
    for(i=0; i<96; i++){
    
              if(j>=0&&j<=14)
               {
                   DataWrite(BLK);
                }

    if(j>=15&&j<=22)
    {
      if((i>=6&&i<=28)||(i>=36&&i<=57)||(i>=66&&i<=91))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }

   if(j>=23&&j<=42)
    {
      if((i>=6&&i<11)||(i>=36&&i<=40)||(i>=53&&i<=57)||(i>=66&&i<=71)||(i>=76&&i<=81)||(i>=86&&i<=91))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }


  if(j>=43&&j<=50)
    {
      if((i>=6&&i<=28)||(i>=36&&i<=57)||(i>=66&&i<=71)||(i>=76&&i<=81)||(i>=86&&i<=91))
    {DataWrite(Dot1);}
    else
    {DataWrite(BLK);} 
    }

    

    if(j>=51&&j<=63)
    {
      
    DataWrite(BLK);
 
    }

                   }
                    }

                    
                      
CommandWrite(0xAF); //Set Display On
  delay(110); //0xAFコマンド後最低100ms必要
//  Brightness_FadeIn(4);
  delay(1000);
  Brightness_FadeOut(4);
  delay(1000);
  
 
 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
  
  
 /*
  CommandWrite(0xAF); //Set Display On
  delay(110); //0xAFコマンド後最低100ms必要
  Brightness_FadeIn(4);
  delay(1000);
  Brightness_FadeOut(4);
  delay(1000);
  CommandWrite(0xAE); //Set Display Off
  delay(1000);
 
  Brightness_FadeIn(0);
  Display_Clear(0, 0, 95, 63);
  CommandWrite(0xAF); //Set Display On
  delay(110); //0xAFコマンド後最低100ms必要
  R=0; G=7; B=0; //256 color : R (0-7), G (0-7), B (0-3)
  Dot1 = (R << 5) | (G << 2) | B;
  for(j=0; j<64; j++){
    for(i=0; i<96; i++){
      DataWrite(Dot1);
    }
  }
  delay(2000);
 
  R=0; G=0; B=3; //256 color : R (0-7), G (0-7), B (0-3)
  Dot1 = (R << 5) | (G << 2) | B;
  for(j=0; j<64; j++){
    for(i=0; i<96; i++){
      DataWrite(Dot1);
    }
  }
  delay(2000);
 
  Display_Clear(0, 0, 95, 63);
 
  CommandWrite(0xA0); //Remap & Color Depth setting　
    CommandWrite(0b01110010); //A[7:6] = 01; 65k color format
 
  R=31; G=63; B=31; //65k color : R (0-31), G (0-63), B (0-31)
  Dot1 = (R << 3) | (G >> 3);
  Dot2 = (G << 5) | B;
  for(j=0; j<64; j++){
    for(i=0; i<96; i++){
      DataWrite(Dot1); //65k colorモードでは、２バイトデータを送る
      DataWrite(Dot2);
    }
  }
  delay(2000);

  */
 
  Display_Clear(0, 0, 95, 63);
  Drawing_Line(0, 0, 95, 63, 31, 0, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Line(95, 0, 0, 63, 0, 31, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Line(48, 0, 48, 63, 0, 0, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);

 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
 
  for(i=0; i<63; i=i+5){
    Drawing_Line(i, 63, 95, 63-i, 0, i, 31);
  }
  delay(2000);
 
  Display_Clear(0, 0, 95, 63);
  Drawing_Rectangle_Line(20, 20, 40, 40, 31, 0, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Rectangle_Line(0, 0, 60, 60, 0, 31, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Rectangle_Line(70, 10, 80, 63, 0, 0, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Display_Clear(0, 0, 95, 63);
  Drawing_Rectangle_Fill(0, 0, 60, 60, 0, 31, 0, 31, 0, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Rectangle_Fill(20, 20, 40, 40, 0, 0, 31, 0, 31, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 
  Drawing_Rectangle_Fill(70, 10, 80, 63, 31, 63, 31, 0, 0, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);

   if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
 
  Display_Clear(0, 0, 95, 63);
  CommandWrite(0xA0); //Remap & Color Depth setting　
    CommandWrite(0b00110010); //A[7:6] = 00; 256 color.
 
  Drawing_Circle_Line_256color(31, 31, 31, 7, 0, 0); //Red(0-7), Green(0-7), Blue(0-3)
  delay(2000);
  Drawing_Circle_Line_256color(50, 31, 20, 0, 7, 0); //Red(0-7), Green(0-7), Blue(0-3)
  delay(2000);
  Drawing_Circle_Line_256color(70, 31, 10, 0, 0, 3); //Red(0-7), Green(0-7), Blue(0-3)
  delay(2000);
   if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
 
  Display_Clear(0, 0, 95, 63);
  Drawing_Circle_Fill(31, 31, 31, 31, 0, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
  Drawing_Circle_Fill(50, 31, 20, 0, 63, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
  Drawing_Circle_Fill(70, 31, 10, 0, 0, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(2000);
 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }

 
  Display_Clear(0, 0, 95, 63);
  CommandWrite(0xA0); //Remap & Color Depth setting　
    CommandWrite(0b01110010); //A[7:6] = 01; 65k color format
 
  Drawing_Circle_Line_65kColor(31, 31, 31, 0, 63, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(1000);
  Drawing_Circle_Line_65kColor(50, 31, 20, 31, 0, 31); //Red(0-31), Green(0-63), Blue(0-31)
  delay(1000);
  Drawing_Circle_Line_65kColor(70, 31, 10, 31, 31, 0); //Red(0-31), Green(0-63), Blue(0-31)
  delay(1000);

 if(digitalRead(MODEpin)==LOW)
  {
  return;
  }
 
  Copy(60, 21, 80, 41, 0, 0);
  Copy(60, 21, 80, 41, 75, 0);
  Copy(60, 21, 80, 41, 0, 43);
 
  for(i=0; i<76; i++){
    Copy(60, 21, 80, 41, 75-i, 43);
    if(i>0){
      Display_Clear(96-i, 43, 95, 63);
    }
    delay(20);
  }
 
  delay(2000);


  }










 
//*********** SSD1331 初期化****************************
void SSD1331_Init(uint8_t CS, uint8_t DC, uint8_t RST){  
  pinMode(RST, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(CS, OUTPUT);
 
  digitalWrite(RST, HIGH);
  digitalWrite(RST, LOW);
  delay(1);
  digitalWrite(RST, HIGH);
 
  digitalWrite(CS, HIGH);
  digitalWrite(DC, HIGH);
 
  SPI.begin(); //VSPI
  SPI.setFrequency(5000000); //SSD1331 のSPI Clock Cycle Time 最低150ns
  SPI.setDataMode(SPI_MODE2); //オシロで測ると、ESP32のSPI_MODE2はMODE3だったので要注意
 
  CommandWrite(0xAE); //Set Display Off
  CommandWrite(0xA0); //Remap & Color Depth setting　
    CommandWrite(0b00110010); //A[7:6] = 00; 256 color. A[7:6] = 01; 65k color format
  CommandWrite(0xA1); //Set Display Start Line
    CommandWrite(0);
  CommandWrite(0xA2); //Set Display Offset
    CommandWrite(0);
  CommandWrite(0xA4); //Set Display Mode (Normal)
  CommandWrite(0xA8); //Set Multiplex Ratio
    CommandWrite(63); //15-63
  CommandWrite(0xAD); //Set Master Configration
    CommandWrite(0b10001110); //a[0]=0 Select external Vcc supply, a[0]=1 Reserved(reset)
  CommandWrite(0xB0); //Power Save Mode
    CommandWrite(0x1A); //0x1A Enable power save mode. 0x00 Disable
  CommandWrite(0xB1); //Phase 1 and 2 period adjustment
    CommandWrite(0x74);
  CommandWrite(0xB3); //Display Clock DIV
    CommandWrite(0xF0);
  CommandWrite(0x8A); //Pre Charge A
    CommandWrite(0x81);
  CommandWrite(0x8B); //Pre Charge B
    CommandWrite(0x82);
  CommandWrite(0x8C); //Pre Charge C
    CommandWrite(0x83);
  CommandWrite(0xBB); //Set Pre-charge level
    CommandWrite(0x3A);
  CommandWrite(0xBE); //Set VcomH
    CommandWrite(0x3E);
  CommandWrite(0x87); //Set Master Current Control
    CommandWrite(0x06);
  CommandWrite(0x15); //Set Column Address
    CommandWrite(0);
    CommandWrite(95);
  CommandWrite(0x75); //Set Row Address
    CommandWrite(0);
    CommandWrite(63);
  CommandWrite(0x81); //Set Contrast for Color A
    CommandWrite(255);
  CommandWrite(0x82); //Set Contrast for Color A
    CommandWrite(255);
  CommandWrite(0x83); //Set Contrast for Color A
    CommandWrite(255);
  CommandWrite(0xAF); //Set Display On
  delay(110); //0xAFコマンド後最低100ms必要
}
//***********ディスプレイ消去****************************
void Display_Clear(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1){
  delayMicroseconds(500); //クリアーコマンドは400μs 以上の休止期間が必要かも
  CommandWrite(0x25); //Clear Window
    CommandWrite(x0); //Column Address of Start
    CommandWrite(y0); //Row Address of Start
    CommandWrite(x1); //Column Address of End
    CommandWrite(y1); //Row Address of End
  delayMicroseconds(800); //ここの間隔は各自調節してください。
}
//***********画面明るさフェードイン**********************
void Brightness_FadeIn(uint8_t interval){
  for(int brightness = 0; brightness < 256; brightness++){
    CommandWrite(0x81); //Set Contrast for Color A
      CommandWrite(brightness);
    CommandWrite(0x82); //Set Contrast for Color A
      CommandWrite(brightness);
    CommandWrite(0x83); //Set Contrast for Color A
      CommandWrite(brightness);
    delay(interval);
  }
}
//***********画面明るさフェードアウト********************
void Brightness_FadeOut(uint8_t interval){
  for(int brightness = 255; brightness >= 0; brightness--){
    CommandWrite(0x81); //Set Contrast for Color A
      CommandWrite(brightness);
    CommandWrite(0x82); //Set Contrast for Color A
      CommandWrite(brightness);
    CommandWrite(0x83); //Set Contrast for Color A
      CommandWrite(brightness);
    delay(interval);
  }
}
//************ 256色カラー 1ピクセル 描画 *****************
void Drawing_Pixel_256color(uint8_t x0, uint8_t y0, uint8_t R, uint8_t G, uint8_t B){
  //R (0-7), G (0-7), B (0-3)
  CommandWrite(0x15); //Set Column Address
    CommandWrite(x0);
    CommandWrite(x0);
  CommandWrite(0x75); //Set Row Address
    CommandWrite(y0);
    CommandWrite(y0);
 
  uint8_t Dot = (R << 5) | (G << 2) | B;
 
  DataWrite(Dot);
}
//************ 65000色カラー 1ピクセル 描画 *****************
void Drawing_Pixel_65kColor(uint8_t x0, uint8_t y0, uint8_t R, uint8_t G, uint8_t B){
  uint8_t Dot1, Dot2;
  CommandWrite(0x15); //Set Column Address
    CommandWrite(x0);
    CommandWrite(x0);
  CommandWrite(0x75); //Set Row Address
    CommandWrite(y0);
    CommandWrite(y0);
 
  Dot1 = (R << 3) | (G >> 3);
  Dot2 = (G << 5) | B;
 
  DataWrite(Dot1);
  DataWrite(Dot2);
}
//************ 65000色　線　描画******************************
void Drawing_Line(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B){
  //Line_R (0-31), Line_G (0-63), Line_B (0-31)
  uint8_t R, B;
  R = Line_R <<1;
  B = Line_B <<1;
 
  CommandWrite(0x21);
    CommandWrite(X0);
    CommandWrite(Y0);
    CommandWrite(X1);
    CommandWrite(Y1);
    CommandWrite(R);
    CommandWrite(Line_G);
    CommandWrite(B);
}
//************ 65000色　四角　線描画***************************
void Drawing_Rectangle_Line(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B){
  //Line_R (0-31), Line_G (0-63), Line_B (0-31)
  uint8_t R, B;
  R = Line_R <<1;
  B = Line_B <<1;
 
  CommandWrite(0x26); //Fill Enable or Disable
    CommandWrite(0b00000000); //A0=1 Fill Disable
     
  CommandWrite(0x22); //Drawing Rectangle
    CommandWrite(X0); //Column Address of Start
    CommandWrite(Y0); //Row Address of Start
    CommandWrite(X1); //Column Address of End
    CommandWrite(Y1); //Row Address of End
    CommandWrite(R);
    CommandWrite(Line_G);
    CommandWrite(B);
    CommandWrite(0);
    CommandWrite(0);
    CommandWrite(0);
}
//************ 65000色　四角　塗りつぶし描画***************************
void Drawing_Rectangle_Fill(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B, uint8_t Fill_R, uint8_t Fill_G, uint8_t Fill_B){
  //Line_R (0-31), Line_G (0-63), Line_B (0-31)
  //Fill_R (0-31), Fill_G (0-63), Fill_B (0-31)
  uint8_t lineR, lineB, fillR, fillB;
  lineR = Line_R <<1;
  lineB = Line_B <<1;
  fillR = Fill_R <<1;
  fillB = Fill_B <<1;
   
  CommandWrite(0x26); //Fill Enable or Disable
    CommandWrite(0b00000001); //A0=0 Fill Enable
 
  CommandWrite(0x22); //Drawing Rectangle
    CommandWrite(X0); //Column Address of Start
    CommandWrite(Y0); //Row Address of Start
    CommandWrite(X1); //Column Address of End
    CommandWrite(Y1); //Row Address of End
    CommandWrite(lineR);
    CommandWrite(Line_G);
    CommandWrite(lineB);
    CommandWrite(fillR);
    CommandWrite(Fill_G);
    CommandWrite(fillB);
}
//************* 256色カラー　円 線描画***********************
void Drawing_Circle_Line_256color(uint8_t x0, uint8_t y0, uint16_t r, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B){
  //Line_R (0-7), Line_G (0-7), Line_B (0-3)
  uint8_t x1, y1;
 
  for(int i=0; i<360; i++){
    x1 = round((float)(x0 + (r * cos(radians(i)))));
    y1 = round((float)(y0 + (r * sin(radians(i)))));
    Drawing_Pixel_256color(x1, y1, Line_R, Line_G, Line_B);
  }
  delay(1);
  //描画範囲を元に戻して置く
  CommandWrite(0x15); //Set Column Address
      CommandWrite(0);
      CommandWrite(95);
    CommandWrite(0x75); //Set Row Address
      CommandWrite(0);
      CommandWrite(63);
}
//************* 65000色カラー　円 線描画***********************
void Drawing_Circle_Line_65kColor(uint8_t x0, uint8_t y0, uint16_t r, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B){
  uint8_t x1, y1;
 
  for(int i=0; i<360; i++){
    x1 = round((float)(x0 + (r * cos(radians(i)))));
    y1 = round((float)(y0 + (r * sin(radians(i)))));
    Drawing_Pixel_65kColor(x1, y1, Line_R, Line_G, Line_B);
  }
  delay(1);
  //描画範囲を元に戻して置く
  CommandWrite(0x15); //Set Column Address
      CommandWrite(0);
      CommandWrite(95);
    CommandWrite(0x75); //Set Row Address
      CommandWrite(0);
      CommandWrite(63);
}
//************* 65000色カラー　円塗りつぶし描画*****************
void Drawing_Circle_Fill(uint8_t x0, uint8_t y0, uint16_t r, uint8_t Line_R, uint8_t Line_G, uint8_t Line_B){
  //Line_R (0-31), Line_G (0-63), Line_B (0-31)
  uint8_t R, B;
  R = Line_R <<1;
  B = Line_B <<1;
 
  uint8_t x1, y1;
 
  for(int i=0; i<360; i++){
    x1 = round((float)(x0 + (r * cos(radians(i)))));
    y1 = round((float)(y0 + (r * sin(radians(i)))));
    Drawing_Line(x0, y1, x1, y1, R, Line_G, B);
  }
}
//********** 範囲コピー *********************************
void Copy(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t X, uint8_t Y){
  CommandWrite(0x23); //Copy　
    CommandWrite(x0); //コピーする範囲水平始点
    CommandWrite(y0); //コピーする範囲垂直始点
    CommandWrite(x1); //コピーする範囲水平終点
    CommandWrite(y1); //コピーする範囲垂直終点
    CommandWrite(X); //コピー先の左上X点
    CommandWrite(Y); //コピー先の左上Y点
}
//********** SPI コマンド出力 ****************************
void CommandWrite(uint8_t b){
  digitalWrite(cs_OLED, LOW);
  digitalWrite(DCpin, LOW);//DC
  SPI.write(b);
  digitalWrite(cs_OLED, HIGH);
}
//********** SPI データ出力 ****************************
void DataWrite(uint8_t b){
  digitalWrite(cs_OLED, LOW);
  digitalWrite(DCpin, HIGH);//DC
  SPI.write(b);
  digitalWrite(cs_OLED, HIGH);
}
