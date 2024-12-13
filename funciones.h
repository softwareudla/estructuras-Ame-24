#define FUNCIONES_H
#define FUNCIONES_H

#define Max_Libros 20

typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    char estado[15]; 
} Libro;

extern Libro biblioteca[Max_Libros];
extern int cont_li;

void registrarLibro();
void mostrarLibros();
void buscarLibro();
void actualizarEstado();
void eliminarLibro();