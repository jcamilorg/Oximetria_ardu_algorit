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

char datar=0; //Dato instantaneo leido
int orden=0;    // orden para asignar datos a variables
bool datnew=false; // llego nuevo dato
 
void setup() {
  Serial.begin(9600); //iniciar comunicacion serial 
  
//-----------------------------------------------------------
 for (int i=0;i < 4; i++){ // Resetear minimos y maximos
  mini[i]=0;
  maxi[i]=0;
  }
}

void loop() {
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

delay(1000);
UsartRx();
}


void UsartRx() {
 if (Serial.available() > 0) {
 datar=(char)Serial.read();
 datnew=true;
 }
 if(datnew==true) {
  datnew=false;
 if(orden==0){ // Se lee primer dato L1_der
   L1_der = (int)datar;
   orden=1;
  }
  else if(orden==1){
   L2_der = (int)datar;
   orden=2;
  }
   else if(orden==2){
   L1_izq = (int)datar;
   orden=3;
  }
  else if(orden==3){
   L2_izq = (int)datar;
   orden=0;
  }
}
}//Usart
