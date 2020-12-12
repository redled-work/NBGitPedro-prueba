// Paniagua Falo Pedro Jose (hace entrega de la practica en Canvas)

// Apellido1 Apellido2, Nombre del alumno 2

#include <stdio.h>

#include <string.h>

#include <ctype.h>

// Resto de include necesarios



#define MAX_CAD 100

#define MAX_ARM 3

// Si se hace uso de constantes deben definirse aqui

struct disfraz
{
   char nombre[MAX_CAD];
   short traje;
   short gorra;
   float precio;
};


   struct disfraz armario[MAX_ARM] = {
                                        { "vampiro", 0, 1, 3.5 }
                                      , { "bruja",   1, 1, 4.5 }
                                      , { "momia", 1, 0, 7.5 }
                                     };



int insertarParte( struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[], float precioParte, char tipo[] );

void mostrarDisfraces( struct disfraz armario[], int capacidadMaxima );

struct disfraz buscarDisfraz( struct disfraz armario[], int capacidadMaxima, char nombre[] );

int borrarDisfraz( struct disfraz armario[], int capacidadMaxima, char nombre[] );



void inicializar( struct disfraz armario[], int capacidadMaxima ); //funcion para inicializar el armario
void loadArmario( struct disfraz armario[], int capacidadMaxima ); //funcion para inicializar el armario

int armario_lleno( struct disfraz armario[], int capacidadMaxima ); //1 si esta lleno, 0 en caso contrario

int armario_vacio( struct disfraz armario[] ); //1 si esta vacio, 0 en caso contrario

void minusculas( char palabra[] ); //convierte la palabra en minusculas

