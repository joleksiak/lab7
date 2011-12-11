#include <stdio.h>
#include <stdlib.h>

int dni[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
		    {31,29,31,30,31,30,31,31,30,31,30,31}};

int przest(int rok){
  if ((rok%4==0)&&(rok%100!=0)) return 1;
  else if (rok%400==0) return 1;
		    else return 0;
}

int f_dzienroku(int rok, int miesiac, int dzien){
  int i;
  int suma=0;
  for (i=1;i<miesiac;i++) suma+=dni[przest(rok)][i-1];
  suma+=dzien;
  return suma;

}

void f_data(int rok, int dzienroku, int *miesiac, int *dzien){
  int i=0;
  int test=0;
    while (test+dni[przest(rok)][i]<dzienroku) {
    test+=dni[przest(rok)][i];
    i++;
  }

  *miesiac=i+1;
  *dzien=dzienroku-test;

}


main(int argc, char *argv[]){
  int rok,miesiac,dzien,dzienroku;
  if ((argc==1)||(argc==2)||(argc>4)) printf("O Co Ci Chodzi??");
  else if (argc>2){
    rok=atoi(argv[1]);
    if (argc==3){
      dzienroku=atoi(argv[2]);
      f_data(rok,dzienroku,&miesiac,&dzien);
      printf("%d-%d-%d\n\n",rok,miesiac,dzien);
    }
    else if (argc==4) {
     miesiac=atoi(argv[2]);
     dzien=atoi(argv[3]);
     printf("%d\n\n",f_dzienroku(rok,miesiac,dzien));

    }
  }
}

