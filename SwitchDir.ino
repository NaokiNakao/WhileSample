/*Este proyecto consta con un conjunto de 6 leds (modificable) y dos botones. Cada botón hará que las luces vayan en una dirección*/
/*Naoki Nakao; 11 de julio, 2020.*/

//variables globales
const byte ledPins[] = {8, 7, 6, 5, 4, 3}; //vector de pines digitales para los leds
int buttonPin_1 = 12, buttonPin_2 = 2; // vector de pines digitales para los botones
const int nPins = sizeof(ledPins); //
const int tDelay = 25; //almacena el intervalo de tiempo para encender los leds

void setup() {
  for (byte index = 0; index <= nPins; index++) { //configurando los pines de salida
    pinMode(ledPins[index], OUTPUT);
  }
}

void loop() {

  while (digitalRead(buttonPin_1) == HIGH) {
    seq_1(ledPins, nPins, tDelay);
    break;
  }

  while (digitalRead(buttonPin_2) == HIGH) {
    seq_2(ledPins, nPins, tDelay);
    break;
  }
}

//funciones

void seq_1(byte arr[], int n, int t) { //Secuencia para el botón 1
  for (int i = 0; i <= n; i++) {
    digitalWrite(arr[i], HIGH);
    delay(t);
  }

  for (int j = n - 1; j >= 0; j--) {
    digitalWrite(arr[j], LOW);
    delay(t);
  }
}

void seq_2(byte arr[], int n, int t) { //Secuencia para el botón 2
  for (int i = n - 1; i >= 0; i--) {
    digitalWrite(arr[i], HIGH);
    delay(t);
  }

  for (int j = 0; j <= n; j++) {
    digitalWrite(arr[j], LOW);
    delay(t);
  }
}
