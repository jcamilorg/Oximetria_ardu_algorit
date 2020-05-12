function data = prepare_data(L1der,L2der,L1izq,L2izq)
%convertir a Str
   strL1der = int2str(L1der);
   strL2der = int2str(L2der);
   strL1izq = int2str(L1izq);
   strL2izq = int2str(L2izq);
  % agregar cero si es neceario
  strAdd = 4 - strlength(strL1der);  %%L1der
  for j=1:strAdd                       
    strL1der = strcat('0',strL1der);
  end
    strAdd = 4 - strlength(strL2der); %% L2der
  for j=1:strAdd 
    strL2der = strcat('0',strL2der);
  end
      strAdd = 4 - strlength(strL1izq); %%L1izq
  for j=1:strAdd 
    strL1izq = strcat('0',strL1izq);
  end
      strAdd = 4 - strlength(strL2izq); %% L2izq
  for j=1:strAdd 
    strL2izq = strcat('0',strL2izq);
  end
  data = strcat(strL1der,',',strL2der,',',strL1izq,',',strL2izq,',');
end