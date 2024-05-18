float temperatura;//valor de la temperatura
int pinEntrada = 0;//pin para entrada de valor de temperatura
int pinLavadora= 13;
int pinTV= 12;
int pinVentilador= 11;
int pinCamaraSeguridad= 10;
int pinAireAcondicionado= 9;
int pintemp1= 7; //medición 1=10 grados
int pintemp2= 6; //medición 2=20 grados
int pintemp3= 5; //medición 3=30 grados
int pintemp4= 4; //medición 4=40 grados
int pintemp5= 3; //medición 5=50 grados

void setup() {
 Serial.begin(9600); // se abre el puerto a 9600 bps
pinMode(pinLavadora, OUTPUT);
pinMode(pinTV, OUTPUT);
pinMode(pinVentilador, OUTPUT);
pinMode(pinCamaraSeguridad, OUTPUT);
pinMode(pinAireAcondicionado, OUTPUT);
pinMode(pintemp1, INPUT); //entrada de datos
pinMode(pintemp2, INPUT); //entrada de datos
pinMode(pintemp3, INPUT); //entrada de datos
pinMode(pintemp4, INPUT); //entrada de datos
pinMode(pintemp5, INPUT); //entrada de datos
}

void loop() {
  
    temperatura = analogRead(pinEntrada);// lectura del pin A0 (temperatura)
    temperatura = (temperatura / 1023 * 5 / 0.1); // pasa el valor a grados
    //valor leído / 1024 equivale al valor de nuestros pines analógicos * 5voltios / los voltios divividos entre los Centigrados.
    Serial.print(temperatura); // escribe el valor de la temperatura por el puerto serial
    Serial.print(" grados centigrados \n");//escribe las unidades
    delay(1000);//Tiempo estimado de 1 segundo


    //Apagado de "electrodomesticos"
    if (digitalRead(pintemp1)){
    digitalWrite(pinLavadora, LOW);
     
    } else {
       digitalWrite(pinLavadora, HIGH);
       delay(1000);
    }
    if (digitalRead(pintemp2)){
    digitalWrite(pinTV, LOW);
     
    } else {
       digitalWrite(pinTV, HIGH);
       delay(1000);
    }
       if (digitalRead(pintemp3)){
    digitalWrite(pinVentilador, LOW);
     
    } else {
       digitalWrite(pinVentilador, HIGH);
       delay(1000);
    }
       if (digitalRead(pintemp4)){
    digitalWrite(pinCamaraSeguridad, LOW);
     
    } else {
       digitalWrite(pinCamaraSeguridad, HIGH);
       delay(1000);
     }
            if (digitalRead(pintemp5)){
    digitalWrite(pinAireAcondicionado, LOW);
     
    } else {
       digitalWrite(pinAireAcondicionado, HIGH);
       delay(1000);
    }


  if(temperatura >= 15 && temperatura <= 24){
    digitalWrite(pinCamaraSeguridad, LOW);
    delay(10000);
  }
    else if(temperatura >=25 && temperatura <= 29){
    digitalWrite(pinAireAcondicionado, LOW);
    delay(10000);
  }
  else if(temperatura >= 30 && temperatura <=38){
    digitalWrite(pinVentilador, LOW);
    delay(10000);
  }
  else if(temperatura >= 39 && temperatura <= 45){
    digitalWrite(pinTV, LOW);
    delay(10000);
  }
  else if(temperatura >= 46 && temperatura <= 50){
    digitalWrite(pinLavadora, LOW);
    delay(1000);
  }
}
