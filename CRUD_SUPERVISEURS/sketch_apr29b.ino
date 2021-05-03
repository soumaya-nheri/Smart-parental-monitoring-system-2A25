
 //Define pins for ultrasonic and buzzer
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 13;


void setup()
{
  pinMode(trigPin, OUTPUT);// trig pin will have pulses outpuy
  digitalWrite (trigPin , LOW);
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  digitalWrite (trigPin , LOW);
  pinMode(buzzPin, OUTPUT);// buzz pin is output to control buzzering
  digitalWrite(buzzPin ,LOW);
  analogWrite (buzzPin ,0);
  Serial.begin (9600);
}
 
void loop()
{  
 // Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
  int duration, distance;
  char data ;
  if ( Serial.available())
{
  data=Serial.read();
  if (data =='1') // si on a activé le capteur via QT
  {
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  // if distance less than 0.5 meter and more than 0 (0 or less means over range) 
    if (distance >= 50)  {
      // Buzz
      digitalWrite(buzzPin, HIGH);
      Serial.write('2');//envoyer vers qt que le buzzer est activé
      }
     else {
      // Don't buzz
      digitalWrite(buzzPin, LOW);
      Serial.write('3'); // envoyer vers qt que le buzzer n'est pas activé
  }
    // Waiting 60 ms won't hurt any one
    delay(60);
    Serial.write('1'); 
  
  }
else if ( data=='0' )
  {
    Serial.write('0'); // envoyer l'état du capteur
  }
  
}
}
