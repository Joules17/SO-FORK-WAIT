#include <stdio.h> //directiva de pre-compilacion
#include <unistd.h> 
#include <sys/wait.h>
#include "maxrand.h" // incluimos el random 

int main(int argc, char* argv[]) {
    pid_t pid; 
    pid = fork(); 
    if (pid == -1) { 
        printf("Error en la creacion del hijo \n"); 
        return -1;
    } else if (pid == 0) {
        printf("[%d] Soy el hijo \n", getpid()); 
        int random = maxrand(50); 
        printf("[%d] Soy el hijo. random: %d\n", getpid(), random); 
        return random;  // implementamos la funcion maxrand para que el hijo salga con un valor ALEATORIO
    } else {
        int status; 
        printf("[%d] Soy el padre \n", getpid());
        wait(&status); 
        printf("[%d] Mi hijo salio con codigo: %d\n", getpid(), WEXITSTATUS(status)); // imprime lo que retorno el proceso hijo
        printf("[%d] Hijo - estado de salida: %d\n", getpid(), WIFEXITED(status)); // imprime estado de salida
    }

    printf("[%d] Termino el programa \n", getpid()); 
    return 0; 
}
