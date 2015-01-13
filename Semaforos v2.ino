/* Programa: Semáforos v2
Simula o funcionamento de semáforos num cruzamento.
Na função setup() estão descritas as portas do arduino utilizadas e com
que luzes estão a trabalhar.
*/

void setup() {
  // declara as portas 4 a 13 como OUTPUT
  pinMode (13, OUTPUT);  // Semáforo Vertical Vermelho
  pinMode (12, OUTPUT);  // Semáforo Vertical Amarelo
  pinMode (11, OUTPUT);  // Semáforo Vertical Verde
  pinMode (10, OUTPUT);  // Semáforo Horizontal Vermelho
  pinMode (9, OUTPUT);   // Semáforo Horizontal Amarelo
  pinMode (8, OUTPUT);   // Semáforo Horizontal Verde
  pinMode (7, OUTPUT);   // Semáforo Peões Vertical Vermelho
  pinMode (6, OUTPUT);   // Semáforo Peões Vertical Verde
  pinMode (5, OUTPUT);   // Semáforo Peões Horizontal Vermelho
  pinMode (4, OUTPUT);   // Semáforo Peões Horizontal Verde
  pinMode (A0, OUTPUT);  // Porta onde vai ligar o Buzzer
  
  /* Testa as luzes dos leds para verificar se estão todas a funcionar
     Liga cada luz durante 1 segundo e depois desliga
  */
  for (int i = 4; i <=13; i++) {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
}

void loop () {
  /*
    Para simplificar a leitura da função loop() dividiu-se o código em
    quatro funções.
  */
  linha1();
  linha2();
  linha3();
  linha4();
}

void linha1 () {
  // Linha 1
  digitalWrite (11, HIGH); // Semáforo Vertical Verde
  digitalWrite (10, HIGH); // Semáforo Horizontal Vermelho
  digitalWrite ( 7, HIGH); // Semáforo Peões Vertical Vermelho
  digitalWrite ( 4, HIGH); // Semáforo Peões Horizontal Verde
  tone(A0,750);
  delay(55*1000); // espera 4 segundos
  
  // Pisca luz verde durante 5 seg
  for (int a=0; a < 5; a++) {
    digitalWrite (11, HIGH); // Semáforo Vertical Verde
    delay(500);
    digitalWrite (11, LOW); // Semáforo Vertical Verde
    delay(500);
  }
}

void linha2() {
  // Linha 2
  digitalWrite (11, LOW); // Semáforo Vertical Verde
  digitalWrite (12, HIGH); // Semáforo Vertical Amarelo
  delay(15*1000); // espera 1 segundos
  
  // Pisca luz amarelo durante 5 seg
  for (int a=0; a < 5; a++) {
    digitalWrite (12, HIGH); // Semáforo Vertical Amarelo
    digitalWrite (4, HIGH); // Semáforo Peões Horizontal Verde
    tone(A0,750);
    delay(500);
    digitalWrite (12, LOW); // Semáforo Vertical Amarelo
    digitalWrite (4, LOW); // Semáforo Peões Horizontal Verde
    tone(A0,0);
    delay(500);
  }
}

void linha3() {
  // Linha 3
  digitalWrite (12, LOW); // Semáforo Vertical Amarelo
  digitalWrite (10, LOW); // Semáforo Horizontal Vermelho
  digitalWrite ( 7, LOW); // Semáforo Peões Vertical Vermelho
  digitalWrite ( 4, LOW); // Semáforo Peões Horizontal Verde

  digitalWrite ( 8, HIGH); // Semáforo Horizontal Verde
  digitalWrite (13, HIGH); // Semáforo Vertical Vermelho
  digitalWrite ( 5, HIGH); // Semáforo Peões Horizontal Vermelho
  digitalWrite ( 6, HIGH); // Semáforo Peões Vertical Verde
  tone(A0,500);
  delay (15*1000); // espera 4 segundos
  
  // Pisca luz Horizontal Verde durante 5 seg
  for (int a=0; a < 5; a++) {
    digitalWrite (8, HIGH); // Semáforo Horizontal Verde
    tone(A0,500);
    delay(500);
    digitalWrite (8, LOW); // Semáforo Horizontal Verde
    tone(A0,0);
    delay(500);
  }
}

void linha4() {
    // Linha 4
  digitalWrite ( 8, LOW); // Semáforo Horizontal Verde
  digitalWrite ( 9, HIGH); // Semáforo Horizontal Amarelo
  delay (1*1000); // espera 1 segundos
  
  // Pisca luz Amarelo Verde durante 5 seg
  for (int a=0; a < 5; a++) {
    digitalWrite (9, HIGH); // Semáforo Horizontal Amarelo
    digitalWrite (6, HIGH); // Semáforo Peões Vertical Verde
    delay(500);
    digitalWrite (9, LOW); // Semáforo Horizontal Amarelo
    digitalWrite (6, LOW); // Semáforo Peões Vertical Verde
    delay(500);
  }
  
  //apaga luzes antes de voltar à linha 1
  digitalWrite ( 9, LOW); // Semáforo Horizontal Verde
  digitalWrite (13, LOW); // Semáforo Vertical Vermelho
  digitalWrite ( 5, LOW); // Semáforo Peões Horizontal Vermelho
  digitalWrite ( 6, LOW); // Semáforo Peões Vertical Verde
}