int main( )
{
   // TO-DO Menu principal

   char nombreDisfraz [MAX_CAD];
   char nombreBusca [MAX_CAD];
   char disfrazborrar[MAX_CAD];
   char nombreTipo[MAX_CAD];
   char parte [30];
   int eleccion1 = 0;
   int res = 0;
   int borrado;
   float precio = 0.0;

   struct disfraz unDisfraz;
   
   inicializar( armario, MAX_ARM );
     
   strcpy( nombreDisfraz, "Naranjito" );
   strcpy( nombreTipo, "Traje" );
   res = insertarParte( armario, MAX_ARM, nombreDisfraz, 9.0, nombreTipo );
   strcpy( nombreBusca, "Naranjito" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );

   strcpy( nombreDisfraz, "Lampara" );
   strcpy( nombreTipo, "Traje" );
   res = insertarParte( armario, MAX_ARM, nombreDisfraz, 7.0, nombreTipo );
   strcpy( nombreBusca, "Lampara" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );
   strcpy( nombreBusca, "Naranjito" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );

   strcpy( nombreDisfraz, "Lombriz" );
   strcpy( nombreTipo, "Traje" );
   res = insertarParte( armario, MAX_ARM, nombreDisfraz, 5.0, nombreTipo );
   strcpy( nombreBusca, "Lampara" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );
   strcpy( nombreBusca, "Naranjito" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );
   strcpy( nombreBusca, "Lombriz" );
   unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );

   strcpy( nombreDisfraz, "Naranjito" );
   strcpy( nombreTipo, "Traje" );
   res = insertarParte( armario, MAX_ARM, nombreDisfraz, 9.0, nombreTipo );

   printf( "  \n" );
   printf( "Armario: \n " );

  
   do
   {
      printf( "\n Introduzca una opcion de 1-5 \n " ); //Pedimos al usuario un  valor
      printf( "1 :Insertar Parte \n " );
      printf( "2: Buscar Disfraz \n " );
      printf( "3 :Mostrar Disfraz  \n " );
      printf( "4: Borrar Disfraz  \n " );
      printf( "5: Salir \n " );

      scanf( "%d", &eleccion1 );
      while ( getchar( ) != '\n' )
         ;

      switch ( eleccion1 )
      {
         case 1:
            printf( "Nombre del traje :\n" );
            gets( nombreDisfraz );
            minusculas( nombreDisfraz );

            printf( "Precio :\n" );
            scanf( "%f", &precio );

            printf( "Tipo de la parte? :\n" );
            scanf( "%s", parte );
            minusculas( parte );

            res = insertarParte( armario, MAX_ARM, nombreDisfraz, precio, parte ); //Si es igual a alguno de estos tres casos llamamos a la funcion correspondiente para ejecutar su algoritmo

            printf( "%d\n", res );

            if ( res == 1 )
            {
               printf( "El traje se ha introducido correctamente" );
            }
            else if ( res == -1 )
            {
               printf( "El traje no se ha podido introducir " );
            }
            else
            {
               printf( "El armario se encuentra lleno o se ha introducido mal gorra o traje" );
            }

            break;



         case 2:

            printf( "Nombre de la parte :\n" );
            gets( nombreBusca );
            minusculas( nombreBusca );

            unDisfraz = buscarDisfraz( armario, MAX_ARM, nombreBusca );

            break;

         case 3:

            if ( armario_vacio( armario ) == 1 )//primero llama a la funcion armario_vacio para comprobar si el armario esta o no vacio, y si es igual a 1 significa que esta vacio e imprime el mensaje encontrado en el printf

            {

               printf( "No se puede mostrar el disfraz porque el armario esta vacio\n" );

            }
            else//el armario no esta vacio por lo cual, se llama a la funcion mostrar disfraz

            {

               mostrarDisfraces( armario, MAX_ARM );

            }

            break;



         case 4:

            if ( armario_vacio( armario ) == 0 )//primero se hace la comprobacion de que el armario no esta vacio, si la funcion devuleve 0 signiifca que no esta vacio y se ejecuta lo que se encuentra dentro del if

            {

               printf( "Escribe el nombre del disfraz a borrar: \n" );

               scanf( "%s", disfrazborrar );

               minusculas( disfrazborrar ); //para converir la palabra recibida en minusculas

               borrado = borrarDisfraz( armario, MAX_ARM, disfrazborrar );



               if ( borrado == 1 )//si la funcion devuelve un 1, eso significaria que el difraz ha sido borrado

               {

                  printf( "Disfraz borrado" );

               }
               else//si la funcion devuelve un 0, el disfraz no ha sido borrado

               {

                  printf( "Disfraz no borrado" );

               }

            }
            else//la funcion armario_vacio ha devuelto un 1 por lo cual el aramrio esta vacio y se imprime el mensaje del printf

            {

               printf( "El armario esta vacio y no se pueden borrar disfraces\n" );

            }

            break;



         case 5:

            printf( "Salir \n " );

            break;



         default:

            printf( "ERROR opcion no valida \n " ); //en caso de que sea un valor no comprendido entre las posibilidades damos un error y volvemos al inicio

      }

   } while ( eleccion1 != 5 ); //Si es diferente a 5 entonces debe repetir de manera infinita este bucle , es decir , que el usuario pueda seguir realizando acciones

}

