//Para acceder a el puntero en una estructura, se utiliza la flecha 
//El . es para acceder dentro de la estructura
#include <stdio.h>
#include <string.h>
#include "funciones.h"


Libro biblioteca[Max_Libros];
int cont_li = 0;

void registrarLibro() {
    if (cont_li >= Max_Libros) {
        printf("\nLa biblioteca esta llena. No se pueden agregar mas libros.\n");
        return;
    }

    Libro nuevoLibro;
    printf("\nIngrese el ID del libro: ");
    scanf("%d", &nuevoLibro.id);

    // Verificar que el ID sea unico.
    for (int i = 0; i < cont_li; i++) {
        if (biblioteca[i].id == nuevoLibro.id) {
            printf("El ID ya existe. Intente con un ID diferente.\n");
            return;
        }
    }
    getchar(); 
    printf("Cual es el titulo del libro: ");
    fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = 0; // Quitar el salto de linea.

    printf("Cual es el autor del libro: ");
    fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = 0;

    printf("Ingrese el anio de publicacion del libro: ");
    scanf("%d", &nuevoLibro.anio_publicacion);

    strcpy(nuevoLibro.estado, "Disponible");

    biblioteca[cont_li++] = nuevoLibro;
    printf("Libro registrado con exito.\n");
}

void mostrarLibros() {
    if (cont_li == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }
 printf("\nLista de libros:\n");
    printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    for (int i = 0; i < cont_li; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio_publicacion,
               biblioteca[i].estado);
    }
}

void buscarLibro() {
    if (cont_li == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    int opcion;
    printf("\nBuscar libro por:\n");
    printf("1. ID\n");
    printf("2. Titulo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
  if (opcion == 1) {
        int id;
        printf("Ingrese el ID del libro: ");
        scanf("%d", &id);

        for (int i = 0; i < cont_li; i++) {
            if (biblioteca[i].id == id) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio_publicacion,
                       biblioteca[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else if (opcion == 2) {
        char titulo[100];
        getchar(); 
        printf("Ingrese el titulo del libro: ");
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = 0;
                for (int i = 0; i < cont_li; i++) {
            if (strcmp(biblioteca[i].titulo, titulo) == 0) {
                printf("\nLibro encontrado:\n");
                printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio_publicacion,
                       biblioteca[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else {
        printf("Opcion no valida.\n");
    }
}

void actualizarEstado() {
    if (cont_li == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    int id;
    printf("\nIngrese el ID del libro: ");
    scanf("%d", &id);
      for (int i = 0; i < cont_li; i++) {
        if (biblioteca[i].id == id) {
            if (strcmp(biblioteca[i].estado, "Disponible") == 0) {
                strcpy(biblioteca[i].estado, "Prestado");
                printf("El estado del libro ha sido actualizado a 'Prestado'.\n");
            } else {
                strcpy(biblioteca[i].estado, "Disponible");
                printf("El estado del libro ha sido actualizado a 'Disponible'.\n");
            }
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro() {
    if (cont_li == 0) {
        printf("\nNo hay libros registrados.\n");
        return;
    }

    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < cont_li; i++) {
        if (biblioteca[i].id == id) {
            for (int j = i; j < cont_li - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            cont_li--;
            printf("Libro eliminado con exito.\n");
                        return;
        }
    }
    printf("Libro no encontrado.\n");
}
