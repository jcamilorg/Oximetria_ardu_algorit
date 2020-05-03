L1der = [1000,1300,1200,1000,900,1100];
L2der  = [1000,1400,1300,1000,800,1350];
L1izq = L1der-300;
L2izq = L2der-500;

s=Ini_Serial();
fscanf(s);
for i=1:length(L1der)
data = prepare_data(L1der(i),L2der(i),L1izq(i),L2izq(i));
pause(0.004)
fprintf(s,data);
end
ac = fscanf(s);
fclose(s);



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
  data = strcat(strL1der,',',strL2der,',',strL1izq,',',strL2izq);
end

function s = Ini_Serial()
delete(instrfind)
s = serial('COM3','BaudRate',115200, 'DataBits', 8);
fopen(s);
end