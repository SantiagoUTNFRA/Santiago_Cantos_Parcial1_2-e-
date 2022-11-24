#ifndef INPUTS_H_
#define INPUTS_H_

#endif /* INPUTS_H_ */

/**
 * @fn int pedirEntero(int*, char[], char[], int, int)
 * @brief Función que pide un numero entero
 *
 * @param enteroValidado enteroValidado int * Valor entero ingresado por el usuario.
 * @param mensaje char * Mensaje a transmitir al usuario.
 * @param mensajeError char * Mensaje de error a transmitir al usuario.
 * @param min int Numero minimo a validar
 * @param max int Numero maximo a validar
 * @return int 0 si pudo hacerlo, -1 si no pudo
 */
int pedirEntero(int *enteroValidado, char mensaje[], char mensajeError[], int min, int max);

/**
 * @fn int pedirFlotante(float*, char[], char[], float, float)
 * @brief Función que pide un numero flotante
 *
 * @param numFloat float * Valor flotante ingresado por el usuario.
 * @param mensaje char * Mensaje a transmitir al usuario.
 * @param mensajeError char * Mensaje de error a transmitir al usuario.
 * @param min float Numero minimo a validar
 * @param max float Numero maximo a validar
 * @return int 0 si pudo hacerlo, -1 si no pudo
 */
int pedirFlotante(float *numFloat, char mensaje[], char mensajeError[], float min, float max);

/**
 * @fn int pedirCadena(char[], char[], char[], int)
 * @brief Función que pide una cadena de caracteres al usuario, valida su rango y su maximo de caracteres
 *
 * @param cadena char * Array de caracteres que guarda lo ingresado por el usuario para lugego validarlo.
 * @param mensaje char * Mensaje a transmitir al usuario.
 * @param mensajeError char * Mensaje de error a transmitir al usuario.
 * @param max int maximo de caracteres permitidos al usuario
 * @return int 0 si pudo hacerlo, -1 si no pudo
 */
int pedirCadena(char cadena[], char mensaje[], char mensajeError[], int max);

/**
 * @fn int pedirCaracter(char*, char[], char[], char, char)
 * @brief Función que pide un caracter
 *
 * @param charValidado char * Caracter ingresado por el usuario.
 * @param mensaje char * Mensaje a transmitir al usuario.
 * @param mensajeError char * Mensaje de error a transmitir al usuario.
 * @param primerChar char Caracter a validar
 * @param segundoChar char Caracter a validar
 * @return int 0 si pudo hacerlo, -1 si no pudo
 */
int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar);

/**
 * @fn int pedirShort(short*, char[], char[], int, int)
 * @brief Función que pide un numero short
 *
 * @param shortValidado int * Valor short ingresado por el usuario.
 * @param mensaje char * Mensaje a transmitir al usuario.
 * @param mensajeError char * Mensaje de error a transmitir al usuario.
 * @param min int Numero minimo a validar
 * @param max int Numero maximo a validar
 * @return int 0 si pudo hacerlo, -1 si no pudo
 */
int pedirShort(short *shortValidado, char mensaje[], char mensajeError[], int min, int max);

/**
 * @fn int menu()
 * @brief Función que imprime un menú principal en pantalla
 *
 * @return int opcion ingresada por el usuario
 */
int menu();

/**
 * @fn int menuModificacion()
 * @brief Función que imprime un menú en modificación en pantalla
 *
 * @return int opcion ingresada por el usuario
 */
int menuModificacion();
