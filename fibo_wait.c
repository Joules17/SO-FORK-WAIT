#include <stdio.h> //directiva de pre-compilacion
#include <unistd.h> 
#include <sys/wait.h>

void fibo(int num) {
    int i = 0, j = 1, sum; 
    for (int x = 0; x < num; x++) {
        sum = i + j; 
        if (x == num - 1) {
            printf("%d", sum);
        } else {
            printf("%d - ", sum); 
        }
        i = j; 
        j = sum;
    }
    printf("\n"); 
}

int main(int argc, char* argv[]) {
    pid_t pid; 
    pid = fork(); 
    if (pid == -1) { 
        printf("Error en la creacion del hijo \n"); 
        return -1;
    } else if (pid == 0) {
        printf("[%d] Soy el hijo \n", getpid()); 
        printf("Sucesion de Fibonacci de 25:\n"); 
        fibo(25);
    } else {
        printf("[%d] Soy el padre, esperare \n", getpid());
        wait(NULL);
        printf("[%d] Mi hijo ya termino\n", getpid()); 
    }

    printf("[%d] Termino el programa \n", getpid()); 
    return 0; 
}


