#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct donde se almacena tamaño del laberinto y el laberinto en un solo string
struct scanner
{
    int size;
    char * maze;
};

//Funcion que obtiene el tamaño del maze al leer la primera linea
int getSize(FILE * fp) {
    char c;
    char * num = (char *)malloc(sizeof (char) * 1024);
    char * tmp = num;
    while ((c = getc(fp)) != '\n')
        *tmp++ = c;
    return atoi(num);
}

//Se construye un string con las posiciones del jugador, del objetivo, de las barreras y los espacios abiertos
//El string se devuelve junto y listo para ser iterado Ex. 1_*___*_*___*_*_*_*_*___*_*_*_*_***_*___*_*___*_*___*_***_*___*_*_*_____*_____*___*_*_*_*___*_*_*__2
char * buildString(char * maze, FILE * fp) {
    char c;
    char * tmp = maze;
    while ((c = getc(fp)) != EOF)
        if (c != '\n' && c != '\0' && (int)c != 10 && (int)c != 32)
            *tmp++ = c;
    *tmp = '\0';
    return maze;
}

//Se devuelve un struct scanner donde se almacena el tamaño del laberinto y un string con el laberinto
struct scanner buildScanner(FILE * fp, char * maze) {
    struct scanner sc;
    sc.size = getSize(fp);
    sc.maze = buildString(maze, fp);
    return sc;
}

//Funcion que abre el archivo maze.txt e inicializa variables para la construccion del struct scanner con los datos del maze
struct scanner scan()
{
    FILE * fp;
    char *maze = (char *)malloc(sizeof (char) * 1024);
    fp = fopen("maze.txt", "r");
    struct scanner sc = buildScanner(fp,maze);
    fclose(fp);
    return sc;
}

//Funcion de prueba
/*  int main(int argc, char const *argv[])
{
    struct scanner s = scan();
    printf("%d %s", s.size, s.maze);
    return 0;
} 
 */