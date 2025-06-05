/*Calcule a média entre duas notas.

Verifique se o aluno foi aprovado:

Aprovado se média é MAIR OU IGUAL A 6 e SE A frequênciaÉ MAIOR OU IGUAL 75%.

Caso contrário, exiba se foi reprovado por nota, por frequência ou por ambos.

Se a média for exatamente 10, exiba: "Parabéns! Nota máxima!

*/

// C++ code

//VARIÁVEIS
float nota1 = 0;
float nota2 = 0; 
float media = 0; 
float frequencia = 100; 


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Digite a sua primeira nota");//
  while (! Serial.available()); //aguarde a resposta do usuário
  nota1 = Serial.parseFloat();
  
  Serial.println("Digite a sua segunda nota");//
  while (! Serial.available()); //aguarde a resposta do usuário
  nota2 = Serial.parseFloat();
  
  Serial.println("Digite a sua frequencia");//
  while (! Serial.available()); //aguarde a resposta do usuário
  frequencia = Serial.parseFloat();
  
  Serial.println();
  Serial.println();
  
  
  
 (media = (nota1 + nota2) / 2);
  
 Serial.println("a media eh: " + String(media));
  
  if(media >= 6){
  Serial.println("Aprovado na media");
  }else if(media = 10){
  Serial.println("Parabéns! Nota máxima!");
  } else {
  Serial.println("Reprovado na media");// vi o código no lopal 15 pois não estava lembrando ao certo o código 
  }
  
  if(frequencia >= 75 ){
  Serial.println("Aprovado na frequencia");// 
  } else {
  Serial.println("Reprovado na frequencia");
  }
 
  delay(20000);
  
  Serial.println();
  Serial.println();

  /*Me esqueci um pouco dos códigos, mas acabei lembrando ao decorrer do trabalho e, olhei tambem o arquivo da explicação do professor
  
  
}