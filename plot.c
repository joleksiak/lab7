#include <stdio.h>
#include <stdlib.h>

void main(){
  FILE *wyjscie;
  int i;
  float a,b,c;
  wyjscie = fopen("dane.dat","w");
  for (i=0;i<=10;i++) {
    a=i*0.1;
    b=a*a;
    c=random()%100;
    c=c/100;
    fprintf(wyjscie,"%3.1f  %4.2f  %4.2f\n",a,b,c);
}
  fclose(wyjscie);

}
