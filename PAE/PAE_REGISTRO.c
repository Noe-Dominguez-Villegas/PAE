#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Estudiante {
    int numero_registro;
    char fecha[20];
    char matricula[20];
    char nombre_apellido[50];
    char estado[30];
};

void registrar_estudiante(struct Estudiante lista[], int *contador);
void asignar_pae(struct Estudiante lista[], int contador);
void consultar_demanda(struct Estudiante lista[], int contador);

int main() {
    struct Estudiante lista[6];
    int contador = 0;
    int opcion;

    printf("============================================================================\n");
    printf("Unidad didactica: Fundamentos de programacion \n");
    printf("Estudiante: Noe Dominguez Villegas \n");
    printf("Matricula: ES261112078 \n");
    printf("Grupo: DS-DFPR-2601-B1-007 \n");
    printf("============================================================================\n");

    do {
        printf("\nPROGRAMA DE ACTIVIDADES EXTRACURRICULARES \n");
        printf("1. Registro estudiante\n");
        printf("2. Asignacion PAE\n");
        printf("3. Consultar demanda PAE'S\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1: registrar_estudiante(lista, &contador); break;
            case 2: asignar_pae(lista, contador); break;
            case 3: consultar_demanda(lista, contador); break;
            case 4: printf("\nGracias por usar el Programa de Actividades Extracurriculares\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;
}

void registrar_estudiante(struct Estudiante lista[], int *contador) {
    if (*contador < 6) {
        printf("============================================================================\n");
        printf("\n REGISTRO ESTUDIANTE \n");
        printf("============================================================================\n");
        lista[*contador].numero_registro = *contador + 1;
        
        printf("Ingresa la matricula: ");
        scanf("%s", lista[*contador].matricula);
        getchar();

        printf("Ingresa el nombre completo: ");
        fgets(lista[*contador].nombre_apellido, 50, stdin);
        lista[*contador].nombre_apellido[strcspn(lista[*contador].nombre_apellido, "\n")] = 0;

        printf("Ingresa la fecha (dd/mm/aa): ");
        scanf("%s", lista[*contador].fecha);
        
        strcpy(lista[*contador].estado, "PENDIENTE");
        
        printf("\nESTUDIANTE REGISTRADO CON EXITO.\n");
        (*contador)++;
    } else {
        printf("\nLimite de registros alcanzado.\n");
    }
}

void asignar_pae(struct Estudiante lista[], int contador) {
    char mat[20];
    int op_taller;
    printf("\n--- ASIGNACION PAE ---\n");
    printf("Ingresa la matricula: ");
    scanf("%s", mat);

    for (int i = 0; i < contador; i++) {
        if (strcmp(lista[i].matricula, mat) == 0) {
            // Verificar si ya tiene asignación
            if (strcmp(lista[i].estado, "PENDIENTE") != 0) {
                printf("\nNo. Registro: %d\nFecha: %s\nEstudiante: %s\nEstado: %s\n", 
                        lista[i].numero_registro, lista[i].fecha, lista[i].nombre_apellido, lista[i].estado);
                printf("ESTUDIANTE CUENTA CON REGISTRO Y PAE ASIGNADO.\n");
                return;
            }

            printf("\nSeleccione el taller:\n1. DANZA\n2. PINTURA\n3. DEBATE\nOpcion: ");
            scanf("%d", &op_taller);
            if(op_taller == 1) strcpy(lista[i].estado, "ASIGNADO DANZA");
            else if(op_taller == 2) strcpy(lista[i].estado, "ASIGNADO PINTURA");
            else if(op_taller == 3) strcpy(lista[i].estado, "ASIGNADO DEBATE");
            
            printf("\nASIGNACION EXITOSA.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

void consultar_demanda(struct Estudiante lista[], int contador) {
    char talleres[3][20] = {"DANZA", "PINTURA", "DEBATE"};
    printf("\n=== 3. CONSULTAR DEMANDA PAE'S ===\n");
    
    for(int t = 0; t < 3; t++) {
        printf("\n====%s====\n", talleres[t]);
        for(int i = 0; i < contador; i++) {
            if (strstr(lista[i].estado, talleres[t]) != NULL) {
                printf("%s\n", lista[i].nombre_apellido);
            }
        }
    }
}




