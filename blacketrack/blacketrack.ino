//Motor Control Advanced
int d1=2;
int d2=3;
int brake1=4;
int brake2=12;
int op2=7;
int pwm1=6;
int pwm2=11;
int pwmanalog1= 3;
int pwmanalog2= 4;
int r1=8;
int r2=9;

void setup() 
{
 pinMode(d1,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(brake1,OUTPUT);
  pinMode(brake2,OUTPUT);
  pinMode(op1,OUTPUT);
  pinMode(op2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  Serial1.begin(9600);

}

void loop() 
{
int speed= 50, val=85;
  if(Serial1.available())
  {
    char c=Serial1.read();
    //Fast Front
    if(c=='1')
    {
      digitalWrite(d1,LOW);
      digitalWrite(pwm1,HIGH);
      digitalWrite(brake2,LOW);
      digitalWrite(pwm2,HIGH);
      digitalWrite(d2,LOW);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
    }
    //Back
    if(c=='0')
    {
      digitalWrite(d1,HIGH);
      digitalWrite(d2,HIGH);
      digitalWrite(pwm1,HIGH);
      digitalWrite(brake1,LOW);
      digitalWrite(pwm2,HIGH);
      digitalWrite(brake2,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
    }
    //Fast Right
    if(c=='4')
    {
      digitalWrite(brake2,LOW);
      digitalWrite(pwm2,HIGH);
      digitalWrite(d1,LOW);
      digitalWrite(pwm1,HIGH);
      digitalWrite(d2,HIGH);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      
    }
    //Fast Left
    if(c=='3')
    {
      digitalWrite(brake2,LOW);
      digitalWrite(pwm2,HIGH);
      digitalWrite(d1,HIGH);
      digitalWrite(pwm1,HIGH);
      digitalWrite(d2,LOW);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
    }
    //Stop
    if(c=='5')
    {
      digitalWrite(brake2,HIGH);
      digitalWrite(d1,LOW);
      digitalWrite(d2,LOW);
      digitalWrite(brake1,HIGH);
      digitalWrite(op1,HIGH);
      digitalWrite(op2,HIGH);
    }
    //Slow Forward
    if(c=='6')
    {
      digitalWrite(d1,LOW);
      //digitalWrite(pwm1,HIGH);
      digitalWrite(brake2,LOW);
      //digitalWrite(pwm2,HIGH);
      digitalWrite(d2,LOW);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      analogWrite(pwm1, val);
      analogWrite(pwm2, val);
   }
   //Slow Back
   if(c=='7')
   {
      digitalWrite(d1,HIGH);
      digitalWrite(d2,HIGH);
      //digitalWrite(pwm1,HIGH);
      digitalWrite(brake1,LOW);
      //digitalWrite(pwm2,HIGH);
      digitalWrite(brake2,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);  
      analogWrite(pwm1, val);
      analogWrite(pwm2, val);
   }
   //Slow right
   if(c=='9')
   {
      digitalWrite(brake2,LOW);
      //digitalWrite(pwm2,HIGH);
      digitalWrite(d1,LOW);
      //digitalWrite(pwm1,HIGH);
      digitalWrite(d2,HIGH);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      analogWrite(pwm1, val);
      analogWrite(pwm2, val);
   }
   //Slow left
   if(c=='8')
   {
      digitalWrite(brake2,LOW);
      //digitalWrite(pwm2,HIGH);
      digitalWrite(d1,HIGH);
      //digitalWrite(pwm1,HIGH);
      digitalWrite(d2,LOW);
      digitalWrite(brake1,LOW);
      digitalWrite(op1,LOW);
      digitalWrite(op2,LOW);
      analogWrite(pwm1, val);
      analogWrite(pwm2, val);  
   }
   if(c=='10')
   {
      digitalWrite(r1,HIGH);
      digitalWrite(r2,LOW);
   }
   if(c=='11')
   {
      digitalWrite(r1,LOW);
      digitalWrite(r2,LOW);
   }
       
  }
}


