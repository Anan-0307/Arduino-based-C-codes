const int lm35_pin = A0;	// Initialising lm35_pin to A0 pin of the arduino // 

void setup() 
{
  Serial.begin(9600);
  pinMode(13, OUTPUT); // setting the built in LED pin 13 as output //
  pinMode(lm35_pin, INPUT); // setting the A0 pin as input to take the input from the sensor //
}

void loop() 
{
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	// Read Temperature //
  temp_val = (temp_adc_val * 4.88);	// Convert adc value to equivalent voltage //
  temp_val = (temp_val/10);	// LM35 gives output of 10mv/°C //

// Turning on the LED for 250ms when the temp is below 30 degrees //
  if(temp_val < 30) 
  {
  float i = 0.0;
  float time = 0.0;
  for(i=0.0; i<=0.250; i=i+0.050) //Declaring a variable time to keep incrementing or counting the time uptill 250ms as soon the temp is below 30 degrees//
  {
    time = time + i;
    digitalWrite(13, HIGH); // The LED is kept on for 250ms, Once the value of time is more than 0.250 , the loop is terminated and the final value of time variable in 0.250//
  }
  if(time = 0.250) // Once the time equals 250ms , the LED will be turned off //
  {
	 digitalWrite(13, LOW); 
  }
  }

// Turning on the LED for 500ms when the temp is above 30 degrees //
  if(temp_val > 30) 
  {
    float j = 0.0;
    float time1 = 0.0;
  for(j=0.0; j<=0.500; j=j+0.100) //Turning on the LED for 500ms, declaring a variable time to keep incrementing or counting the time uptill 500ms as soon the temp is above 30 degrees//
  {
    time1 = time1 + j;
    digitalWrite(13, HIGH); // The LED is kept on for 500ms, Once the value of time is more than 0.500 , the loop is terminated and the final value of time variable in 0.500//
  }
  if(time1 = 0.500) // Once the time equals 500ms , the LED will be turned on //
  {
	 digitalWrite(13, LOW); 
  }
  }
  
}
