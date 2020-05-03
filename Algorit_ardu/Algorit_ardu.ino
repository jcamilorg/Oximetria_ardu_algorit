#include <TimerOne.h>

// Variables para datos inmediato de valor de luz en logitudes de onda
int L1_der;
int L2_der;
int DC1_der;
int DC2_der;
int L1_izq;
int L2_izq;
int DC1_izq;
int DC2_izq;
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
int LAC[4];
//LAC[1] L2_AC_der;
//LAC[2] L1_AC_izq;
//LAC[3] L2_AC_izq;
// DC
long LDC[4]={1,1,1,1};
//LAC[0] L1_AC_der;
//LDC[0] L1_DC_der;
//LDC[1] L2_DC_der;
//LDC[2] L1_DC_izq;
//LDC[3] L2_DC_izq;


char datar[]={'0','0','0','0'}; //Dato instantaneo leido
int orden=0;    // orden para asignar datos a variables
bool datnew=false; // llego nuevo dato

//logica para guardar datos
 int pos=0;
 int iteracion;
void setup() {
  Serial.begin(2000000); //iniciar comunicacion serial 
  Timer1.initialize(2000000);
  Timer1.attachInterrupt(Envio);
//-----------------------------------------------------------
 for (int i=0;i < 4; i++){ // Resetear minimos y maximos
  mini[i]=1024;
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
 

 if(pos==4) {
  pos=0;
 if(orden==0){ // Se lee primer dato L1_der
   L1_der = atoi(&datar[0]);
   orden++;
  }
  else if(orden==1){
   DC1_der = atoi(&datar[0]);
   orden=2;
  }
  else if(orden==2){
   L2_der = atoi(&datar[0]);
   orden++;
  }
  else if(orden==3){
   DC2_der = atoi(&datar[0]);
   orden++;
  }  
   else if(orden==4){
   L1_izq = atoi(&datar[0]);
   orden++;
  }
   else if(orden==5){
   DC1_izq = atoi(&datar[0]);
   orden++;
  }
  else if(orden==6){
   L2_izq = atoi(&datar[0]);
   orden++;
  }
    else if(orden==7){
   DC2_izq= atoi(&datar[0]);
   orden=0;
   iteracion++;
   // Promediar el Valor DC
 LDC[0]=(LDC[0] + DC1_der);
 LDC[1]=(LDC[1] + DC2_der);
 LDC[2]=(LDC[2] + DC1_izq);
 LDC[3]=(LDC[3] + DC2_izq); 
  }
}
}

void Envio() {
    LDC[0]=LDC[0]/iteracion;
    LDC[1]=LDC[1]/iteracion;
    LDC[2]=LDC[2]/iteracion;
    LDC[3]=LDC[3]/iteracion;
    iteracion=1;
  //calculo AmpAC
  LAC[0]=maxi[0]-mini[0];  //AC valor longitud 1 parte derecha
  LAC[1]=maxi[1]-mini[1];  //AC valor longitud 1 parte derecha
  LAC[2]=maxi[2]-mini[2];  //AC valor longitud 1 parte izquierda
  LAC[3]=maxi[3]-mini[3];  //AC valor longitud 2 parte izquierda
  // Calculo de "R"
  float AD_L1_der= (LAC[0]/LDC[0]);
  float AD_L2_der= (LAC[1]/LDC[1]);
  float R_der= (AD_L1_der/AD_L2_der);
  
  float AD_L1_izq = (LAC[2]/LDC[2]);
  float AD_L2_izq = (LAC[3]/LDC[3]);
  float R_izq  = (AD_L1_izq/AD_L2_izq);
  
  //-------------__________  Enviar Datos ____________-----------------------------
  Serial.print("AC DC ,");
  for (int i=0;i < 4; i++){ 
  Serial.print(LAC[i]);
  Serial.print(',');
  Serial.print(LDC[i]);
  Serial.print(',');
  }
    Serial.print(" R ,"); 
    Serial.print(R_der);
    Serial.print(',');
    Serial.println(R_izq);
  
 for (int i=0;i < 4; i++){ // Resetear AC y DC
  LAC[i]=0;
  LDC[i]=1;
  mini[i]=1023;
  maxi[i]=0;
  L1_der=0;
 L2_der=0;
 DC1_der=0;
 DC2_der=0;
 L1_izq=0;
 L2_izq=0;
 DC1_izq=0;
 DC2_izq=0;
  }
  }
  
void cal_min_max(){
 // Encontrar Maximo y minimo L1 der.-----
  if (L1_der < mini[0] && L1_der != 0) {
    mini[0]=L1_der;
  }
  if (L1_der > maxi[0]&& L1_der != 0) {
    maxi[0]=L1_der;
  }
// Encontrar Maximo y minimo L2 der.-----
  if (L2_der < mini[1]&& L2_der != 0) {
    mini[1]=L2_der;
  }
  if (L2_der > maxi[1]&& L2_der != 0) {
    maxi[1]=L2_der;
  }
// Encontrar Maximo y minimo L1 izq.------
  if (L1_izq < mini[2]&& L1_izq != 0) {
    mini[2]=L1_izq;
  }
  if (L1_izq > maxi[2]&& L1_izq != 0) {
    maxi[2]=L1_izq;
  }
// Encontrar Maximo y minimo L2 izq.-------
  if (L2_izq < mini[3]&& L2_izq != 0) {
    mini[3]=L2_izq;
  }
  if (L2_izq > maxi[3]&& L2_izq != 0) {
    maxi[3]=L2_izq;
    }
//-------------------------------------
  }
