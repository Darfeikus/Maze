struct scanner { int size; char * maze; };
int getSize(FILE * fp);
char * buildString(char * maze, FILE * fp);
struct scanner buildScanner(FILE * fp, char * maze);
struct scanner scan();