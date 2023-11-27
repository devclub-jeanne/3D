#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  mpu.initialize();

  // Vérification de la connexion
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful");
  } else {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
}

void loop() {
  // Lire les valeurs de l'accéléromètre
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Afficher les valeurs X et Y
  Serial.print("X: ");
  Serial.print(ax);
  Serial.print("\tY: ");
  Serial.println(ay);

  delay(500); // Ajouter un délai pour éviter un affichage trop rapide
}