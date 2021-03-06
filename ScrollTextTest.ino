/* MEKANUS ROBÓTICA EDUCACIONAL
 * TESTE DE DISPLAY I2C PARA 1602 E 2004.
 * Imprime texto maior que a quantidade de caractere disponível
 * aplicando o efeito scroll, permitindo leitura normal da mensagem.
 * Para mais informações: http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 */

#include <LiquidCrystal_I2C.h>  // Inclui bibliotecas:
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);  // Inicializa a biblioteca com os pinos da interface I2C:

int Interval = 500;     //Variáveis para ajuste de tempo e comprimento da mensagem:
int Comprimento = 1;     //Variáveis para ajuste de tempo e comprimento da mensagem:

void setup() {      // Configura o tipo de display. Comente a linha do display NÃO USADO e imprime mensagem padrão:
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Mekanus Robotica Educacional");
  lcd.setCursor(0,1);
  lcd.print("Mekanus Robotica Educacional");
  delay(1000);
}

void loop() {
  for (int positionCounter = 0; positionCounter < Comprimento; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(Interval);
  }
}