int insertarParte( struct disfraz armario[], int capacidadMaxima, char nombreDisfraz[100], float precioParte, char tipo[] )
{
   int ret = 0;
   int j = 0;
   int encontrado = 0;
   struct disfraz unDisfraz;
   int posicion = 1;

   // Empezamos por convertir a minusculas para que al comparar no se tenga en cuenta mayusculas o minusculas.
   minusculas( tipo );
   if ( strcmp( tipo, "gorra" ) == 0 || strcmp( tipo, "traje" ) == 0 )
   {
      // Es traje o gorra.
      
      if ( armario_lleno( armario, capacidadMaxima ) == 0)
      {
         // El armario no esta lleno.
   
         minusculas( nombreDisfraz );
         
         if ( armario_vacio( armario ) != 0 )
         {
            // Armario vacio.
            
            strcpy( armario[0].nombre, nombreDisfraz );
            if ( strcmp( tipo, "gorra" ) == 0 )
            {
               // Compra la gorra. 
               armario[0].traje = 0;
               armario[0].gorra = 1;
            }
            else if ( strcmp( tipo, "traje" ) == 0 )
            {
               // Compra el traje. 
               armario[0].traje = 1;
               armario[0].gorra = 0;
            }
            armario[0].precio = precioParte;
            
            ret = 1;
         }
         else
         {
            // Armario no vacio.
            
            // Buscamos si esta el disfraz.
            for ( j=0;    j < capacidadMaxima  
                       &&  encontrado==0  
                       &&  strcmp(armario[j].nombre, "?") != 0
                       &&  strcmp(armario[j].nombre, nombreDisfraz) < 0; j++ )
            {
               // Hay que comparar sin tener en cuenta mayusculas o minusculas.
               // O bien usamos la funcion stricmp o convertimos nombre a minusculas
               // antes de comparar.
               minusculas( nombreDisfraz );
               if ( strcmp( armario[j].nombre, nombreDisfraz ) == 0 )
               {
                  encontrado = 1;

                  if ( strcmp( tipo, "gorra" ) == 0 && armario[j].gorra == 0 )
                  {
                     // Compra la gorra. 
                     armario[j].gorra = 1;
                     armario[j].precio += precioParte;

                     ret = 1;
                  }
                  else if ( strcmp( tipo, "traje" ) == 0 && armario[j].traje == 0 )
                  {
                     // Compra el traje. 
                     armario[j].traje = 1;
                     armario[j].precio += precioParte;

                     ret = 1;
                  }
                  else
                  {
                     // La parte ya esta comprada.
                     ret = -1;
                  }

               }
            }
            
            if ( encontrado == 0 )
            {
               // No ha encontrado el disfraz. Ponerlo en el armario.

               // Si la posicion j donde hay que ponerlo esta ocupada, hay que 
               // desplazar antes de ocuparla.

               if ( strcmp( armario[j].nombre, "?" ) != 0 )
               {
                  for ( int k = capacidadMaxima-1;  k>j;  k-- )
                  {
                     strcpy( armario[k].nombre, armario[k-1].nombre );
                     armario[k].traje = armario[k-1].traje;
                     armario[k].gorra = armario[k-1].gorra;
                     armario[k].precio = armario[k-1].precio;
                  }
               }

               strcpy( armario[j].nombre, nombreDisfraz );
               if ( strcmp( tipo, "gorra" ) == 0 )
               {
                  // Compra la gorra. 
                  armario[j].traje = 0;
                  armario[j].gorra = 1;
                  armario[j].precio = precioParte;
               }
               else if ( strcmp( tipo, "traje" ) == 0 )
               {
                  // Compra el traje. 
                  armario[j].traje = 1;
                  armario[j].gorra = 0;
                  armario[j].precio = precioParte;
               }

               ret = 1;
            }
         }

      }
   }
   
   return ret;
}

void mostrarDisfraces( struct disfraz armario[], int capacidadMaxima )

{

   int i = 0;

   printf( "        Nº   Nombre   Precio      Traje      Gorra    \n" ); //tabla con los elementos a mostrar

   while ( strcmp( armario[i].nombre, "?" ) != 0 && i < capacidadMaxima )//este bucle se realiza mientras nombre sea distinto de ?, y se hace uso de strcmp para comparar que el nombre es distnto a ? y eso debe ser distinto de 0, ya que si es 0 eso significaria que son iguales y que no hay disfraz, ademas tambien tiene que ser menor que la capacidad maxima del armario

   {

      //este if es para ver si el valor que hay alamcenado en las distintas posiciones del armario contienen traje y gorra, y si es asi se imprime ordendamente el nombre, precio, gorra y traje

      if ( armario[i].traje == armario[i].gorra )

      {

         printf( "%d    %s         %0.2f       Traje:[si]  Gorra:[si]\n", i + 1, armario[i].nombre, armario[i].precio ); //se realiza i+1 en todos los printf, ya que el array empieza en posicion 0, y para que de este modo no imprima la primera vez que imprime 0 sino que empiece por 1

      }
      else if ( armario[i].traje == 1 && armario[i].gorra == 0 )//este else if se ejecutara cuando en la posicion del armario exite traje pero no gorra

      {

         printf( "%d    %s         %0.2f       Traje:[si]  Gorra:[no]\n", i + 1, armario[i].nombre, armario[i].precio );

      }
      else//este else se ejecutara cuando no exita traje pero si gorra en la posicion del armario correspondiente

      {

         printf( "%d    %s         %0.2f       Traje:[no]  Gorra:[si]\n", i + 1, armario[i].nombre, armario[i].precio );

      }



      i++; //las posiciones del array van aumentado cada iteracion para poder recorrer todo el armario

   }

}

