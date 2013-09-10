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
  Serial.println(DXSensVal);
  if(DXSensVal>300){
    digitalWrite(8,HIGH);
    mp.setPlayMode(MODE_NORMAL);
    s=random(0,4);
    Serial.println(s);
    //mp.creatPlaylist();
    if(s<=1){
      Serial.println("in 1");
      mp.playSong("Stranger.MP3");
    }
    if(s==2){
      Serial.println("in 2");
      mp.playSong("theclaw.mp3");
    }
    if(s>=3){
      Serial.println("in 4");
      mp.playSong("bozo.mp3");
    }
    delay(2000);
  }
  delay(100);
  digitalWrite(8,LOW);
  DXSensVal=0;
}
