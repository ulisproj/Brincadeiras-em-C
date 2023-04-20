#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define PI 3.14159265

char welcome(char text[200]){
    int i;
    for(i=0;i<50;i++){
        printf("-");
    }
    printf("\n%s\n",text);
    for(i=0;i<50;i++){
        printf("-");
    }
}
double rota(double eixorot[]){
    int i;
    char esc,eixos[3]={'x','y','z'};
    double seno,cosseno,angle,rotacoord[3];
    system("cls");
    printf("\nEm que eixo deseja realizar a rotação? (Atenção - Favor, digitar a letra em minúsculo)\n\n");
    scanf("\n%c",&esc);
    switch(esc)
    {
        case 'x':
            printf("\nEm que ângulo?\n\n");
            scanf("\n%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            rotacoord[0]=eixorot[0];
            rotacoord[1]=(eixorot[1]*cosseno)-(eixorot[2]*seno);
            rotacoord[2]=(eixorot[1]*seno)+(eixorot[2]*cosseno);
            for(i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],rotacoord[i]);
            }
            break;
        case 'y':
            printf("\nEm que ângulo?\n\n");
            scanf("\n%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            rotacoord[0]=(eixorot[0]*cosseno)+(eixorot[2]*seno);
            rotacoord[1]=eixorot[1];
            rotacoord[2]=-(eixorot[0]*seno)+(eixorot[2]*cosseno);
            for(int i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],rotacoord[i]);
            }
            break;
        case 'z':
            printf("\nEm que ângulo?\n\n");
            scanf("\n%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            rotacoord[0]=(eixorot[0]*cosseno)-(eixorot[1]*seno);
            rotacoord[1]=(eixorot[0]*seno)+(eixorot[1]*cosseno);
            rotacoord[2]=eixorot[2];
            for(int i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],rotacoord[i]);
            }
            break;
        default:
            printf("\nOpção Inválida\n");
            break;
    }
}
double trans(double eixotrans[]){
    int i;
    char esc,eixos[3]={'x','y','z'};
    double transcoord[3],valor[3];
    system("cls");
    printf("\nQuais os valores para translação em cada eixo, respectivamente?\n\n");
    for(i=0;i<3;i++){
        scanf("%lf",&valor[i]);
        transcoord[i]=eixotrans[i]+valor[i];
    }
    for(i=0;i<3;i++){
        printf("\nNovo %c: %.3lf",eixos[i],transcoord[i]);
    }

}
double homo(double eixohomo[]){
    int i;
    char esc,eixos[4]={'x','y','z','d'};
    double seno,cosseno,angle,homocoord[4],valor[4];
    system("cls");
    printf("\nQuais os valores para translação em cada eixo, respectivamente?\n\n");
    for(i=0;i<3;i++){
        scanf("%lf",&valor[i]);
    }
    valor[3]=1;
    printf("\nEm que eixo deseja realizar a rotação (Atenção - Favor, digitar a letra em minúsculo?)\n\n");
    scanf("\n%c",&esc);
    switch(esc){
        case 'x':
            printf("\nEm que ângulo?\n\n");
            scanf("%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            homocoord[0]=(eixohomo[0]+valor[0]);
            homocoord[1]=(eixohomo[1]*cosseno)-(eixohomo[2]*seno)+valor[1];
            homocoord[2]=(eixohomo[1]*seno)+(eixohomo[2]*cosseno)+valor[2];
            for(i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],homocoord[i]);
            }
            printf("\nNovo %c: %.3lf",eixos[3],valor[3]);
            break;
        case 'y':
            printf("\nEm que ângulo?\n\n");
            scanf("%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            homocoord[0]=(eixohomo[0]*cosseno)+(eixohomo[2]*seno)+valor[0];
            homocoord[1]=eixohomo[1]+valor[1];
            homocoord[2]=-(eixohomo[0]*seno)+(eixohomo[2]*cosseno)+valor[2];
            for(i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],homocoord[i]);
            }
            printf("\nNovo %c: %.3lf",eixos[3],valor[3]);
            break;
        case 'z':
            printf("\nEm que ângulo?\n\n");
            scanf("%lf",&angle);
            seno=sin(angle*PI/180);
            cosseno=cos(angle*PI/180);
            homocoord[0]=(eixohomo[0]*cosseno)-(eixohomo[1]*seno)+valor[0];
            homocoord[1]=(eixohomo[0]*seno)+(eixohomo[1]*cosseno)+valor[1];
            homocoord[2]=eixohomo[2]+valor[2];
            for(i=0;i<3;i++){
                printf("\nNovo %c: %.3lf",eixos[i],homocoord[i]);
            }
            printf("\nNovo %c: %.3lf",eixos[3],valor[3]);
            break;
        default:
            printf("\nOpção inválida\n");
            break;
    }


}
int main(){
    int resp,i,cont;
    double coorden[3];
    setlocale(LC_ALL, "Portuguese");
    welcome("Seja bem-vindo(a)");
    do{
        printf("\n\nO que deseja realizar?\n");
        printf("\n1 - Rotação\n2 - Translação\n3 - Transformação Homogênea\n\n");
        printf("Opção selecionada --> ");
        scanf("%d",&resp);
        switch(resp){
            case 1:
                printf("\n\nPor favor, digite as coordenadas x, y e z a seguir, respectivamente:\n\n");
                for(i=0;i<3;i++){
                    scanf("%lf",&coorden[i]);
                }
                rota(coorden);
                break;
            case 2:
                printf("\n\nPor favor, digite as coordenadas x, y e z a seguir, respectivamente:\n\n");
                for(i=0;i<3;i++){
                    scanf("%lf",&coorden[i]);
                }
                trans(coorden);
                break;
            case 3:
                printf("\n\nPor favor, digite as coordenadas x, y e z a seguir, respectivamente:\n\n");
                for(i=0;i<3;i++){
                    scanf("%lf",&coorden[i]);
                }
                homo(coorden);
                break;
            default:
                printf("\nOpção inválida\n");
            }
        printf("\n\n\nDeseja realizar outra operação?\n\n");
        printf("1 - Sim\n2 - Não\n\n");
        scanf("%d",&cont);
        if(cont==1){
            system("cls");
        }
    }while(cont==1);
}
