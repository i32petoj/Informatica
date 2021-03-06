function valida = mochila(s)

n = length(s);
%Funcion que comprueba si una mochila es supercreciente y para ello realiza
%una serie de pruebas en un bucle para todos sus elementos
for i=1:n-1
   if mod(s(i), 1) == 0 &&  s(i)>0
       sumatorio = 0;
       for j=1:i
            sumatorio = sumatorio + s(j);
       end
       if s(i+1) < s(i)
           disp('La mochila no esta ordenada crecientemente');
           valida = 0;
           return
       end
       
       if sumatorio > s(i+1)
            valida = 0;
            disp('La mochila no es supercreciente');
            return
       end
   else
       valida = 0;
       disp('Los elementos de la mochila no son naturales o positivos');
       return
   end
end

valida = 1;