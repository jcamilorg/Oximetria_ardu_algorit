#include <TimerOne.h>

// Variables para datos inmediato de valor de luz en logitudes de onda
int L1_der;
int L2_der;
int DC_der;
int L1_izq;
int L2_izq;
int DC_izq;
//Fin

int mini[4]; //Este vector guarda el valor minimo actual de todas las loguitudes de onda.
//Posicion 0 = min(L1_der)
//Posicion 1 = min(L2_der)
//Posicion 2 = min(L1_izq)
//Posicion 3 = min(L2_izq)
int maxi[4];//Este vector guarda el valor maximo actual de todas las loguitudes de onda.
//Posicion 0 = max(L1_der)
//Posicion 1 = max(L2_der)
//Posicion 2 = max(L1_izq)
//Posicion 3 = max(L2_izq)

// Valores de amplitud AC y DC
//AC
int L1AC_der;
int L2AC_der;
int L1AC_der;
int L2AC_der;
// DC
int L1DC_der;
int L2DC_der;
int L1DC_izq;
int L2DC_izq;



char datar[]={'0','0','0','0'}; //Dato instantaneo leido
int orden=0;    // orden para asignar datos a variables
bool datnew=false; // llego nuevo dato
//logica para guardar datos
 int pos=0;
 
void setup() {
  Serial.begin(9600); //iniciar comunicacion serial 
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(Envio);
//-----------------------------------------------------------
 for (int i=0;i < 4; i++){ // Resetear minimos y maximos
  mini[i]=0;
  maxi[i]=0;
  }
}

void loop() {
cal_min_max();
UsartRx();
}


void UsartRx() {
 if (Serial.available() > 0) {
 char dataexclude=(char)Serial.read();
 if (dataexclude == 10 || dataexclude == ','){}
 else{
 datar[pos]=dataexclude;
 pos++;
  }
 }
 

 if(pos==4 || datnew==true) {
  pos=0;datnew=false;
 if(orden==0){ // Se lee primer dato L1_der
   L1_der = atoi(&datar[0]);
   orden=1;
  }
  else if(orden==1){
   L2_der = atoi(&datar[0]);
   orden=2;
  }
   else if(orden==2){
   L1_izq = atoi(&datar[0]);
   orden=3;
  }
  else if(orden==3){
   L2_izq = atoi(&datar[0]);
   orden=0;
  }
}
}

void Envio() {
  //calculo AmpAC
  L1
  
  //-------------__________  Enviar Datos ____________-----------------------------
    Serial.print("Min ");
    for (int i=0;i < 4; i++){ // Resetear minimos y maximos
    Serial.print(mini[i]);
    Serial.print(',');
    }
    Serial.println("");
    Serial.print("Max ");
    for (int i=0;i < 4; i++){ // Resetear minimos y maximos
    Serial.print(maxi[i]);
    Serial.print(',');
    }
    Serial.println("");
    Serial.println(orden); //
    Serial.println(atoi(&datar[0]));
  }
  
void cal_min_max(){
 // Encontrar Maximo y minimo L1 der.-----
  if (L1_der < mini[0]) {
    mini[0]=L1_der;
  }
  if (L1_der > maxi[0]) {
    maxi[0]=L1_der;
  }
// Encontrar Maximo y minimo L2 der.-----
  if (L2_der < mini[1]) {
    mini[1]=L2_der;
  }
  if (L2_der > maxi[1]) {
    maxi[1]=L2_der;
  }
// Encontrar Maximo y minimo L1 izq.------
  if (L1_izq < mini[2]) {
    mini[2]=L1_izq;
  }
  if (L1_izq > maxi[2]) {
    maxi[2]=L1_izq;
  }
// Encontrar Maximo y minimo L2 izq.-------
  if (L2_izq < mini[3]) {
    mini[3]=L2_izq;
  }
  if (L2_izq > maxi[3]) {
    maxi[3]=L2_izq;
    }
//-------------------------------------
  }
