/*
El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los
colegios secundarios. Los primeros datos que ingresar son la fecha (enteros, mes entre 1 y
12, y año mayor a 2024) y la cantidad de colegios de la ciudad en que se realizó la encuesta
(entero, mayor a cero).
De cada colegio se conoce:
• Número de escuela (entero, mayor a cero)
• La cantidad de alumnos inscriptos (entero, entre 1 y 35)
• La especialidad (caracter, ‘T’: técnico, ‘N’: no técnico).
De cada alumno del colegio que respondió la encuesta se conoce:
• DNI (entero, entre 1 y 99999999)
• Edad (entero, entre 10 y 25)
• Sexo (carácter, ‘M’, ‘F’ o ‘X’)
• Opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos)
Se identifica el fin de ingreso de datos de los alumnos que respondieron la encuesta por
cada colegio con el ingreso de DNI igual a cero del estudiante.
Informar:
a) Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la
cantidad de alumnos inscriptos del colegio.
b) Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta.
c) Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que
respondieron la encuesta.
d) Porcentaje de estudiantes que respondieron que los conocimientos adquiridos
eran malos, sobre el total de encuestados.
e) El alumno de mayor edad de los estudiantes encuestados, informando el DNI, el
número de escuela y la especialidad que posee.
f) Número del colegio con mayor opinión buena sobre los conocimientos
adquiridos.
*/

#include<stdio.h>

int main(){
    int mes, cant_colegios;
    int colegioOpinionBuena = 0;
    int num_escuela,inscriptos;
    char especialidad;
    int respondieron;
    int noTecnicos = 0, respTot = 0, malosCon = 0;
    int mujeresTecnicas = 0;
    int DNI, edad;
    char sexo, opinion;
    int mayorEdad = 0;
    int DNIMayor = 0;
    int NumEscuelaMayor = 0;
    char TecnicaMayor;
    int colegio_opi = 0;
    int num_esc_opi = 0;
    printf("Ingresar un mes (1 a 12): ");
    scanf("%d",&mes);
    while(mes < 1 || mes > 12){
        printf("\nIngrese un mes valido: ");
        scanf("%d",&mes);
    }

    printf("\nIngrese la cantidad de colegios: ");
    scanf("%d",&cant_colegios);
    while(cant_colegios <= 0){
        printf("\nIngrese una cantidad positiva de colegios: ");
        scanf("%d",&cant_colegios);
    }
    while(cant_colegios--){
        printf("\nIngrese el numero de la escuela: ");
        scanf("%d",&num_escuela);
        while(num_escuela <= 0){
            printf("\nIngrese un valor mayor a cero: ");
            scanf("%d",&num_escuela);
        }
        printf("\nIngrese la cantidad de inscriptos: ");
        scanf("%d",&inscriptos);
        while(inscriptos <= 0 || inscriptos >= 36){
            printf("\nIngrese la cantidad de inscriptos valida: ");
            scanf("%d",&inscriptos);
        }
        printf("Ingrese la especialidad: ");
        getchar();
        scanf("%c",&especialidad);
        while(especialidad != 'T' && especialidad != 'N'){
            printf("\nIngrese una especialidad valida: ");
            getchar();
            scanf("%c",&especialidad);
        }
        printf("Ingrese la cantidad de alumnos que respondieron: ");
        scanf("%d",&respondieron);
        if(especialidad == 'N'){
            noTecnicos+=respondieron;
        }
        while(respondieron > inscriptos || respondieron <= 0){
            printf("Ingrese una cantidad razonable: ");
            scanf("%d",&respondieron);
        }
        respTot+=respondieron;
        printf("Respondieron la encuesta %.2f%%: ",respondieron/inscriptos*100.0);
        while(respondieron--){
            printf("\nIngrese el DNI: ");
            scanf("%d",&DNI);
            while(DNI < 0){
                printf("INGRESE UN DNI VALIDO: ");
                scanf("%d",&DNI);
            }
            printf("\nIngrese la edad: ");
            scanf("%d",&edad);
            printf("\nIngrese el sexo: ");
            getchar();
            scanf("%c",&sexo);
            while(sexo != 'M' && sexo != 'F' && sexo != 'X'){
                printf("\nIngrese un sexo valido: ");
                getchar();
                scanf("%c",&sexo);
            }
            if(sexo == 'F' && especialidad == 'T') mujeresTecnicas++;
            printf("\nIngrese su opinion: ");
            getchar();
            scanf("%c",&opinion);
            while(opinion != 'B' && opinion != 'M'){
                printf("\nIngrese una opinion valida: ");
                getchar();
                scanf("%c",&opinion);
            }
            if(opinion == 'M') malosCon++;
            if(mayorEdad < edad){
                mayorEdad = edad;
                NumEscuelaMayor = num_escuela;
                DNIMayor = DNI;
                TecnicaMayor = especialidad;
            }
            if(opinion == 'B') colegioOpinionBuena++;
        }
        if(colegioOpinionBuena > colegio_opi){
            colegio_opi = colegioOpinionBuena;
            num_esc_opi = num_escuela;
        }
    }
    printf("\nLa cantidad de alumnos de colegios no tecnicos que contestaron fue de: %d ",noTecnicos);
    printf("\nEl porcentaje de mujeres que respondieron la encuesta y son de tecnicas es de: %.2f",mujeresTecnicas/respTot*100.0);
    printf("\nEl porcentaje de estudiantes que respondieron que los conocimientos eran malos fue de %.2f%%: ",malosCon/respTot * 100.0);
    printf("\nEl alumno de mayor edad tiene DNI %d, su escuela es n°%d y su especialidad es %c",DNIMayor, NumEscuelaMayor, TecnicaMayor);
    printf("\nEl numero del colegio con mayor opinion buena fue: %d",num_esc_opi);
}