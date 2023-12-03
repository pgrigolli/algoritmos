#include <stdio.h>
#define PI 3.141593

int soma_sub(){ //Ex01: Ler dois numeros e fazer a soma e a sub;
    int a;
    int b;
    printf("Insira dois valores: ");
    scanf("%d %d", &a, &b);

    int soma = a + b;
    int sub = a - b;
    printf("A soma dos dois numeros e %d e a subtracao e %d", soma, sub);
    return 0;
}

int mult_div(){ //Ex02: Ler dois numeros e fazer a mult, div int e div float;
    int a;
    int b;
    printf("Insira dois valores: ");
    scanf("%d %d", &a, &b);
    int mult = a * b;
    int div_inteira =  a / b;
    float div_float = (float)a / b;


    printf("A multiplicacao desses dois numeros e %d, a divisao inteira e %d e a divisao float e %f", mult, div_inteira, div_float);
    return 0;

}

int circle(){ //Ex03
    int r;
    printf("Insira um valor para o raio: ");
    scanf(" %d", &r);

    int diametro = 2*r;
    float circ = 2 * PI * r;
    float area = PI * r * r;

    printf("o diametro e: %d, a circunferencia e: %f e a area e: %f", diametro, circ, area);
}


int resto(){ //Ex04
    int a, b;
    int resto1, resto2, temp;

    printf("Insira os valores de a e b: ");
    scanf("%d %d", &a, &b);
    
    resto1 = a % b;
    temp = (a / b) * b;
    resto2 = a - temp;

    printf(" %d %d", resto1, resto2);
    return 0;



}

int tabuada(){
    int num;

    printf("Insira um numero para a tabuada: ");
    scanf("%d", &num);

    printf("1 x %d = %2d     6 x %d = %2d\n", num, num * 1, num, num * 6);
    printf("2 x %d = %2d     7 x %d = %2d\n", num, num * 2, num, num * 7);
    printf("3 x %d = %2d     8 x %d = %2d\n", num, num * 3, num, num * 8);
    printf("4 x %d = %2d     9 x %d = %2d\n", num, num * 4, num, num * 9);
    printf("5 x %d = %2d     10 x %d = %2d\n", num, num * 5, num, num * 10);


}

void print_float(float float_num){
    int parte_inteira;
    float parte_decimal;

    parte_inteira = (int)float_num;
    parte_decimal = float_num - parte_inteira;

    printf("%.2f\n", float_num);
    printf("%d\n", parte_inteira);
    printf("%f\n", parte_decimal);
    printf("%e\n", float_num);


}

void print_days(int days){
    int anos, resto_semanas, semanas, dias, resto_anos;


    dias = days;


    resto_anos = days % 365;
    days -= resto_anos;
    anos = days / 365;
    days = resto_anos;

    resto_semanas = days % 7;
    days -= resto_semanas;
    semanas = days / 7;
    days = resto_semanas;

    


    printf("%d dias e igual a %d ano(s), %d semana(s) e %d dia(s).",dias, anos, semanas, days);
}

int is_leap_year(int year){
    if (year % 4 == 0 && !(year % 100 == 0)){
        printf("Bissexto!\n");
    }
    else if(year % 400 == 0)
        printf("Bissexto!\n");


    else{
    printf("Nao e bissexto!\n");
    }


}

void print_sorted(int a, int b, int c){
    int max;
    int max2;
    int max3;
    if (a > b && a > c){
        max = a;
        if(b > c){
            max2 = b;
            max3 = c;
        }

        else{
            max2 = c;
            max3 = b;    
            
        }
    }
    else if(b > c){
        max = b;
        if(a > c){
            max2 = a;
            max3 = c;
        }
        else{
            max2 = c;
            max3 = a;
        }
    }
    else{
        max = c;
        if(a > b){
            max2 = a;
            max3 = b;
        }
        else{
            max2 = b;
            max3 = a;
        }

    }
    printf("%d e o maior, %d e o segundo maior, %d e o menor", max, max2, max3);



}


void print_grade(float n1, float n2, float n3){
    int media = (n1 + n2 + n3) / 3;

    if (media <= 10 && media >= 8.5)
        printf("Conceito A\n");

    else if (media < 8.5 && media >= 7)
        printf("Conceito B\n");

    else if (media < 7 && media >= 5.5)
        printf("Conceito C\n");
    
    else{
        printf("Conceito D\n");
    }
}

void letter_check(){
    char caractere;

    printf("Insira um caracter: "); 
    scanf(" %c ", &caractere);

    if (caractere > 'a'){
        printf("Nao e caractere.");
    }
    else{
        printf("É caractere");
        if (caractere < 96){
            caractere += 32;
            printf("%c", caractere);
        }
        else{
            printf("%c",caractere);
        }
    }

}

int inverso(){
    int num;
    int negativo = 1;
    int digito;
    printf("Insira um numero: ");
scanf(" %d", &num);

    if (num < 0){
        num = num * (-1);
        negativo = -1;
    }


    while (1){
        if(num >= 10){
            digito = num % 10;
            num = (int)num / 10;
            digito = digito * negativo;
            printf("%d", digito);
        }
        else{
            break;
        }
    }
    printf("%d", num);
}


void por_extenso(){
    int num, digito;
    printf("Insira um numero: ");
    scanf(" %d", &num);

    
    digito = num % 10;
    if (digito = 1){
        printf("Mil");
    }
    if (digito = 2){
        printf("Dois Mil");
    }
    if (digito = 3){
        printf("Tres Mil");
    }
    if (digito = 4){
        printf("Quatro Mil");
    }
    if (digito = 5){
        printf("Cinco Mil");
    }
    if (digito = 6){
        printf("Seis Mil");
    }
    if (digito = 7){
        printf("Sete Mil");
    }
    if (digito = 8){
        printf("Oito Mil");
    }
    if (digito = 9){
        printf("Nove Mil");
    }
    


}
int main(){

}