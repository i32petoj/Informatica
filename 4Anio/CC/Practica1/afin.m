function cifradoafin = afin(clave, d, texto)
numero = letranumero(texto);
cifradoafin = [];
clave = floor(clave);
d = floor(d);
abecedario = 'abcdefghijklmnnopqrstuvwxyz';
abecedario(15) = char(241);

if gcd(clave, length(abecedario)) == 1
    
    numero = numero * clave + d;
    numero = mod(numero, length(abecedario));

    cifradoafin = numeroletra(numero);
else
    error('ErrrorTest:convertTest', 'El maximo comun divisor no es 1')
    
    
end
