#include <Fat16.h>
#include <Fat16Util.h>
#include <NewSPI.h>
#include <arduino.h>
#include "pins_config.h"
#include "vs10xx.h"
#include "newSDLib.h"
#include "MusicPlayer.h"

MusicPlayer mp;
int DXSensVal=0;
unsigned int s=0;

void setup(){
  Serial.begin(9600);
  mp.begin();
}

void loop(){
  DXSensVal=analogRead(4);
  //Serial.println(DXSensVal);
  if(DXSensVal>300){
    digitalWrite(8,HIGH);
    mp.setPlayMode(MODE_NORMAL);
    s=random(0,4);
    //mp.creatPlaylist();
    if(s<=1){
      mp.playSong("Stranger.MP3"); //This is a specific file on the sd card
    }
    if(s==2){
      mp.playSong("theclaw.mp3");
    }
    if(s>=3){
      mp.playSong("bozo.mp3");
    }
    delay(2000);
  }
  delay(100);
  digitalWrite(8,LOW);
  DXSensVal=0;
}
