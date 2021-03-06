function cifrado = cifrado_hill(A,m, texto)

   if (inv_modulo(A, m)~=0)

       d = size(A, 1);
       %Comprobamos que el texto es divisible entre el numero de filas o
       %columnas de A
       a = mod(length(texto), d);
       if(a ~= 0)
            %Si no es divisible metemos X al final
            for i=1:d-a
               texto = strcat(texto, 'w');
            end
       end
        %Pasamos el texto a numeros y lo dividimos en grupos
        numeros = letranumero(texto);
        X = reshape(numeros, d, []);
        Y = mod(A*X, m);
        %Ahora tenemos que concatenar las columnas y pasarlo a letra

        cifrado = reshape(Y, 1, []);

        %Con esto ya deberiamos de tener el texto cifrado
        cifrado = numeroletra(cifrado);
   else
       error('ErrorTests:convertTest','La matriz no tiene inversa')
   end