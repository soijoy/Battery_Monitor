#include <LiquidCrystal.h>

// ピン指定: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const float R1 = 10000.0;
const float R2 = 10000.0;

void setup() {
  analogReference(INTERNAL);
  lcd.begin(16, 2); // 16文字2行で初期化
  lcd.print("Voltage Monitor");
}

void loop() {
  int rawValue = analogRead(A0);
  
  // 1.1V基準での実電圧
  float vAtPin = (rawValue * 1.1) / 1024.0;
  
  // 【ここを調整】 0.70Vを実際のバッテリー電圧（例: 4.1V）に引き上げる倍率
  float vBat = vAtPin * 6.0; 

  lcd.setCursor(0, 1);
  lcd.print("Bat: ");
  lcd.print(vBat);
  lcd.print(" V  ");
  
  delay(500);
}

/*LCDのピン,Arduinoのピン / 接続先,役割
1 (VSS),GND,電源（ー）
2 (VDD),5V,電源（＋）
3 (V0),可変抵抗の中央ピン,コントラスト調整
4 (RS),D12,制御信号
5 (RW),GND,読み書き（常に書込でOK）
6 (E),D11,イネーブル信号
11 (D4),D5,データ線
12 (D5),D4,データ線
13 (D6),D3,データ線
14 (D7),D2,データ線
15 (A),5V（または220Ω抵抗経由）,バックライト（＋）
16 (K),GND,バックライト（ー）*/