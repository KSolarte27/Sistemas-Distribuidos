#include <stdio.h>
#include <fcntl.h>   // Para open, O_CREAT, etc.
#include <unistd.h>  // Para write, read, close
#include <string.h>

int main() {
    int fd;
    char mensaje[256];
    const char *filename = "Actividad1Optativa4.txt";

    printf("Escribe el mensaje que desea guardar en el archivo:\n");
    fgets(mensaje, sizeof(mensaje), stdin);


    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error al crear el archivo");
        return 1;
    }


    if (write(fd, mensaje, strlen(mensaje)) == -1) {
        perror("Error al escribir en el archivo");
        close(fd);
        return 1;
    }

    close(fd);

  
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }


    char buffer[128];
    int bytesRead;
    printf("\nContenido leido del archivo:\n");
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; 
        printf("%s", buffer);
    }

    close(fd);
    return 0;
}