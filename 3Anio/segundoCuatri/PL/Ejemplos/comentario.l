%{
  /* Descripcion:
	El analizador léxico reconoce y cuenta los comentarios del lenguaje C
        Se muestra el uso de 
		BEGIN 
		reglas condicionales controladas por un estado de flex definido por el programador
 */

  /* Indica el número de comentario */
 int comentario=0;

 /* Indica el número de líneas de cada comentario */
 int lineas_comentario;
%}

/* Definiciones regulares */
letra         [a-zA-Z]
digito        [0-9]
identificador {letra}({letra}|{digito})*

/* Se define un nuevo estado: ESTADO_COMENTARIO */
%x ESTADO_COMENTARIO

%% 

{identificador}          {printf("identificador = %s\n", yytext);}

"/*"	                  {
			    /* Se activa el reconocimiento de un comentario */
			    BEGIN ESTADO_COMENTARIO; 
			    comentario++; 
			    lineas_comentario=1;
			  }

<ESTADO_COMENTARIO>"/*"/(.|\n)  {
			          printf("\n No se pueden anidar comentarios\n"); 
				  return 0;
				 }

<ESTADO_COMENTARIO>"*/"          { /* Fin del comentario: se vuelve al estado por defecto */
				  BEGIN 0; 
				  printf("\n nº comentario = %d, lineas_comentario = %d\n",comentario, lineas_comentario);
				  }      

<ESTADO_COMENTARIO>.              {;}

<ESTADO_COMENTARIO>\n            {lineas_comentario++;}

#       	                  {printf("\n Final\n\n"); return 0;} 

.       	                  {ECHO;}
%%  


