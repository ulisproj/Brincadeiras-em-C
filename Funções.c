#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#define PI 3.14159265

float grausrad(float graus){
    float rad;
    rad=graus*(PI/180);
    printf("\n%.2f equivale a: %.2f",graus,rad);
}
float celkel(float graus){
    float kel;
    kel=graus+273;
}
float periarea(float catop, float catadj){
    float peri, area, hip;
    char unit[2];
    printf("\nQual a unidade de medida? cm, m, km\n\n");
    scanf("%s",&unit);
    hip=sqrt(pow(catop,2)+pow(catadj,2));
    peri=hip+catop+catadj;
    area=(catadj*catop)/2;
    printf("\nSeu triângulo retângulo tem área e perímetro respectivamente iguais a:\n%.2f %s\n%.2f %s²",area,unit,peri,unit);
}
float tabu(float x){
    int i;
    float val;
    for(i=0;i<10;i++){
        val=x*(i+1);
        printf("\n%.1f x %d = %.1f",x,(i+1),val);
    }
}
float soma(float vals[]){
    int i,j;
    float somat=0;
    for(i=0;i<10;i++){
        somat=somat+vals[i];
    }
    printf("\nA soma total desses valores é equivalente a: %.1f", somat);
}
int main(){
    int esc,i;
    float valorg1, valorg2, cat1, cat2, x, val[10];
    setlocale(LC_ALL, "Portuguese");
    printf("O que deseja realizar?\n\n1 - Conversão - Graus p/ Radianos\n2 - Conversão - Celsius p/ Kelvin");
    printf("\n3 - Perímetro e Área\n4 - Tabuada de multiplicação\n5 - Soma de 10 valores\n\n");
    scanf("%d",&esc);
    system("cls");
    switch(esc){
        case 1:
            printf("\nQual o valor em Graus que deseja converter?\n\n");
            scanf("%f",&valorg1);
            grausrad(valorg1);
            break;
        case 2:
            printf("\nQual o valor em Celsius que deseja converter?\n\n");
            scanf("%f",&valorg2);
            printf("\n\n%.1f° equivale a: %.2f K",valorg2,celkel(valorg2));
            break;
        case 3:
            printf("\nQual o valor do cateto oposto e adjacente, respectivamente?\n\n");
            scanf("\n%f",&cat1);
            scanf("\n%f",&cat2);
            periarea(cat1,cat2);
            break;
        case 4:
            printf("\nDeseja tabuada de que número?\n\n");
            scanf("%f",&x);
            tabu(x);
            break;
        case 5:
            printf("\nDigite a seguir os 10 valores:\n\n");
            for(i=0;i<10;i++){
                scanf("%f",&val[i]);
            }
            soma(val);
            break;
        default:
            printf("\n\nOpção inválida");
    }
}
