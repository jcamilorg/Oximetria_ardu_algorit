L1der = 56;
L2iz  = 98;

Data_Vector=zeros(1,100);
%%Iniciar Serial
s=Ini_Serial();

fscanf(s) %% lectura de datos 
for i=1:5
    fprintf(s,'1234');
    fscanf(s)
    fscanf(s)
    fscanf(s)
end
fclose(s);

function s = Ini_Serial()
delete(instrfind)
s = serial('COM3','BaudRate',9600, 'DataBits', 8);
fopen(s);
end

