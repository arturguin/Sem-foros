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
  
  // outra maneira de colocar os pins a OFF
  for (int i = 4; i <=13; i++) {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
}

void loop () {
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
  delay(4*1000); // espera 4 segundos
}

void linha2() {
  // Linha 2
  digitalWrite (11, LOW); // Semáforo Vertical Verde
  digitalWrite (12, HIGH); // Semáforo Vertical Amarelo
  delay(1*1000); // espera 1 segundos
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
  delay (4*1000); // espera 4 segundos
}

void linha4() {
    // Linha 4
  digitalWrite ( 8, LOW); // Semáforo Horizontal Verde
  digitalWrite ( 9, HIGH); // Semáforo Horizontal Amarelo
  delay (1*1000); // espera 1 segundos
  
  //apaga luzes antes de voltar à linha 1
  digitalWrite ( 9, LOW); // Semáforo Horizontal Verde
  digitalWrite (13, LOW); // Semáforo Vertical Vermelho
  digitalWrite ( 5, LOW); // Semáforo Peões Horizontal Vermelho
  digitalWrite ( 6, LOW); // Semáforo Peões Vertical Verde
}
