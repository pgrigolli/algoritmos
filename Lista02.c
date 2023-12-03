#include <stdio.h>
#include <limits.h>

int print_function(int n, int v[]){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int is_perfect_number(int number){
    int divisores = 0;

    for(int i = 1; i < number; i++){
        if(number % i == 0){
            divisores += i;
        }
        else{
            i++;
        }
    }
    if(divisores == number){
        printf("E perfeito!\n");
        return 1;
    }
    else{
        printf("Nao e perfeito!\n");
        return 0;
    }
}

void print_factors(int number){
    //Achar os primos
    //Dividir pelo primo
    //Guardar a quantidade de divisões
    //Printar a quantidade de divisões e qual é o primo

int count, numero;
numero = number;

for(int i = 2; i < numero;){
    if(number % i == 0){

        number = (int)number/i;
        count += 1;
    }
    else{
        if (count * i != 0){

        printf(" %dx fator %d\n", count, i);
        count = 0;
        i++;
        }
        else{
            count = 0;
            i++;
        }
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

int mdc(int a, int b){
    int max;
    if (a > b){ //Achando o maior entre a e b
        max = a;
    }
    else{
        max = b;
    }


    int div_max;
    for(int i = 2; i < max; i++){
        if (a % i == 0 && b % i == 0){
            div_max = i;
        }
    }
    printf("%d", div_max);
}


int mmc(int a, int b){
    int max, min;
    if (a > b){
        max = a;
        min = b;
    }
    else{
        max = b;
        min = a;
    }

    int i = 1;
    int menor_mult;
    while (1){
        if ((max * i) % min == 0){
            menor_mult = max * i;
            printf("%d", menor_mult);
            break;
        }
        else{
            i++;
        }
    }
}

void print_even(int n, int vet[]){

    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            printf("%d ", vet[i]);
        }
    }
}


int set_positive(int n, int v[]){////////////////////////////////////////////////////////////
    for(int i = 0; i < n; i++){
        if (v[i] < 0){
            v[i] = v[i] * -1;
        }
    }
    print_function(n, v);
}//////////////////////////////////////////////////////////////


int is_sorted(int n, int vet[]){
    for (int i = 0; i < n - 1; i++){
        if (vet[i] > vet[i + 1]){
            return 0;
        }

    }
    return 1;
}

int find_max(int n, int v[]){
    int max = INT_MIN;

    for (int i = 0; i < n; i++){
        if (v[i] > max){
            max = v[i];
        }
    }
    return max;
}

int replace_all(int n, int v[], int elem){
    for (int i = 0; i < n; i++){
        if (v[i] == elem){
            v[i] = -1;
        }
    }
    print_function(n, v);
}

int reverse_array(int n, int v[]){
    int hold;
    for (int i = 0, j = n-1; i < n/2; i++, j--){
        hold = v[i];
        v[i] = v[j];
        v[j] = hold;
    }
    print_function(n, v);
}

int read_vector(int n, int v[]){
    int a;
    v[n] = 0;
    for (int i = 0; i < n; i++){
        printf("Insira um valor: ");
        scanf("%d", &a);
        v[i] = a;

    }

    print_function(n, v);
}

void count_elements(int n, int v[]){
    int cp[n];
    for(int i = 0; i < n; i++){
        cp[i] = v[i];
    }
    for(int i = 0; i < n; i++){
        int count = 1;
        if(cp[i] == 0) continue;
        for(int j = i + 1; j < n; j++){
            if(cp[i] == cp[j]){
                count++;
                cp[j] = 0;

            }
        printf("%d x [%d]\n", count, cp[i]);
        }
    }
}

void min_bills(int value, int n, int bills[]){
    //bills = 1, 5, 10, 50, 100
    int count[n], j = 1;

    while (value > 0){
        if (value > bills[n - j]){
            value = value - bills[n - j];
            count[n]++;
            j ++;
        }
        else{
            j++;
        }
    }
    print_function(n, count);

}

void vector_copy(int n, int vet1[], int vet2[]){
    for(int i = 0; i < n; i++){
        vet2[i] = vet1[i];
    }

    print_function(n, vet2);
}

int vector_insert(int n, int vet[], int elem){
    for (int i = 0; i < n; i++){
        if (vet[i] == -1){
            vet[i] = elem;
            print_function(n, vet);
            return 0;
        }
    }
    printf("Nao ha posicoes disponiveis para colocar %d", elem);
}

int vector_remove(int n, int vet[], int pos){
    if (pos > n - 1){
        printf("Posicao invalida");
    }
    for (int i = 0; i < n; i++){
        if (i == pos){
            vet[i] = -1;
            print_function(n, vet);
            return 0;
        }
    }
}

void vector_defrag(int n, int vet[n]){
    int vet2[n];
    for (int i = 0; i < n; i++){
        vet2[i] = vet[i];
    }
        print_function(n, vet);
    int k = 1;
    for (int j = 0; j < n; j++){
        if (vet2[j] == -1);
        vet[n - k] = -1;
        k++;
    }
        print_function(n, vet);
    int m = 1;
    for (int l = 0; l > n; l++){
        if (vet2[l] != -1){
            vet[k - m] = vet2[l];
        }
    }
    print_function(n, vet);
}/////


int vector_concat(int n1, int v1[n1], int n2, int v2[n2]){
    int v3[n1 + n2];
    for (int i = 0; i < n1; i++){
        v3[i] = v1[i];
    }
    for (int j = 0; j < n2; j++){
        v3[j + n1] = v2[j];
    }

    print_function(n1 + n2, v3);
}

int vector_union(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    for (int x = 0; x < n1; x++){
        v3[x] = v1[x];
    }
    int y = 0;
    for (int i = 0; i < (n1 + n2); i++){
        for (int j = 0; j < n2; j++){
            if (v2[j] == v3[i]){
                continue;
            }
            else{
                v3[n1 + y] = v2[j];
            }
        }
    }
    print_function(n1 + n2, v3);

}


int vector_intersec(int n1, int v1[n1], int n2, int v2[n2], int v3[]){
    int min = n1;
    if (n2 < min){
        min = n2;
    }



    int y = 0;
    for (int i = 0; i < n1 + n2; i++){
        for (int j = 0; j < min; j++){
            if (v1[i] == v2[j]){
                v3[y] = v2[j];
                y++;
            }
        }
    }
    print_function(n2, v3);
}


int merge(int n1, int v1[n1], int n2, int v2[n2], int v3[n1 + n2]){
    // Variavel que percorra por v1
    // Variavel que percorra por v2
    // Comparar uma com a outra
    // Colocar a menor entre as duas em v3

    int i = 0, j = 0, k = 0;
    
    // i vai percorrer por v1
    // j vai percorrer por v2

    while (i < n1){ // Percorrendo por v1
        while (j < n2){ // Percorrendo por v2
            if (v1[i] <= v2[j]){   
                v3[k] = v1[i];
                i++;
                k++;
            }
            else{
                v3[k] = v2[j];
                j++;
                k++;
            }

        }
    }
    print_function(n1 + n2, v3);

}


void max_sum_slice2(int n, int v1[]){
    int sum = 0;
    for (int i = 0; i < n ; i += 2){
        if (v1[i] + v1[i + 1] < 0){
            sum = 0;
        }
        else{
            sum += v1[i] + v1[i + 1];
        }
    }

    printf("%d ", sum);

}
int main(){
    int v2[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4 , 1};
    int v1[] = {5, 2, -2, -7, 3, 14,};
    int v3[12];
    
    vector_intersec(12, v1, 6, v2, v3);

}

void arrayIntersec(int size1, int v1[], int size2, int v2[], int v3[]){
    int menor;
    int maior;
    int index = 0;

    if(size1 > size2){
        maior = size1;
        menor = size2;
    }
    else{
        maior = size2;
        menor = size1;
    }

    for(int i = 0; i < maior; i++){
        for(int j = 0; j < menor; j++){
            if(maior == size1){
                if(v1[i] == v2[j]){
                    v3[index] = v2[j];
                    index++;
                }
            }
            else{
                if(v2[i] == v1[j]){
                    v3[index] = v2[i];
                    index++;
                }
            }
        }
    }
}

int main(){
    int v2[5] = {1,2,3,4,8};
    int v1[4] = {1,3,5,8};
    int v3[3] = {0};
    arrayIntersec(5, v2, 4, v1, v3);
    return 0;
}