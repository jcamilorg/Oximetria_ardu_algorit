L1der = 56;
L2iz  = 98;

Data_Vector=zeros(1,100);
%%Iniciar Serial
s=Ini_Serial();

for i=1:10 
   fprintf(s,'1234');
   p1 = fscanf(s);
   p2 = fscanf(s);
   p3 = fscanf(s);
   a = strcat(p1,p2,p3)
   clear p1;clear p2;clear p3;
end
fclose(s);

function s = Ini_Serial()
delete(instrfind)
s = serial('COM3','BaudRate',9600, 'DataBits', 8);
fopen(s);
end

