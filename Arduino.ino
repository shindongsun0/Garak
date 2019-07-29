#include <LiquidCrystal.h>
//#include <SoftwareSerial.h>
#define btn1 A8 //
버튼 1 의 아두이노 핀번호 정의
#define btn2 A9 //
버튼 2 의 아두이노 핀번호 정의
#define btn3 A10 //
버튼 3 의 아두이노 핀번호 정의
#define btn4 A11 //
버튼 4 의 아두이노 핀번호 정의
#define btn5 A12 //
버튼 5 의 아두이노 핀번호 정의
#define btn6 A13 //
버튼 6 의 아두이노 핀번호 정의
#define btn7 A14 //
버튼 7 의 아두이노 핀번호 정의
#define btn8 A15
// 버튼 8 의 아두이노 핀번호 정의
#define btn9
A5 // 버튼 9 의 아두이노 핀번호 정의
#define btn10 A4 //
버튼 10 의 아두이노 핀번호 정의
// 3:midi rx , 4:midi reset
아두이노 핀 3 번 4 번은 이미 사용중
//#define btn8 2 //
버튼 8 의 아두이노 핀번호 정의
//(SoftSerial 에서 Rx 핀으로 선언되지만 재 세팅 후 버튼용으로 사용
#define btn11 A3 //
버튼 11 의 아두이노 핀번호 정의
#define btn12 A2 //
버튼 12 의 아두이노 핀번호 정의
int max1 =0, max2 =0, m
ax3 =0, max4 =0, max5 =0, max6=0, max7=0, max8=0,max9=0, max10=0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 32, d5 = 33, d6 = 34, d7 = 35;
Liquid
Crystal lcd(rs, en, d4, d5, d6, d7);
byte note = 0; //The MIDI
연주될 note( 음계
byte resetMIDI = 4; // VS1053 Reset
용 핀
byte ledPin = 13; //MIDI
트래픽 표시용 LED
boolean bs1 = false; //
버튼 1 의 현재상태 눌림 or 안눌림
boolean bs2 = false; //
이하 , 위와 유사
boolean bs3 = false;
boolean bs4 = false;
boolean bs5 = false;
boolean bs6 = false;
boolean bs7 = false;
boolean bs8 = false;
boolean bs9 = false;
boolean bs10 = false;
boolean bs11 = false;
boolean bs12 = false;
boolean br1; //
버튼 1 상태 확인용 입력값 임시저장용
boolean br2; //
이하 , 위와 유사
boolean br3;
boolean br4;
boolean br5;
boolean br6;
boolean br7;
boolean br8;
boolean br9;
boolean br10;
boolean br11;
boole
an br12;
int patch = 0; //
악기 대응 , 연주될 악기 종류 (0~127: 기본 128 가지 선택가능
int bn1 = 60; //
버튼 1 의 note( 음계 ) 가령 도 " 0~127 까지 지정가능 정확한 음계 설정은 MIDI
관련정보참고
int bn2 = 62; //
버튼 2 의 note( 음계 ) 가령 레
int bn3 = 64; //
버튼 3 의 note( 음계 ) 가령 미
int bn4 = 65; //
버튼 4 의 note( 음계 ) 가령 파
int bn5 = 67; //
버튼 5 의 note( 음계 ) 가령 솔
int bn6 = 69; //
버튼 6 의 note( 음계 ) 가령 라
int bn7 = 71; //
버튼 7 의 note( 음계 ) 가령 시
int bn8 = 72; //
버튼 8 의 note( 음계 ) 가령 도
int bn9 = 74; //
버튼 8 의 note( 음계 ) 가령 레
int bn10 = 76; //
버튼 8 의 note( 음계 ) 가령 미
byte byteData;
void setup() {
Serial.begin(9600);
미디컨트롤을 위한 소프트웨어 시리얼을 준비합니다
Serial2.begin(31250);
// Serial3.begin(
// set up the LCD's number of columns and
lcd.begin(16, 2);
//VS1053 를 초기화하고 사용할 준비를 합니다
pinMode(resetMIDI, OUTPUT);
digitalWrite(resetMIDI, LOW);
delay(100);
digitalWrite(resetMIDI, HIGH);
delay(100);
pinMode( btn1, INPUT); // 버튼 1 입력용 핀모드를 입력모드로 전환
digitalWrite( btn1, HIGH); // 내부 PullUp 설정
pinMode( btn2, INPUT);
digitalWrite( btn2, HIGH);
pinMode( btn3, INPUT);
digitalWrite( btn3 ,
pinMode( btn4, INPUT);
digitalWrite( btn4, HIGH);
pinMode( btn5, INPUT);
digitalWrite( btn5, HIGH);
pinMode( btn6, INPUT);
digitalWrite( btn6, HIGH);
pinMode( btn7, INPUT);
digitalWrite( btn7, HIGH);
pinMode( btn8, INPUT);
digi talWrite( btn8, HIGH);
pinMode( btn9, INPUT);
digitalWrite( btn9, HIGH);
pinMode( btn10, INPUT);
digitalWrite( btn10, HIGH);
pinMode( btn11, INPUT);
digitalWrite( btn11, HIGH);
pinMode( btn12, INPUT);
digitalWrite( btn12, HIGH);
}
void loop() {
int printMax[10] = {0};
br1 = digitalRead(btn1);
br2 = digitalRead(btn2);
br3 = digitalRead(btn3);
br4 = digitalRead(btn4);
br5 = digitalRead(btn5);
br6 = digitalRead(btn6);
br7 = digitalRead(btn7);
br8 = digitalRead(btn8);
br9 = digitalRead(btn9);
br10 = digitalRead(btn10);
br11 = digitalRead(btn11);
br12 = digitalRead(btn12);
int Reading1 = analogRead(btn1);
Reading1 = map(Reading1, 235, 1000, 0, 1023);
int Reading2 = analogRead(
Reading2 = map(Reading2, 235, 1000, 0, 1023);
int Reading3 = analogRead(btn3);
Reading3 = map(Reading3, 235, 1000, 0, 1023);
int Reading4 = analogRead(btn4);
Reading4 = map(Reading4, 235, 1000, 0, 1023);
int Rea ding5 = analogRead(btn5);
Reading5 = map(Reading5, 235, 1000, 0, 1023);
int Reading6 = analogRead(btn6);
Reading6 = map(Reading6, 235, 1000, 0, 1023);
int Reading7 = analogRead(btn7);
Reading7 = map(Reading7, 235, 1000, 0, 1023);
int Reading8 = analogRead(btn8);
Reading8 = map(Reading8, 235, 1000, 0, 1023);
int Reading9 = analogRead(btn9);
Reading9 = map(Reading9, 235, 1000, 0, 1023);
int Reading10 = analogRead(b tn10);
Reading10 = map(Reading10, 226, 1000, 0, 1023);
int Reading11 = analogRead(btn11);
Reading11 = map(Reading11, 226, 1000, 0, 1023);
int Reading12 = analogRead(btn12);
Reading12 = map(Reading12, 226, 1000, 0, 1023);
값보정
if (Re ading1 < 5)
Reading1 = 0;
if (Reading2 < 5)
Reading2 = 0;
if (Reading3 < 5)
Reading3 = 0;
if (Reading4 < 5)
Reading4 = 0;
if (Reading5 < 5)
Reading5 = 0;
if (Reading6 < 5)
Reading6 = 0;
if (Reading7 < 5)
Reading7 = 0;
if (Reading8 < 5)
Reading8 = 0;
if (Reading9 < 5)
Reading9 = 0;
if (Reading10 < 5)
Reading10 = 0;
낮은 도
if( !bs1 && !br1){
// noteOff(0, bn1,
else if( !bs1 && br1){
noteOn(0, bn1, 100);
bs1 = true;
else if( bs1 && br1){
// noteOn(0, bn1,
if(Reading1 > max1){
max1 = Reading1;
else{
noteOff(0, bn1, 100);
bs1 = false;
if(max1 > 0){
printMax[0] = max1;
//Serial.print(
//Serial.
} // 2,3,4,5,6,7,8 max2, max3, max4, max5, max6, max7, max8 >0 && max1 ==0 print 0
max1 = 0;
레
if( !bs2 && !br2){
// noteOff(0, bn2,
else if( !bs2 && br2){
noteOn(0, bn2, 100);
bs2 = true;
else if( bs2 && br2){
// noteOn(0, bn1,
if(Reading2 > max2){
max2 = Reading2;
else{
noteOff(0, bn2, 100);
bs2 = false;
if(max2 > 0){
printMax[1] = max2;
//Serial.print(
//Serial.
}
max2 = 0;
미
if( !bs3 && !br3){
// noteOff(0, bn3,
else if( !bs3 && br3){
noteOn(0, bn3, 100);
bs3 = true;
else if( bs3 && br3){
// noteOn(0, bn3,
if(Reading3 > max3){
max3 = Reading3;
else{
noteOff(0, bn3, 100);
bs3 = false;
if(max3 > 0){
printMax[2] = max3;
//Serial.print(
//Serial.
}
max3 = 0;
파
if( !bs4 && !
// noteOff(0, bn4,
else if( !bs4 && br4){
noteOn(0, bn4, 100);
bs4 = true;
else if( bs4 && br4){
// noteOn(0, bn4,
if(Reading4 > max4){
max4 = Reading4;
else{
noteOff(0, bn4, 100);
bs4 = false;
if(max4 > 0){
printMax[3] = max4;
//Serial.print(
//Serial.
}
max4 = 0;
솔
if( !bs5 && !br5){
// noteOff(0, bn5,
else if( !bs5 && br5){
noteOn(0, bn5, 100);
bs5 = true;
else if( bs5 && br5){
// noteOn(0, bn5,
if(Reading5 > max5){
max5 = Reading5;
else{
noteOff(0, bn5, 100);
bs5 = false;
if(max5 > 0){
printMax[4] = max5;
//Serial.print(
//Serial.
}
max5 = 0;
라
if( !bs6 && !br6){
// noteOff(0, bn6,
else if( !bs6 && br6){
noteOn(0, bn6, 100);
bs6 = true;
else if( bs6 && br 6){
// noteOn(0, bn1,
if(Reading6 > max6){
max6 = Reading6;
else{
noteOff(0, bn6, 100);
bs6 = false;
if(max6 > 0){
printMax[5] = max6;
//Serial.print(
//Serial.
}
max6 = 0;
시
if( !bs7 && !br7){
// noteOff(0, bn7,
else if( !bs7 && br7){
noteOn(0, bn7, 100);
bs7 = true;
else if( bs7 && br7){
// noteOn(0, bn7,
if(Reading7 > max7)
max7 = Reading7;
else{
noteOff(0, bn7, 100);
bs7 = false;
if(max7 > 0){
printMax[6] = max7;
//Serial.print(
//Serial.
}
max7 = 0;
높은 도
if( !bs8 && !br8){
// noteOff(0, bn8,
else if( !bs8 && br8){
noteOn(0, bn8, 100);
bs8 = true;
else if( bs8 && br8){
// noteOn(0, bn8,
if(Reading8 > max8){
max8 = Reading8;
else{
noteOff(0, bn8, 100);
bs8 = false;
if(max8 > 0){
printMax[7] = max8;
//Serial.print(
//Serial.
}
max8 = 0;
높은 레
if( !bs9 && !br9){
// noteOff(0, bn8,
else if( !bs9 && br9){
noteOn(0, bn9, 100);
bs9 = true;
else if( bs9 && br9){
// noteOn(0, bn8,
if(Reading9 > max9){
max9 = Reading9;
else{
noteOff(0, bn9, 100);
bs9 = false;
if(max9 > 0){
printMax[8] = max9;
//Serial.print(
//Serial.
}
max9 = 0;
높은 미
if( !bs10 && !br10){
// noteOff(0, bn8,
else if( !bs10 && br10){
noteOn(0, bn10, 100);
bs10 = true;
else if( bs10 && br10){
// noteOn(0, bn8,
if(Reading10 > max10){
max10 = Reading10;
else{
noteOff(0, bn10, 100);
bs10 = false;
if(max10 > 0){
printMax[9] = max10;
//Serial.print(
//Seri al.print(";");
}
max10 = 0;
if(printMax[0] || printMax[1] || printMax[2] || printMax[3] || printMax[4] || printMax[5] || printMax[6]
|| printMax[7] || printMax[8] || printMax[
for(int i =0; i < 9; i++){
Serial.print(printMax[ i]);
Serial.print(",");
Serial.println(printMax[9]);
}
//*************** MIDI LOOPBACK
if(Serial.available() > 0)
byteData = Serial.read();
Serial2.write( byteData);
}
}
//
노트 온 미디 메세지를 송출합니다 . 버튼이 눌린상태와 같습니다
//
채널 범위는 0 15 입니다
void noteOn(byte channel, byte note, byte attack_velocity) {
talkMIDI( (0x90 | channel), note, attack_velocity);
}
//
노트 오프 미디 메세지를 송출합니다 . 버튼이 눌리지 않은 상태와 같습니다
void noteOff(byte channel, byte note,
byte release_velocity) {
talkMIDI( (0x80 | channel), note, release_velocity);
}
void talkMIDI(byte cmd, byte data1, byte data2) {
digitalWrite(ledPin, HIGH);
Serial2.write(cmd );
Serial2.write(data1 );
모든 명령은 1 바이트를 지니며 , 모든 cmds 는 0xBn 보다 2 데이터 바이트를 덜 지닙니다 .
//(sort of: http://253.ccarh.org/handout/
if( (cmd & 0xF0) <= 0xB0)
Serial2.write(data2 );
digitalWrite(ledPin, LOW);
}
