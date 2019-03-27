//Programa que simula el funcionamiento del algoritmo Round Robin

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Se crea un registro que contiene 3 variables
struct PROCESO{
    char nombre[1];
    int tamanioInicial;
    int tamanioRestante;
};

//Prototipos de funciones
void mostrarMenu(PROCESO[], int);
void ingresarDatos(PROCESO[], int, int);
void ejecutar(PROCESO[], int, int, int N);
void mostrarProcesos(PROCESO[], int, int N, int);

int main()
{
    //Se crea un arreglo de tipo Proceso para almacenar 3 variables en cada índice
    PROCESO proceso[9];
    int quantum;

    cout << "\t\t***BIENVENIDO AL PROYECTO 1 SISTEMAS OPERATIVOS***\n\n";

    //Pide el quantum mientras este este fuera del rango estipulado
    do{
        cout << "Ingrese el valor del Quantum (numero del 1 al 10): ";
        cin >> quantum;
      }while(quantum < 1 || quantum > 10);

    mostrarMenu(proceso, quantum);

    cout << endl;

    system("pause");

    return 0;
}

//Esta funcion muestra el menú principal
void mostrarMenu(PROCESO p[], int quantum)
{
    int opcion;
    int contador = 0;
    int N = 0;

    do{
        cout << "\n**Seleccione la opcion que desee realizar**\n"
             << "1. Ingresar proceso\n"
             << "2. Ejecutar procesos\n"
             << "3. Salir" << endl;
        cin >> opcion;

        //Dependiendo de la opcion escogida realizará una funcion
        switch (opcion)
        {
            case 1: ingresarDatos(p, quantum, contador);
                    break;
            case 2: ejecutar(p, quantum, contador, N);
                    break;
            case 3: cout << "PROGRAMA TERMINADO" << endl;
                    break;
            default: cout << "No ingreso una opcion valida" << endl;
        }
        //si escoge la opcion 1 suma al contador
        //esto es para llevar la cuenta de los datos ingresados
        if(opcion == 1)
            contador++;

        //Si escoge la opcion 2 suma 1 a N
        //esto es para llevar la cuenta de las ejecuciones
        if(opcion == 2)
            N++;

        //si las ejecuciones son mayores a contador menos 1, ejecucion se vuelve 0
        // esto es para iniciar el ciclo de nuevo
        if(N > contador-1)
            N = 0;

        //Esto es para terminar el programa en caso de que todos los procesos sean menores o iguales a 0
        int suma = 0;
            for (int i=0; i < contador; i++)
            {
                if ((p[i].tamanioRestante) > 0)
                suma++;
            }

            if (suma <= 0){
                opcion = 3;
                cout << "\nLa lista de procesos esta vacia"
                     << "\nTerminando programa...\n" << endl;
            }


    }while (opcion != 3);

}

//Esta funcion es para ingresar datos
void ingresarDatos(PROCESO p[], int quantum, int contador)
{
    cout << "\nPor favor ingrese el nombre del proceso (letra de la A a la Z): ";
    cin >> p[contador].nombre;
    cout << endl;

    //se ejecuta este codigo reiteradas ocaciones mientras este fuera del rango
    //Luego se asigna el tamaño inicial y se copia también a tamaño restante
    //esto para dejar a tamaño inicial como una constante y restar a tamaño restante
    do{
    cout << "Ingrese el tamanio del proceso (numero del 1 al 20): ";
    cin >> p[contador].tamanioInicial;
    p[contador].tamanioRestante = p[contador].tamanioInicial;
    cout <<endl;}
    while(p[contador].tamanioInicial < 1 || p[contador].tamanioInicial > 20);
}

//Funcion para ejecutar procesos
void ejecutar(PROCESO p[], int quantum, int contador, int N)
{
        //resta el quántum al tamaño del proceso
        p[N].tamanioRestante -= quantum;

        int suma = 0;
            //comprueba cuales procesos son mayores que 0
            // para no mostrarlos en pantalla
            for (int i=0; i < contador; i++)
            {
                if ((p[i].tamanioRestante) > 0)
                suma++;
            }

        mostrarProcesos(p, contador, N, suma);
}

//funcion para mostrar procesos
void mostrarProcesos(PROCESO p[], int contador, int N, int suma)
{

    int cont2 = 0;

        //si el proceso es menor que cero no se muestra
        if (suma <= 0)
        {
            ;
        }
        else
        {
          cout <<setw(6) << "Proceso" << setw(20) << "Tamanio Inicial" << setw(25) << "Tamanio Restante\n";
        }

        //Imprime todos los procesos mayorea que 0
        for(int i = N; i < contador; i++){
            if(p[i].tamanioRestante <= 0)
            {
                cont2++;
                continue;
            }
            cout << setw(6) << p[i].nombre << setw(20) << p[i].tamanioInicial << setw(25) << p[i].tamanioRestante << endl;
            cont2++;

        }

        //Muetra los proceso quehan sido enviados al final de la lista
        if(cont2 != contador){
            for(int i = 0; i < (contador-cont2); i++){
                if(p[i].tamanioRestante <= 0)
                   {
                      continue;
                   }

            cout << setw(6) << p[i].nombre << setw(20) << p[i].tamanioInicial << setw(25) << p[i].tamanioRestante << endl;
            }
        }

}

