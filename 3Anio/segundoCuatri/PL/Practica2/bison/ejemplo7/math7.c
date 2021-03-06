#include <math.h>
#include <errno.h>
#include "ejemplo7.h"

/*  Referencia a la variable global que indica los codigos 
   de los errores generados por las funciones matematicas */
extern int errno;

/* Prototipo de la funcion que comprueba errores matematicos **/
double errcheck(double d, char *s);

/*****************************************************************/
/** Nombre: Log                                                 **/
/** Labor que desarrolla: calcula el logaritmo neperiano de un  **/
/**       numero real, pero comprueba antes si hay algun error  **/
/**       en el argumento.                                      **/ 
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: x                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: indica el numero al cual se le va aplicar       **/
/**            la funcion logaritmo neperiano                   **/
/*****************************************************************/
double Log(double x)
{
 return errcheck(log(x),"logaritmo neperiano");
 }

/*****************************************************************/
/** Nombre: Log10                                               **/
/** Labor que desarrolla: calcula el logaritmo decimal de un    **/
/**       numero real, pero comprueba antes si hay algun error  **/
/**       en el argumento.                                      **/ 
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: x                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: indica el numero al cual se le va aplicar       **/
/**            la funcion logaritmo decimal                     **/
/*****************************************************************/
double Log10(double x)
{
 return errcheck(log10(x),"logaritmo decimal");
}

/*****************************************************************/
/** Nombre: Exp                                                 **/
/** Labor que desarrolla: calcula la exponencial de un numero   **/
/**       real, pero comprueba antes si hay algun error en el   **/
/**       argumento.                                            **/ 
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: x                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: indica el numero al cual se le va aplicar       **/
/**            la funcion exponencial                           **/
/*****************************************************************/
double Exp(double x)
{
 return errcheck(exp(x),"exponencial");
}

/*****************************************************************/
/** Nombre: Sqrt                                                **/
/** Labor que desarrolla: calcula la raiz cuadrada de un numero **/
/**       real, pero comprueba antes si hay algun error en el   **/
/**       argumento.                                            **/ 
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: x                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: indica el numero al cual se le va aplicar       **/
/**            la funcion raiz cuadrada.                        **/
/*****************************************************************/
double Sqrt(double x)
{
 return errcheck(sqrt(x),"raiz cuadrada");
}

/*****************************************************************/
/** Nombre: integer                                             **/
/** Labor que desarrolla: calcula la parte entera de un numero  **/
/**       real, pero comprueba antes si hay algun error en el   **/
/**       argumento.                                            **/ 
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: x                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: indica el numero al cual se le va aplicar       **/
/**            calcular la parte entera.                        **/
/*****************************************************************/

double integer(double x)
{
 return  (double) (long) x;
}

/*****************************************************************/
/** Nombre: errcheck                                            **/
/** Labor que desarrolla: comprueba si se ha producido un error **/
/**       al realizar la evaluacion matematica del primer       **/
/**       parametro. Si no hay error, entonces devuelve el      **/
/**       primer parametro; en caso contrario muestra el error  **/ 
/**       producido.                                            **/
/** Tipo de resultado: real de doble precision "double"         **/
/** Parametro:                                                  **/
/**  Nombre: d                                                  **/
/**    	Tipo: real de doble precision "double"                  **/
/**     Mision: almacenar el valor obtenido al aplicar una      **/
/**            funcion matematica                               **/
/**  Nombre: s                                                  **/
/**    	Tipo: cadena de caracteres o puntero a caracter "char *"**/
/**     Mision: indica el nombre de la funcion que se ha        **/
/**       utilizado para calcular el valor del primer parametro.**/
/*****************************************************************/
double errcheck(double d, char *s)
{
 if (errno==EDOM)
    {
     errno=0; /* Desactiva el error */
     execerror(s," argumento fuera de dominio ");
    }
   else if (errno==ERANGE)
           {
            errno=0; /* Desactiva el error */
            execerror(s," resultado fuera de rango ");
           }
 return d;
}
