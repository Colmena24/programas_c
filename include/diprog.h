/******************************************************************************
* @file     diprog.c
* @author   Diego M. Caprioli <diego@artfultec.com>
* @author   Carlos Cadabeira  <carlos@artfultec.com>
* @version  1.1
* 
* Librería con funciones útiles para la Diplomatura en Programación de Artfultec
* Academy.
* Esta versión mejora la estructura utilizada para la definición de la librería,
* utilizando propiamente un archivo header (.h) y un archivo de código (.c).
* Para hacer de esta nueva versión, empezamos a utilizar la utilidad "make".
*
* Copyright (c) 2023
* All rights reserved
*
* BSD 3-Clause License
* http://www.opensource.org/licenses/BSD-3-Clause
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* * Redistributions of source code must retain the above copyright notice,
*   this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
* * Neither the name of DiProg nor the names of its contributors may be used
*   to endorse or promote products derived from this software without
*   specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
******************************************************************************/


// Incluir librerias necesarias
#include <stdlib.h>
#include <stdio.h>

/**
 * Longitud máxima para tipo de datos string (usado para limitar algunas funciones)
 */
#define LONG_MAX_STRING 1024

/**
 * Longitud máxima para tipo de datos string (usado para limitar algunas funciones)
 */
#define MAX_STRINGS 256

/**
 * Definicion simple de un tipo de datos string, como utilitario básico.
 */
typedef char *string;

/**
 * Imprime el mensaje, lee un char entero por teclado y lo devuelve como 
 * valor de retorno de la función.
 */
char leer_char(string mensaje);

/**
 * Imprime el mensaje, lee un string por teclado y lo devuelve como 
 * valor de retorno de la función.
 *
 * IMPORTANTE: Mantenemos la definidicón de esta función, como ejemplo de 
 * una implementación extremadamente simple. Ha sido reemplzada por la
 * actual función leer_string()
 */
string leer_string_old(string mensaje);

/**
 * Imprime el mensaje, lee un string por teclado y lo devuelve como 
 * valor de retorno de la función.
 * Soporta CR (\r), LF (\n), y CRLF (\r\n) como finales de línea.
 * Si el usuario ingresa solamente un fin de linea, devuelve "" y no
 * un NULL. Retorna NULL en caso de error.
 * Almacena el string en el heap, pero luego el destructor libera la
 * memoria en la terminación del programa. 
 */
string leer_string(string mensaje);

/**
 * Imprime el mensaje, lee un int por teclado y lo devuelve como 
 * valor de retorno de la función.
 */
int leer_int(string mensaje);

/**
 * Imprime el mensaje, lee un int por teclado y lo devuelve como 
 * valor de retorno de la función.
 */
 long leer_long(string mensaje);

/**
 * Imprime el mensaje, lee un float por teclado y lo devuelve como 
 * valor de retorno de la función.
 */
float leer_float(string mensaje);

/**
 * Imprime el mensaje, lee un float por teclado y lo devuelve como 
 * valor de retorno de la función.
 */
double leer_double(string mensaje);
