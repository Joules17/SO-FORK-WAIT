#include <stdio.h> //directiva de pre-compilacion
#include <unistd.h> 
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int contador = 1; 
    pid_t pid = fork(); 
    if (pid == -1) {
        printf("Error en la creación del hijo \n");
        return -1; 
    } else if (pid == 0) {
        printf("[%d] Soy el hijo \n", getpid());
        contador = contador + 5;
    } else {
        printf("[%d] Soy el padre \n", getpid());  
        contador = contador + 2;
    
    }

    printf("[%d] Termino el programa \n", getpid()); 
    printf("[%d] Valor del contador: %d \n", getpid(), contador); 
    return 0; 
} 