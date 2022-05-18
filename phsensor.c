#define ph_pin A0
int buffer_array[10],temp;
unsigned int avgval;
float ph_act =0;

void setup() {
 
Serial.begin(9600);
}

void loop() {
for (int i=0; i<10; i++)
 {
  buffer_array[i]=analogRead(ph_pin);
  delay(30);
 }
 for(int i=0;i<9;i++)
 {
   for (int j=i+1; j<1; j++)
   {
    if(buffer_array [i]>buffer_array[j])
    {
      temp= buffer_array[i];
      buffer_array[i]=buffer_array[j];
      buffer_array[j]=temp;
      }
    }
   }
   for( int i=0; i<8; i++)
   
    avgval+=buffer_array[i];
    float volt = avgval*5.0/1023/6;

    ph_act=volt*3.5;
    Serial.print("PH_METER VAL=  ");
    Serial.print(ph_act);
    delay(1000);
 }
