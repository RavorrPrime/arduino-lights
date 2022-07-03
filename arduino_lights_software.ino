#define potentiometer  A3
#define motionSensor 2
#define LED 5
#define roomLight 3

int read_ADC = 0;
int setTimer = 0;
int sensor = 0;
int seconds = 0 ,timer = 0;
int check = 0;

long delay_Start;


void setup(){ 

Serial.begin(9600);
  
pinMode(motionSensor, INPUT);
pinMode(LED, OUTPUT);
pinMode(roomLight, OUTPUT);

digitalWrite(roomLight, HIGH); // Wyłącza przekaźnik

delay(1000); 
}


void loop(){
read_ADC = analogRead(potentiometer); // 0-1023
setTimer = read_ADC /17.05; // To jest po to, aby maksymalna wartosc sekund wynosila 60

sensor = digitalRead(motionSensor);

//Wykrycie ruchu
if(sensor==1){
Serial.println("MOTION DETECTED!");
digitalWrite(LED, HIGH);
digitalWrite(roomLight, LOW);

seconds = 0;
check = 1;
delay_Start = millis(); // Startuje timer
}

else{
Serial.println("NO MOTION!");
digitalWrite(LED, LOW);
}

if((check==1) && (millis()- delay_Start) > 999){ 
seconds = seconds+1;  
delay_Start = millis();
}

if(seconds>setTimer){
check = 0;
seconds = 0; 
digitalWrite(roomLight, HIGH);
}

delay(200);
}