struct disfraz buscarDisfraz( struct disfraz armario[], int capacidadMaxima, char nombre[] )
{
   int j = 0;
   int encontrado = -1;  // -1 es no encontrado.
   struct disfraz unDisfraz;

   for ( j=0;     j < capacidadMaxima  
              &&  encontrado==-1
              &&  strcmp(armario[j].nombre, "?") != 0; j++ )
   {
      // Hay que comparar sin tener en cuenta mayusculas o minusculas.
      // O bien usamos la funcion stricmp o convertimos nombre a minusculas
      // antes de comparar.
      minusculas( nombre );
      if ( strcmp( armario[j].nombre, nombre ) == 0 )
      {
         encontrado = j;
      }
   }
   
   if ( encontrado != -1 )
   {
      // Copiamos el encontrado.
      strcpy( unDisfraz.nombre, armario[encontrado].nombre );
      unDisfraz.traje = armario[encontrado].traje;
      unDisfraz.gorra = armario[encontrado].gorra;
      unDisfraz.precio = armario[encontrado].precio;
   }
   else
   {
      // Un disfraz vacio.
      strcpy( unDisfraz.nombre, "?" );
      unDisfraz.traje = 0;
      unDisfraz.gorra = 0;
      unDisfraz.precio = 0.0;
   }

   return unDisfraz;
}

int borrarDisfraz( struct disfraz armario[], int capacidadMaxima, char nombre[] )

{ //i es para las distintas posiciones del array

   int encontrado = 0, i = 0; //encontrado es una variable usada para encontrar el disfraz a borrar, que cambia a 1 cuando lo ha encontrado

   while ( strcmp( armario[i].nombre, "?" ) != 0 && i < capacidadMaxima && encontrado == 0 )//este bucle se realiza mientras el nombre del disfraz sea distinto de ?, es decir la comparacion usando strcmp debe ser distinta de 0, y la posicion donde se esta buscando debe ser menor a la capacidad maxima del armario y mientras encontrado sea distinto de 0
   {
      if ( strcmp( armario[i].nombre, nombre ) == 0 )//con strcmp se compara el nombre que se encuentra en las distintas posiciones del array hasta que coincida con el nombre a borrar intorducido por teclado
      {
         encontrado = 1; //como el nombre del difraz a borrar se ha encontrado, encontrado cambia a 1

         for ( int j = i; j < capacidadMaxima; j++ )//este for es para realizar el borrado compacto, recorriendo todo el armario
         {
            if ( j < capacidadMaxima - 1 )//este if es para que entren todas las posicones del array menos la ultima, ya que sera distinta a los demas casos
            {
               strcpy( armario[j].nombre, armario[j + 1].nombre ); //para cambiar el nombre del disfraz a borrar por el que se encuentra en una posicion posterior
               armario[j].traje = armario[j + 1].traje; //para cambiar el valor del traje del disfraz a borrar por el que se encuentra en una posicion posterior, lo mismo ocurre con gorra y precio
               armario[j].gorra = armario[j + 1].gorra;
               armario[j].precio = armario[j + 1].precio; //relizando lo que se encuentra dentro del if te aseguras de que no va a haber un espacio vacio entre un difraz y otro
            }
            else//el ultimo elemento del armario es especial, porque queda duplicado en la penultima y ultima posicion, y para que eso no pase la ultima posicion se vacia
            {
               strcpy( armario[j].nombre, "?" );
               armario[j].traje = 0;
               armario[j].gorra = 0;
               armario[j].precio = 0.0;
            }
         }
      }

      i++;
   }

   return encontrado;
}

