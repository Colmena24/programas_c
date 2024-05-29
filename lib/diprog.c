

// Incluir header "propio"
#include <diprog.h>

/**
 * Cantdad de strings alocados por leer_string.
 */
static size_t allocations = 0;

/**
 * Array de strings alocados por leer_string.
 */
static string *strings = NULL;


char leer_char(string mensaje)
{
   string s = leer_string(mensaje);
   return s[0];
}


string leer_string_old(string mensaje)
{
   // Reservar memoria en la pila con malloc para devolver una variable que existe 
   // fuera del contexto de la función local. 
   // ADVERTENCIA: Potencial problema de memory leak. Sólo utilizar en ejemplos y
   // progrramos pequeños para simplificar la obtencón de string y aprender otros 
   // conceptos.
   char *s = malloc(sizeof (char) * LONG_MAX_STRING);
   
   printf("%s", mensaje);
   fgets(s, LONG_MAX_STRING, stdin);

   return s;
}


string leer_string(string mensaje)
{
   // Verificar si tenemos lugar para otro string
   if (allocations == MAX_STRINGS / sizeof (string)) {
      return NULL;
   }

   // buffer de caracteres
   string buffer = NULL;

   // cpacidad del buffer
   size_t capacity = 0;

   // Cantidad de caracteres actualmente en el buffer
   size_t size = 0;

   // Para leer el caracter
   int c;

   // Pedir ingreso al usuario
   printf("%s", mensaje);

   // Obtener los caracteres hasta el fin de linea. CR (Mac OS), LF (Linux), CRLF (Windows)
   while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF) {

      // Incrementar el buffer si es necesario
      if (size + 1 > capacity) {

         // Incrementar la capacidad del buffer
         if (capacity < MAX_STRINGS) {
            capacity++;
         } else {
            free(buffer);
            return NULL;
         }

         // Extender la capacidad
         string temp = realloc(buffer, capacity);
         if (temp == NULL) {
            free(buffer);
            return NULL;
         }
         buffer = temp;
      }

      // Agregar el char actual al buffer
      buffer[size++] = c;
   }

   // El usuario ingreso caracteres?
   if (size == 0 && c == EOF) {
      return NULL;
   }

   // Demasiados caracteres?
    if (size == LONG_MAX_STRING) {
      free(buffer);
      return NULL;
   }

   // Si el última char leído fue CR, intentar leer LF también
   if (c == '\r' && (c = fgetc(stdin)) != '\n') {
      // Devolver NULL si el char no se puede mandar a stdin
      if (c != EOF && ungetc(c, stdin) == EOF) {
         free(buffer);
         return NULL;
      }
   }

   // Minimizar el buffer
   string s = realloc(buffer, size + 1);
   if (s == NULL) {
      free(buffer);
      return NULL;
   }

   // finalizar el string
   s[size] = '\0';

   // Cambiar tamaño del array
   string *tmp = realloc(strings, sizeof (string) * (allocations + 1));
   if (tmp == NULL) {
      free(s);
      return NULL;
   }
   strings = tmp;

   // Append string to array
   strings[allocations] = s;
   allocations++;

   // Return string
   return s;
}


int leer_int(string mensaje)
{
   // Declaración de variables
   int i;

   printf("%s", mensaje);
   scanf("%i", &i);

   return i;
}


long leer_long(string mensaje)
{
   // Declaración de variables
   long l;

   printf("%s", mensaje);
   scanf("%li", &l);

   return l;
}


float leer_float(string mensaje)
{
   // Declaración de variables
   float f;

   printf("%s", mensaje);
   scanf("%f", &f);

   return f;
}


double leer_double(string mensaje)
{
   // Declaración de variables
   double d;

   printf("%s", mensaje);
   scanf("%lf", &d);

   return d;
}