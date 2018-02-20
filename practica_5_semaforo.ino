/*Instituto Tecnologio de Leon
 Ingenieria en Sistemas Computacionales
 Sistemas Programables
 Autor: Canencia Rodriguez Aurora Denysse
 Nombre: Simulacion de semaforos con arduino
 Descripcion: Practica de arduino en donde se implemente el funcionamiento de dos semaforos, un semaforo peatonal
 y otro vehicular, el cambio de un semaforo a otro podra realizarse presionando un boton, ademas de poder regualar
 el tiempo de duracion de los semaforos con un potenciometro.
 Fecha: 19/02/2018*/

//Declara las variables que se van a utilizar 
int contador=0; //contador para saber si el boton fue presionado o no 
int estadoAnt=HIGH; //el estado anterior del boton
int potenciometro= A0; // pin donde del potenciometro
int velocidad; // la velocidad que variara con el potencimetro
int valor; // variable que guarda el valor que manda directamente el protenciometro 
 
void setup() { // Se ejecuta cada vez que el arduino se inicia
  pinMode(9,OUTPUT);  // Led VerdeCarros
  pinMode(10,OUTPUT);  // Led AmarilloCarros
  pinMode(11,OUTPUT);  // Led RojoCarros
   pinMode(12,OUTPUT);  // Led RojoPeatones
  pinMode(13,OUTPUT);  // Led VerdePeatones
  pinMode(8,INPUT_PULLUP); // Botón
}


void loop() { //Esta funcion se mantiene ejecutandose 
  valor=analogRead(potenciometro); //Lee el valor actual dedl potenciometro
  velocidad = map(valor,0,70,0,500); //Funcion que permite obtener el valor de la velocidad del potenciometro
  estadoAnt=digitalRead(8); // estado del boton
 
  if((contador==0 && estadoAnt==HIGH)  ){ //si el boton no ha sido presionado 
    delay(1000); //epera un tiempo de 1 segundo
    digitalWrite(12,HIGH);//enciende el Led RojoPeatones
    digitalWrite(9,HIGH); //enciende el Led VerdeCarros
    contador=1; //incrementa el contador para poder pasar al siguiente estado
    delay(1000);
     }
     
  if((contador==1 && estadoAnt==LOW)  ){ //Si el boton fue presionado
    digitalWrite(9,HIGH); //matiene encendido el Led VerdeCarros
    digitalWrite(12,HIGH);//matiene encendido el Led RojoPeatones
    parpadeo(); //llamada al metodo que hace parpadear el Led VerdeCarros
    delay(1000); // espera un segundo y pasa a siguiente bloque
    
    digitalWrite(9,LOW); //apaga el Led VerdeCarros
    digitalWrite(10,HIGH); //enciende el Led AmarilloCarros
    delay(2000); 
    digitalWrite(12,LOW); //apaga el Led RojoPeatones 
    digitalWrite(10,LOW);  //apaga el Led AmarilloCarros
   
    digitalWrite(11,HIGH); //enciende el Led RojoCarros
    digitalWrite(13,HIGH); //enciende el Led VerdePeatones
    delay(2000); 
   
    if(digitalRead(11)== HIGH){ 
    digitalWrite(13,HIGH);
    delay (velocidad); //espera el tiempo que este dado por la variable velocidad
    }
    digitalWrite(11,LOW); //apaga el Led RojoCarros
    digitalWrite(13,LOW); // apaga el Led VerdePeatones
    contador=0;  //vuelve a inicial el contador en 0 para regresar al estado inicial 
  }
}//metodo que permite al Led VerdeCarros parpadear
    void parpadeo(){
      for(int i=0;i<3;i++) {
    
  digitalWrite(9,HIGH);
  delay(250); 
  digitalWrite(9,LOW);    
  delay(250);
  }
    }
    //Fin del programa
