#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void print_matrix(int rows, int cols, int m[rows][cols]){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void print_reversed_matrix(int rows, int cols, int m[rows][cols]){
    for(int i = rows - 1; i >= 0; i--){
        for(int j = cols - 1; j >= 0; j--){
            printf("%d ", m[i][j]);
        }
    }
    printf("\n");
}


void print_min_max(int rows, int cols, int m[rows][cols]){

    int min = INT_MAX;
    int max = INT_MIN;

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (m[i][j] < min){
                min = m[i][j]; 
            }
            if (m[i][j] > max){
                max = m[i][j];
            }
        }
    }
    printf("min: %d, max: %d \n", min, max);
}

float matrix_average(int rows, int cols, int m[rows][cols]){
    
    float div = rows * cols;
    int sum = 0;
    
    for (int i = 0; i < rows; i++){
        int j = 0;
        for (; j < cols; j++){
            sum += m[i][j];
        }
    }
    
    float media = sum / div;
    printf("sum: %d \n", sum);
    printf("media: %.2f \n", media);
}

void init_values(int rows, int cols, int m[rows][cols], int start, int step){
    int num = start;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m[i][j] = num;
            num += step;
        }
    }
    print_matrix(rows, cols, m);
}

void init_random(int rows, int cols, int m[rows][cols], int min, int max){

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
        int num = min + (rand() % (max - min + 1));
            m[i][j] = num;
        }
    }
    print_matrix(rows, cols, m);
}


int max_line(int rows, int cols, int m[rows][cols]){

    int sum = 0;
    int maior_soma = 0;
    int linha = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
                sum += m[i][j];
        }
        if (sum > maior_soma){
            maior_soma = sum;
            linha = i;
            
        }
        sum = 0;
    }
    printf("A maior soma é %d\n", maior_soma);
    printf("E está na linha %d\n", linha);

}

void put_totals(int rows, int cols, int m[rows][cols]){

    int sum = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            sum += m[i][j];
        }
        m[i][cols-1] = sum;
        sum = 0;
    }
    print_matrix(rows, cols, m);
}

int matrix_equals(int rows1, int cols1, int m1[rows1][cols1], int rows2, int cols2, int m2[rows2][cols2]){
    if (rows1 != rows2 || cols1 != cols2){
        return 0;
    }
    for(int i = 0; i < rows1; i++){
        for (int j = 0; j < cols1; j++){
            if (m1[i][j] != m2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}


void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    print_matrix(rows, cols, m3);
}


void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    if (r1 == c2 && r2 == c1){
        for(int i = 0; i < r1; i++){
            for (int j = 0; j < c1; j++){
                m2[j][i] = m1[i][j];
            }
        }
            
        }
    
    print_matrix(r2,c2,m2);
}

void switch_diagonals(int d, int m1[d][d]){
    int j = 0;
    int temp = 0;
    int last = d-j;

    for(int i = 0; i < d; i++){
        temp = m1[i][i];
        m1[i][i] = m1[i][last];
        m1[i][last] = temp;
        last--;
    }
    print_matrix(3, 3, m1);

};


void pascal_triangle(int n){

    int m1[n][n+1];

    for(int i = 0; i < n + 1; i++){
        if (i == 1){
            m1[0][i] = 1;
        }else{
        m1[0][i] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            m1[i + 1][j] = m1[i][j] + m1[i][j+ 1];
        }
    }
    print_matrix(n, n, m1);



}


int check_upper_triangule(int d, int m1[d][d]){

    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(i > j && m1[i][j] != 0){
                return 0;
            }

        }

    }
    return 1;
}


int check_identity(int rows, int cols, int m[rows][cols]){

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (i == j){
                if (m[i][j] != 1){
                    return 0;
                }
            }
            else{
                if (m[i][j] != 0 || m[j][i] != 0){
                    return 0;
                }
            }
        }
    }
    return 1;

}

int check_symetric(int d, int m[d][d]){

    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if (i != j){
                if(m[i][j] != m[j][i]){
                    return 0;
                }
            }


        }
    }
    return 1;
}

int print_strings(int n, int len, char list[n][len]){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < len; j++){
            printf("%c", list[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}



void print_string_minmax(int n, int len, int list[n][len]){

    int min = INT_MAX, max = INT_MIN;
    int min_str = 0, max_str = 0;

    for(int i = 0; i < n; i++){
        if(strlen(list[i]) < min){
            min = strlen(list[i]);
            min_str = i;
        }     
        if(strlen(list[i]) > max)){
            max = strlen(list[i]);
            max_str = i;
        }  

    }


    printf("Maior: %s", list[max_str]);
    printf("Menor: %s", list[min_str]);


}






int main(){


char list[6][10] = {"Pedro", "Jujuba", "Eduardo", "Kaike", "Felipe", "Vitinho"};

print_string_minmax(6, 10, list);

}