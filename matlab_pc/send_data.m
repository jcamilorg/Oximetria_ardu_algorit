L1der = [1000,1300,1200,1000,900,1000];
L2der  = [1000,1400,1300,1000,800,1000];
L1izq = L1der-300;
L2izq = L2izq-500;

s=Ini_Serial();
for i=1:length(L1der)
  
    
   fprintf(s,'1234');
   pause(0.0025);
   clear p1;clear p2;clear p3;
end
   p1 = fscanf(s);
fclose(s);

function s = Ini_Serial()
delete(instrfind)
s = serial('COM3','BaudRate',9600, 'DataBits', 8);
fopen(s);
end

function data = prepare_data(L1der,L2der,L1izq,L2izq)
%convertir a Str
   strL1der = int2str(L1der(i));
   strL2der = int2str(L2der(i));
   strL1izq = int2str(L1izq(i));
   strL2izq = int2str(L1izq(i));
  % agregar cero si es neceario
  strAdd = 4 - strlength(strL1der);  %%L1der
  for j=0:strAdd                       
    strL1der = strcat('0',strL1der);
  end
    strAdd = 4 - strlength(strL2der); %% L2der
  for j=0:strAdd 
    strL2der = strcat('0',strL2der);
  end
      strAdd = 4 - strlength(strL1izq); %%L1i
  for j=0:strAdd 
    strL1der = strcat('0',strL1der);
  end
      strAdd = 4 - strlength(strL1der); %% L2der
  for j=0:strAdd 
    strL1der = strcat('0',strL1der);
  end
  

end