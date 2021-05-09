int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int btn4 = 5;
int btn5 = 6;
int btn6 = 7;
int btn7 = 8;//kopuk
int btn8 = 9;//yikama
int btn9 = 10;//kurulama
int btn10 = 11;//cilalama
int btn11 = 12;//reset
int rastgele=0;
int sayac=0;
int kullanim[3];
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C setLCD(0x27,16,2);


char text[]={"20,20,10,30,5 TL 1,kopukleme,30,15 TL 2,yikama,50,10 TL 3,kurulama,100,5 TL 4,cilalama,20,50 TL"};
char *islem=NULL;
char *node=NULL;
char *node1=NULL;
char *app[10];
char *para[5];
char *hesap[50];
int i=0,k=0,j=0;
int beslik=0;
int onluk=0;
int yirmilik=0;
int ellilik=0;
int yuzluk=0;

int kparasi=0;
int resetsayac=0;
int hizmetf=0;
int paraustu=0;
int kacadet=0;

int count2=0;
int count1=0;
int count=0;
int cuzdan=0;
void setup() {
  setLCD.init();
  setLCD.backlight();
  setLCD.setCursor(0,0);
  randomSeed(10);
  setLCD.print("HOSGELDINIZ");
  delay(100);
  Serial.begin(9600);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);  
  pinMode(btn4, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  pinMode(btn6, INPUT_PULLUP);
  pinMode(btn7, INPUT_PULLUP);
  pinMode(btn8, INPUT_PULLUP);  
  pinMode(btn9, INPUT_PULLUP);
  pinMode(btn10, INPUT_PULLUP);
  pinMode(btn11, INPUT_PULLUP);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  islem=strtok(text," TL ");
  while(islem!=NULL){
    app[i]=islem;
    i++;
    islem=strtok(NULL," TL ");
  }
      node=strtok(app[0],",");
      while(node!=NULL){
          para[k]=node;
        k++;
      node=strtok(NULL,",");
      }
      for(int m=1;m<i;m++){
      node1=strtok(app[m],",");
      while(node1!=NULL){
          hesap[j]=node1;
        j++;
      node1=strtok(NULL,",");
      } 
     }
  beslik=atoi(para[0]);
  onluk=atoi(para[1]);
  yirmilik=atoi(para[2]);
  ellilik=atoi(para[3]);
  yuzluk=atoi(para[4]);
   
  kullanim[0]= atoi(hesap[2]);
  kullanim[1]= atoi(hesap[6]);
  kullanim[2]= atoi(hesap[10]);
  kullanim[3]= atoi(hesap[14]);

  cuzdan+=5*atoi(para[0]);
  cuzdan+=10*atoi(para[1]);
  cuzdan+=20*atoi(para[2]);
  cuzdan+=50*atoi(para[3]);
  cuzdan+=100*atoi(para[4]);
}
void loop() {
  int value_btn1 = digitalRead(btn1);
  int value_btn2 = digitalRead(btn2);
  int value_btn3 = digitalRead(btn3);
  int value_btn4 = digitalRead(btn4);
  int value_btn5 = digitalRead(btn5);
  int value_btn6 = digitalRead(btn6);
  int value_btn7 = digitalRead(btn7);
  int value_btn8 = digitalRead(btn8);
  int value_btn9 = digitalRead(btn9);
  int value_btn10 = digitalRead(btn10);
  int value_btn11 = digitalRead(btn11);
  
  if (value_btn1 == 1){
    setLCD.setCursor(0,0);
    beslik++; 
      kparasi=kparasi+5;
      cuzdan=cuzdan+5;
      setLCD.print(kparasi);
      setLCD.print("TL Para attiniz."); 
      delay(1000);
      setLCD.clear();
  }
  
  if (value_btn2 == 1){
    setLCD.setCursor(0,0);
    onluk++;
    kparasi=kparasi+10; 
      cuzdan=cuzdan+10;
      setLCD.print(kparasi); 
      setLCD.print("TL Para attiniz."); 
      delay(1000);
      setLCD.clear();
  }
  
  if (value_btn3 == 1){
    setLCD.setCursor(0,0); 
    yirmilik++;
    kparasi=kparasi+20;
      cuzdan=cuzdan+20;
      setLCD.print(kparasi);
      setLCD.print("TL Para attiniz."); 
      delay(1000);
      setLCD.clear();
  }
    if (value_btn4 == 1){
    setLCD.setCursor(0,0);
    ellilik++;
    kparasi=kparasi+50;
      cuzdan=cuzdan+50;
      setLCD.print(kparasi); 
        setLCD.print("TL Para attiniz."); 
      delay(1000);
      setLCD.clear();
  }
    if (value_btn5 == 1){
    setLCD.setCursor(0,0);
    yuzluk++; 
    kparasi=kparasi+100;
      cuzdan=cuzdan+100;
      setLCD.print(kparasi); 
        setLCD.print("TL Para attiniz."); 
      delay(1000);
      setLCD.clear();
  }
    if (value_btn6 == 1){
      count2++;
      if(sayac==0){
        sayac++;
      setLCD.setCursor(0,0);
      setLCD.print("HESAP:");
      setLCD.setCursor(6,0);
      setLCD.print(cuzdan);
    setLCD.setCursor(0,1); 
      setLCD.print("ISLEM");
      setLCD.setCursor(5,1);
      setLCD.print(" SECINIZ");
      delay(1000);
      setLCD.clear();
      }else if(sayac>=2){
        paraustu=kparasi-hizmetf;
        setLCD.setCursor(0,0); 
        setLCD.print("paraustunuz:");
        setLCD.setCursor(0,1); 
        setLCD.print(paraustu);
        delay(1000);
      setLCD.clear();
        rastgele =random(1,5);
        Serial.println("***");
        Serial.print("random sayi:");
        Serial.println(rastgele);
       setLCD.setCursor(0,0);
      setLCD.print("Random sayi");
       setLCD.setCursor(0,1);
      setLCD.print(rastgele);
           if(rastgele==2)
           {
             analogWrite(A1,255); 
             analogWrite(A0,0); 
             delay(2000);
             analogWrite(A1,0); 
             setLCD.setCursor(0,0);
             setLCD.print("paranizi aliniz:");
             setLCD.setCursor(0,1);
             setLCD.print(kparasi);
             delay(1000);
             
             kparasi=0;
             cuzdan=0;
             cuzdan+=5*atoi(para[0]);
             cuzdan+=10*atoi(para[1]);
             cuzdan+=20*atoi(para[2]);
             cuzdan+=50*atoi(para[3]);
             cuzdan+=100*atoi(para[4]);
             setLCD.clear();
             
           }
           else
           {
            analogWrite(A0,255); 
            analogWrite(A1,0);       
             delay(2000);
            analogWrite(A0,0);

      Serial.println("Para ustu:");
        Serial.println(paraustu);
      if(paraustu<0){
        Serial.println("Kasada yeterli para yoktur");
        setLCD.setCursor(0,0);
        setLCD.print("bakiye yetersiz");
        delay(1000);
        setLCD.clear();
      }else{
        if((paraustu/100)>0)//icinde 100luk var mi
       {
        kacadet=paraustu/100;//parada kac adet yuzluk var

        if(kacadet>yuzluk)//eger bizim yuzlugumuz yetersiz ise olan kadarı ver
        {
           paraustu=paraustu%(yuzluk*100);
           yuzluk=0;
          
        Serial.print(kacadet);
        Serial.println("adet yuzluk  ");
        }
        else//eger yeteri kadar yuzluk var ise
        {
            kacadet=paraustu/100;
              
            paraustu=paraustu%100;
            yuzluk=yuzluk-kacadet;
       
        Serial.print(kacadet);
        Serial.println("adet yuzluk  ");
       
        }

    }
     printf("\n******************\n");
    kacadet=0;
        
        
    if((paraustu/50)>0)//icinde 50lik var mi
    {
        kacadet=paraustu/50;//parada kac adet ellilik var

        if(kacadet>yuzluk)//eger bizim elliligimiz yetersiz ise olan kadarı ver
        {
           paraustu=paraustu%(ellilik*50);
           ellilik=0;
        Serial.print(kacadet);
        Serial.println("adet ellilik  ");
       
        }
        else//eger yeteri kadar ellilik var ise
        {
            kacadet=paraustu/50;
           
            paraustu=paraustu%50;
                
       
        Serial.print(kacadet);
        Serial.println("adet ellilik  ");
        
        }

    }
          printf("\n******************\n");
    kacadet=0;
      
        
    if((paraustu/20)>0)//icinde 20lik var mi
    {
        kacadet=paraustu/20;//parada kac adet yirmilik var

        if(kacadet>yirmilik)//eger bizim yirmiligimiz yetersiz ise olan kadarı ver
        {
           paraustu=paraustu%(yirmilik*20);
           yirmilik=0;
        
        Serial.print(kacadet);
        Serial.println("adet yirmilik  ");
      
       

        }
        else//eger yeteri kadar yirmilik var ise
        {
            kacadet=paraustu/20;
             
            paraustu=paraustu%20;
                
         
        Serial.print(kacadet);
        Serial.println("adet yirmilik  ");
       
        }

    }
          printf("\n******************\n");
    kacadet=0;
      
        
    if((paraustu/10)>0)//icinde 10luk var mi
    {
        kacadet=paraustu/10;//parada kac adet onluk var

        if(kacadet>onluk)//eger bizim onluk yetersiz ise olan kadarı ver
        {
           paraustu=paraustu%(onluk*10);
           yirmilik=0;
          
        Serial.print(kacadet);
        Serial.println("adet onluk  ");
        
        }
        else//eger yeteri kadar onluk var ise
        {
            kacadet=paraustu/10;
              
            paraustu=paraustu%10;
             
        Serial.print(kacadet);
        Serial.println("adet onluk  ");
      
        }

    }
               printf("\n******************\n");
    kacadet=0;
        
        
    if((paraustu/5)>0)//icinde 5lik var mi
    {
        kacadet=paraustu/5;//parada kac adet beslik var

        if(kacadet>beslik)//eger bizim beslik yetersiz ise olan kadarı ver
        {
           paraustu=paraustu%(beslik*5);
           beslik=0;
         
        Serial.print(kacadet);
        Serial.println("adet beslik  ");
      

        }
        else//eger yeteri kadar beslik var ise
        {
            kacadet=paraustu/5;
          
            paraustu=paraustu%5;
                
      
        Serial.print(kacadet);
        Serial.println("adet beslik  ");
   
        }

    }
             
           }
          
             
      }
      }
        sayac++;
  }

 if (value_btn7 == 1){
      kullanim[0]= kullanim[0]-1;
      hizmetf=hizmetf+atoi(hesap[3]);
      setLCD.setCursor(0, 0); 
      setLCD.print(hesap[1]);
      setLCD.setCursor(10, 0); 
      setLCD.print(hesap[3]);
      setLCD.setCursor(13, 0); 
      setLCD.print("TL");
      setLCD.setCursor(0, 1); 
      setLCD.print("kalan:");
      setLCD.setCursor(7, 1); 
      setLCD.print(kullanim[0]);
       delay(1000);
      setLCD.clear();
  }
   if (value_btn8 == 1){
     kullanim[1]= kullanim[1]-1;
     hizmetf=hizmetf+atoi(hesap[7]);
      setLCD.setCursor(0, 0); 
      setLCD.print(hesap[5]);
            setLCD.setCursor(10, 0); 
      setLCD.print(hesap[7]);
      setLCD.setCursor(13, 0); 
      setLCD.print("TL");
       setLCD.setCursor(7, 1); 
      setLCD.print(kullanim[1]);  
      setLCD.setCursor(0, 1); 
      setLCD.print("kalan:");
       delay(1000);
      setLCD.clear();
  }
      if (value_btn9 == 1){
     kullanim[2]= kullanim[2]-1;
     hizmetf=hizmetf+atoi(hesap[11]);
      setLCD.setCursor(0, 0); 
      setLCD.print(hesap[9]);
                 setLCD.setCursor(10, 0); 
      setLCD.print(hesap[11]);
      setLCD.setCursor(13, 0);
            setLCD.print("TL");
       setLCD.setCursor(7, 1); 
      setLCD.print(kullanim[2]);  
      setLCD.setCursor(0, 1); 
     
      setLCD.print("kalan:");
       delay(1000);
      setLCD.clear();
  }
      if (value_btn10 == 1){
     kullanim[3]= kullanim[3]-1;
     hizmetf=hizmetf+atoi(hesap[15]);
      setLCD.setCursor(0, 0); 
      setLCD.print(hesap[13]);
                 setLCD.setCursor(10, 0); 
      setLCD.print(hesap[15]);
      setLCD.setCursor(13, 0);
            setLCD.print("TL");
       setLCD.setCursor(7, 1); 
      setLCD.print(kullanim[3]);  
      setLCD.setCursor(0, 1); 
     
      setLCD.print("kalan:");
       delay(1000);
      setLCD.clear();
  }
  if(value_btn11 == 1){
   if(count2==1){
  kullanim[0]= atoi(hesap[2]);
  kullanim[1]= atoi(hesap[6]);
  kullanim[2]= atoi(hesap[10]);
  kullanim[3]= atoi(hesap[14]);
  setLCD.setCursor(0,1);
  setLCD.print("secim yapın");
  delay(1000);
  setLCD.clear();
   }else{
  kullanim[0]= atoi(hesap[2]);
  kullanim[1]= atoi(hesap[6]);
  kullanim[2]= atoi(hesap[10]);
  kullanim[3]= atoi(hesap[14]);
  kparasi=0;
  setLCD.setCursor(0,0);
  setLCD.print("GULE ");
  setLCD.setCursor(5,0);
  setLCD.print("GULE");
  delay(1000);
  setLCD.clear();
   }
  }
}
