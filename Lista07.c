#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


int* create_vector(int n){

    int *v = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) *v = 0;
    return v;

}

int* get_largest(int n, int* v, int max){

    int largest = v[0];
    int largest_idx = 0;
    int *v1= malloc(max * sizeof(int));


    for(int i = 0; i < max; i++){

        for(int j = 0; j < n; j++){

            largest = v[largest_idx];

            if(v[j] > largest){
                largest = v[j];
                largest_idx = j;
            }

        }
            v1[i] = largest;
            v[largest_idx] = INT_MIN;


    }

    for(int i = 0; i < max; i++){
        printf("%d ", v1[i]);
    }


}

char* copy_string(const char* str){

    char* str1 = malloc(strlen(str) * sizeof(char));

    for(int i = 0; str[i] != '\0'; i++){
        str1[i] = str[i];
        
    }

    return str1;

}

char* copy_reversed(const char* str){

    char* str1 = malloc(strlen(str) * sizeof(char));

    for(int i = 0; str[i] != '\0'; i++){
        str1[i] = str[strlen(str) - i];
        
    }

    return str1;

}

char* concat_string(const char* str1, const char* str2){

    char* str3 = malloc((strlen(str1) +strlen(str2)) * sizeof(int));
    int count = 0;

    for(int i = 0; str1[i] != '\0'; i++){
        str3[i] = str1[i];
        count++;
        
    }

    for (int i = 0; str2[i] != '\0'; i++){
        str3[count] = str2[i];
        count++;
    }
    
    return str3;
}

void print_vector(int n1, int* v1){
    for(int i = 0;  i < n1; i++){
        printf("%d ", *v1);
        v1++;
    }
    printf("\n"); 
}

int* union_vet(int n1, const int* v1, int n2, const int* v2){
    int * v3 = malloc((n1 + n2) * sizeof(int));
    int * a = v3;
    for(int count = 0; count < n1; count++){
        *v3 = *v1;
        v1++;
        v3++;
    }

    for(int count = 0; count < n2; count++){
        *v3 = *v2;
        v2++;
        v3++;
    }

    print_vector(n1 + n2, a);

}

int* vet_intersec(int n1, const int * v1, int n2, const int * v2){
    int * v3 = malloc((n1) * sizeof(int));
    int count = 0;

    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(*v1 == *v2){
                *v3 = *v1;
                v3++;
                count++;
            }
            v2++;

        }
    v1++;
    v2 -= n2;
    }
    v3 -= count;

    print_vector(n1, v3);
}

void print_vector2D(int m, int n, int** v){

    for(int i = 0; i < m*n; i++){
        printf("%d ", **v);
        v++;
        if(i % n == 0){
            printf("\n");
        }
    }

}



int main(){

    // EX 01 //

    // printf("\n%p\n", create_vector(7));

    // EX 02 //

    // int v1[7] = {1,2,3,4,5,6,7};

    // get_largest(7, v1, 7);

    // EX 03 //

    // char str[] = "John Doe";

    // char* str1 = copy_string(str); 
    // printf("%s\n", str1);

    // EX 04 //

    // char str[] = "John Doe";
    // char* str1 = copy_reversed(str);
    // printf("%s\n", str1);

    // EX 05 //

    // char str1[] = "John Doe";
    // char str2[] = "is boring";
    // char* str3 = concat_string(str1, str2);
    // printf("%s\n", str3);

    // EX 06 //
    // int v1[] = {1,2,3,4,5,6};
    // int v2[] = {9,8,7,6,5,4};
    // union_vet(6, v1, 6, v2);

    // EX 07 //

    // int v1[] = {1,2,3,4,5,6};
    // int v2[] = {9,8,7,6,5,4};
    // vet_intersec(6, v1, 6,v2);
    
    // EX 08 //

    int v[][4] = { {1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12}};
    int** p_v = v;


                
    print_vector2D(3,4,p_v);
    
    
    
    return 0;

}