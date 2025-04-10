#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050.h>
#include <Tone.h>

// LCD config
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust I2C address if needed
MPU6050 mpu;

// Flex sensors
const int flexPin1 = A0;
const int flexPin2 = A1;

// Buzzer setup
const int buzzerPin = 9;
Tone tonePlayer;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // LCD setup
  lcd.begin();
  lcd.backlight();
  lcd.print("AirNote Ready");

  // MPU6050 setup
  mpu.initialize();
  if (!mpu.testConnection()) {
    lcd.clear();
    lcd.print("MPU FAIL!");
    while (1); // Halt if sensor fails
  }

  tonePlayer.begin(buzzerPin);
  delay(2000);
  lcd.clear();
}

void loop() {
  int flex1 = analogRead(flexPin1);
  int flex2 = analogRead(flexPin2);

  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Map flex sensor values to tone pitch and duration
  int pitch = map(flex1, 500, 800, 262, 523); // C4 to C5
  int duration = map(flex2, 500, 800, 100, 400); // Short to long note

  // Display note info on LCD
  lcd.setCursor(0, 0);
  lcd.print("Pitch: "); lcd.print(pitch);
  lcd.setCursor(0, 1);
  lcd.print("Dur: "); lcd.print(duration); lcd.print("ms ");

  // Play sound
  tonePlayer.play(pitch, duration);
  delay(duration + 100); // Wait for sound to complete
}