int armario_lleno( struct disfraz armario[], int capacidadMaxima )//esta funcion es para comprobar si el armario esta lleno o no esta lleno pero hay algun disfraz
{

   int result;

   if ( strcmp( armario[capacidadMaxima - 1].nombre, "?" ) == 0 )//comprueba en la ultima posicion del armario si el nombre es igual a ?, si es asi strcmp devulve 0, y eso significa que no esta lleno
   {
      result = 0;
   }
   else //si strcmp devuelve un numero distinto de 0 eso significa que el armario esta lleno
   {
      result = 1;
   }

   return result;
}

int armario_vacio( struct disfraz armario[] )//esta funcion es para ver si el armario esta vacio o hay algun disfraz dentro, devuelve 1 si esta vacio y 0 si hay algun disfraz
{
   int result;

   if ( strcmp( armario[0].nombre, "?" ) == 0 )//compara con strcmp si el nombre en la primera posicion del array es igual a ?, si es asi strcmp devuleve un 0 y eso significa que el armario esta vacio, ya que no hay nada en la posicion 0
   {
      result = 1;
   }
   else
   {
      result = 0;
   }

   return result;
}

void minusculas( char palabra[] )//esta funcion ha sido creada para convertir las letras de las palabras en minusculas
{

   for ( int i = 0; i < strlen( palabra ); i++ )//este for recorre las letras de la palabra desde la posicion 0 hasta la lonitud de la palabra
   {
      if ( palabra[i] >= 'A' && palabra[i] <= 'Z' )//comprueba que existen mayusculas y si es asi, las convierte a minusculas realizando lo que se encuentra dentro del if
      {
         palabra[i] = tolower( palabra[i] );
      }
   }
}

void inicializar( struct disfraz armario[], int capacidadMaxima )//esta funcion es para inicializar el armario
{
   FILE * fArmario = NULL;
   char linea[256] ;
   int i = 0;
   int k = 0;
   
   fArmario = fopen( "armario.txt", "r" );
   if ( fArmario != NULL )
   {
      /* Leer cada linea */
      while ( fscanf( fArmario, "%s", linea ) != EOF )
      {
         /* ahora convertimos los ';' en espacios */
         for ( k = 0; k < strlen( linea ); k++ )
         {
            if ( linea[k] == ';' )
               linea[k] = ' ';
         }

         sscanf( linea, "%s %d %d %f", armario[i].nombre
                 , (int*) &armario[i].traje
                 , (int*) &armario[i].gorra
                 , &armario[i].precio );
         
         
         printf( "%s %d %d %.4f\n", armario[i].nombre
                                  , armario[i].traje
                                  , armario[i].gorra
                                  , armario[i].precio );  
         
      }
      
   }

   fclose( fArmario );
   
   // Si no se ha podido abrir el fichero o si se han leido
   // menos disfraces (lineas) que la capacidad del armario, lo rellenamos con
   // disfraces vacios.
   for (   ; i < MAX_ARM ; i++ )
   {
      strcpy( armario[i].nombre, "?" );
      armario[i].traje = 0;
      armario[i].gorra = 0;
      armario[i].precio = 0.0;
   }
}

void loadArmario( struct disfraz armario[], int capacidadMaxima )//esta funcion es para inicializar el armario
{
   FILE * fArmario = NULL;
   char linea[256] ;
   int i = 0;
   
   fArmario = fopen( "armario.txt", "r" );
   if ( fArmario == NULL )
   {
      return ;
   }
   
   /* Leer cada linea del fichero */   
   while ( fscanf( fArmario, "%s", linea ) != EOF )
   {
      /* ahora convertimos los ';' en espacios */
      for ( i=0; i<strlen(linea) ; i++ )
         if ( linea[i] == ';' )
            linea[i] = ' ';

      sscanf( linea, "%s %d %d %f",         armario[i].nombre
                                  , (int*) &armario[i].traje
                                  , (int*) &armario[i].gorra
                                  ,        &armario[i].precio );
      
      printf( "%s %d %d %.2f\n", armario[i].nombre
                               , armario[i].traje
                               , armario[i].gorra
                               , armario[i].precio );  
      
      i++;
   }

   fclose( fArmario );
}
